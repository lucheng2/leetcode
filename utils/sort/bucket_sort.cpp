#include<vector>
using namespace std;

void insertion_sort(vector<int> & vec) {
    for(int i=0; i<vec.size(); i++) {
        int key = vec[i];
        int j = i-1;
        while(j>=0 && vec[j] > key) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

void bucket_sort(vector<int> &data) {
    int mx=data[0], mn=data[0];
    for(int i=1; i<data.size(); i++) {
        mx = max(mx, data[i]);
        mn = min(mn, data[i]);
    }
    int n = data.size();
    int w = mx - mn + 1;
    int bucket_size = w / n + 1;
    vector<vector<int>> bucket(n);
    for(int i=0; i<n; i++) {
        bucket[(data[i]-mn) / bucket_size].push_back(data[i]);
    }
    int p = 0;
    for(int i=0; i<n; i++) {
        insertion_sort(bucket[i]);
        for(int j=0; j<bucket[i].size(); j++) 
            data[p++] = bucket[i][j];
    }
}


