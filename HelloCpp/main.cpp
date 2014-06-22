#include <cassert>
#include "../StaticLib/fun.h"
#include "../DynamicLib/DynamicLib.h"

#if _DEBUG
void foo() { }
#endif

#define MUL(a,b) a*b
 
int main()
{
  assert(MUL(2, 4) == 8);
  //assert(MUL(2,2+2) == 8);

  // try building to show unresolved external
  assert(add(2, 2) == 4);

  assert(multiply(3, 4) == 12);

  // explain non-automatic dependencies

  return 0;
}