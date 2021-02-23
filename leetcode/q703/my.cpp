#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto n: nums)
            add(n);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};

int main() {
	
	return 0;
}
