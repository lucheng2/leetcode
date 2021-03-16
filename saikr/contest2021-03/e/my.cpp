#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int V;
string s;

int main() {
    cin>>V;
    cin>>s;
    int amout = 0;
    int num2 = 0;
    long long int ans=0;
    for(int i=1; i<=s.size(); i++) {
        int cost = s[i-1] - '0';
        if(V-cost>=0) {
            V = V-cost;
            amout ++;
            if(cost==2) {
                num2 ++;
            }
        } else {
            if(cost==2) {
            } else {
                if(num2>0) {
                    V+=1;
                    num2--;
                }
            }
        }
        ans += amout;
    }
    printf("%lld", ans);
	return 0;
}
