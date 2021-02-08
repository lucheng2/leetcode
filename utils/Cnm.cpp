long long Cnm(int n, int m) {
    if(n - m < m)
        m = n - m;
    long long ans = 1;
    for(int i=1; i<=m; i++) {
        ans = ans*(n-i+1)/i;
    }
    return ans;
}

