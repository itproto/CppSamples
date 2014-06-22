#pragma once

class EmpFactory
{
public:
  Employee makeEmp(int id)
  {
    Employee emp;
    emp.taxId = id;
    return emp;
  }
};