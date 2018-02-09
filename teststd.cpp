﻿#include "teststd.h"
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <memory>
#include <xfunctional>
#include <stdio.h>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include <QDebug>
#include "ClassA.h"
#include <chrono>

using namespace std;

TestStd::TestStd()
{

}

inline bool eq100(int value)
{
    return value == 100;
}

inline bool lessThan100(int value)
{
    return value < 100;
}

inline bool lessThan(int value1, int value2)
{
    return value1 < value2;
}

inline void printItem(int value)
{
    std::cout<< value << std::endl;
}

struct UserInfo
{
    UserInfo(int id, const std::string & name)
    {
        uid = id;
        uname = name;
    }

    int uid;
    std::string uname;
};

class UserFinder
{
public:
    UserFinder(int uid)
        :m_uid(uid)
    {

    }

    bool operator()(const UserInfo & uInfo)
    {
        return uInfo.uid == m_uid;
    }

private:
    int m_uid = 0;
};

struct UserCompare : public std::binary_function<UserInfo, UserInfo, bool>
{
    bool operator() (const UserInfo & lhs, const UserInfo & rhs) const
    {
        return lhs.uid < rhs.uid;
    }
};

struct UserComparePtr : public std::binary_function<const UserInfo *, const UserInfo *, bool>
{
    bool operator() (const UserInfo * lhs, const UserInfo * rhs) const
    {
        return lhs->uid < rhs->uid;
    }
};

struct UserCompareSharePtr : public std::binary_function<const std::shared_ptr<UserInfo>, const std::shared_ptr<UserInfo> &, bool>
{
    bool operator() (const std::shared_ptr<UserInfo> & lhs, const std::shared_ptr<UserInfo> & rhs) const
    {
        return lhs->uid < rhs->uid;
    }
};

