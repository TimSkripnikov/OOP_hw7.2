#pragma once

#include <iostream>
#include <exception>

class SimpleWatch;
class Watch;

class InvalidTimeException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid time values!";
    }
};

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
    static unsigned count;
    void Normalize();

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time &t);
    ~Time();

    static unsigned GetCount() noexcept;

    void SetHours(int h);
    void SetMinutes(int m);
    void SetSeconds(int s);

    int GetHours() const noexcept;
    int GetMinutes() const noexcept;
    int GetSeconds() const noexcept;

    int ToSeconds() const noexcept;
    void PrintTime() const noexcept;

    Time operator+(const Time &other) const noexcept;
    Time operator-(const Time &other) const noexcept;
    Time &operator+=(const Time &other) noexcept;
    Time &operator-=(const Time &other) noexcept;
    Time &operator=(const Time &other) noexcept;
    bool operator==(const Time &other) const noexcept;

    friend class SimpleWatch;
    friend class Watch;
};
