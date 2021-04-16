#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        long long count = 0;
        int cir = min(min(xPos, yPos), min(num-1-xPos, num-1-yPos));
        if(cir > 0)
            count = 4*(num-1)*cir - 8*(cir-1)/2;
        if(cir == xPos)
            count += yPos - cir;
        else if(cir == num-1-yPos)
            count += (num-2*cir-1) + (xPos - cir);
        else if(cir == num-1-xPos)
            count += (num-2*cir-1)*2 + (num-2*cir-1-yPos);
        else
            count += (num-2*cir-1)*3 + (num-2*cir-1-xPos);
        return count % 9 + 1;
    }
};

int main() {
    Solution s;
    int ans = s.orchestraLayout(3, 0, 2);
	
	return 0;
}
