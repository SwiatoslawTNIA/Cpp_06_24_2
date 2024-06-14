//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "ctime"
#include "time_own.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//
int main(void)
{
  using namespace std;
  Time planning, coding(4, 44), fixing(2,23), total;
  cout << "planning time = ";
  planning.show();
  cout << endl;
  cout << "coding time = ";
  coding.show();
  cout << endl;
  cout << "fixing time = ";
  fixing.show();
  cout << endl;
  cout << "total time = ";
  total.show();
  cout << endl;
  coding = coding * 2;//this expands to total.operator*(2);
  coding.show(); //Time Time::operator*(double n);
  coding = coding * coding;//expands to total.operator*(coding);
  coding.show();

  //the syntax: Time Time::operator*(const Time & t) const;
  coding = 2 * coding;
  coding.show();
  //the syntax: a friend non-member func is defined: auto operator*(double n, const Time &) -> Time 
  // total = coding.sum(fixing);
  //instead of the code above we can now use:
  // total = coding + fixing;
  // cout << "coding.sum(fixing) = " ;
  // total.show();
  // Time morefixing(4,123);
  // cout << "morefixing = ";
  // morefixing.show();
  // morefixing = morefixing.operator+(total);
  // morefixing.show();

  cout << coding << fixing << planning;
  return 0;
}
