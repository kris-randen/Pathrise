//A is sorted array
int binary_searchRecursive(int A[], int key, int s, int e)
{
    if (e < s) return -1;
    if (A[(s + e) / 2] == key) 
      return (s + e) / 2;
    else if (A[(s + e) / 2] < key) 
      return binary_searchRecursive(A, key, (s + e)/2 + 1, e);
    else 
      return binary_searchRecursive(A, key, s, (s + e)/2 - 1);
}

int binary_search(int A[], int key, int len) 
{
  //TODO: Write - Your - Code
  return binary_searchRecursive(A, key, 0, len - 1);

  return -1;
}