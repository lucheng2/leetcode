#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int res = 0;
        for(int i=0; i<3; i++)
            if(guess[i] == answer[i])
                res++;
        return res;
    }
};

int main() {
	
	return 0;
}
