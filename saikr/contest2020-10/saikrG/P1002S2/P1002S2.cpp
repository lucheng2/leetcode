#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ull unsigned long long
using namespace std;

ull dp[30][30] = { 0 };
bool trap[30][30];
int dirX[] = { 0, 1, -1, 1, -1, 2, -2, 2, -2 };
int dirY[] = { 0, 2, -2, -2, 2, 1, -1, -1, 1 };

int main() {
    int m, n, horseX, horseY;
    scanf("%d %d %d %d", &m, &n, &horseX, &horseY);
    //x，y坐标的表示都自增1，避免索引为负
    m += 2, n += 2, horseX += 2, horseY += 2;
    //标记陷阱
    for (int i = 0; i <= 8; i++) {
        trap[horseX + dirX[i]][horseY + dirY[i]] = true;
    }
    dp[2][2] = 1;
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            if (trap[i][j]) {
                continue;
            }
            dp[i][j] = max(dp[i - 1][j] + dp[i][j - 1], dp[i][j]);
        }
    }
    printf("%llu", dp[m][n]);
    return 0;
}
