#include<iostream>
#include<vector>

using namespace std;

int pantHouse(vector<vector<int>> cost) {
    int n = cost.size();
    if(n <= 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    //cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;
    for(int i=1; i<n; i++)  {
        for(int j=0; j<3; j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3], 
                    dp[i-1][(j+2)%3]) + cost[i][j];
        }
    //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    int ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    return ans;
}

int main() {
    vector<vector<int>> cost1 = {
        {1, 2, 3},
        {6, 5, 4},
        {7, 8, 9},
        {1, 2, 3}
    };
    vector<vector<int>> cost2 ;
    int ans1 = pantHouse(cost1);
    int ans2 = pantHouse(cost2);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}
