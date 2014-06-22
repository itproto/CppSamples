#include "stdafx.h"
#include "Address.h" // added when address introduced!
#include "Person.h"

Person::Person(int age, string name, int sex): 
age(age), name(name), sex(sex)
{
  address = nullptr;
}

// illustrates calling other ctors
Person::Person(int age, string name, int sex, int houseNumber, string streetName, string city)
  : Person(age, name, sex) // explain ctor call
{
  if (address != nullptr)
    delete address;

  address = new Address(houseNumber, streetName, city);
}

Person::~Person()
{
  if (address != nullptr)
  {
    delete address;
    address = nullptr;
  }
}

Person::Person(Person const& p)
: age(p.age), name(p.name), sex(p.sex)
{
  auto* a = p.address;
  address = new Address(a->houseNumber, 
    a->streetName, a->city);
}

void Person::greet()
{
  cout << "My name is " <<
    this->name << " and I am " <<
    this->age << " years old." << endl;

  // added for address
  if (address)
  {
    cout << "I live at " <<
      address->houseNumber << " " <<
      address->streetName << ", " <<
      address->city << endl;
  }
}

int Person::getLifeExpectancy()
{
  return lifeExpectancy;
}

int Person::lifeExpectancy = 80;