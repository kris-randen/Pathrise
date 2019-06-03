// LeetCode Problems and my Solutions

// Depth-First Search

// 199. Binary Tree Right Side View


/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
Accepted
165,738
Submissions
346,977
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void printVector(const vector<int>& v)
{
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void dfs(TreeNode* root, vector<int>& v, int l)
{
    if (root == NULL) 
    {
        cout << "NULL node at level " << l << ". Returning." << endl;
        return;
    }
    cout << "val at level " << l << " = " << root->val << endl;
    if (l > v.size()) v.push_back(root->val);
    printVector(v);
    l++;
    dfs(root->right,v,l);
    dfs(root->left,v,l);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        dfs(root,v,1);
        
        return v;
    }
};

// Smaller more efficient solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void dfs(TreeNode* root, vector<int>& v, int l)
{
    if (root == NULL) return;
    
    if (l > v.size()) v.push_back(root->val); 
    l++;
    dfs(root->right,v,l);
    dfs(root->left,v,l);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        int l = 1;
        dfs(root,v,l);
        
        return v;
    }
};


// Runtime: 4 ms, faster than 97.38% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 9.7 MB, less than 34.06% of C++ online submissions for Binary Tree Right Side View.

// It's interesting that the following attempt at a recursive BFS was the same as DFS.

void bfsR(TreeNode* root, queue<TreeNode*>& q)
{
    if (root == NULL) return;
    
    q.push(root);
    cout << "val = " << root->val << endl;
    
    if (root->right != NULL) cout << "val = " << root->right->val << endl;
    if (root->left != NULL) cout << "val = " << root->left->val << endl;
    while(!q.empty())
    {
        TreeNode* p = q.front();
        if (p != NULL)
        {
            // cout << "val = " << p->val << endl;
            q.pop();
            bfsR(p->right, q);
            bfsR(p->left, q);
        }
    }
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        queue<TreeNode*> q;
        bfsR(root, q);
        
        return v;
    }
};

// Bread-First Search Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void bfs(TreeNode* root, vector<int>& v)
{
    if (root == NULL) return;
    queue<TreeNode*> q;
    queue<int> s;
    
    q.push(root);
    s.push(1);
    while(!q.empty())
    {
        TreeNode* p = q.front();
        int r = s.front();
        if (p != NULL)
        {
            cout << "val at level " << r << "= " << p->val << endl;
            if (r > v.size()) v.push_back(p->val);
            q.pop();
            s.pop();
            if (p->right != NULL) 
            {
                q.push(p->right);
                s.push(r+1);
            }
            if (p->left != NULL) 
            {
                q.push(p->left);
                s.push(r+1);
            }
        }
    }
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        int l = 1;
        
        bfs(root, v);
        return v;
    }
};

// Runtime: 4 ms, faster than 97.38% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 9.9 MB, less than 10.47% of C++ online submissions for Binary Tree Right Side View.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void dfs(TreeNode* root, vector<int>& v, int l)
{
    if (root == NULL) return;
    
    if (l > v.size()) v.push_back(root->val); 
    l++;
    dfs(root->right,v,l);
    dfs(root->left,v,l);
}

void bfs(TreeNode* root, vector<int>& v)
{
    if (root == NULL) return;
    queue<TreeNode*> q;
    queue<int> s;
    
    q.push(root);
    s.push(1);
    while(!q.empty())
    {
        TreeNode* p = q.front();
        int r = s.front();
        if (p != NULL)
        {
            if (r > v.size()) v.push_back(p->val);
            q.pop();
            s.pop();
            if (p->right != NULL) 
            {
                q.push(p->right);
                s.push(r+1);
            }
            if (p->left != NULL) 
            {
                q.push(p->left);
                s.push(r+1);
            }
        }
    }
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        
        bfs(root, v);
        return v;
    }
};


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 10 MB, less than 8.65% of C++ online submissions for Binary Tree Right Side View.

