#pragma once
class Employee : public Person
{
  friend class EmpFactory;

  int taxId;
public:
  // add this later
  Employee() : Person(0, "", 0) {}

  // generate this, keep private
  Employee(int age, string const& name, int sex,
    string department = string())
    : Person(age, name, sex), department(department)
  {
  }

  // Generate|overriding members
  void greet() override;
  string department;
};

