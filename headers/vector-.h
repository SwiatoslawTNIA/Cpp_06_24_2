#ifndef VECTOR_
#define VECTOR_
#include <iostream>
namespace VECTOR
{
   class Vector
   {
      public:
         enum Mode {RECT, POL};//not a var definition
      private:
         double x;
         double y;
         double mag;
         double angle;
         Mode mode;//to differentiatite between two modes.
         //private methods:
         void set_mag(void);
         void set_angle(void);
         void set_x(void);
         void set_y(void);
      public:
         Vector();
         Vector(double i_x, double i_y, Mode i_mode = RECT);// a default input mode is RECT type
         void reset(double i_x, double i_y, Mode i_mode = RECT);
         ~Vector();
         //report values:
         double x_val(void) const {return x;};
         double y_val(void) const {return y;};
         double mag_val(void) const {return mag;};
         double ang_val(void) const {return angle;};
         void polar_mode(void);
         void rect_mode(void);
         //operator overloading:
         Vector operator+(const Vector & input_vector) const;
         Vector operator-(const Vector & input_vector) const;
         Vector operator-() const;
         Vector operator*(double n) const;
         //friends:
         friend Vector operator*(double n, const Vector & input_vector);
         friend std::ostream & operator<<(std::ostream & os, const Vector & input_vector);
         friend void example(void);

   };
}
#endif