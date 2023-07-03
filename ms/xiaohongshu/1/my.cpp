#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;


vector<vector<int>> data;

int mycmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int main() {
    int n;
    int cnt1=0, cnt2=0, cnt0=0;
    int a, b, c;
    cin>>n;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        if(x==1)
            cnt1++;
        else if(x==2)
            cnt2++;
        else {
            cin>>a>>b;
            c = a - b;
            data.push_back({a, b, c});
            cnt0++;
        }
    }
    if(abs(cnt1-cnt2) > cnt0) {
        cout<<-1<<endl;
        return 0;
    }
    sort(data.begin(), data.end(), mycmp);
    int c1 = (cnt0+cnt2-cnt1)/2;
    int ans = 0;
    for(int i=0; i<c1; i++) 
        ans += data[i][0];
    for(int i=c1; i<cnt0; i++)
        ans += data[i][1];
	
    cout<<ans<<endl;
	return 0;
}
