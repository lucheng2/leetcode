#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>::iterator arr, int len) {
    if(len <= 1)
        return;
    int qviot = arr[0];

    //j:第一个等于qviot的索引，k：第一个大于qvoit的索引
    int i=0, j=0, k=len;
    while(i < k) {
        if(arr[i] < qviot) 
            swap(arr[i++], arr[j++]);
        else if(arr[i]> qviot)
            swap(arr[i], arr[--k]);
        else
            i++;
    }
    quickSort(arr, j);
    quickSort(arr+k, len - k);
}

void qsort(vector<int> &arr) {
    quickSort(arr.begin(), arr.size());
}

int main() {
    int n;
    cin>>n;
    vector<int> test(n);
    for(int i=0; i<n; i++) {
        cin>>test[i];
    }
    qsort(test);
    for(int i=0; i<n; i++) {
        cout<<test[i]<<" ";
    }
    cout<<endl;
    return 0;
}

