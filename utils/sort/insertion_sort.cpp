#include<vector>

void insertion_sort(std::vector<int> & vec) {
    for(int i=1; i<vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        while(j>=0 && vec[j] > key) {
            vec[j+1] = vec[j];
            --j;
        }
        vec[j+1] = key;
    }
}
