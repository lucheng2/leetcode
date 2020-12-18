#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string::size_type pos;
        while((pos=command.find("()")) != command.npos)
            command = command.replace(pos, 2, "o");
        while((pos=command.find("(al)")) != command.npos)
            command = command.replace(pos, 4, "al");
        return command;
    }
};

int main() {
	
	return 0;
}
