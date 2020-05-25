#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "args.h"
#include "macros.h"

using namespace std;

class CountPrimes
{
public:
    int solution(int n)
    {
        int numPrimes = 0;

        bool *notPrimes = new bool[n + 1]();

        // By definition, 1 is not a prime
        if (n == 1)
            return 0;

        for (int i = 2; i <= n; i++)
        {
            // Don't bother if this isn't a prime
            if (notPrimes[i])
            {
                continue;
            }
            numPrimes++;
            notPrimes[i] = true;

            // Mark off all multiples as not a prime
            for (int j = 1; (j * i) <= n; j++)
            {
                notPrimes[j * i] = true;
            }
        }
        delete[] notPrimes;

        return numPrimes;
    };
};

TEST(CountPrimes, CorrectTest)
{
    CountPrimes countPrimes;
    ASSERT_EQ(countPrimes.solution(10), 4);
}

TEST(CountPrimes, TwoTest)
{
    CountPrimes countPrimes;
    ASSERT_EQ(countPrimes.solution(2), 1);
}

TEST(CountPrimes, OneTest)
{
    CountPrimes countPrimes;
    ASSERT_EQ(countPrimes.solution(1), 0);
}

TEST(CountPrimes, LargeTest)
{
    CountPrimes countPrimes;
    ASSERT_EQ(countPrimes.solution(499979), 41538);
}