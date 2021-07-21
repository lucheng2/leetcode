#include<vector>

using namespace std;

void select_sort(vector<int> & vec) {
    for(int i=0; i<vec.size(); i++) {
        int ith = i;
        for(int j=i+1; j<vec.size(); j++) {
            if(vec[j] < vec[ith])
                ith = j;
        }
        swap(vec[i], vec[ith]);
    }
}

