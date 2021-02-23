#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class SubrectangleQueries {
public:
	vector<vector<int>> rectangle;
	vector<vector<int>> history;
    SubrectangleQueries(vector<vector<int>>& rectangle) :rectangle(rectangle) {

    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		history.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
		for (int i=history.size()-1; i>=0; i--) {
			if(history[i][0]<=row && history[i][1]<=col &&
				history[i][2]>=row && history[i][3]>= col) {
				return history[i][4];
			}
		}
		return rectangle[row][col];
    }
};


int main() {
	
	return 0;
}
