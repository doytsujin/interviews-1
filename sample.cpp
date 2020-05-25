#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "args.h"
#include "macros.h"

using namespace std;

class Challenge
{
public:
    bool solution(bool value)
    {
        return value;
    }
};

TEST(Challenge, CorrectTest)
{
    Challenge challenge;
    bool correct = true;
    ASSERT_EQ(challenge.solution(correct), correct);
}