#pragma once

#include <iostream>
#include <chrono>
#include <ctime>

class Timer{
public:

    Timer(){
        _start = std::chrono::system_clock::now();
    }


    Timer(std::string & name):name_(name){
        _start = std::chrono::system_clock::now();
    }
    void restart(){
        _start = std::chrono::system_clock::now();
    }

    double elapsed_ms()
    {
        _end = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
    }


    double elapsed_micro()
    {
        _end = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
    }


    double elapsed_ns()
    {
        _end = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();
    }


    void print_timer_ms(){
        std::cout << name_ << " " << elapsed_ms() << std::endl;
    }

    std::chrono::time_point<std::chrono::system_clock> _start, _end;

    std::string name_ = "Timer";
};
