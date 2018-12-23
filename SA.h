#ifndef SA_H
#define SA_H

#include "type.h"

class sa{
public:
    // constructor
    sa(vector<facility> facilities, vector<customer> customers, int facilityNum, int customerNum){
        this->facilities.assign(facilities.begin(), facilities.end());
        this->customers.assign(customers.begin(), customers.end());
        this->facilityNum = facilityNum;
        this->customerNum = customerNum;
    }
    
    void exec(int);
    
    void getRandom();

    int getCost(const vector<customer> &, const vector<facility> &);

    // 邻域操作
    vector<customer> expel(vector<facility> &);
    vector<customer> swapTwo(vector<facility> &);

private:
    vector<facility> facilities;
    vector<customer> customers;
    int facilityNum;
    int customerNum;
    float T = 2000; // 初温
    float T_end = 0.001; //末温
    float q = 0.99; // 降温系数
};

#endif