#ifndef TYPE_H
#define TYPE_H
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct facility{
    int capacity; // 容量
    int cost;     // 费用
    bool isopen;  // 是否已经开启
    int count;    // 客户用户数量
    facility(int capacity, int cost){
        this->capacity = capacity;
        this->cost = cost;
        this->isopen = false;
        this->count = 0;
    }
};

struct customer{
    int demand;
    vector<int> assignment_cost;
    bool isassign;
    int fid; // 被分配的工厂
};

#endif