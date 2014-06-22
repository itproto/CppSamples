#include "stdafx.h" // don't forget
#include "Address.h" // try fogetting this and see what happens :)
#include "Person.h"
#include "Employee.h"


void Employee::greet()
{
  // not static!
  Person::greet();

  cout << "By the way, I work in " << department << endl;
}