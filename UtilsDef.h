#ifndef UTILSDEF_H
#define UTILSDEF_H

#include <string>
#include <chrono>
#include <iostream>
#include <codecvt>

#include <locale>

#define START_TIMER auto stime = std::chrono::system_clock::now();
#define START_TIMER_NODEF stime = std::chrono::system_clock::now();

#define STOP_TIMER(msg) auto etime = std::chrono::system_clock::now();\
    std::cout<<__func__<<" "<<__LINE__<<" "<< (msg) <<" elasped:"<<std::chrono::duration_cast<std::chrono::milliseconds>(etime- stime).count()<<std::endl;
#define STOP_TIMER_NODEF(msg) etime = std::chrono::system_clock::now();\
    std::cout<<__func__<<" "<<__LINE__<<" "<< (msg) <<" elasped:"<<std::chrono::duration_cast<std::chrono::milliseconds>(etime- stime).count()<<std::endl;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define COUT_FUNC_INFO(msg) std::cout<<__FUNCTION__ <<" "<<__LINE__<<" "<<msg<<std::endl;
#define COUT_FUNC_ERROR(msg) std::cout<<RED<<__FUNCTION__ <<" "<<__LINE__<<" ---error:"<<msg<<std::endl;std::cout<<RESET;

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

//inline std::u16string to_utf16( std::string str ) // utf-8 to utf16
//{ return std::wstring_convert< std::codecvt_utf8_utf16<char16_t>, char16_t >{}.from_bytes(str); }
//
//inline std::string to_utf8( std::u16string str16 )
//{ return std::wstring_convert< std::codecvt_utf8_utf16<char16_t>, char16_t >{}.to_bytes(str16); }
//
//inline std::u32string to_utf32( std::string str )
//{ return std::wstring_convert< std::codecvt_utf8<char32_t>, char32_t >{}.from_bytes(str); }
//
//inline std::string to_utf8( std::u32string str32 )
//{ return std::wstring_convert< std::codecvt_utf8<char32_t>, char32_t >{}.to_bytes(str32); }
//
//inline std::wstring to_wchar_t( std::string str )
//{ return std::wstring_convert< std::codecvt_utf8<wchar_t>, wchar_t >{}.from_bytes(str); }
//
//inline std::string to_utf8( std::wstring wstr )
//{ return std::wstring_convert< std::codecvt_utf8<wchar_t>, wchar_t >{}.to_bytes(wstr); }

#endif
