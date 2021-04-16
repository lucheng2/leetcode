#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<numeric>
#include<climits>

using namespace std;
int N;

int main() {
    scanf("%d", &N);
    unordered_map<int, vector<long long>> hm;
    int limit = 0;
    long long i = 1;
    int sum;
    while(limit<N) {
        sum = 0;
        long long tmp = i;
        while(tmp) {
            sum += tmp % 10;
            tmp = tmp/ 10;
        }
        hm[sum].push_back(i);
        int size = hm[sum].size();
        limit = max(limit, size);
        i++;
    }
    for(int i=0; i<hm[sum].size(); ++i) {
        printf("%lld,", hm[sum][i]);
    }
    printf("\n");
    long long int ans = accumulate(hm[sum].begin(), hm[sum].end(), 0);
    printf("%lld", ans);
	return 0;
}