void TestStd::testList()
{
    std::vector<int> scores;
    std::cout<< "capacity:" << scores.capacity()<<std::endl;

    scores.push_back(100);
    scores.push_back(80);
    scores.push_back(45);
    scores.push_back(75);
    scores.push_back(99);
    scores.push_back(100);
    std::cout<< "capacity:" << scores.capacity()<<" "<<scores.size()<< " " << scores.max_size() <<std::endl;

    auto NumberOf100Scores = std::count(scores.begin(), scores.end(), 100);
    std::cout << "There were " << NumberOf100Scores << " scores of 100" << std::endl;
    NumberOf100Scores = std::count_if(scores.begin(), scores.end(), eq100);
    std::cout << "There were " << NumberOf100Scores << " scores of 100" << std::endl;
    NumberOf100Scores = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << "accumulate " << NumberOf100Scores << std::endl;

    std::vector<int>::iterator iter = std::find(scores.begin(), scores.end(), 100);
    std::cout << *iter << std::endl;
    iter = std::find_if(scores.begin(), scores.end(), lessThan100);
    std::cout <<"find less than 100:" << *iter << std::endl;

    iter = std::min_element(scores.begin(), scores.end());
    std::cout <<"min element:"<< *iter << std::endl;
    iter = std::max_element(scores.begin(), scores.end());
    std::cout <<"max element:"<< *iter << std::endl;

    std::replace(scores.begin(), scores.end(), 80, 81);

    std::reverse(scores.begin(), scores.end());
    std::cout<<"reversed:"<<std::endl;
    std::for_each(scores.begin(), scores.end(), printItem);
    std::cout<<std::endl;

    std::for_each(scores.begin(), scores.end(), printItem);
    std::cout<<std::endl;

    //scores.sort();
    std::sort(scores.begin(), scores.end(), std::less<int>() );
    std::for_each(scores.begin(), scores.end(), printItem);
    std::cout<<std::endl;

    iter = std::min_element(scores.begin(), scores.end());
    std::cout << *iter << std::endl;

    std::list<int> iList;
    std::copy(scores.begin(), scores.end(), std::inserter(iList, iList.begin()));
    std::copy(scores.begin(), scores.end(), std::inserter(iList, iList.begin()));
    std::copy(scores.begin(), scores.end(), std::inserter(iList, iList.begin()));
    std::cout<<"copy iterator"<< std::endl;
    std::for_each(iList.begin(), iList.end(), printItem);


    //list find_if
    std::list<UserInfo> userList;
    userList.push_back(UserInfo(2, "hanmm"));
    userList.push_back(UserInfo(4,"lilei"));
    userList.push_back(UserInfo(1,"tom"));
    userList.push_back(UserInfo(7,"kate"));

    const auto & uiter = std::find_if(userList.begin(), userList.end(), UserFinder(4));
    std::cout<<"user finder:"<<(*uiter).uid<<" "<<(*uiter).uname<<std::endl;


    scores.push_back(100);
    scores.push_back(80);
    scores.push_back(45);
    scores.push_back(75);
    scores.push_back(99);
    scores.push_back(100);

    std::set<int, std::greater<int> > intset;
    intset.insert(3);
    intset.insert(2);
    intset.insert(9);
    intset.insert(5);
    for ( auto iter : intset )
    {
        std::cout<< iter << std::endl;
    }

    std::set<UserInfo, UserCompare> user_set;
    user_set.insert(UserInfo(1, "lilei"));
    user_set.insert(UserInfo(4, "hanmeimei"));
    user_set.insert(UserInfo(3, "tom"));
    user_set.insert(UserInfo(2, "lily"));
    user_set.insert(UserInfo(6, "lucy"));
    for ( std::set<UserInfo>::iterator iter = user_set.begin(); iter != user_set.end(); iter++ )
    {
        std::cout<< (*iter).uid << " "<< (*iter).uname << std::endl;
    }

    std::set<std::shared_ptr<UserInfo>, UserCompareSharePtr> usershareptr_set;
    usershareptr_set.insert(std::shared_ptr<UserInfo>(new UserInfo(4, "hanmeimei")));
    usershareptr_set.insert(std::shared_ptr<UserInfo>(new UserInfo(5, "lucy")));
    usershareptr_set.insert(std::shared_ptr<UserInfo>(new UserInfo(1, "lilei")));
    usershareptr_set.insert(std::shared_ptr<UserInfo>(new UserInfo(3, "tom")));
    usershareptr_set.insert(std::shared_ptr<UserInfo>(new UserInfo(2, "lily")));
    for ( std::set<std::shared_ptr<UserInfo> >::iterator iter = usershareptr_set.begin(); iter != usershareptr_set.end(); iter++ )
    {
        std::cout<< (*iter)->uid << " "<< (*iter)->uname << std::endl;
    }

    std::map<int, UserInfo> intUserMap;
    intUserMap.insert(std::map<int, UserInfo>::value_type(5, UserInfo(5, "Lucy")));
}

void TestStd::testVector()
{
    std::vector<int> scores;
    std::cout<< "capacity:" << scores.capacity()<<std::endl;

    scores.resize(6);
    std::cout<< "capacity:" << scores.capacity()<<endl;

    scores[0] = 100;
    scores[1] = 80;
    scores[2] = 45;
    std::cout<< "capacity:" << scores.capacity()<<" "<<scores.size()<< " " << scores.max_size() <<std::endl;
}

void TestStd::TestCopy()
{
    //copy list to list
    std::list<std::string> oldList;
    std::list<std::string> newList;
    oldList.push_back("test1");
    oldList.push_back("test2");
    oldList.push_back("test3");

    std::copy(oldList.begin(), oldList.end(), std::back_inserter(newList));

    //copy vector to vector
    std::vector<std::string> oldVector;
    std::vector<std::string> newVector;
    oldVector.push_back("test4");
    oldVector.push_back("test5");
    oldVector.push_back("test6");
    std::copy(oldVector.begin(), oldVector.end(), std::back_inserter(newVector));

    //copy list to vector
    std::list<std::string> list1;
    std::vector<std::string> vector1;
    list1.push_back("test7");
    list1.push_back("test8");
    list1.push_back("test9");

    vector1.push_back("vector1");
    std::copy(list1.begin(), list1.end(), std::back_inserter(vector1));

    //copy vector to list
    std::list<std::string> vector2;
    std::vector<std::string> list2;
    vector2.push_back("test10");
    vector2.push_back("test11");
    vector2.push_back("test12");
    std::copy(vector2.begin(), vector2.end(), std::back_inserter(list2));
}

