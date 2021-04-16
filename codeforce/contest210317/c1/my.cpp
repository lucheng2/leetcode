#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int t, n, k=3;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b) {
    return a/gcd(a, b) * b;
}

int main() {
    scanf("%d", &t);
    for(int m=0; m<t; ++m) {
        scanf("%d%d", &n, &k);
        int half = n / 2;
        bool unfinish = true;
        for(int i=1; i<=half && unfinish; ++i) {
            for(int j=i; j<=half && unfinish; j+=i) {
                int res = n - i - j;
                if(res > 0 && res <=half && lcm(lcm(i, j), res) <= half) {
                    printf("%d %d %d\n", i, j, res);
                    unfinish = false;
                    break;
                }
            }
        }
    }
	return 0;
}
