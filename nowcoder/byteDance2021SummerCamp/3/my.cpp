#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int T;
    long long n;
    cin>>T;
    while(T--) {
        cin>>n;
        if(n==1)
            cout<<1<<endl;
        else if(n==2)
            cout<<4<<endl;
        else if(n==3)
            cout<<5<<endl;
        else 
            cout<<100<<endl;
    }
	
	return 0;
}