void TestStd::testStringStream()
{
    std::stringstream osstr;
    osstr<<1.0<<" "<<1.0<<" "<<0.5;
    std::string aStr = osstr.str();
    std::cout<<aStr<<endl;

    std::stringstream isstr(aStr);
    float r, g, b;
    isstr>>r;
    isstr>>g;
    isstr>>b;
    std::cout<<r<<","<<g<<","<<b<<endl;
}

template<class T>
void getTypeName(const T & val)
{
    std::cout<<val<<","<<typeid(T).name()<< ",type compare:"<<(typeid(T).hash_code() == typeid(int).hash_code())<<std::endl;
}

void TestStd::testTypeId()
{
    int i = 0;
    getTypeName<int>(i);//int type compare:1

    bool b = false;
    getTypeName<bool>(b);//bool type compare:0

    E_ColorType clrType = e_red;
    getTypeName<E_ColorType>(clrType);
}

void TestStd::testTuple()
{
    std::tuple<std::string, int, float, double> tp1 = std::make_tuple(std::string("tupletest"), 1, 2.0f, 3.0);
    std::cout<<std::get<0>(tp1)<<" "<<std::get<1>(tp1)<<" "<<std::get<2>(tp1)<<" "<<std::get<3>(tp1)<<endl;
    //tupletest 1 2 3

    int a = 4, b = 5, c = 6;
    auto tp2 = std::tie(a, b, c);//creates a tuple of lvalue references,元素必须是变量,std::tie(3,4,5)会编译出错

    int d, e, g;
    std::tie(d, e, g) = tp2;//unpacks a tuple into individual objects

    std::cout<<"d="<<d<<" e="<<e<<" g="<<g<<endl;
    //d=4 e=5 g=6

    auto tp3 = std::tuple_cat(tp1, tp2, std::make_pair(7, 8));
    std::cout<< std::tuple_size<decltype(tp3)>::value <<endl;
    //9

    std::cout<<typeid(decltype(std::tuple_size<decltype(tp3)>::value)).name()<<endl;
    //unsigned __int64

    const int i = 4;
    std::cout<<std::get<i>(tp3)<<endl;//std::get<i>(tp3),i必须是常量
    //4
}

void TestStd::checkFileExists()
{
    std::string fontPath = "C:/Windows/Fonts/msyh.ttc";
    std::ifstream ifstrm1(fontPath);
    if (!ifstrm1)
    {
        std::cout<<fontPath<<" not exists."<<std::endl;
    }

    fontPath = "C:/Windows/Fonts/msyh.ttf";
    std::ifstream ifstrm2(fontPath);
    if (!ifstrm2)
    {
        std::cout<<fontPath<<" not exists."<<std::endl;
    }
}

void TestStd::testMemory()
{
    int num = 100;
    unsigned char * unchar = new unsigned char[num];
    memset(unchar, 5, sizeof(unsigned char) * num);
    for (int i = 0; i < num; i++)
    {
        qDebug()<<unchar[i];
    }
}

void TestStd::testErase()
{
    std::list<int> iList;
    iList.push_back(3);
    iList.push_back(4);
    iList.push_back(3);
    iList.push_back(2);
    iList.push_back(1);
    iList.push_back(4);
    iList.push_back(2);

    iList.erase(std::remove(iList.begin(), iList.end(), 3), iList.end());
    for_each(iList.begin(), iList.end(), printItem);
    std::cout<<__func__<<std::endl;
    iList.erase(std::remove_if(iList.begin(), iList.end(), [&](int val)->bool{return val == 2;}), iList.end());
    for_each(iList.begin(), iList.end(), printItem);
}

std::vector<std::function< float(const float &, const float &) > > funs;
std::vector<std::function< void(void) > > voidFuns;
float add(const float & a, const float & b) { return a + b; }

