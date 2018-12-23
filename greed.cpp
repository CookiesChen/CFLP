#include "greed.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

void greed::exec(int id){
    int not_assign = customerNum;
    int result = 0;
    clock_t start = clock();
    while(not_assign > 0){
        int minEvaluate = -1;
        int indexC = -1;
        int indexF = -1;
        int minCost = -1;
        for(int i = 0; i < customerNum; i++){
            // 顾客未被分配
            if(!customers[i].isassign){
                for(int j = 0; j < facilityNum; j++){
                    // 顾客可被分配到工厂  
                    if(facilities[j].capacity - customers[i].demand >= 0){
                        int cost = 0;
                        if(!facilities[j].isopen) cost += facilities[j].cost;
                        cost += customers[i].assignment_cost[j];
                        if(indexC == -1 || (cost / customers[i].demand) < minEvaluate){
                            indexC = i;
                            indexF = j;
                            minEvaluate = (cost / customers[i].demand);
                            minCost = cost;
                        }
                    }
                }
            }
        }
        result += minCost;
        customers[indexC].isassign = true;
        customers[indexC].fid = indexF;
        facilities[indexF].isopen = true;
        facilities[indexF].capacity -= customers[indexC].demand;
        facilities[indexF].count++;
        not_assign--;
    }
    clock_t end = clock();
    ofstream fout;
    string path = "test/greed/p";
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