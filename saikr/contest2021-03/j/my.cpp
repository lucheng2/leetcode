#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double A, B, a, b;
double dis = (double)1/50000;

int main() {
    scanf("%lf%lf%lf%lf", &A, &B, &a, &b);
    int m=0, n=0;
    while(A-a>=0) {
        m++;
        A = A - 2*a + dis; 
    }
    while(B-b>=0) {
        n++;
        B = B - 2*b + dis; 
    }
    int ans = m*n;
    printf("%d", ans);
	return 0;
}
