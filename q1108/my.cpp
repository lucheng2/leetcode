#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0; i<3; i++)
            address = address.replace(address.find("."), 1, "[!]");
        for(int i=0; i<3; i++)
            address = address.replace(address.find("!"), 1, ".");
        return address;
    }
};

int main() {
	
	return 0;
}
