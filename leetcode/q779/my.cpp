#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1)
            return 0;
        if(K <= (1<<(N-2)))
            return kthGrammar(N-1, K);
        else 
            return kthGrammar(N-1, K - (1<<(N-2))) ^ 1;
    }
};

int main() {
	
	return 0;
}
