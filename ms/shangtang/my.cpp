#include<iostream>
#include<vector>

using namespace std;


int findKth(vector<int>::iterator  arr, int kth, int n) {
    int qvoit = arr[rand() %n];
    int i=0, j=0, k=n;
    while(i<k) {
        if (arr[i] > qvoit) 
            swap(arr[i++], arr[j++]);
        else if(arr[i] < qvoit) 
            swap(arr[i], arr[--k]);
        else
            i++;
    }
    if(j >= kth)
        return findKth(arr, kth, j);
    else if(k < kth)
        return findKth(arr + k, kth - k, n - k);
    return qvoit;
}

int main() {
    vector<int> test = {5, 1, 4, 2, 3};
    int ans = findKth(test.begin(), 3, test.size());
    cout<<ans<<endl;
    return 0;
}
