#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    int m, n, horseX, horseY;
    scanf("%d %d %d %d", &m, &n, &horseX, &horseY);
    long long** dp = (long long**)malloc(sizeof(long long) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dp[i] = (long long*)malloc(sizeof(long long) * (n + 1));
    }
    dp[0][0] = 1;
    int dir[][2] = {
        {-1,-2},
        {-1, 2},
        {1, -2},
        {1, 2},
        {-2, -1},
        {-2,1},
        {2,-1},
        {2,1}
    };
    //标记陷阱
    dp[horseX][horseY] = -1;
    for (int i = 0; i < 8; i++) {
        int x = horseX + dir[i][0], y = horseY + dir[i][1];
        if (x >= 0 && x <= m && y >= 0 && y <= n) {
            dp[x][y] = -1;
        }
    }
    if (dp[m][n] == -1 || dp[0][0] == -1) {
        printf("0");
        return 0;
    }
    long long cx, cy;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (dp[i][j] == -1) {
                continue;
            }
            if (i - 1 >= 0) {
                cx = (dp[i - 1][j] == -1 ? 0 : dp[i - 1][j]);
            }
            else
            {
                cx = 0;
            }
            if (j - 1 >= 0) {
                cy = (dp[i][j - 1] == -1 ? 0 : dp[i][j - 1]);

            }
            else
            {
                cy = 0;
            }
            dp[i][j] = max(cx + cy, dp[i][j]);
        }
    }
    printf("%ld", dp[m][n]);
    return 0;
}
