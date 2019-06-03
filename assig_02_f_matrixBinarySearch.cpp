#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;
typedef pair<int, int> Points;
typedef pair<Points, Points> Pair;

Pair makePointPair(int x0, int y0, int x1, int y1)
{
    Points p0 = make_pair(x0, y0);
    Points p1 = make_pair(x1, y1);
    
    return make_pair(p0, p1);
}

bool isDownwardDiagonalNeighbor(int x0, int y0, int x1, int y1)
{
    if (x1 - x0 > 1 || y1 - y0 > 1) return false;
    if (x1 < x0 || y1 < y0) return false;
    if (x1 == x0 && y1 == y0) return false;
    
    return true;
}

bool diagonalPairIsKey(const Pair& p)
{
    return (p.first == p.second);
}

Pair diagonalBinarySearch(Matrix& m, int key, int x0, int y0, int x1, int y1)
{
    if (isDownwardDiagonalNeighbor(x0, y0, x1, y1)) return makePointPair(x0, y0, x1, y1);
    
    int x, y; x = (x0 + x1) / 2; y = (y0 + y1) / 2;
    if (key == m[x][y])
    {
        return makePointPair(x, y, x, y);
    }
    else if (key < m[x][y])
    {
        return diagonalBinarySearch(m, key, x0, y0, x, y);
    }
    else
    {
        return diagonalBinarySearch(m, key, x, y, x1, y1);
    }
}

bool matrixBinarySearch(Matrix& m, int key, int x0, int y0, int x1, int y1) 
{
    if (x0 > x1 || y0 > y1) return false;
    if (key == m[x0][y0] || key == m[x1][y1]) return true;
    if (key < m[x0][y0] || key > m[x1][y1]) return false;
    if (x0 == x1 && y0 == y1) return (key == m[x0][y0]);
    
    Pair p = diagonalBinarySearch(m, key, x0, y0, x1, y1);
    if (diagonalPairIsKey(p)) return true;
    
    int upperX0 = x0; int upperY0 = p.first.second + 1;
    int upperX1 = p.first.first; int upperY1 = y1;
    
    int lowerX0 = p.second.first; int lowerY0 = y0;
    int lowerX1 = x1; int lowerY1 = p.second.second - 1;
    
    
    return (matrixBinarySearch(m, key, upperX0, upperY0, upperX1, upperY1) || matrixBinarySearch(m, key, lowerX0, lowerY0, lowerX1, lowerY1));
}

class Solution 
{
public:
    bool searchMatrix(Matrix& matrix, int target) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        return matrixBinarySearch(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
};

// Runtime: 8 ms, faster than 98.29% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.8 MB, less than 69.88% of C++ online submissions for Search a 2D Matrix.