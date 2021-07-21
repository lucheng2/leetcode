#include<vector>
using namespace std;

void shift_down(vector<int> & vec, int start, int end) {
    int father = start;
    int son = start * 2 + 1;
    while(son <= end) {
        if(son+1 <= end && vec[son+1] > vec[son])
            son++;
        if(vec[father] >= vec[son])
            return;
        else {
            swap(vec[father], vec[son]);
            father = son;
            son = father * 2 + 1;
        }
    }
}

void heap_sort(vector<int> & data) {
    for(int i=data.size()-1; i>=0; i--) {
        shift_down(data, i, data.size()-1);
    }
    for(int i=data.size()-1; i>0; i--) {
        swap(data[0], data[i]);
        shift_down(data, 0, i-1);
    }
}
