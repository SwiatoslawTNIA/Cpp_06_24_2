#include <iostream>
#include <cmath>
#include "vector-.h"
namespace VECTOR
{
   using namespace std;
   const double RAD = 57.295779;
   void Vector::set_mag(void)
   {
      mag = sqrt(x*x + y*y);
     
   }
   void Vector::set_angle(void)
   {
      if(x == 0 && y == 0)
         angle = 0;
      else 
         angle = atan2(y, x);
   }
   //polar coords:
   void Vector::set_x(void)
   {
      x = cos(angle) * mag;
   }
   void Vector::set_y(void)
   {
      y = sin(angle) * mag;
   }
   //public methods:
   Vector::Vector(void)
   {
      x = y = mag = angle = 0.0;
      mode = RECT;
   }
   Vector::Vector(double i_x, double i_y, Mode i_mode)
   {
      if(i_mode == RECT)
      {
         mode = RECT;
         x = i_x;
         y = i_y;
         set_mag();
         set_angle();
      }
      else if(i_mode == POL)
      {
         mode  = POL;
         mag = sqrt( i_x * i_x + i_y * i_y);
         angle = atan2(i_y, i_x);
         set_x();
         set_y();
      }
      else
      {
          cout << "Incorrect third arg";
          x = y = angle = mag = 0.0;
      }
   }
   Vector::~Vector(void)
   {
      printf("\nA destructor has been called.");
   }
   //reset the vector from rect if form is rect or from polar if form is polar:
   void Vector::reset(double i_x, double i_y, Mode i_mode)
   {
      if(i_mode == RECT)
      {
         x = i_x;
         y = i_y;
         set_mag();
         set_angle();
      }
      else if(i_mode == POL)
      {
         mag = sqrt( i_x * i_x + i_y * i_y);
         angle = atan2(i_y, i_x);
         set_x();
         set_y();
      }
      else
      {
          cout << "Incorrect third arg";
          x = y = angle = mag = 0.0;
          mode = RECT;//set the default mode
      }
   }
   void Vector::polar_mode(void)
   {
      mode = POL;

   }
   void Vector::rect_mode(void)
   {
      mode = RECT;
   }
   //operator overloading:
   Vector Vector::operator+(const Vector & vector_2) const
   {
      Vector new_vector;
      new_vector.mode = RECT;
      new_vector.x = this->x + vector_2.x;
      new_vector.y = this->y + vector_2.y;
      new_vector.set_angle();
      new_vector.set_mag();
      return new_vector;
   }
   Vector Vector::operator-(const Vector & vector_2) const
   {
       return Vector(x - vector_2.x, y - vector_2.y);
   }
   Vector Vector::operator-(void) const
   {
      return Vector(-x, -y);
   }
   Vector Vector::operator*(double n) const
   {
      return Vector(x * n, y * n);
   }
   Vector operator*(double n, const Vector & vector)
   {
      return Vector(vector.x * n, vector.y * n);
   }
   std::ostream & operator<<(std::ostream & os, const Vector & vector)
   {
      cout << "The rect coords: " << vector.x << ":" << vector.y << "\nThe polar coords:"
      << vector.mag << ", angle: " << vector.angle;
      return os;
   }
   void example(void)
   {
      ;
   }
}


