//
// Test executable for Interviews problems
//
#include <iostream>
#include <vector>

// #include "sample.h"
#include <gtest/gtest.h>
#include <gflags/gflags.h>

#include "macros.h"
#include "args.h"

using namespace std;

namespace lesson
{
    namespace test
    {
        // Add utility functions here
        /*
        vector<int> generateRandomSequence(const int &N, const int &M, int seed)
        {
            vector<int> A(N);
            if ( !seed ) {
                seed = time(0);
            }
            cout << "Generating random sequence using " << seed << endl;
            srand(seed);

            for (int i=0; i<N; i++) {
                A[i] = rand() % (M+1);
            }
            return A;
        }
        */
    } // namespace test
} // namespace lesson

/*
TEST(SampleTest, BruteForce) 
{
    ASSERT_EQ(lesson::bruteForce(A), 0);
}

TEST(SampleTest, Edge) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}

TEST(SampleTest, Sample) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}

TEST(SampleTest, Empty) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}

TEST(SampleTest, Zeroes) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}

TEST(SampleTest, Maximum) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}

TEST(SampleTest, Minimum) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}

TEST(SampleTest, MaxRandom) 
{
    ASSERT_EQ(lesson::bruteForce(A), lesson::solution(A));
}
*/
