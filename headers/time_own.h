#ifndef TIME_
#define TIME_
#include <iostream>
class Time
{
private:
   unsigned int d_hours;
   unsigned int d_minutes;
   // unsigned int another_val;
public:
   Time();
   Time(int h, int m = 0);
   ~Time();
   void addMin(int minutes);
   void addHours(int hours);
   void reset(int hours = 0, int minutes = 0);
   // Time sum(const Time &time_1) const;//promises not to change the object it is called on
   //change above to:
   Time operator+(const Time &time_1) const;
   Time operator-(const Time &time) const;
   Time operator*(const Time &time) const;
   Time operator*(double n) const;
   //the declaration like this is an error, 
   //because the compiler thinks, it's an ordinary member func, 
   //Time operator*(double n, const Time &time_obj);
   friend Time operator*(double n, const Time &time_obj);//it's not a member function, 
   //it's a friend function, it still has access to all the data 
   void show(void) const;
   friend std::ostream & operator<<(std::ostream & output_stream, const Time &time_obj);
};
#endif