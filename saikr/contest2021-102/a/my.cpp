#include<iostream>

using namespace std;
int const mod = 425;
int data[4];

int main() {
    int t;
    cin>>t;
    t = t / 60;

    if(t<=3) {
        int ans = t==0?0:1;
        cout<<ans<<endl;
        return 0;
    }
    data[0]=data[1]=data[2]=1;
    while(t>3) {
        t--;
        data[3] = (data[0]+data[1]+data[2]) % mod;
        data[0] = data[1];
        data[1] = data[2];
        data[2] = data[3];
    }
    cout<<data[3]<<endl;
	return 0;
}
