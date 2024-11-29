#include "Watch.hpp"
#include <iostream>

void Watch::ShowTime(const Time &time) const
{
    int displayHours = is24HourFormat ? time.hours : (time.hours % 12 == 0 ? 12 : time.hours % 12);
    std::cout << "Watch shows time: "
              << displayHours << ":"
              << time.minutes << ":"
              << time.seconds
              << (time.hours >= 12 ? " PM" : " AM")
              << "\n";
}

void Watch::SetTime(Time &time, int h, int m, int s)
{
    time.hours = h;
    time.minutes = m;
    time.seconds = s;
    time.Normalize();
}

void Watch::SetFormat(bool format)
{
    is24HourFormat = format;
}