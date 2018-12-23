#include "hill_climb.h"

#include <ctime>
#include <cstdlib>
#include <fstream>

void hillClimb::exec(int id){
    int MAX_ITERATION = 1000;
    int iteration = 0;
    // 随机初始解
    //getRandom();
    int result = getCost(customers, facilities);
    clock_t start = clock();
    while(iteration < MAX_ITERATION){
        vector<facility> tempFacilities;
        tempFacilities.assign(facilities.begin(), facilities.end());
        vector<customer> tempCustomers;
        tempCustomers.assign(customers.begin(), customers.end());
        int minCost = result;
        for(int i = 0; i < 10; i++){
            // 邻域操作驱逐客户
            vector<facility> newFacilityies;
            newFacilityies.assign(facilities.begin(), facilities.end());
            vector<customer> newCustomers = expel(newFacilityies);
            int cost = getCost(newCustomers, newFacilityies);
            if(cost < minCost){
                minCost = cost;
                tempFacilities.swap(newFacilityies);
                tempCustomers.swap(newCustomers);
            }
            // 邻域操作交换客户
            vector<facility> newFacilities2;
            newFacilities2.assign(facilities.begin(), facilities.end());
            vector<customer> newCustomers2 = swapTwo(newFacilities2);
            int cost1 = getCost(newCustomers2, newFacilities2);
            if(cost1 < minCost){
                minCost = cost1;
                tempFacilities.swap(newFacilities2);
                tempCustomers.swap(newCustomers2);
            }
        }
        if(minCost < result){
            result = minCost;
            customers.swap(tempCustomers);
            facilities.swap(tempFacilities);
            iteration = 0;
        }
        iteration++;
        // cout << "current cost: "  << result << endl;
    }
    clock_t end = clock();
    ofstream fout;
    string path = "test/hc/p";
    fout.open(path + to_string(id));
    for(int i = 0; i < customerNum; i++) {
        cout << customers[i].fid << " ";
        fout << customers[i].fid << " ";
    }
    cout << endl;
    fout << '\n';
    int opencost = 0;
    for(int i = 0; i < facilityNum; i++){
        cout << facilities[i].isopen << " ";
        fout << facilities[i].isopen << " ";
    }
    cout << endl;
    fout << endl;
    cout << "Time: " << (double)(end-start)/CLOCKS_PER_SEC << "s" << endl;
    fout << "Time: " << (double)(end-start)/CLOCKS_PER_SEC << "s" << '\n';
    cout << "Total cost: "  << result << endl;
    fout << "Total cost: "  << result;
    fout.close();
}

void hillClimb::getRandom(){
    for(int i = 0; i < customerNum; i++){
        while(true){
            int randomF = rand() % facilityNum;
            if(customers[i].demand <= facilities[randomF].capacity){
                customers[i].fid = randomF;
                facilities[randomF].capacity -= customers[i].demand;
                facilities[randomF].count++;
                if(!facilities[randomF].isopen){
                    facilities[randomF].isopen = true;
                }
                break;
            }
        }
    }
}

int hillClimb::getCost(const vector<customer> &customers, const vector<facility> &facilities){
    int cost = 0;
    for(int i = 0; i < customerNum; i++){
        int fid = customers[i].fid;
        cost += customers[i].assignment_cost[fid];
    }
    for(int i = 0; i < facilityNum; i++){
        if(facilities[i].isopen){
            cost += facilities[i].cost;
        }
    }
    return cost;
}

vector<customer> hillClimb::expel(vector<facility> & newFacilities){
    vector<customer> newCustomers;
    newCustomers.assign(customers.begin(), customers.end());
    int randomC = rand() % customerNum;
    int flag = 0;
    while(true){
        int randomF = rand() % facilityNum;
        if(newCustomers[randomC].demand <= newFacilities[randomF].capacity){
            // 原来的工厂
            int fid = newCustomers[randomC].fid;
            newFacilities[fid].capacity += newCustomers[randomC].demand;
            newFacilities[fid].count--;
            if(newFacilities[fid].count == 0) newFacilities[fid].isopen = false;
            // 新的工厂
            newCustomers[randomC].fid = randomF;
            newFacilities[randomF].capacity -= newCustomers[randomC].demand;
            newFacilities[randomF].count++;
            if(!newFacilities[randomF].isopen){
                newFacilities[randomF].isopen = true;
            }
            break;
        }
    }
    return newCustomers;
}

vector<customer> hillClimb::swapTwo(vector<facility> & facilities){
    vector<customer> newCustomers;
    newCustomers.assign(customers.begin(), customers.end());
    int randomC1 = rand() % customerNum;
    int flag = 0;
    while(true){
        int randomC2 = rand() % customerNum;
        int flag = 0;
        if(newCustomers[randomC2].demand <= newCustomers[randomC1].demand + facilities[customers[randomC1].fid].capacity && 
        newCustomers[randomC1].demand <= newCustomers[randomC2].demand + facilities[customers[randomC2].fid].capacity){
            // 交换
            int fid1 = newCustomers[randomC1].fid;
            int fid2 = newCustomers[randomC2].fid;
            facilities[fid1].capacity += newCustomers[randomC1].demand - newCustomers[randomC2].demand;
            facilities[fid2].capacity += newCustomers[randomC2].demand - newCustomers[randomC1].demand;
            newCustomers[randomC1].fid = fid2;
            newCustomers[randomC2].fid = fid1;
            break;
        }
    }
    return newCustomers;
}