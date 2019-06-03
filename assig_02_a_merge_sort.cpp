#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>&v)
{
  for (int i=0; i < v.size(); ++i)
  {
    cout << v[i] << ", ";
  }
  cout << endl;
}

vector<int> merge(const vector<int>& u, const vector<int>& v)
{
  if (u.size() == 0) return v;
  if (v.size() == 0) return u;

  int l, r; l = r = 0;

  vector<int> merged;

  while(true)
  {
    while(u[l] < v[r]) merged.push_back(u[l++]);
    while(v[r] < u[l]) merged.push_back(v[r++]);

    if (l == u.size() - 1 || r == v.size() - 1) break;
  }

  if (l == u.size() - 1)
  {
    while(r < v.size()) merged.push_back(v[r++]);
  }
  if (r == v.size() - 1)
  {
    while(l < u.size()) merged.push_back(u[l++]);
  }
  return merged;
}

int main()
{
  vector<int> v;
  vector<int> u;

  int p;

  while(true)
  {
    cout << "Enter a number: ";
    cin >> p;
    if (p == -1) break;
    v.push_back(p);
  }

  while(true)
  {
    cout << "Enter a number: ";
    cin >> p;
    if (p == -1) break;
    u.push_back(p);
  }

  print(u); print(v);

  // print(merge(v, u));
  
  return 0;
}