/*
200. Number of Islands
Medium

2543

92

Favorite

Share
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

// Depth-first Search

typedef vector<vector<char>> Grid;

bool isValid(const Grid& grid, int i, int j)
{
    return !(i < 0 || j < 0 || i > (grid.size()-1) || j > (grid[0].size()-1));
}

bool dfs(Grid& grid, int i, int j)
{
    if (!isValid(grid, i, j) || grid[i][j] == '2' || grid[i][j] == '0') return false;
    grid[i][j] = '2';
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
    return true;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = 0;
        
        for (int i=0; i<grid.size(); ++i)
        {
            for (int j=0; j<grid[0].size(); ++j)
            {
                if (dfs(grid, i, j)) n++;
            }
            cout << endl;
        }
        return n;
    }
};

// Runtime: 12 ms, faster than 98.50% of C++ online submissions for Number of Islands.
// Memory Usage: 10.6 MB, less than 96.12% of C++ online submissions for Number of Islands.




// Breadth-first Search
typedef vector<vector<char>> Grid;
typedef char* Char;
typedef queue<Char> Queue;
typedef queue<int> Qint;
typedef const int& Cint;


bool isValid(const Grid& grid, Cint i, Cint j)
{
    return !(i < 0 || j < 0 || i > (grid.size()-1) || j > (grid[0].size()-1) || grid[i][j] == '2' || grid[i][j] == '0');
}

void qPush(Queue& q, Char e)
{
    q.push(e);
    *e = '2';
}

void qValidPush(Queue& q, Grid& grid, Cint i, Cint j)
{
    if (isValid(grid, i, j)) qPush(q, &grid[i][j]);
}

void qValidPushes(Queue& q, Grid& grid, Cint i, Cint j, Qint& iq, Qint& jq)
{
    if (isValid(grid, i+1, j))
    {
        qPush(q, &grid[i+1][j]);
        iq.push(i+1); jq.push(j);
    }
    if (isValid(grid, i-1, j)) 
    {
        qPush(q, &grid[i-1][j]);
        iq.push(i-1); jq.push(j);
    }
    if (isValid(grid, i, j+1))
    {
        qPush(q, &grid[i][j+1]);
        iq.push(i); jq.push(j+1);
    }
    if (isValid(grid, i, j-1)) 
    {
        qPush(q, &grid[i][j-1]);
        iq.push(i); jq.push(j-1);
    }
}

bool bfs(Grid& grid, Cint i, Cint j)
{
    if (!isValid(grid, i, j)) return false;
    Queue q;
    Qint iq, jq;
    
    qPush(q, &grid[i][j]);
    iq.push(i); jq.push(j);
    
    while(!q.empty())
    {
        Char p = q.front();
        int ir = iq.front();
        int jr = jq.front();
        q.pop(); iq.pop(); jq.pop();
        *p = '2';
        qValidPushes(q, grid, ir, jr, iq, jq);
    }
    return true;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = 0;
        
        for (int i=0; i<grid.size(); ++i)
        {
            for (int j=0; j<grid[0].size(); ++j)
            {
                if (bfs(grid, i, j)) n++;
            }
        }
        return n;
    }
};

// Runtime: 20 ms, faster than 36.51% of C++ online submissions for Number of Islands.
// Memory Usage: 12.4 MB, less than 13.21% of C++ online submissions for Number of Islands.

// Runtime: 12 ms, faster than 98.50% of C++ online submissions for Number of Islands.
// Memory Usage: 12.5 MB, less than 12.72% of C++ online submissions for Number of Islands.


typedef vector<vector<char>> Grid;


bool isValid(const Grid& grid, const int& i, const int& j)
{
    return !(i < 0 || j < 0 || i > (grid.size()-1) || j > (grid[0].size()-1) || grid[i][j] == '2' || grid[i][j] == '0');
}

void qPush(queue<char*>& q, char* e)
{
    q.push(e);
    *e = '2';
}

void qValidPush(queue<char*>& q, Grid& grid, const int& i, const int& j)
{
    if (isValid(grid, i, j)) qPush(q, &grid[i][j]);
}

void qValidPushes(queue<char*>& q, Grid& grid, const int& i, const int& j, queue<int>& iq, queue<int>& jq)
{
    if (isValid(grid, i+1, j))
    {
        qPush(q, &grid[i+1][j]);
        iq.push(i+1); jq.push(j);
    }
    if (isValid(grid, i-1, j)) 
    {
        qPush(q, &grid[i-1][j]);
        iq.push(i-1); jq.push(j);
    }
    if (isValid(grid, i, j+1))
    {
        qPush(q, &grid[i][j+1]);
        iq.push(i); jq.push(j+1);
    }
    if (isValid(grid, i, j-1)) 
    {
        qPush(q, &grid[i][j-1]);
        iq.push(i); jq.push(j-1);
    }
}

bool bfs(Grid& grid, const int& i, const int& j)
{
    if (!isValid(grid, i, j)) return false;
    queue<char*> q;
    queue<int> iq, jq;
    
    qPush(q, &grid[i][j]);
    iq.push(i); jq.push(j);
    
    while(!q.empty())
    {
        char* p = q.front();
        int ir = iq.front();
        int jr = jq.front();
        q.pop(); iq.pop(); jq.pop();
        *p = '2';
        qValidPushes(q, grid, ir, jr, iq, jq);
    }
    return true;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = 0;
        
        for (int i=0; i<grid.size(); ++i)
        {
            for (int j=0; j<grid[0].size(); ++j)
            {
                if (bfs(grid, i, j)) n++;
            }
        }
        return n;
    }
};

// Runtime: 12 ms, faster than 98.50% of C++ online submissions for Number of Islands.
// Memory Usage: 12.4 MB, less than 13.44% of C++ online submissions for Number of Islands.

// Runtime: 20 ms, faster than 36.51% of C++ online submissions for Number of Islands.
// Memory Usage: 12.4 MB, less than 13.21% of C++ online submissions for Number of Islands.




/*
104. Maximum Depth of Binary Tree: EASY
Easy

1283

49

Favorite

Share
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* root, int l, int& s)
{
    if (root == NULL) return;
    if (l > s) s = l;
    l++;
    dfs(root->left, l, s); 
    dfs(root->right, l, s);
}

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == NULL) return 0;
        int s = 1;
        dfs(root, 1, s);
        return s;
    }
};

// Runtime: 8 ms, faster than 98.53% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.3 MB, less than 71.90% of C++ online submissions for Maximum Depth of Binary Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == NULL) return 0;
        return (max(1 + maxDepth(root->left), 1 + maxDepth(root->right)));     
    }
};

// Runtime: 8 ms, faster than 95.49% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.5 MB, less than 35.23% of C++ online submissions for Maximum Depth of Binary Tree.

/*
108. Convert Sorted Array to Binary Search Tree: EASY
Easy

1111

108

Favorite

Share
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* arrayToBST(const vector<int>& v, int s, int e)
{
    if (e < s) return NULL;
    TreeNode* root = new TreeNode(v[(s + e)/2]);
    root->left = arrayToBST(v, s, (s + e)/2 - 1);
    root->right = arrayToBST(v, (s + e)/2 + 1, e);
    return root;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return arrayToBST(nums, 0, nums.size() - 1);
    }
};

// Runtime: 16 ms, faster than 98.59% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 21.4 MB, less than 24.29% of C++ online submissions for Convert Sorted Array to Binary Search Tree.



/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool operator==(vector<int>& lhs, vector<char>& rhs)
{
    for (int i=0; i<lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i]) return false;
    }
    return true;
}

void dfsRL(TreeNode* root, vector<char>& v)
{
    if (root == NULL) 
    {
        v.push_back('N');
        return;
    }
    v.push_back('0' + root->val);
    dfsRL(root->right, v); 
    dfsRL(root->left, v);
}

void dfsLR(TreeNode* root, vector<char>& v)
{
    if (root == NULL)
    {
        v.push_back('N');
        return;
    }
    v.push_back('0' + root->val);
    dfsLR(root->left, v); 
    dfsLR(root->right, v);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        vector<char> lr;
        vector<char> rl;
        dfsLR(root, lr); dfsRL(root, rl);
        return lr == rl;
    }
};


// Runtime: 4 ms, faster than 98.12% of C++ online submissions for Symmetric Tree.
// Memory Usage: 15.8 MB, less than 49.30% of C++ online submissions for Symmetric Tree.

// LeetCode Solutions

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root); q.push(root);
        
        while(!q.empty())
        {
            TreeNode* l;
            TreeNode* r;
            l = q.front(); q.pop();
            r = q.front(); q.pop();
            
            if (l == NULL && r == NULL) continue;
            if (l == NULL || r == NULL) return false;
            if (l->val != r->val) return false;
            
            q.push(l->left); q.push(r->right); 
            q.push(l->right); q.push(r->left);
        }
        return true;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isMirror(TreeNode* l, TreeNode* r)
{
    if (l == NULL && r == NULL) return true;
    if (l == NULL || r == NULL) return false;
    return  (l->val == r->val)
         && (isMirror(l->right, r->left))
         && (isMirror(l->left, r->right));
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
         return isMirror(root, root);   
    }
};


/*
116. Populating Next Right Pointers in Each Node
Medium

979

83

Favorite

Share
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

typedef unordered_map<Node*, Node*> ParentMap;
typedef vector<Node*> Nodes;

void mapParents(Node* root, ParentMap& p)
{
    if (root == NULL) return;

    if (root->left != NULL) p[root->left] = root;
    if (root->right != NULL) p[root->right] = root;
    
    mapParents(root->right, p);
    mapParents(root->left, p); 
}

Nodes append(const Nodes& lhs, const Nodes& rhs)
{
    Nodes nodes;
    
    for (int i=0; i<lhs.size(); ++i)
    {
        nodes.push_back(lhs[i]);
    }
    for (int i=0; i<rhs.size(); ++i)
    {
        nodes.push_back(rhs[i]);
    }
    return nodes;
}

Nodes inOrderTraversal(Node* root)
{
    Nodes n;
    if (root == NULL) return n;
    n.push_back(root);
    return append(append(inOrderTraversal(root->left), n), inOrderTraversal(root->right));
}

void printNodes(const Nodes& v)
{
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i]->val << " ";
    }    
}


class Solution {
public:
    Node* connect(Node* root) 
    {   
        Nodes v = inOrderTraversal(root);    
        
        printNodes(v);
        
        for (int i=0; i<log(v.size()+1); ++i)
        {
            int jump = pow(2, i+1);
            int index = pow(2, i) - 1;
            
            int j = index;
            while(j + jump < v.size())
            {
                v[j]->next = v[j + jump];
                j += jump;
            }
        }
        return root;
    }
};

/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

1679

46

Favorite

Share
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef unordered_map<int, int> Hash;

Hash hashVector(const vector<int>& v)
{
    Hash h;
    
    for (int i=0; i<v.size(); ++i)
    {
        h[v[i]] = i;
    }
    
    return h;
}

TreeNode* bTR(const vector<int>& preorder, const vector<int>& inorder, Hash& h, int is, int ie, int p)
{
    if (ie < is) return NULL;
    while(h[preorder[p]] < is) p++;
    while(h[preorder[p]] > ie) p--;
    
    bool leftIsNull = (h[preorder[p]] == is) ? true : false;
    bool rightIsNull = (h[preorder[p]] == ie) ? true : false;
    
    int m = h[preorder[p]];
    TreeNode* root = new TreeNode(preorder[p++]);
    
    if (leftIsNull) root->left = NULL;
    else
    {
        root->left = bTR(preorder, inorder, h, is, m-1, p);
    }
    if (rightIsNull) root->right = NULL;
    else
    {
        root->right = bTR(preorder, inorder, h, m+1, ie, p);
    }
    return root;
}
class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        Hash h = hashVector(inorder);
        return bTR(preorder, inorder, h, 0, inorder.size()-1, 0);
    }
};

// Runtime: 12 ms, faster than 99.34% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 17.3 MB, less than 36.33% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

/*
98. Validate Binary Search Tree
Medium

1888

282

Favorite

Share
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool sorted(vector<int> v)
{
    for (int i=1; i<v.size(); ++i)
    {
        if (v[i] <= v[i-1]) return false;
    }
    return true;
}

vector<int> append(vector<int> a, int b)
{
    a.push_back(b); return a;
}

vector<int> append(vector<int> a, vector<int> b)
{
    for (int i=0; i<b.size(); ++i)
    {
        a.push_back(b[i]);
    }
    return a;
}

vector<int> inorder(TreeNode* root)
{
    vector<int> v;
    if (root == NULL) return v;
    
    return append(append(inorder(root->left), root->val), inorder(root->right));
}

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return sorted(inorder(root));
    }
};

// Runtime: 24 ms, faster than 33.66% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 27.9 MB, less than 5.03% of C++ online submissions for Validate Binary Search Tree.


/*
266. Palindrome Permutation
Easy

192

39

Favorite

Share
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true
*/

