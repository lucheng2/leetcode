#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

void quick_sort(vector<int> &data, int low, int high) {
    if(low >= high)
        return;
    int qviot = data[low];
    int l = low, r = high;
    while(low < high) {
        while(low < high && data[high] >= qviot)
            high --;
        data[low] = data[high];
        while(low < high && data[low] < qviot)
            low ++;
        data[high] = data[low];
    }
    data[low] = qviot;
    quick_sort(data, l, low-1);
    quick_sort(data, low+1, r);
}

int main() {
    int n;
    vector<int> data;
    cin>>n;
    data.resize(n);
    for(int i=0; i<n; i++) {
        cin>>data[i];
    }
    quick_sort(data, 0, n-1);
    for(int i=0; i<n; i++) 
        cout<<data[i]<<" ";
    cout<<endl;
	return 0;
}
