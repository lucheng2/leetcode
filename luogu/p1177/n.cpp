#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

void quick_sort(vector<int>::iterator vec, int len){
    if(len < 2)
        return;
    int i=0, j=0, k=len;
    int pviot = vec[rand() % len];
    while(i < k) {
        if(vec[i] < pviot)
            swap(vec[i++], vec[j++]);
        else if(vec[i] > pviot)
            swap(vec[i], vec[--k]);
        else
            i++;
    }
    quick_sort(vec, j);
    quick_sort(vec + k, len - k);
}

int main() {
    int n;
    vector<int> data;
    cin>>n;
    data.resize(n);
    for(int i=0; i<n; i++) {
        cin>>data[i];
    }
    quick_sort(data.begin(), n);
    for(int i=0; i<n; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
	return 0;
}
