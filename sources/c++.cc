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
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "vector-.h"
#include "stone.h"
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
  //the seed for rand:
  srand(time(NULL));
  // Time planning, coding(4, 44), fixing(2,23), total;
  // cout << "planning time = ";
  // planning.show();
  // cout << endl;
  // cout << "coding time = ";
  // coding.show();
  // cout << endl;
  // cout << "fixing time = ";
  // fixing.show();
  // cout << endl;
  // cout << "total time = ";
  // total.show();
  // cout << endl;
  // coding = coding * 2;//this expands to total.operator*(2);
  // coding.show(); //Time Time::operator*(double n);
  // coding = coding * coding;//expands to total.operator*(coding);
  // coding.show();

  // //the syntax: Time Time::operator*(const Time & t) const;
  // coding = 2 * coding;
  // coding.show();
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

  // cout << coding << fixing << planning;
  // {
  //   using namespace VECTOR;
  //   Vector vector_1;
  //   vector_1.reset(34, 22, Vector::Mode(1));//reset the mode
  //   cout << vector_1;
  // }

  // a random walk implementation:
  // unsigned int step_size = 2;
  // int total_distance = 0, angle = 0;
  // using namespace VECTOR;
  // Vector total_step, current_step;
  // unsigned int steps = 0;
  // while(total_step.mag_val() < 50)
  // {
  //   angle = rand() % 360;
  //   current_step = Vector(cos(angle) * step_size, sin(angle) * step_size);
  //   total_step = total_step + current_step;
  //   total_distance += 
  //   sqrt(current_step.x_val() * current_step.x_val() + current_step.y_val() * current_step.y_val());
  //   steps++;
  // } 
  // cout << "Total distance traveled: " << total_distance << "\n, steps: " << steps;
  // cout << "Location: " << total_step.x_val() << ":" << total_step.y_val();
  Stone my_cat(12,32.4);
  my_cat.show_stones();
  double total = my_cat;//testing the explicit conversion operator
  int another_total = my_cat;
  cout << "This is the int result" << another_total;
  cout << "This is the result: " << total;
  // cout << my_cat;//an error, it doesn't know which type to convert it to, 
  cout << int(my_cat);//works just fine;
  // my_cat = 19.4;
  //now what happens above: we assign my_cat , an object, value 19.4, what happens?
  //a constructor that has only one arg is called, created automatically, then it's copy is
  //returned and assigned to my_cat;
  //to avoid this automatic conversion -> use the word explicit
  return 0;
}
