#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int N, x, y;
double n;
double per = (double)2 / 3;
int countDays = 0;
int countX = 0;
bool usedRecover = false;
void trans() {
    n = per*n;
    countDays++;
    countX++;
}
void recover() {
    n += N / 2.0;
    countX = 0;
}
bool isFailed() {
    if(n<(N/32.0)) {
        return true;
    } else {
        return false;
    }
}
int main() {
    scanf("%d%d%d", &N, &x, &y);
    n = N;
    while(countDays<y) {
        trans();
        if(!usedRecover && countX>=x) {
            recover();
            usedRecover = true;
        } 
        if(isFailed()) {
            printf("N0!\n");
            printf("%d %.6lf", countDays, n);
            return 0;
        }
        if(countDays>=y) {
            printf("YE5!\n");
            printf("%.6lf", n);
            return 0;
        }
    }
	return 0;
}
