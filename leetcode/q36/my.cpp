#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int> (9, 0));
        vector<vector<int>> col(9, vector<int> (9, 0));
        vector<vector<int>> box(9, vector<int> (9, 0));
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.')
                    continue;
                int key = board[i][j] - '1';
                int box_index = (i/3) * 3 + j/3;
                if(row[i][key] || col[j][key] || box[box_index][key]) {
                    return false;
                } else {
                    row[i][key] = 1;
                    col[j][key] = 1;
                    box[box_index][key] = 1;
                }
            }
        }
        return true;
    }
};

int main() {
	
	return 0;
}
