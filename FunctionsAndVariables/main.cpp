#include <iostream>
#include <string>
using namespace std;

namespace life
{
  // try int first
  auto meaning = 42;

  auto* pm = &meaning;
  auto& rm = meaning;
}

int add(int a, int b) { return a + b; }

// postfix
auto add2(int a, int b) -> int { return a + b; }

void inc(int& a) { a++; }

enum Color
{
  Red,
  Green,
  Blue
};

enum class GameState : short
{
  Win = 1,
  Lose = 5
};

struct OtherColor
{
  enum
  {
    Purple,
    Orange,
    Magenta
  };
};

struct Size
{
  int width, height;
} size; // this gets added later

union Data
{
  int integer;
  float fpnumber;
  char* text;
};

int main()
{
  

  getchar();
}