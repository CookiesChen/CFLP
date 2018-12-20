#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "utils.h"

using namespace std;

struct facility{
    int capacity;
    int cost;
    facility(){
        capacity = 0;
        cost = 0;
    }
};

struct customer{
    vector<int> demand;
    vector<int> assignment_cost;
};

vector<facility> facilities;
int customerNum = 0;
int facilityNum = 0;

int main(){
    ifstream fin;
    fin.open("Instances/p1");
    string s;
    getline(fin,s);
    getCFCount(s);
    printf("Facility: %d, Customers: %d", facilityNum, customerNum);
    for(int i=0; i < facilityNum; i++){
        getline(fin,s);
        getFacility(s);
    }
    string data = "";
    while(getline(fin,s)) {
        data += s; 
    }
    getCustomer(data);
    return 0;
}

// 获取客户数量和工厂数量
void getCFCount(string s){
    while(s[0] == ' '){
        s = s.substr(1, s.length()-1);
    }
    int flag = 0;
    for(int i = 0; i < s.length(); i++ ){
        if(s[i] == ' '){
            flag = i;
            string cstr = s.substr(0, i+1);
            facilityNum = atoi(cstr.c_str());
        }
    }
    s = s.substr(flag, s.length()-flag);
    while(s[0] == ' '){
        s = s.substr(1, s.length()-1);
    }
    for(int i = 0; i < s.length(); i++ ){
        if(s[i] == '\n' || s[i] == ' ' || i == s.length()-1){
            string cstr = s.substr(0, i+1);
            customerNum = atoi(cstr.c_str());
        }
    }
}

// 获取工厂
void getFacility(string s){
    facility myfacility;
    while(s[0] == ' '){
        s = s.substr(1, s.length()-1);
    }
    int flag = 0;
    for(int i = 0; i < s.length(); i++ ){
        if(s[i] == ' '){
            flag = i;
            string cstr = s.substr(0, i+1);
            myfacility.capacity = atoi(cstr.c_str());
        }
    }
    s = s.substr(flag, s.length()-flag);
    while(s[0] == ' '){
        s = s.substr(1, s.length()-1);
    }
    for(int i = 0; i < s.length(); i++ ){
        if(s[i] == '\n' || s[i] == ' ' || i == s.length()-1){
            string cstr = s.substr(0, i+1);
            myfacility.cost = atoi(cstr.c_str());
        }
    }
    facilities.push_back(myfacility);
}

void 
