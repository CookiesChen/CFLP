#ifndef HILL_CLIMB_H
#define HILL_CLIMB_H
#include "type.h"

class hillClimb{
public:
    // constructor
    hillClimb(vector<facility> facilities, vector<customer> customers, int facilityNum, int customerNum){
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
};

#endif