class Solution {
public:
    bool canPermutePalindrome(string s) 
    {
        unordered_map<char, int> h;
        unordered_map<char, int>::iterator t;
        
        for (int i=0; i < s.size(); ++i)
        {
            if (h.count(s[i]) == 0) h[s[i]] = 1;
            else
            {
                h[s[i]] = (h[s[i]] + 1) % 2;
            }
        }
        
        // If a string is a permutation of a palindrome there are two possibilities
        // 1. It's an even palindrome.
        // 2. It's an odd palindrome.
        // If it's an even palindrome it should have an even number of chars for every char.
        // If it's an odd palindrome exactly one char should be present in an odd number and others should an even number count.
        
        int numEvenChars, numOddChars;
        numEvenChars = numOddChars = 0;
        
        for (t=h.begin(); t!=h.end(); ++t)
        {
            if (t->second % 2 == 0) numEvenChars++;
            else numOddChars++;
        }
        
        if (s.size() % 2 == 0) return (numOddChars == 0);
        else return (numOddChars == 1);
    }
};

// Runtime: 4 ms, faster than 95.36% of C++ online submissions for Palindrome Permutation.
// Memory Usage: 8.3 MB, less than 36.72% of C++ online submissions for Palindrome Permutation.

/*
110. Balanced Binary Tree
Easy

1218

108

Favorite

Share
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getHeight(TreeNode* root)
{
    if (root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return max(l, r) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if (root == NULL) return true;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return (abs(l - r) < 2 && isBalanced(root->left) && isBalanced(root->right));
    }
};

// Runtime: 12 ms, faster than 96.89% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 17.6 MB, less than 14.42% of C++ online submissions for Balanced Binary Tree.



/*
481. Magical String
Medium

81

533

Favorite

Share
A magical string S consists of only '1' and '2' and obeys the following rules:

The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.

The first few elements of string S is the following: S = "1221121221221121122……"

If we group the consecutive '1's and '2's in S, it will be:

1 22 11 2 1 22 1 22 11 2 11 22 ......

and the occurrences of '1's or '2's in each group are:

1 2 2 1 1 2 1 2 2 1 2 2 ......

You can see that the occurrence sequence above is the S itself.

Given an integer N as input, return the number of '1's in the first N number in the magical string S.

Note: N will not exceed 100,000.

Example 1:

Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
*/


