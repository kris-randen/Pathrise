/*
Writing programming interview questions hasn't made me rich yet ... so I might give up and start trading Apple stocks all day instead.
First, I wanna know how much money I could have made yesterday if I'd been trading Apple stocks all day.

So I grabbed Apple's stock prices from yesterday and put them in a list called stock_prices, where:

The indices are the time (in minutes) past trade opening time, which was 9:30am local time.
The values are the price (in US dollars) of one share of Apple stock at that time.
So if the stock cost $500 at 10:30am, that means stock_prices[60] = 500.

Write an efficient function that takes stock_prices and returns the best profit I could have made from one purchase and one sale of one share of Apple stock yesterday.
*/

#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

int getMaxProfit(const vector<int>& v)
{
    // calculate the max profit
    
    if (v.size() < 2) return 0;
    
    int p = v[1] - v[0];
    int m = min(v[0], v[1]);
    
    for (int i=2; i<v.size(); ++i)
    {
        p = max(p, v[i] - m);
        m = min(m, v[i]);
    }

    return p;
}


















// tests

const lest::test tests[] = {
    CASE("price goes up then down") {
        const int actual = getMaxProfit({1, 5, 3, 2});
        const int expected = 4;
        EXPECT(actual == expected);
    },

    CASE("price goes down then up") {
        const int actual = getMaxProfit({7, 2, 8, 9});
        const int expected = 7;
        EXPECT(actual == expected);
    },

    CASE("price goes up all day") {
        const int actual = getMaxProfit({1, 6, 7, 9});
        const int expected = 8;
        EXPECT(actual == expected);
    },

    CASE("price goes down all day") {
        const int actual = getMaxProfit({9, 7, 4, 1});
        const int expected = -2;
        EXPECT(actual == expected);
    },

    CASE("price stays the same all day") {
        const int actual = getMaxProfit({1, 1, 1, 1});
        const int expected = 0;
        EXPECT(actual == expected);
    },

    CASE("exception with empty prices") {
        EXPECT_THROWS(getMaxProfit({}));
    },

    CASE("exception with one price") {
        EXPECT_THROWS(getMaxProfit({1}));
    },
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}