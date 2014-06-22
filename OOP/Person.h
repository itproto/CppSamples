#pragma once

class Person
{
  static int lifeExpectancy;
public:
  // const is not static by default
  const static int female = 0;
  const static int male = 1;

  int age;
  string name;
  int sex;
  Address *address;

  // only for ctors/dtors section
  Person(int age, string name, int sex);
  Person(int age, string name, int sex,
    int houseNumber, string streetName, string city);
  virtual ~Person();

  // copy ctor/assign
  Person(const Person& p);

  // make virtual later on
  virtual void greet();

  static int getLifeExpectancy();
};

