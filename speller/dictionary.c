// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table (تم زيادة العدد لسرعة البحث وتحسين الكفاءة)
const unsigned int N = 26 * 26 * 26;

// Hash table
node *table[N];

// Global variable to keep track of total words loaded
unsigned int word_count = 0;
bool is_loaded = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase to ensure case-insensitive search
    int length = strlen(word);
    char lower_word[LENGTH + 1];
    for (int i = 0; i < length; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[length] = '\0';

    // Get the hash value for the word
    unsigned int index = hash(lower_word);

    // Point to the first node in that bucket's linked list
    node *cursor = table[index];

    // Traverse the linked list
    while (cursor != NULL)
    {
        // Compare words case-insensitively
        if (strcasecmp(cursor->word, lower_word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number (Improved hash function)
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0' && i < 3; i++)
    {
        hash_value = (hash_value << 2) + tolower(word[i]);
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer to read words into
    char word[LENGTH + 1];

    // Read strings from file one by one
    while (fscanf(file, "%s", word) == 1)
    {
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy word into node
        strcpy(n->word, word);
        n->next = NULL;

        // Get hash value for the word
        unsigned int index = hash(word);

        // Insert node into hash table at that index
        n->next = table[index];
        table[index] = n;

        // Increment word count
        word_count++;
    }

    // Close the dictionary file
    fclose(file);
    is_loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (is_loaded)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through all buckets in the hash table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
