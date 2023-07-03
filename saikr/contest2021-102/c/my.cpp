#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long


using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> data = vector<int>(n);
    for(int i=0; i<n; i++) {
        cin>>data[i];
    }
    sort(data.begin(), data.end());
    cout<<data[1]<<endl;
	return 0;
}