int notPrev(const vector<int>& v, int i)
{
    return (v[i-1] == 1) ? 2:1 ;
}

class Solution {
public:
    int magicalString(int n) 
    {
        vector<int> s = {1, 2, 2};
    
        int currS = 3; int currC = 2;
        
        int num = 0;
    
        while(currS < n)
        {
            if (s[currC++] == 1)
            {
                int e = notPrev(s, currS++);
                s.push_back(e); 
            }
            else
            {
                int e = notPrev(s, currS++); 
                currS++;
                s.push_back(e); s.push_back(e); 
            }
        }
        
        for (int i=0; i < n; ++i)
        {
            if (s[i] == 1) num++;
        }
        
        return num;
    }
};

// Runtime: 4 ms, faster than 98.25% of C++ online submissions for Magical String.
// Memory Usage: 15.1 MB, less than 6.56% of C++ online submissions for Magical String.


class Solution {
public:
    int magicalString(int n) 
    {
        vector<int> s = {1, 2, 2};
    
        int currS = 3; int currC = 2; int num = 0;
    
        while(currS < n)
        {
            int e = (s[currS++ - 1] == 1) ? 2 : 1;
            if (s[currC++] == 1) s.push_back(e); 
            else 
            {
                currS++; s.push_back(e); s.push_back(e); 
            }
        }
        
        for (int i=0; i < n; ++i)
        {
            if (s[i] == 1) num++;
        }
        
        return num;
    }
};

