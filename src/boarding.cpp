#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "args.h"
#include "macros.h"

using namespace std;

class Boarding
{
public:
    struct BoardingPass
    {
        string dep;
        string arr;
    };

    vector<string> solution(vector<BoardingPass> passes)
    {
        map<string, string> pairs;
        vector<string> output;
        vector<string> arrivals;
        // Using maps because of hash lookup. Vector would be too slow
        // A little extra memory but worth it for performance
        map<string, int> departures;

        // Exit if nothing is passed to us
        if (passes.size() == 0)
        {
            return output;
        }

        // Create my data structures
        for (auto &p : passes)
        {
            // push dep onto stack
            departures[p.dep] = 1;
            arrivals.push_back(p.arr);
            pairs[p.dep] = p.arr;
        }

        // loop through departures and remove them from arrivals list
        // Last departure is starting point
        for (auto &a : arrivals)
        {
            auto it = departures.find(a);
            if (it != departures.end())
                departures.erase(it);
        }

        // Should only have one departure
        if (departures.size() > 1)
        {
            output.push_back("error");
            return output;
        }

        string origin = departures.begin()->first;
        output.push_back(origin);

        // Now loop through and push while there are elements
        auto it = pairs.find(origin);
        while (it != pairs.end())
        {
            output.push_back(it->second);
            it = pairs.find(it->second);
        }

        return output;
    }
};

TEST(Boarding, CorrectTest)
{
    Boarding boarding;
    vector<Boarding::BoardingPass> passes = {
        {"ATL", "LAX"},
        {"LAX", "SFO"},
        {"JFK", "ATL"},
    };

    vector<string> correct = {"JFK", "ATL", "LAX", "SFO"};
    ASSERT_EQ(boarding.solution(passes), correct);
}

TEST(Boarding, SingleTest)
{
    Boarding boarding;
    vector<Boarding::BoardingPass> passes = {
        {"1", "2"},
    };

    vector<string> correct = {"1", "2"};
    ASSERT_EQ(boarding.solution(passes), correct);
}

TEST(Boarding, SimpleTest)
{
    Boarding boarding;
    vector<Boarding::BoardingPass> passes = {
        {"1", "2"},
        {"2", "3"},
    };

    vector<string> correct = {"1", "2", "3"};
    ASSERT_EQ(boarding.solution(passes), correct);
}

TEST(Boarding, EmptyTest)
{
    Boarding boarding;
    vector<Boarding::BoardingPass> passes = {};

    vector<string> correct = {};
    ASSERT_EQ(boarding.solution(passes), correct);
}

TEST(Boarding, ErrorTest)
{
    Boarding boarding;
    vector<Boarding::BoardingPass> passes = {
        {"1", "2"},
        {"3", "4"},
    };

    vector<string> correct = {"error"};
    ASSERT_EQ(boarding.solution(passes), correct);
}