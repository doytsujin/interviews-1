# Interview Question Solutions

## Lessons

Here are my solutions to the following interview questions:

1. [population.cpp](src/population.cpp) - Given a list of records with people's birth and death years, determine which year had the most living people.

2. reflection - Write a function that takes as input a binary tree and returns the "reflection" of that tree. For every path in the original tree from the root (e.g., RLLRRL) there should be a reflected path in the new tree (e.g., LRRLLR)

3. boarding - You are taking a trip from one city to another with several layovers and you have a separate boarding pass for each leg. For example, `JFK -> ATL -> LAX -> SFO`. Each boarding pass has a start and end city for that leg of the trip. Write a function where the input is a list of boarding passes for a trip and the output is the boarding passes sorted in order.
   `Example:`  
   `Input: {'s': ATL, 'e': LAX}, {'s': LAX, 'e': SFO}, {'s': JFK, 'e': ATL}`  
   `Output: {'s': JFK, 'e': ATL}, {'s': ATL, 'e': LAX}, {'s': LAX, 'e': SFO}`

4. football - In football you can score a touchdown to get 7 points, a field goal to get 3 points, or a safety to get 2 points. Given a final score, compute all the different ways it could be achieved. Assume the order of the scores doesn't matter (so a touchdown and a safety is the same as a safety and a touchdown).

5. correspondence - You are given a mapping of letters to numbers `a -> 1 b -> 2 c -> 3 ... z -> 26` Given a number, count the number of ways that it can be interpreted as a string of characters by reversing this correspondence. (FB)
   `For example:`  
   `123 -> 1 + 23 = a + (some letter)`  
   `123 -> 12 + 3 = (some letter) + c`  
   `123 -> 1 + 2 + 3 = a + b + c`  
   `So, there are 3 ways to interpret 123 in letters`

6. longest - Given a binary tree (each node has at most 2 children) give the length of the longest path in the tree as a non-directed graph. That is, the longest path may or may not go through the root and need not start or end there.

7. english - Given an integer, print it out in written English. For example 19 -> nineteen, 532 -> five hundred thirty two, etc.

8. interleave Given a singly-linked list `E1 -> E2 -> ... -> E(n-1) -> En`, interleave the first half with the second half reversed: `E1 -> En -> E2 -> E(n-1) -> ...`

9. submatrix - Given an n x m matrix of numbers A, find the largest submatrix whose sum is under a given value b.

10. connected - You are given an arbitrary matrix containing 0's and 1's. A connected component is a collection of cells which are all 1's and which are all connected to each other by steps in one of the four horizontal or vertical directions. Count the number of connected components of your matrix. Follow up:
  - Find the centroid of each connected component.
  - What if retrieving or setting the cell value is expensive?

11. [countPrimes.cpp](src/countPrimes.cpp) - Count the number of prime numbers up to a non-negative number, ***n***.

## Tests

Assuming you are using cmake, tests will be located in your `$BUILD_DIR}/bin` directory. All tests are in the same `challenges` binary. Individual tests can be run per the [googletest framework documentation](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#running-test-programs-advanced-options). Here is a quick reference:

```
/path/to/build/bin> challenges --help
/path/to/build/bin> challenges --gtest_list_tests
/path/to/build/bin> challenges --gtest_filter=TestName.Test
/path/to/build/bin> challenges --gtest_filter=TestName.\*
/path/to/build/bin> challenges --seed 12345
```

### Dependencies

Test are built using the following packages. Use CMake and the dependencies will be downloaded and built for you.

- [gflags](https://gflags.github.io/gflags/)
- [googletest](https://github.com/google/googletest)

### Building

You can build the tests for your favorite development environment using `cmake`. e.g.:

- For the command line:

```shell
mkdir test/build
cd test/build
cmake ..
make
```

- For XCode:

```shell
mkdir test/xcode
cd test/xcode
cmake -G Xcode ..
make
```

Tests will be created in the `bin` directory located wherever you ran cmake from (`test\build\bin` in the example above).

## Contributing

You are welcome to contribute provided you accept the [Contributor Covenant Code of Conduct](CONTRIBUTING.md).

## License

This repository is licensed under [The Unlicense](LICENSE.md).

## Acknowledgements

- Thank you to the [gflags](https://gflags.github.io/gflags/) command line parsing library.
- Thank you to the [googletest](https://github.com/google/googletest) C++ test framework.
