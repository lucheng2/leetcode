#include<vector>

void bubble_sort(std::vector<int> & vec) {
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i=0; i<vec.size() - 1; i++) {
            if(vec[i] > vec[i+1]) {
                std::swap(vec[i], vec[i+1]);
                flag = true;
            }
        }
    }
}
