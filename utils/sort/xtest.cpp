#include<vector>
#include<stdio.h>
#include<iostream>
#include "selection_sort.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "counting_sort.cpp"
#include "quick_sort.cpp"

using namespace std;

int main() {
    int n, t;
    int test[10000];
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>t;
        test[i] = t;
    }
    // select_sort(test);
    // bubble_sort(test);
    // insertion_sort(test);
    // test = counting_sort(test, 10);
    // quick_sort(test, 0, test.size() -1);
    quick_sort_three_ways(test, n);
    for(int i=0; i<n; i++) {
        cout<<test[i]<<" ";
    }
    cout<<endl;
    return 0;
}
