#include "stdafx.h"

void iteration()
{
  int a[]{ 1, 2, 3, 4 };

  for (int i = 0; i < 4; ++i)
    cout << a[i] << "\t";
  cout << endl;

  // pointer arithmetic
  for (int *p = a, *e = a + 4; p != e; ++p)
    cout << *p << "\t";
  cout << endl;

  // these are iterators
  auto ba = begin(a);
  auto ea = end(a); // hover the mouse over
  for (; ba != ea; ba++)
    cout << *ba << "\t";
  cout << endl;

  // range-based for
  // pair of begin and end form a range
  for (auto value : a)
    cout << value << "\t";
  cout << endl;

  // variable-size container
  vector<int> v{ 5, 6, 7, 8 };
  auto bv = begin(v); // member also

  // can return constant iterators
  auto cvb = v.cbegin();
  // *cvb = 3; // oops!

  // ++ overloaded for iterator
  for (auto i = v.rbegin(); i != v.rend(); i++)
    cout << *i << "\t";
  cout << endl;
}

void switching()
{
  int i = 0;

  switch (i)
  {
  case 0:
    cout << "hello " << endl;
  case 1:
    cout << "world" << endl;
  default:
    cout << "!" << endl;
  }

  // string isn't a type
  // cannot switch on a string
}

void to_bool()
{
  // not so safe
  char* s = "pluralsight";

  while (*s)
  {
    putchar(*s);
    s++;
  }

  // ok
  int* n = nullptr;
  if (n)
  {

  }

  // smart pointers, too
  auto p = make_shared<int>(42);
  if (p)
  {

  }
}

int _tmain(int argc, _TCHAR* argv[])
{
  //iteration();
  //switching();

  to_bool();

  getchar();
	return 0;
}

