#ifndef STONE_
#define STONE_
#include <iostream>
class Stone
{
double pounds;//whole pounds
int stones;
double pounds_left;//fractional pounds
enum Type { Lbs_per_stn = 14};
public:
   Stone();
   explicit Stone(double lbs);//constructor for pounds + avoid automatic implicit conversions
   //Stone(double lbs);//constructor for pounds + avoid automatic implicit conversions
   
   Stone(int stn, double lbs);//constructor for stone + double pounds
   ~Stone();// a destructor
   //functions:
   double get_pounds(void) const {return pounds;};
   int get_stones(void) const {return stones;};
   //overloading operators:
   void show_lbs(void) const;
   void show_stones(void) const;
   //conversion functions:
   operator double() const;
   operator int() const;
};
#endif
// class Complex
// {
//    double real;
//    double imaginary;
// public:
//    Complex();
//    Complex(double real, double imaginary);
//    ~Complex();
//    //overloading funcs:
//    Complex operator+(const Complex & n_1) const;
//    Complex operator-(const Complex & n_1) const;
//    Complex operator*(const Complex & n_1) const;
//    friend Complex operator*(double n, const Complex & n_1);//overloading for the case 
//    //number * object;
//    friend std::ostream & operator<<(std::ostream & os, const Complex & complex_n);
//    friend std::istream & operator>>(std::istream & is, Complex & complex_n);
// };