#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int total = 0;
        for(int i=0; i<n; i++)
            total += customers[i] * (1 - grumpy[i]);

        int increase = 0;
        for(int i=0; i<X; ++i) 
            increase += customers[i] * grumpy[i];

        int maxIncrease = increase;

        for(int i=X; i<n; ++i) {
            increase = increase - customers[i-X]* grumpy[i-X] + customers[i]*grumpy[i];
            maxIncrease = max(maxIncrease, increase);
        }
        return total + maxIncrease;
    }
};

int main() {
	
	return 0;
}
