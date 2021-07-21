#include<vector>

using namespace std;

void merge_sort(vector<int> &a, vector<int> &b, int ll, int rr) {
    if(rr - ll <= 1)
        return;
    int mid = ll + (rr-ll) / 2;
    merge_sort(a, b, ll, mid);
    merge_sort(a, b, mid, rr);
    int p=ll, q=mid, s=ll;
    while(s < rr) {
        if(p >= mid || (q<rr && a[p] > a[q]))
            b[s++] = a[q++];
        else
            b[s++] = a[p++];
    }
    for (int i=ll; i<rr; i++) 
        a[i] = b[i];
}


