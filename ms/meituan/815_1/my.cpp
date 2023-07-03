#include<iostream>

using namespace std;


int main() {
    string s;
    cin>>s;
    int i=0, j=s.size()-1;
    int n = s.size() / 2;
    int len = 0;
    while(i < n && s[i] == s[j]) {
        len ++;
        i++, j--;
    }
    int ans = max(0, (int)s.size() - 2*len - 1);
    cout<<ans<<endl;
	return 0;
}