void TestStd::createfun()
{
    //普通函数
    std::function<float(const float &, const float &)> f_fun = add;

    //bind 普通函数（固定参数）
    auto f_bind_fun = std::bind(add, 1, 1);

    //bind 普通函数（传入参数）
    auto f_bind_placeholders = std::bind(add, std::placeholders::_1, std::placeholders::_2);

    //bind 对象函数
    ClassA ca;
    auto f_bind_class_obj = std::bind(&ClassA::add, ca, std::placeholders::_1, std::placeholders::_2);

    //bind 对象指针函数
    auto f_bind_class_ptr = std::bind(&ClassA::add, &ca, std::placeholders::_1, std::placeholders::_2);

    //仿函数
    Functor fun_obj;
    auto f_functor = fun_obj;

    //匿名函数(lambda函数)
    float d = 1000;
    auto f_lambda = [&d](const float &/*a*/ , const float &b)->float { return d + b; };

    funs.push_back(f_fun);
    funs.push_back(f_bind_fun);
    funs.push_back(f_bind_placeholders);
    funs.push_back(f_bind_class_obj);
    funs.push_back(f_bind_class_ptr);
    funs.push_back(f_functor);
    funs.push_back(f_lambda);

    ClassA * pac = new ClassA;
    auto f_void = std::bind(&ClassA::printSelf, pac);
    voidFuns.push_back(f_void);
    f_void();
}

void TestStd::execFun(const std::vector<std::function<float (const float &, const float &)> > funs)
{
    int i = 10;
    for ( const auto & aFun : funs )
    {
        float c = aFun(0, i);
        qDebug()<<QString("0+%1=%2").arg(QString::number(i), QString::number(c));
        i++;
    }
}

void TestStd::testNumericLimits()
{
    std::cout<<"int min:"<<std::numeric_limits<int>::min()<<std::endl;//int min:-2147483648
    std::cout<<"int max:"<<std::numeric_limits<int>::max()<<std::endl;//int max:2147483647
    std::cout<<"int infinity:"<<std::numeric_limits<int>::infinity()<<std::endl;//int infinity:0

    std::cout<<"uint min:"<<std::numeric_limits<unsigned int>::min()<<std::endl;//uint min:0
    std::cout<<"uint max:"<<std::numeric_limits<unsigned int>::max()<<std::endl;//uint max:4294967295

    std::cout<<"double min:"<<std::numeric_limits<double>::min()<<std::endl;//double min:2.22507e-308
    std::cout<<"double max:"<<std::numeric_limits<double>::max()<<std::endl;//double max:1.79769e+308
    std::cout<<"double infinity:"<<std::numeric_limits<double>::infinity()<<std::endl;//double infinity:inf

    std::cout<<"float min:"<<std::numeric_limits<float>::min()<<std::endl;//float min:1.17549e-38
    std::cout<<"float max:"<<std::numeric_limits<float>::max()<<std::endl;//float max:3.40282e+38
    std::cout<<"float infinity:"<<std::numeric_limits<float>::infinity()<<std::endl;//float infinity:inf

    double maxDbl = std::numeric_limits<float>::max();
    if ( maxDbl >= std::numeric_limits<float>::max() )
    {
        std::cout<<"compare double max"<<std::endl;
    }

    std::cout<<"int min by macro:"<<INT_MIN<<std::endl;
    std::cout<<"int max by macro:"<<INT_MAX<<std::endl;
}

void TestStd::timeClock()
{
    std::chrono::system_clock::time_point begin_time = std::chrono::system_clock::now();

    for ( int i = 0; i < 1e5; i++ )
    {
        std::cout<<__func__<<" "<<i<<std::endl;
    }

    std::chrono::system_clock::time_point end_time = std::chrono::system_clock::now();

    std::cout<<__func__<<" spend time:"<<std::chrono::duration_cast<std::chrono::milliseconds>(end_time- begin_time).count()<<std::endl;

    std::cout<<__func__<<" time_t:"<<std::chrono::system_clock::to_time_t(begin_time)<<std::endl;
}
