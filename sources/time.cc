#include "time_own.h"
#include "iostream"
//the implementation:
Time::Time(void)
{
   d_hours = 0; 
   d_minutes = 0;
}
Time::Time(int h, int m)
{
   d_minutes = m % 60;
   d_hours = h + m / 60;
}
Time::~Time()
{
   std::cout << "Buy, the obj is destructed...\n";
}
void Time::addMin(int minutes)
{
   if(minutes < 60)
      return;//exit
   if(minutes + d_minutes > 59)
   {
      addHours(1);//add one hour
      d_minutes = (minutes + d_minutes) % 60;
   }
   else
   {
      d_minutes += minutes;
   }
}
void Time::addHours(int hours)
{
   if(hours < 0)
      return;//exit
   if(d_hours + hours > 23)
   {
      d_hours = (d_hours + hours) % 24;
   }
   else
   {
      d_hours += hours;
   }
}
void Time::reset(int hours, int minutes)
{
   if(hours < 0 || minutes < 0)
      return;
   //it will automatically adjust hours and minutes:
   int hours_in_minutes = 0;  
   if(minutes > 59)
   {
      d_minutes = minutes % 60;
      hours_in_minutes = minutes / 60;
   }
   d_hours = (hours + hours_in_minutes) % 24;
}  
Time Time::operator+(const Time &time_1) const
{
   Time new_obj;
   new_obj.d_hours = d_hours + time_1.d_hours + time_1.d_minutes / 60;
   new_obj.d_minutes = (this->d_minutes + time_1.d_minutes) % 60;
   return new_obj;//a reference cannot be returned, because if a newly created 
   //object is returned, we can catch a copy of it, but a reference is a refere
   //rence to a nonexistent object, since it is deleted when the compiler exits 
   //the current scope
}
//promises not to change the object it is called on
void Time::show(void) const
{
   std::cout << "Current time: " << d_hours << ":" << d_minutes << std::endl;
}
Time Time::operator-(const Time &time) const
{
   Time new_obj;
   if(d_hours < time.d_hours)
      return *this;//exit
   if(d_minutes < time.d_minutes && d_hours < 1)
      return *this;
   if(d_minutes < time.d_minutes)
   {
      new_obj.d_hours = d_hours - 1;
      new_obj.d_minutes = 60 + d_minutes - time.d_minutes;
   }
   else
   {
      new_obj.d_minutes = d_minutes - time.d_minutes;
   }
   new_obj.d_hours = d_hours - time.d_hours;
   return new_obj;
}

Time Time::operator*(const Time &time) const
{
   Time object;
   object.d_minutes = (d_minutes * time.d_minutes)  % 60;
   object.d_hours = (d_hours * (time.d_hours + (d_minutes * time.d_minutes) / 60)) % 24;
   return object;
}
Time Time::operator*(double value) const
{
   Time object;
   object.d_minutes = ( static_cast<int>(this->d_minutes * value )) % 60;
   object.d_hours =( this->d_hours * value) + ((this->d_minutes * value) / 60);
   return object;
}
Time operator*(double value, const Time & time_obj)//func def, but It can't directly access the 
//private data inside of the Time class;so we need to grant it access to it, by declaring this
//func as a friend func
{
   Time new_obj;
   new_obj.d_minutes = static_cast<int>(value * time_obj.d_minutes ) % 60;
   new_obj.d_hours = (value * time_obj.d_hours) + (static_cast<int>(value * time_obj.d_minutes) / 60);
   return new_obj;
}
//to be able to use something like: cout << Time_obj
std::ostream & operator<<(std::ostream & output_stream, const Time & obj)
{
   std::cout << "The time: " << obj.d_hours << ":" << obj.d_minutes;
   return output_stream;
   static int val = 0;
   val++;//count the times the func has been called.
}//the void return type works fine, but for statements like cout << a << b it won't work, 
//because we have to return a reference to the ostream to the next object, for it to be able to 
//be displayed.