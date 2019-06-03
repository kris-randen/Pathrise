/*
String Compression
*/

#include <string>
#include <iostream>

using namespace std;

vector<char> compress(vector<char> chars) 
  {
      unsigned int h[128] = {0};
      
      for (unsigned int i=0; i < chars.size(); ++i)
      {
          h[chars[i]]++;
      }
      
      vector<char> r;
      
      for (unsigned int i=0; i < 128; ++i)
      {
          if (h[i] > 0)
          {
              cout << "h[i] = " << h[i] << endl;
              char c = i;
              r.push_back(c); r.push_back('0' + h[i]);
              cout << "r last = " << r[r.size() - 1] << endl;
              cout << "r second last = " << r[r.size() - 2] << endl;
          }
      }
      
      if (r.size() < chars.size()) return r;
      else return chars;
  }