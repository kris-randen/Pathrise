
typedef pair<double, double> SlopeInt;
typedef pair<int, int> PointPair;
typedef map<SlopeInt, int> MapSlopeInt;
typedef map<SlopeInt, set<int> > MapSIntP;
typedef map<SlopeInt, int>::iterator MapSIt;

SlopeInt getMC(const vector<int>& p1, const vector<int>& p2)
{
    int x1, x2, y1, y2; double m, c;
                
    x1 = p1[0]; x2 = p2[0];
    y1 = p1[1]; y2 = p2[1];

    if (x1 == x2) m = 1000000000.0;
    else m = (y2 - y1) / (x2 - x1);
    c = y1 - (m * x1);

    return make_pair(m, c);
}

class Solution 
{
public:
    int maxPoints(vector<vector<int>>& p) 
    {
        if (p.size() < 3) return p.size();
        // vector<SlopeInt> Mc;
        
        MapSlopeInt Mp;
        MapSIntP Ms;
        
        for (int i=0; i < p.size(); ++i)
        {
            for (int j=i+1; j < p.size(); ++j)
            {
                SlopeInt mc = getMC(p[i], p[j]);
                
                Ms[mc].insert(i); Ms[mc].insert(j);
                
                if (Mp.count(mc) == 0) 
                {
                    Mp[mc] = 2;
                    // Ms[mc].insert(i); Ms[mc].insert(j);
                }
                else 
                {
                    if (Ms[mc].count(j) == 0) Mp[mc]++;
                    
                }
            }
        }
        
        int maxN = 0;
        
        // MapSIt t;
        MapSIntP::iterator t;
        // for (t = Mp.begin(); t != Mp.end(); ++t)
        // {
        //     if (t->second > maxN) maxN = t->second;
        // }
        for (t = Ms.begin(); t != Ms.end(); ++t)
        {
            if (t->second.size() > maxN) maxN = t->second.size();
        }
        return maxN;
    }
};


typedef pair<double, double> SlopeInt;
typedef pair<int, int> PointPair;
// typedef pair<int, int> Point;
typedef map<PointPair, int> PointCount;
typedef vector<vector<int> > PointPairs;
typedef map<SlopeInt, int> MapSlopeInt;
typedef map<SlopeInt, set<int> > MapSIntP;
typedef map<SlopeInt, int>::iterator MapSIt;

SlopeInt getMC(const vector<int>& p1, const vector<int>& p2)
{
    int x1, x2, y1, y2; double m, c;
                
    x1 = p1[0]; x2 = p2[0];
    y1 = p1[1]; y2 = p2[1];

    if (x1 == x2) m = 1000000000.0;
    else m = (y2 - y1) / (x2 - x1);
    c = y1 - (m * x1);

    return make_pair(m, c);
}

class Solution 
{
public:
    int maxPoints(vector<vector<int>>& pR) 
    {
        if (pR.size() < 3) return pR.size();
        
        PointPairs p;
        PointCount pc;
        
        for (int i=0; i < pR.size(); ++i)
        {
            PointPair pxy = make_pair(p[i][0], p[i][1]);
            if (pc.count(pxy) == 0) 
            {
                pc[pxy] = 1;
                p.push_back(pR[i]);
            }
            else pc[pxy]++;
        }
        
        
        MapSIntP Ms;
        
        for (int i=0; i < p.size(); ++i)
        {
            for (int j=i+1; j < p.size(); ++j)
            {
                SlopeInt mc = getMC(p[i], p[j]);
                
                Ms[mc].insert(i); Ms[mc].insert(j);
            }
        }
        
        int maxN = 0;
        
        MapSIntP::iterator t;
        set<int>::iterator s;
        
        for (t = Ms.begin(); t != Ms.end(); ++t)
        {
            int temp = 0;
            
            // for (s = t->second.begin(); s != t->second.end(); ++s)
            // {
            //     int i = *s;
            //     temp += pc[make_pair(p[i][0], p[i][1])];
            // }
            
            temp = t->second.size();
            
            if (temp > maxN) maxN = temp;
        }
        return maxN;
    }
};




typedef pair<double, double> SlopeInt;
typedef pair<int, int> PointPair;
typedef map<SlopeInt, int> MapSlopeInt;
typedef map<SlopeInt, set<int> > MapSIntP;
typedef map<SlopeInt, int>::iterator MapSIt;

SlopeInt getMC(const vector<int>& p1, const vector<int>& p2)
{
    int x1, x2, y1, y2; double m, c;
                
    x1 = p1[0]; x2 = p2[0];
    y1 = p1[1]; y2 = p2[1];

    if (x1 == x2) m = 1000000000.0;
    else m = (y2 - y1) / (x2 - x1);
    c = y1 - (m * x1);

    return make_pair(m, c);
}

class Solution 
{
public:
    int maxPoints(vector<vector<int> >& pR) 
    {
        if (pR.size() < 3) return pR.size();
        
        MapSIntP Ms;
        vector<vector<int> > p;
        map<PointPair, int> pc;
        
        for (int i=0; i < pR.size(); ++i)
        {
            PointPair pp = make_pair(pR[i][0], pR[i][1]);
            if (pc.count(pp) == 0)
            {
                pc[pp] = 1; p.push_back(pR[i]);
            }
            else pc[pp]++;
        }
        
        int maxN = 0;

        for (int i=0; i < p.size(); ++i)
        {
            for (int j=i+1; j < p.size(); ++j)
            {
                SlopeInt mc = getMC(p[i], p[j]);
                
                Ms[mc].insert(i); Ms[mc].insert(j);
            }
        }

        
        
        
        MapSIntP::iterator t;
        for (t = Ms.begin(); t != Ms.end(); ++t)
        {
            if (t->second.size() > maxN) maxN = t->second.size();
        }
        return maxN;
    }
};
