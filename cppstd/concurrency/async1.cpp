/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething (char c)
{
    // random-number generator (use c as seed to get different sequences)
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10,1000);
 
    // loop to print character after a random period of time
    for (int i=0; i<10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }

    return c;
}

int func1 ()
{
    return doSomething('.');
}

int func2 ()
{
    return doSomething('+');
}

double sum(double low, double up)
{
    double res = 0;
    for ( double i= low; i <= up; i++ )
    {
        res += i;
    }

    return res;
}

int main()
{
//    std::cout << "starting func1() in background"
//              << " and func2() in foreground:" << std::endl;

//    // start func1() asynchronously (now or later or never):
//    std::future<int> result1(std::async(func1));

//    int result2 = func2();    // call func2() synchronously (here and now)

//    // print result (wait for func1() to finish and add its result to result2
//    int result = result1.get() + result2;

//    std::cout << "\nresult of func1()+func2(): " << result
//              << std::endl;

    std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
    std::future<double> sum1 = std::async(std::launch::async, sum, 0, 5e7);
    std::future<double> sum2 = std::async(std::launch::deferred, sum, 5e7+1, 1e8);
    double sumres = sum1.get() + sum2.get();
//    double sumres = sum(0, 1e8);
    std::chrono::system_clock::time_point end_time = std::chrono::system_clock::now();
    std::cout << "\nspend time : " << std::chrono::duration_cast<std::chrono::microseconds>(end_time- start_time).count() << std::endl;
    std::cout << "sum result : " << sumres << std::endl;

}
