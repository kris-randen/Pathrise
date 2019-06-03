/*
Given a list of integers, find the highest product you can get from three of the integers.
The input list_of_ints will always have at least three integers.
*/



#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

int highest(const vector<int>& v)
{
    int max = v[0];
    
    for (int i=1; i<v.size(); ++i)
    {
        if (v[i] > max) max = v[i];
    }
    
    return max;
}

int lowest(const vector<int>& v)
{
    int min = v[0];
    
    for (int i=1; i<v.size(); ++i)
    {
        if (v[i] < min) min = v[i];
    }
    
    return min;
}

int highest(int a, int b, int c)
{
    return max(max(a, b), c);
}

int lowest(int a, int b, int c)
{
    return min(min(a, b), c);
}

int highestProductOf3(const vector<int>& v)
{
    // calculate the highest product of three numbers
    
    cout << "size of v = " << v.size() << endl;
    if (v.size() < 3) return -1;
    
    int hp3 = v[0] * v[1] * v[2];
    if (v.size() == 3) return (hp3);
    
    int h, l, hp2, lp2, c;
    c = 0;
    
    hp2 = highest(v[0] * v[1], v[1] * v[2], v[2] * v[0]);
    lp2 = lowest(v[0] * v[1], v[1] * v[2], v[2] * v[0]);
    h = highest(v[0], v[1], v[2]);
    l = lowest(v[0], v[1], v[2]);
    
    for (int i=3; i<v.size(); ++i)
    {
        cout << "hp3 = " << hp3 << endl;
        cout << "hp2 = " << hp2 << endl;
        cout << "lp2 = " << lp2 << endl;
        cout << "h = " << h << endl;
        cout << "l = " << l << endl;
        
        c = v[i];
        hp3 = highest(hp3, hp2*c, lp2*c);
        hp2 = highest(hp2, c*h, c*l);
        lp2 = lowest(lp2, c*h, c*l);
        
        h = max(h, c);
        l = min(l, c);
        
        cout << "hp3 = " << hp3 << endl;
        cout << "hp2 = " << hp2 << endl;
        cout << "lp2 = " << lp2 << endl;
        cout << "h = " << h << endl;
        cout << "l = " << l << endl;
    }

    return hp3;
}


















// tests

const lest::test tests[] = {
    CASE("short vector") {
        const int actual = highestProductOf3({1, 2, 3, 4});
        const int expected = 24;
        EXPECT(actual == expected);
    },

    CASE("longer vector") {
        const int actual = highestProductOf3({6, 1, 3, 5, 7, 8, 2});
        const int expected = 336;
        EXPECT(actual == expected);
    },

    CASE("vector has one negative") {
        const int actual = highestProductOf3({-5, 4, 8, 2, 3});
        const int expected = 96;
        EXPECT(actual == expected);
    },

    CASE("vector has two negatives") {
        const int actual = highestProductOf3({-10, 1, 3, 2, -10});
        const int expected = 300;
        EXPECT(actual == expected);
    },

    CASE("vector is all negatives") {
        const int actual = highestProductOf3({-5, -1, -3, -2});
        const int expected = -6;
        EXPECT(actual == expected);
    },

    CASE("exception with empty vector") {
        EXPECT_THROWS(highestProductOf3({}));
    },

    CASE("exception with one number") {
        EXPECT_THROWS(highestProductOf3({1}));
    },

    CASE("exception with two numbers") {
        EXPECT_THROWS(highestProductOf3({1, 1}));
    },
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}



/*
Write a recursive function for generating all permutations of an input string. Return them as a set.
Don't worry about time or space complexity—if we wanted efficiency we'd write an iterative version.

To start, assume every character in the input string is unique.

Your function can have loops—it just needs to also be recursive.
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;
typedef unordered_set<string> Perms;
typedef unordered_map<int, Perms> SizedPerms;
typedef Perms::iterator PermsIt;

Perms getPermutations(const string& s)
{
    // generate all permutations of the input string
    Perms p;

    if (s.size() < 2) 
    {
        p.insert(s); return p;
    }
    
    string r = s;
    
    SizedPerms q;
    
    string c(1, r[r.size()-1]);
    
    int size = r.size() - 1;
    q[size] = getPermutations(r.erase(size, 1));
    
    PermsIt t;
    
    
    for (t=q[size].begin(); t!=q[size].end(); ++t)
    {
        for (int j=0; j<=t->size(); ++j)
        {
            string u = *t;
            p.insert(u.insert(j, c));
        }
    }
    
    return p;
}


















// tests

const lest::test tests[] = {
    CASE("empty string") {
        const unordered_set<string> expected {""};
        auto actual = getPermutations("");
        EXPECT(actual == expected);
    },
    CASE("one character string") {
        const unordered_set<string> expected {"a"};
        auto actual = getPermutations("a");
        EXPECT(actual == expected);
    },
    CASE("two character string") {
        const unordered_set<string> expected {"ab", "ba"};
        auto actual = getPermutations("ab");
        EXPECT(actual == expected);
    },
    CASE("three character string") {
        const unordered_set<string> expected {"abc", "acb", "bac", "bca", "cab", "cba"};
        auto actual = getPermutations("abc");
        EXPECT(actual == expected);
    },
    CASE("name string") {
        const unordered_set<string> expected { "iskr", "risk", "srki", "skir", "rsik", "kisr", "riks", "ksir", "sikr", "kris", "krsi", "ikrs", "iksr", "rski", "ksri", "kirs", "isrk", "rksi", "skri", "irsk", "sirk", "irks", "srik", "rkis", };
        auto actual = getPermutations("kris");
        EXPECT(actual == expected);
    }
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}


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

price goes up then down        passed: actual == expected for 4 == 4
price goes down then up        passed: actual == expected for 7 == 7
price goes up all day          passed: actual == expected for 8 == 8
price goes down all day        passed: actual == expected for -2 == -2
price stays the same all day   passed: actual == expected for 0 == 0
exception with empty prices    failed: didn't get exception: getMaxProfit({})
exception with one price       failed: didn't get exception: getMaxProfit({1})