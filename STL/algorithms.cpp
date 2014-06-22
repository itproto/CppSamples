#include "stdafx.h"

struct Person
{
  string name;
  int age;

  friend ostream& operator<<(ostream& os, const Person& p)
  {
    return os << p.name << " is " << p.age << " years old.";
  }
};

int algorithms()
{
  vector<Person> people{ { "John", 27 }, { "Chris", 24 }, { "Ann", 31 } };

  auto print_all = [&]()
  {
    cout << people.size() << " persons:" << endl;
    for_each(begin(people), end(people), [](const Person& p) { cout << p << endl; });
  };
  print_all();

  // find out who is oldest
  auto oldest = *max_element(people.begin(), people.end(),
    [](const Person& a, const Person& b)
  {
    return a.name < b.name;
  });
  cout << oldest.name << " is the oldest" << endl;
  
  // let's find john
  auto john = find_if(people.begin(), people.end(), [](const Person& p)
  {
    return p.name == string("John"); // change to Jill
  });
  if (john != people.end())
    cout << "Found " << john->name << " who is " << john->age << endl;

  // number of people younger than 
  auto youngerThan30 = count_if(people.begin(), people.end(),
    [](const Person& p) {return p.age < 30; });
  cout << "Found " << youngerThan30 << " people younger than 30." << endl;

  // sort by age
  sort(people.begin(), people.end(), 
    [](const Person& a, const Person& b)
  {
    return a.age < b.age;
  });
  cout << "People sorted by age:" << endl;
  print_all();

  // replace john with jill
  Person jill{ "Jill", 44 };
  replace_if(people.begin(), people.end(),
    [](const Person& p) -> bool { return p.name == "John"; },
    jill);
  print_all();

  getchar();
  return 0;
}