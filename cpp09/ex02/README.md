# 📁 PmergeMe

PmergeMe is a C++ project designed to sort a positive integer sequence using the merge-insert sort (Ford-Johnson) [algorithm](https://en.wikipedia.org/wiki/Merge-insertion_sort). 
It makes use of the Standard Template Library (STL) containers (in this case vectors and lists) to perform the operations.

### 📥 Input
- The program receives a positive integer sequence.
- Example: `3 4 2 7 9 1 10 23`

### 📤 Output
- The program outputs the ordered sequence and the time it took for the program to sort it using std::vector and std::list.
- For the example above, the output would be: 
```
Before: 3 4 2 7 9 1 10 23 
After: 1 2 3 4 7 9 10 23 
Time to process a range of 8 elements with std::vector 6 us
Time to process a range of 8 elements with std::list 8 us
```

## ✨ Features

- **Versatile Container Support**: Handles both `std::vector` and `std::list`, showcasing the flexibility of STL containers.
- **Classic Algorithm Implementation**: Implements the Ford-Johnson sorting algorithm, offering insight into a less commonly used but historically significant sorting method.
- **Educational Value**: Great resource for learning about STL containers, their operations, and how to efficiently handle merging tasks.
- **Error Handling**: Comprehensive error checking and handling to ensure the program runs smoothly under various conditions.

## 🛠️ Usage

1. Clone this repository;
2. Compile the program: `make`;
3. Run: `./PmergeMe <positive_integer_sequence>`; 
