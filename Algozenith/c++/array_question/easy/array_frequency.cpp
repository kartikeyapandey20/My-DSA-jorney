#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n , m ;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    int freq[m+1] = {0};

    for(int i = 0;i < n; i++)
    {
        freq[arr[i]]++;
    }

    for(int i = 0; i <= m; i++) cout << freq[i] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int _t = 1;
    cin >> _t;
    while(_t--) {
        solve();
    }
    return 0;
}