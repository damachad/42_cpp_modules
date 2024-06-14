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

## Merge insert algorithm (Ford-Johnson)
This algorithm performs the following steps, on an input *X* of n elements:

1. Group the elements of *X* into [n/2] pairs of elements, arbitrarily, leaving one element unpaired (straggler) if there is an odd number of elements.
2. Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair, and sort each pair.
3. Recursively sort the [n/2] pairs, based on the larger element from each pair, 
4. Separate the larger element from each pair into sequence *S*, in ascending order. The remaining elements from each pair stay in sequence *pend*.
5. Insert at the start of *S* the element from *pend* that was paired with the first and smallest element of *S*.
6. Insert the remaining [n/2] - 1 elements of *pend* into *S*, one at a time. This step is optimized by using Jacobsthal numbers. These provide a more balanced insertion and minimize the cost of insertion.
7. Insert the unpaired element (straggler), if present.

## Links
https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
