//
//  main.cpp
//  ticTacToe
//
//  Created by Kris Rajendren on May/30/19.
//  Copyright © 2019 House Shout. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > board(3, vector<char>(3, ' '));

vector<char> player = {'x', 'o'};

void printBoard()
{
    for (int i=0; i < board.size(); ++i)
    {
        for (int j=0; j < board[0].size(); ++j)
        {
            cout << "| " << board[i][j] << " | ";
        }
        cout << endl;
    }
}

bool isAlegalMove(int x, int y, int p)
{
    if (p < 0 || p > 1 || x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ') return false;
    return true;
}

bool makeMove(int x, int y, int p)
{
    if (isAlegalMove(x, y, p))
    {
        board[x][y] = player[p];
        return true;
    }
    else
    {
        cout << "x = " << x << " and y = " << y << " is an illegal move." << endl;
        return false;
    }
}

void xScan(int s, int& x, int& y)
{
    for (int j=0; j < board[0].size(); ++j)
    {
        if (board[s][j] == 'x') x++;
        else if (board[s][j] == 'y') y++;
    }
}

void yScan(int s, int& x, int& y)
{
    for (int i=0; i < board.size(); ++i)
    {
        if (board[i][s] == 'x') x++;
        else if (board[i][s] == 'y') y++;
    }
}

void dScan(int s, int& x, int& y)
{
    if (s)
    {
        for (int i=0; i < board.size(); ++i)
        {
            if (board[i][i] == 'x') x++;
            else if (board[i][i] == 'y') y++;
        }
    }
    else
    {
        for (int i=0; i < board.size(); ++i)
        {
            if (board[i][board.size() - i - 1] == 'x') x++;
            else if (board[i][board.size() - i - 1] == 'y') y++;
        }
    }
}

bool gameOver()
{
    int mX, mY; mX = mY = 0;
    
    for (int i=0; i < board.size(); ++i)
    {
        int x, y; x = y = 0;
        xScan(i, x, y);
        mX = max(x, mX); mY = max(y, mY);
        if (mX == 3 || mY == 3) return true;
    }
    
    for (int i=0; i < board.size(); ++i)
    {
        int x, y; x = y = 0;
        yScan(i, x, y);
        mX = max(x, mX); mY = max(y, mY);
        if (mX == 3 || mY == 3) return true;
    }
    
    for (int i=0; i < 2; ++i)
    {
        int x, y; x = y = 0;
        dScan(i, x, y);
        mX = max(x, mX); mY = max(y, mY);
        if (mX == 3 || mY == 3) return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int m = 0;
    
    while(!gameOver())
    {
        int x, y;
        cout << player[m % 2] << "'s move: ";
        cin >> x >> y;
        if (makeMove(x, y, (m % 2)))
        {
            m++;
            printBoard();
        }
    }
    
    cout << "Game won by: " << player[--m % 2] << endl;
    printBoard();
    
    return 0;
}
