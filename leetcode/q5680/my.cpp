#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1;
        for(int i=0; i<points.size(); i++) {
            if(points[i][0] == x || points[i][1] == y) {
                if(index < 0)
                    index = i;
                else {
                    if(abs(points[i][0] - x) + abs(points[i][1] - y) < abs(points[index][0] -x) + abs(points[index][1] -y))
                        index = i;
                }
            }
        }
        return index;
    }
};


int main() {
	
	return 0;
}
