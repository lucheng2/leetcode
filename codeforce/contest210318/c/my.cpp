#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>

using namespace std;

int t;
int n;
long long int c[120000];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1; i<=n; ++i) {
            cin>>c[i];
        }
        long long minX = c[1], minY = c[2];
        long long sumX = c[1], sumY = c[2];
        long long int ans = (c[1] + c[2]) * n;
        for(int i=3; i<=n; ++i) {
            if(i&1) {
                sumX += c[i];
                minX = min(minX, c[i]);
            }
            else {
                sumY += c[i];
                minY = min(minY, c[i]);
            }
            ans = min(ans, sumX + minX*(n-(i+1)/2) + sumY + minY*(n-i/2));
        }
        cout<<ans<<endl;
    }
	return 0;
}
