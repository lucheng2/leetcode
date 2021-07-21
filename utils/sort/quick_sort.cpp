#include <utility>
#include<vector>
#include<cstdlib>

void quick_sort(std::vector<int> &vec, int first, int last) {
    if(first >= last)
        return;
    int pivot = vec[first];
    int ll = first, rr = last;
    while(ll < rr) {
        while(ll < rr && vec[rr] >= pivot)
            rr --;
        vec[ll] = vec[rr];
        while(ll < rr && vec[ll] < pivot)
            ll ++;
        vec[rr] = vec[ll];
    }
    vec[ll] = pivot;
    quick_sort(vec, first, ll-1);
    quick_sort(vec, ll + 1, last);
}

void quick_sort_three_ways(int vec[], int len) {
    if(len <= 1)
        return;
    const int pivot = vec[std::rand() % len];
    int i=0, j=0, k=len;
    while(i < k) {
        if (vec[i] < pivot)
            std::swap(vec[i++], vec[j++]);
        else if (vec[i] > pivot)
            std::swap(vec[i], vec[--k]);
        else
            i++;
    }
    quick_sort_three_ways(vec, j);
    quick_sort_three_ways(vec + k, len-k);
}


void quick_sort_three_ways(std::vector<int>::iterator vec, int len) {
    if(len <= 1)
        return;
    const int pivot = vec[std::rand() % len];
    int i=0, j=0, k=len;
    while(i < k) {
        if (vec[i] < pivot)
            std::swap(vec[i++], vec[j++]);
        else if (vec[i] > pivot)
            std::swap(vec[i], vec[--k]);
        else
            i++;
    }
    quick_sort_three_ways(vec, j);
    quick_sort_three_ways(vec + k, len-k);
}

