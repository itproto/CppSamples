#pragma once

void inc(int& x) { x++; }

int meaningOfLife() { return 42; }

void z()
{
  int a = 0;
  inc(a); // ok
  
  // lvalue is something that can stand on the 
  // left side of the assignment
  //inc(1); // no :(

  auto swap = [](int& a, int& b)
  {
    int z{ a };
    a = b;
    b = z; // too much stuff!
  };

  // an rvalue ref can be bound to an rvalue but not lvalue

  // no
  //int& x = meaningOfLife();

  //int&& x = meaningOfLife();
  //cout << x << endl;


}