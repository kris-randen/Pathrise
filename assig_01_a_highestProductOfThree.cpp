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