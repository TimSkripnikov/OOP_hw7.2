#include <iostream>
#include <exception>

class InvalidTimeException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid time!";
    }
};

class Time
{
protected:
    int hours;
    int minutes;
    int seconds;
    static unsigned count;

public:
    Time() : hours(0), minutes(0), seconds(0)
    {
        ++count;
        std::cout << "Default constructor called. Current object count: " << count << std::endl;
    }

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        Normalize();
        ++count;
        std::cout << "Parameterized constructor called. Current object count: " << count << std::endl;
    }

    Time(const Time &t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds)
    {
        ++count;
        std::cout << "Copy constructor called. Current object count: " << count << std::endl;
    }

    ~Time()
    {
        if (count > 0)
        {
            --count;
        }
        std::cout << "Destructor called. Current count: " << count << std::endl;
    }

    static unsigned GetCount() noexcept
    {
        return count;
    }

    void Normalize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (seconds < 0)
        {
            minutes -= 1 + (-seconds) / 60;
            seconds = 60 - (-seconds) % 60;
        }

        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (minutes < 0)
        {
            hours -= 1 + (-minutes) / 60;
            minutes = 60 - (-minutes) % 60;
        }

        if (hours >= 24)
        {
            hours %= 24;
        }
        if (hours < 0)
        {
            hours = (hours % 24 + 24) % 24;
        }
    }

    void SetHours(int h)
    {
        if (h < 0 || h >= 24)
        {
            throw InvalidTimeException();
        }
        hours = h;
        Normalize();
    }

    void SetMinutes(int m)
    {
        if (m < 0 || m >= 60)
        {
            throw InvalidTimeException();
        }
        minutes = m;
        Normalize();
    }

    void SetSeconds(int s)
    {
        if (s < 0 || s >= 60)
        {
            throw InvalidTimeException();
        }
        seconds = s;
        Normalize();
    }

    int GetHours() const noexcept
    {
        return hours;
    }

    int GetMinutes() const noexcept
    {
        return minutes;
    }

    int GetSeconds() const noexcept
    {
        return seconds;
    }

    int ToSeconds() const noexcept
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void PrintTime() const noexcept
    {
        std::cout << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << std::endl;
    }

    Time operator+(const Time &other) const
    {
        int totalSeconds = ToSeconds() + other.ToSeconds();
        return Time(0, 0, totalSeconds);
    }

    Time operator-(const Time &other) const
    {
        int totalSeconds = ToSeconds() - other.ToSeconds();
        return Time(0, 0, totalSeconds);
    }

    Time &operator+=(const Time &other)
    {
        *this = *this + other;
        return *this;
    }

    Time &operator-=(const Time &other)
    {
        *this = *this - other;
        return *this;
    }

    Time &operator=(const Time &other)
    {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        return *this;
    }

    bool operator==(const Time &other) const
    {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }
};

unsigned Time::count = 0;

class Clock
{
protected:
    Time time;

public:
    Clock(int h, int m, int s) : time(h, m, s)
    {
        std::cout << "Clock constructor called" << std::endl;
    }

    virtual ~Clock()
    {
        std::cout << "Clock destructor called" << std::endl;
    }

    virtual void showTime() const
    {
        std::cout << "Time: " << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << std::endl;
    }
};

class CuckooClock : public Clock
{
public:
    CuckooClock(int h, int m, int s) : Clock(h, m, s)
    {
        std::cout << "CuckooClock constructor called" << std::endl;
    }

    ~CuckooClock()
    {
        std::cout << "CuckooClock destructor called" << std::endl;
    }

    void showTime() const override
    {
        std::cout << "Cuckoo Clock Time: " << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << std::endl;
    }
};

class WallClock : public Clock
{
public:
    WallClock(int h, int m, int s) : Clock(h, m, s)
    {
        std::cout << "WallClock constructor called" << std::endl;
    }

    ~WallClock()
    {
        std::cout << "WallClock destructor called" << std::endl;
    }

    void showTime() const override
    {
        std::cout << "Wall Clock Time: " << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << std::endl;
    }
};

class Watch : public Clock
{
public:
    Watch(int h, int m, int s) : Clock(h, m, s)
    {
        std::cout << "Watch constructor called" << std::endl;
    }

    ~Watch()
    {
        std::cout << "Watch destructor called" << std::endl;
    }

    void showTime() const override
    {
        std::cout << "Watch Time: " << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << std::endl;
    }
};

class SmartWatch : public Watch
{
public:
    SmartWatch(int h, int m, int s) : Watch(h, m, s)
    {
        std::cout << "SmartWatch constructor called" << std::endl;
    }

    ~SmartWatch()
    {
        std::cout << "SmartWatch destructor called" << std::endl;
    }

    void showTime() const override
    {
        std::cout << "SmartWatch Time: " << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << std::endl;
    }
};

int main()
{
    std::cout << "---------------------------------------" << std::endl;
    CuckooClock cuckoo(10, 30, 0);
    cuckoo.showTime();

    std::cout << "---------------------------------------" << std::endl;
    WallClock wallClock(12, 45, 30);
    wallClock.showTime();

    std::cout << "---------------------------------------" << std::endl;
    Watch watch(8, 20, 50);
    watch.showTime();

    std::cout << "---------------------------------------" << std::endl;
    SmartWatch smartWatch(6, 15, 45);
    smartWatch.showTime();
    std::cout << "---------------------------------------" << std::endl;

    return 0;
}
