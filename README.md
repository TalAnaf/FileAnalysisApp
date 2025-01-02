
# File Analysis App  📚

A C program that reads the contents of a file, sorts all the words in **lexicographic order**, and outputs each word along with the line numbers where it appears.

---

## 📖 Description

This program:
1. Prompts the user to input the name of a text file.
2. Reads the file line by line and extracts all words.
3. Sorts the words in **lexicographic order** (alphabetical order).
4. Tracks and prints the line numbers where each word appears.

It handles duplicate words by aggregating their line numbers and ensures efficient memory management using dynamic memory allocation.

---

## 🚀 Features

- **Lexicographic Sorting**: Sorts words alphabetically for easy readability.
- **Line Tracking**: Tracks all line numbers where each word appears.
- **Duplicate Handling**: Avoids duplicates by grouping occurrences of the same word.
- **Dynamic Memory Management**: Allocates memory dynamically for flexibility with file size.

---

## 🛠️ How It Works

1. **File Input**:
   - User inputs the file name.
   - The program opens and validates the file.

2. **Word Extraction**:
   - Reads the file line by line.
   - Extracts individual words and removes newline characters.

3. **Lexicographic Sorting**:
   - Words are sorted using a bubble sort algorithm for lexicographic order.

4. **Line Tracking**:
   - Maintains a list of line numbers for each word.
   - Aggregates line numbers if a word appears multiple times.

5. **Output**:
   - Prints each word along with its associated line numbers.
