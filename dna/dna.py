import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    rows = []
    with open(database_file, "r") as file:
        reader = csv.DictReader(file)
        subsequent_fields = reader.fieldnames[1:]
        for row in reader:
            rows.append(row)

    with open(sequence_file, "r") as file:
        dna_sequence = file.read()

    str_counts = {}
    for str_seq in subsequent_fields:
        str_counts[str_seq] = longest_match(dna_sequence, str_seq)

    for person in rows:
        match = True
        for str_seq in subsequent_fields:
            if int(person[str_seq]) != str_counts[str_seq]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        if count > longest_run:
            longest_run = count

    return longest_run


if __name__ == "__main__":
    main()
