#ifndef UTILSDEF_H
#define UTILSDEF_H

#include <string>
#include <chrono>

#define START_TIMER auto stime = std::chrono::system_clock::now();
#define START_TIMER_NODEF stime = std::chrono::system_clock::now();

#define STOP_TIMER(msg) auto etime = std::chrono::system_clock::now();\
    std::cout<<__func__<<" "<<__LINE__<<" "<< (msg) <<" elasped:"<<std::chrono::duration_cast<std::chrono::milliseconds>(etime- stime).count()<<std::endl;
#define STOP_TIMER_NODEF(msg) etime = std::chrono::system_clock::now();\
    std::cout<<__func__<<" "<<__LINE__<<" "<< (msg) <<" elasped:"<<std::chrono::duration_cast<std::chrono::milliseconds>(etime- stime).count()<<std::endl;

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
