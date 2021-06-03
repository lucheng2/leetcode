#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
long long N, M;
vector<long long> trees;

bool check(long long h) {
    long long amount = 0;
    for(auto t: trees) {
        if(t>h)
            amount += t-h;
    }
    return amount>=M ? true: false;
}
int main() {
    cin>>N>>M;
    trees.resize(N);
    for(int i=0; i<N; i++) {
        cin>>trees[i];
    }
    int left=0, right=1e9;
    int ans=0;
    while(left <= right) {
        int mid = left + ((right-left)>>1);
        if(check(mid)) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else {
            right = mid -1;
        }
    }
    cout<<ans;
	return 0;
}
