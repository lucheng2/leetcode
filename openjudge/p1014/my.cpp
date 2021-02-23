#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int sum = 0, N, i;
    scanf("%d", &N);
    for(i=1; sum+i<N; i++) {
        sum += i;
    }
    int j = N - sum;
    printf("%d/%d\n", i+1-j, j); 
	return 0;
}
