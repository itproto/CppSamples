#include "stdafx.h"

int main()
{
  cout << "Maximum integer is " << numeric_limits<int>::max() << endl;

  cout << sin(M_PI / 2) << endl; // f12 on this

  cout << expf(0.3f) << endl;

  vector<int> v{ 1, 2, 3, 4 };
  next_permutation(v.begin(), v.end());
  for (auto i : v) cout << i << "\t";
  cout << endl;

  auto product = accumulate(v.begin(), v.end(), 1,
    [](int a, int b) {return a*b; });
  cout << "1x2x3x4 = " << product << endl;

  complex<float> f(0.4f, 0.5f);
  cout << f*f << endl;

  // old c-style rng
  srand((unsigned)time(nullptr));
  for (int i = 0; i < 100; ++i)
  {
    cout << rand() % 10 << "\t";
  }

  auto seed = chrono::system_clock::now()
    .time_since_epoch().count();
  mt19937 gen(seed);
  normal_distribution<float> nd;

  for (int i = 0; i < 100; ++i)
  {
    cout << nd(gen) << "\t";
  }

  getchar();
  return 0;
}