#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<numeric>
#define ll long long

using namespace std;
int const mod = 1000000007;
int dp[1000000005];
int b[100005];

int main() {
    int L, k;
    cin>>L>>k;
    for(int i=0; i<k; i++)
        cin>>b[i];
    memset(dp, 1, L);
    for(int i=0; i<k; i++) 
        dp[b[i]] = 0;
	
	return 0;
}
