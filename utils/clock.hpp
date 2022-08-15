/*
** EPITECH PROJECT, 2022
** indie
** File description:
** clock
*/


#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>

using timePoint = std::chrono::time_point<std::chrono::system_clock>;

namespace indie
{
    class Clock
    {
    public:
        Clock() {};
        ~Clock() {};

        timePoint getClockStart()
        {
            return (_start);
        };
        timePoint getClockEnd()
        {
            return (_end);
        };

        void start()
        {
            _start = std::chrono::system_clock::now();
        };
        void restart()
        {
            _start = std::chrono::system_clock::now();
        };

        float getElapsedTime()
        {
            _end = std::chrono::system_clock::now();
            _elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();

            return (_elapsedTime);
        };

    protected:
    private:
        timePoint _start;
        timePoint _end;
        uint64_t _elapsedTime;
    };
}

#endif /* !CLOCK_HPP_ */
