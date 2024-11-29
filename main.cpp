#include "Time.hpp"
#include "SimpleWatch.hpp"
#include "Watch.hpp"

int main()
{
    Time time(10, 15, 30);

    SimpleWatch simpleWatch;
    simpleWatch.ShowTime(time);
    simpleWatch.SetFormat(false);
    simpleWatch.ShowTime(time);

    Watch watch;
    watch.ShowTime(time);
    watch.SetTime(time, 14, 30, 45);
    watch.SetFormat(false);
    watch.ShowTime(time);

    return 0;
}
