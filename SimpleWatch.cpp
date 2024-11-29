#include "SimpleWatch.hpp"
#include <iostream>

void SimpleWatch::ShowTime(const Time &time) const
{
    int displayHours = is24HourFormat ? time.hours : (time.hours % 12 == 0 ? 12 : time.hours % 12);
    std::cout << "SimpleWatch shows time: "
              << displayHours << ":"
              << time.minutes << ":"
              << time.seconds
              << (time.hours >= 12 ? " PM" : " AM")
              << "\n";
}

void SimpleWatch::SetTime(Time &time, int h, int m, int s)
{
    time.hours = h;
    time.minutes = m;
    time.seconds = s;
    time.Normalize();
}

void SimpleWatch::SetFormat(bool format)
{
    is24HourFormat = format;
}