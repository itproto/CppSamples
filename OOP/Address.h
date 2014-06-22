#pragma once

// declare inline!
class Address
{
public:
  int houseNumber;
  string streetName;
  string city;

  // keep this inline
  Address(int houseNumber, string const& streetName, 
    string const& city)
    : houseNumber(houseNumber), streetName(streetName), 
      city(city)
  {
  }
};

