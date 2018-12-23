#ifndef GREED_H
#define GREED_H
#include "type.h"

class greed{
public:
    // constructor
    greed(vector<facility> facilities, vector<customer> customers, int facilityNum, int customerNum){
        this->facilities.assign(facilities.begin(), facilities.end());
        this->customers.assign(customers.begin(), customers.end());
        this->facilityNum = facilityNum;
        this->customerNum = customerNum;
    }
    
    void exec(int);
    
    vector<facility> getFacilities(){
        return this->facilities;
    }

    vector<customer> getCustomers(){
        return this->customers;
    }

private:
    vector<facility> facilities;
    vector<customer> customers;
    int facilityNum;
    int customerNum;
};

#endif