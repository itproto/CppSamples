#include "stdafx.h"

typedef pair<int, int> int_pair;
//typedef tuple<int, int, int> trie;

// start with pair<int,int>
int_pair sum_and_product(int a, int b)
{
  return int_pair(a+b, a*b);
}

template<typename T1, typename T2, typename T3>
struct triple // explain struct here
{
  typedef T1 first_type;

  T1 first;
  T2 second;
  T3 third;

  triple(const T1& first, const T2& second, const T3& third)
    : first(first), second(second), third(third)  {  }
};

typedef triple<int, int, int> trie;

// start with int first arg
//trie sum_product_avg(trie::first_type a, int b, int c)
//{
//  return trie(a + b + c, a*b*c, (a + b + c) / 3);
//}

// generic
template<typename T1, typename T2, typename T3>
triple<T1,T2,T3> sum_product_avg(const T1& a, const T2& b, const T3& c)
{
  return triple<T1, T2, T3>(a + b + c, a*b*c, (a + b + c) / T1(3)); // add T1(3) later
}

// try changing argument type to see it fail
// write only after showing complex stuff
typedef complex<double> cd;
typedef triple<cd, cd, cd> cdt;
template<> cdt sum_product_avg(const cd& a, const cd& b, const cd& c)
{
  auto result = sum_product_avg(a.real(), b.real(), c.real());
  return cdt(result.first, result.second, result.third);
}

void template_classes()
{
  int a = 2, b = 3, c = 4;
  auto result = sum_product_avg(a, b, c);
  cout << result.first << ", " << result.second << ", " << result.third << endl;
}

void template_specialization()
{
  
  cd a(2,3), b(3,4), c(4,5);

  auto result = sum_product_avg(a, b, c);
  cout << result.first << ", " << result.second << ", " << result.third << endl;


}

void consuming_templates()
{
  // start with int
  int a = 2, b = 3;
  auto result = sum_and_product(a, b);
  //cout << "sum = " << result.first << " product = " << result.second << endl;
  cout << "sum = " << get<0>(result) << " product = " << get<1>(result) << endl;

  /*int c = 4;
  auto all = sum_product_avg(a, b, c);
  cout << "sum = " << get<0>(all) << " product = " << get<1>(all) << " avg = "
    << get<2>(all) << endl;*/
}

template <int N>
struct Factorial
{
  enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0>
{
  enum { value = 1 };
};

template< typename T >
T sum(T t)
{
  return t;
}

template< typename T, typename ...U >
auto sum(T t, U ...u) -> decltype(t + sum(u...))
{
  return t + sum(u...);
}

void variadic()
{
  // start with 2
  cout << sum(1, 2.5, 3, 4) << endl;
  cout << sum(string("abra"), string("cadabra")) << endl;
}

void metaprogramming()
{
  // hover the mouse over ::value to show evaluated values
  int x = Factorial<4>::value;
  int y = Factorial<0>::value;
}

int main(int argc, char* argv[])
{
  // consuming_templates();
  //template_classes();
  //template_specialization();
  //variadic();

  getchar();
	return 0;
}

