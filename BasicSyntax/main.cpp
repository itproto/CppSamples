#include <iostream>
#include <string>
#include <array>
using namespace std;

void references()
{
  int x = 0;
  int &y = x;
  int *z = &y;
}

void controlflow()
{
  int numbers[] {1, 2, 3};
  for (int n : numbers)
    cout << n << endl;
}

int main()
{
  controlflow();

  getchar();
  return 0;
}