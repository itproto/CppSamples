#include "stdafx.h"
#include "MoveSemantics.h"

class Address
{
public:
  string city;

  Address() {}

  Address(string const& city) : city(city)
  {
    cout << city << " Address created " << endl;
  }

  ~Address()
  {
    cout << city << " Address destroyed" << endl;
  }
};

class Person
{
public:
  Address* address;

  Person(string const& city) {
    address = new Address(city);
    cout << "Person created" << endl;
  }

  ~Person()
  {
    delete address;
    cout << "Person deleted" << endl;
  }
};

class Person2
{
  Person2(){}
  Person2(const Person2& _) {}
  ~Person2(){}

  int ref_count;
public:
  static Person2* create()
  {
    auto* p = new Person2;
    p->ref_count = 1;
    return p;
  }

  void add_ref() { ref_count++; }
  void release()
  {
    if (--ref_count == 0)
      delete this;
  }
};

class Person3
{
public:
  shared_ptr<Address> address;

  Person3(string const& city)
  {
    cout << "Person created" << endl;
    address = make_shared<Address>(city);
  }

  ~Person3()
  {
    // hmm, nothing here
    cout << "Person destroyed" << endl;
  }
};

void basics()
{
  // basic pointer management
  Person* p = new Person("Toronto");
  cout << p->address->city << endl;
  delete p;

  /*
  Address* address;

  {
  Person p("New York");
  address = p.address;
  }

  cout << address->city << endl;
  */
  
  // cannot do this
  auto* p2 = Person2::create();

  p2->release();
}

void rvalue_move()
{

}

void shared_pointer()
{
  shared_ptr<Address> a;

  {
    Person3 p3("Stockholm");
    a = p3.address;
  }

  cout << a->city << endl;
}

unique_ptr<Address> create_address(string const& city)
{
  //auto* a = new Address("Leningrad");
  //a->city = "St.Petersburg";
  // return new unique_ptr<Address>(a);
  //return unique_ptr<Address>(new Address(city));
  return make_unique<Address>(city);
}

int main(int argc, char* argv[])
{
  //shared_pointer();

  auto a = create_address("Vancouver");
  

  // move/rvalue
  // jump to 
  //Address *places[100];
  //places[23] = new Address("Montreal");

  // unique_ptr stuff
  
  // cannot copy construct
  //auto v(u);
  //auto w = u;

  // ---- shared_Ptr stuff
  
  //z();

  //getchar();
	return 0;
}

