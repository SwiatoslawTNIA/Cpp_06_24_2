//implementation of the stone Class:
#include <iostream>
#include "stone.h"
using namespace std;

Stone::Stone(void)
{
   pounds = pounds_left = 0.0;
   stones = 0;
}
Stone::~Stone()
{
   cout << "<A stone desctructor>";
}
Stone::Stone(double lbs)
{
   if(lbs < 0)
      cerr << "Invalid number of pounds, setting the value of pounds to the default.";
   pounds = lbs;
   stones = (int)(lbs / Lbs_per_stn);//conver to int
   pounds_left = (int(lbs)) % Lbs_per_stn + lbs - int(lbs);//lbs - int(lbs) adds the fractional part
   //to the pounds_left;

}
Stone::Stone(int stns, double lbs)
{
   if(lbs < 0 || stns < 0)
      cerr << "Invalid number of pounds, setting the value of pounds to the default.";
   stones = stns;
   pounds_left = lbs;
   pounds = stns * Lbs_per_stn + lbs;
   
}
void Stone::show_lbs(void) const
{
   cout << "\nThe weight in pounds: " << pounds;

}
void Stone::show_stones(void) const
{
   cout << "\n the weight: stones: " << stones << ", pounds: " << pounds_left;
}

//conversion functions to convert an obj. to a specific type:
Stone::operator int() const
{
   return int(pounds + 0.5);
}
Stone::operator double() const
{
   return pounds;
}
