#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 //i assign the value max (max inputs at once) to be 9 as then easily to change it



//vote function trial
 bool vote ( string name) //bool as it gives true or false
{
    for (int i = 0; i < candidate_count; i++) //we will do this for all candidates
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes ++;
            return true;
        }
    } return false; //in invalid inputs cases
}

//winner function trial
void print_winner() //void as no return value or parameter
{
    
}


