#ifndef UTILSDEF_H
#define UTILSDEF_H

#include <string>
#include <chrono>

#define START_TIMER_VAR std::chrono::system_clock::time_point stime = std::chrono::system_clock::now();
#define START_TIMER stime = std::chrono::system_clock::now();

#define END_TIMER_VAR std::chrono::system_clock::time_point etime = std::chrono::system_clock::now();\
    std::cout<<__func__<<" spend time:"<<std::chrono::duration_cast<std::chrono::milliseconds>(etime- stime).count()<<std::endl;

#define END_TIMER etime = std::chrono::system_clock::now();\
    std::cout<<__func__<<" spend time:"<<std::chrono::duration_cast<std::chrono::milliseconds>(etime- stime).count()<<std::endl;

class timer {
public:
    clock_t start;
    clock_t end;
    std::string name;
    timer(const std::string & n) {
        start = clock();
        name = n;
    }
    ~timer() {
        end = clock();
        std::cout <<"time:  "<< name <<" "<<(end - start) << std::endl;
    }
};

#endif
