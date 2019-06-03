//
//  main.cpp
//  equationValueQuery
//
//  Created by Kris Rajendren on May/22/19.
//  Copyright © 2019 House Shout. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

typedef string Node;
typedef vector<Node> Nodes;
typedef pair<Node, Node> Edge;

typedef pair<Node, Node> Equation;
typedef vector<Equation> Equations;
typedef Equation Query;
typedef vector<Query> Queries;
typedef double Value;
typedef vector<Value> Values;

typedef unordered_map<Edge, Value> Edges;
typedef unordered_map<Node, vector<Edge> > NEmap;

struct Graph
{
    Nodes N;
    Edges E;
    NEmap NE;
    
    stack<Node> next(Node n)
    {
        stack<Node> s;
        
        if (NE.count(n) > 0)
        {
            for (int i=0; i < NE[n].size(); ++i)
            {
                s.push(NE[n][i].second);
            }
        }
        return s;
    }
};

Graph process(const Equations& E, const Values& V)
{
    Graph G;
    
    for (int i=0; i < E.size(); ++i)
    {
        if (G.E.count(E[i]) == 0)
        {
            G.N.push_back(E[i].first);
            G.N.push_back(E[i].second);
            G.E[E[i]] = V[i];
            
            Equation invE = make_pair(E[i].second, E[i].first);
            G.E[invE] = 1/V[i];
            
            G.NE[E[i].first].push_back(E[i]);
            G.NE[E[i].second].push_back(invE);
        }
    }
    
    for (int i=0; i < G.N.size(); ++i)
    {
        Node n = G.N[i];
        stack<Node> s = G.next(n);
        while(!s.empty())
        {
            Node p = s.top(); s.pop();
            Value v = G.E[make_pair(n, p)];
            stack<Node> r = G.next(p);
            while(!r.empty())
            {
                Node t = r.top(); r.pop();
                Equation e = make_pair(n, t);
                Value u = G.E[make_pair(p, t)];
                v = v * u;
                if (G.E.count(e) == 0)
                {
                    G.E[e] = v;
                    G.NE[n].push_back(e);
                }
            }
        }
    }
    
    return G;
}

void findPath(Graph& G, Query& q, Value& v)
{
    if (G.E.count(q) == 0) v = -1; return;
    v = G.E[q]; return;
}

Values solver(const Equations& E, const Values& V, Queries& Q)
{
    Graph G = process(E, V);
    Values R;
    
    for (int i=0; i < Q.size(); ++i)
    {
        Value v = -1.0;
        findPath(G, Q[i], v);
        R.push_back(v);
    }
    return R;
}

int main(int argc, const char * argv[])
{
    
    return 0;
}
