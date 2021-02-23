#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int data[101][101];
int dp[101][101];
int R, C;

int main() {
    scanf("%d%d", &R, &C);
    for(int i=1; i<=R; ++i)
        for(int j=1; j<=C; ++j) {
            scanf("%d", &data[i][j]);
            dp[i][j] = 1;
        }
    multimap<int, pair<int, int>> mm;
    for(int i=1; i<=R; ++i)
        for(int j=1; j<=C; ++j) {
            mm.insert(make_pair(data[i][j], make_pair(i,j)));
        }
	
    for(auto it=mm.begin(); it!=mm.end(); ++it)
    {
        int i=it->second.first, j=it->second.second;
        if(i-1>=1 && data[i-1][j]<data[i][j])
            dp[i][j] = max(dp[i][j], dp[i-1][j]+1);
        if(i+1<=R && data[i+1][j]<data[i][j])
            dp[i][j] = max(dp[i][j], dp[i+1][j]+1);
        if(j-1>=1 && data[i][j-1]<data[i][j])
            dp[i][j] = max(dp[i][j], dp[i][j-1]+1);
        if(j+1<=C && data[i][j+1]<data[i][j])
            dp[i][j] = max(dp[i][j], dp[i][j+1] +1);
    }
    int ans = dp[1][1];
    for(int i=1; i<=R; ++i)
         for(int j=1; j<=C; ++j)
             if(ans<dp[i][j])
                 ans = dp[i][j];
    printf("%d\n", ans);
	return 0;
}
