#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "args.h"
#include "macros.h"

using namespace std;

class Population
{
public:
    struct RecordStruct
    {
        int birth;
        int death;
    };

    // Limits
    // - Min year is 0, Max year is 10000
    //
    // Instructions:
    // - If empty, should return -1
    // - If any record has death before birth, return -1
    // - If any record has an invalid year, return -1
    // - If there are multiple years with the same number, return the first year
    int solution(vector<RecordStruct> records)
    {
        if (records.empty())
            return -1;

        int minYear = 10000;
        int maxYear = -1;

        map<int, int> years;

        for (auto r = records.begin(); r != records.end(); ++r)
        {
            if (r->death < r->birth)
                return -1;
            if (r->birth < 0)
                return -1;
            if (r->death < 0)
                return -1;

            if (r->birth < minYear)
                minYear = r->birth;
            if (r->death > maxYear)
                maxYear = r->death;

            for (int y = r->birth; y <= r->death; y++)
            {
                years[y]++;
            }
        }

        int count = 0;
        int mostYear = -1;
        for (int y = minYear; y <= maxYear; y++)
        {
            if (years[y] > count)
            {
                mostYear = y;
                count = years[y];
            }
        }

        return mostYear;
    }
};

TEST(Population, Simple)
{
    Population population;
    vector<Population::RecordStruct> records = {
        {1950, 1974},
        {1974, 1980},
    };

    ASSERT_EQ(population.solution(records), 1974);
}

TEST(Population, Empty)
{
    Population population;
    vector<Population::RecordStruct> records;

    ASSERT_EQ(population.solution(records), -1);
}

TEST(Population, One)
{
    Population population;
    vector<Population::RecordStruct> records;
    records.push_back({1974, 1980});

    ASSERT_EQ(population.solution(records), 1974);
}

TEST(Population, Same)
{
    Population population;
    vector<Population::RecordStruct> records;
    records.push_back({1974, 1974});

    ASSERT_EQ(population.solution(records), 1974);
}

TEST(Population, Invalid)
{
    Population population;
    vector<Population::RecordStruct> records;
    records = {{1974, 1973}};
    ASSERT_EQ(population.solution(records), -1);

    records = {{-1, 1973}};
    ASSERT_EQ(population.solution(records), -1);

    records = {{1973, -1}};
    ASSERT_EQ(population.solution(records), -1);
}

TEST(Population, Test1)
{
    Population population;
    vector<Population::RecordStruct> records = {
        {0, 20},
        {2, 18},
        {10, 20},
        {0, 10},
        {10, 10},
        {1974, 1980},
        {1974, 1980},
    };

    ASSERT_EQ(population.solution(records), 10);
}

TEST(Population, Test2)
{
    Population population;
    vector<Population::RecordStruct> records = {
        {1, 20},
        {2, 20},
        {3, 20},
        {4, 20},
        {5, 20},
        {6, 20},
    };

    ASSERT_EQ(population.solution(records), 6);
}
