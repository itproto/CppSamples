#include "stdafx.h"

// show how to relocate these to a separate header instead

class EmpFactory; // explain this

#include "Address.h" // position is important!
#include "Person.h"
#include "Employee.h"
#include "EmpFactory.h"

int main()
{
  // person on the stack
  Person p(30, "Jane Doe", Person::female); // constructors will fail here

  // on the heap
  Person *p2 = new Person(25, "John Doe", Person::male);
  //p2->age = 25;
  //p2->name = "John Doe";

  p2->greet();

  

  //----------------------

  // try getting lifeExpectancy
  cout << Person::getLifeExpectancy() << endl;

  //-----------------------

  Person *p3 = new Person(44, "Jack Jones", Person::male);
  auto* address = new Address(123, "Oxford Street", "London");
  
  // show member assign before generating ctor
  //address->houseNumber = 123;
  //address->streetName = "Oxford Street";
  //address->city = "London";
  p3->address = address;

  p3->greet();
  
  // copy construction
  Person p4(p);

  p.address->city = "Exeter";
  cout << p4.address->city << endl;
  // access violation!

  // copy assignment
  // not explained
  Person p5 = p;
  cout << p5.address->city << endl;

  // keep this last
  delete p2;
  delete p3;

  // inheritance ----------------------------
  Employee e(33, "Chris", Employee::male, "Engineering");

  auto u = [](const Person& p)
  {
    cout << p.name << endl;
  };
  u(e);
  
  // automatic
  Person& pr = e;

  Employee& er = static_cast<Employee&>(pr);
  er.greet();

  // what if pr is not an employee?
  Person& pr2 = p;
  //Employee& er2 = static_cast<Employee&>(pr2);
  //cout << er2.department << endl;

  try {
    Employee& er2 = dynamic_cast<Employee&>(pr2);
    cout << er2.department << endl;
  }
  catch (const bad_cast& e)
  {
    cout << "Cannot cast this!" << endl;
  }

  Person* pp = &p;
  Employee* ep = dynamic_cast<Employee*>(pp);
  if (!ep)
    cout << "Failed to cast pointer" << endl;
  else
    cout << ep->department << endl;

  getchar();
  return 0;
}