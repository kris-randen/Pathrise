/*
a can only be followed by e
e can only be followed by a or i
i can only be followed by a e or i
*/

int numMagicalStrings(int n)
{
  int na, ne, ni; na = ne = ni = 1;
  int nan, nen, nin;

  for (int i=1, i < n; ++i)
  {
    nan = ne + ni;
    nen = na + ni;
    nin = 
  }
}