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
    facility(int capacity, int cost){
        this->capacity = capacity;
        this->cost = cost;
    }
};

struct customer{
    int demand;
    vector<int> assignment_cost;
};

vector<facility> facilities;
vector<customer> customers;

int customerNum = 0;
int facilityNum = 0;

int main(){
    getInput();
   
    return 0;
}

void getInput(){
    ifstream fin;
    fin.open("Instances/p58");
    string s;
    fin >> s;
    facilityNum = atoi(s.c_str());
    fin >> s;
    customerNum = atoi(s.c_str());
    for(int i = 0; i < facilityNum; i++){
        fin >> s;
        int capacity = atoi(s.c_str());
        fin >> s;
        int cost = atoi(s.c_str());
        facilities.push_back(facility(capacity, cost));
    }
    for(int i = 0; i < customerNum; i++){
        customers.push_back(customer());
        fin >> s;
        if(s[s.length()-1] == '.') s = s.substr(0, s.length()-1);
        customers[i].demand = atoi(s.c_str());
    }

    for(int i = 0; i < customerNum; i++){
        for(int j = 0; j < facilityNum; j++){
            fin >> s;
            if(s[s.length()-1] == '.') s = s.substr(0, s.length()-1);
            customers[i].assignment_cost.push_back(atoi(s.c_str()));
        }
    }
    for(int i = 0; i < customerNum; i++){
        cout << customers[i].demand << endl;
        for(int j = 0; j < facilityNum; j++){
            cout << customers[i].assignment_cost[j] << " ";
        }
        cout << endl;
    }
}