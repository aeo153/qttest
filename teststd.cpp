#include "teststd.h"
#include <list>
#include <vector>
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

    int NumberOf100Scores(0);
    NumberOf100Scores = std::count(scores.begin(), scores.end(), 100);
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
