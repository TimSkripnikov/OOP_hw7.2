#include "Time.hpp"

class Watch
{
private:
    bool is24HourFormat{true};

public:
    void ShowTime(const Time &time) const;
    void SetTime(Time &time, int h, int m, int s);
    void SetFormat(bool format);
};