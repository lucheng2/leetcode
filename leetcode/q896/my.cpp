#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(A[0] == A[n-1]) {
            for(int i=1; i<n; ++i)
                if(A[i-1] != A[i])
                    return false;
        }
        else if(A[0] < A[n-1]) {
            for(int i=1; i<n; ++i)
                if(A[i-1] > A[i])
                    return false;
        }
        else {
            for (int i=1; i<n; ++i)
                if(A[i-1] < A[i])
                    return false;
        }
        return true;

    }
};

int main() {
	
	return 0;
}
