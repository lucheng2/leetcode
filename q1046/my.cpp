#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s: stones)
            pq.push(s);

        int a,b;
        while(pq.size()>1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            if(a-b>0) {
                pq.push(a-b);
            }
        }
        return pq.size()==0? 0: pq.top();
    }
};

int main() {
	
	return 0;
}
