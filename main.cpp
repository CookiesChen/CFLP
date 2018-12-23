#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include "type.h"
#include "greed.h"
#include "hill_climb.h"
#include "SA.h"

using namespace std;

vector<facility> facilities;
vector<customer> customers;

int customerNum = 0;
int facilityNum = 0;

void getInput(string path);

int main(){
    srand((int)time(0));
    string path = "Instances/p";
    for(int i = 1; i <= 71; i++){
        cout << "Test " << i << endl;
        getInput(path + to_string(i));
        /* 贪心算法 */
        greed mygreed(facilities, customers, facilityNum, customerNum);
        mygreed.exec(i);

        // hillClimb myHillClimb(mygreed.getFacilities(), mygreed.getCustomers(), facilityNum, customerNum);
        // myHillClimb.exec(i);

        // sa sa(mygreed.getFacilities(), mygreed.getCustomers(), facilityNum, customerNum);
        // sa.exec(i);
    }

    return 0;
}

// 获取输入
void getInput(string path){
    ifstream fin;
    fin.open(path);
    float s;
    fin >> s;
    facilityNum = s;
    fin >> s;
    customerNum = s;

    customers.clear();
    facilities.clear();

    for(int i = 0; i < facilityNum; i++){
        fin >> s;
        int capacity = s;
        fin >> s;
        int cost = s;
        facilities.push_back(facility(capacity, cost));
    }

    for(int i = 0; i < customerNum; i++){
        customers.push_back(customer());
        fin >> s;
        customers[i].demand = s;
        customers[i].isassign = false;
    }

    for(int i = 0; i < facilityNum; i++){
        for(int j = 0; j < customerNum; j++){
            fin >> s;
            customers[j].assignment_cost.push_back(s);
        }
    }

}