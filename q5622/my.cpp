#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int finishTime = 0;
        for(int i=0; i<customers.size(); ++i) {
            finishTime = max(customers[i][0], finishTime) + customers[i][1];
            customers[i][1] = finishTime;
        }
        double sum = 0;
        for(int i=0; i<customers.size(); ++i) {
            sum += (customers[i][1] - customers[i][0]);
        }
        return (sum) / customers.size();
    }
};

int main() {
	
	return 0;
}