// Runtime: 4 ms, faster than 98.25% of C++ online submissions for Magical String.
// Memory Usage: 15.1 MB, less than 6.56% of C++ online submissions for Magical String.

/*
518. Coin Change 2
Medium

733

37

Favorite

Share
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        if (coins.size() == 0) return (amount > 0) ? 0:1;
        bool b = (amount % coins[0] == 0);
        if (coins.size() == 1) return b ? 1:0;
        
        vector<vector<int> > T(coins.size(), vector<int>(amount + 1, 0));
        
        for (int i=1; i <= amount; ++i)
        {
            T[0][i] = (i % coins[0] == 0) ? 1:0 ;
        }
        
        for (int j=0; j < coins.size(); ++j)
        {
            T[j][0] = 1;
        }
        
        for (int j=1; j < coins.size(); ++j)
        {
            for (int i=1; i <= amount; ++i)
            {
                for (int k=0; k <= (i / coins[j]); ++k)
                {
                    T[j][i] += T[j-1][i - k*(coins[j])];
                }
            }
        }
        return T[coins.size()-1][amount];
    }
};

// Runtime: 140 ms, faster than 10.51% of C++ online submissions for Coin Change 2.
// Memory Usage: 19.8 MB, less than 30.42% of C++ online submissions for Coin Change 2.

/*
23. Merge k Sorted Lists
Hard

2447

160

Favorite

Share
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.size() < 1) return NULL;
        if (lists.size() == 1 && lists[0] == NULL) return NULL;
        priority_queue<int, vector<int>, greater<int> > q;
        
        for (int i=0; i < lists.size(); ++i)
        {
            ListNode* root = lists[i]; 
            if (root == NULL) continue;
            q.push(root->val);
            
            while(root->next != NULL) 
            {
                q.push(root->next->val); root = root->next;
            }
        }
        
        if (q.empty()) return NULL;
        ListNode* head = root = new ListNode(q.top()); q.pop();
        
        while(!q.empty())
        {
            ListNode* node = new ListNode(q.top()); q.pop();
            root->next = node;
            root = node;
        }
        
        return head;
    }
};

// Runtime: 28 ms, faster than 87.34% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.8 MB, less than 44.54% of C++ online submissions for Merge k Sorted Lists.



