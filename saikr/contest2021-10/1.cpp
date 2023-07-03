#include<vector>
#include<iostream>

using namespace std;

bool check(vector<int> &A, int ans) {
    int n = A.size();
    int cnt = 0;
    int cnt2 = 0;
    for(int i=1; i<n; i+=2) {
        if(i+1<n) {
            if(!(A[i-1] > A[i] && A[i] < A[i+1])) {
                cnt++;
            }
            if(!(A[i-1] < A[i] && A[i] > A[i+1])) {
                cnt2++;
            }
        }
        else {
            if(!(A[i-1] > A[i])) {
                cnt++;
            }
            if(!(A[i-1] < A[i])) {
                cnt2++;
            }
        }
    }
    if(cnt <=ans || cnt2 <= ans)
        return true;
    return false;
}

int solution(vector<int> &A) {
    int lmt = 100000;
    int l=0, r=lmt, ans=lmt;
    while(l<=r) {
        int m = (l+r)/2;
        if(check(A, m)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
}


