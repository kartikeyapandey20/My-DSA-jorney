#include<bits/stdc++.h>

using namespace std;

int main() {
    int l1 , r1, l2 , r2;
    cin >> l1 >> r1 >> l2 >> r2;
    
    int left_point = max(l1, l2);
    int right_point = min(r1, r2);

    if (left_point <= right_point) {
        cout << left_point << " " << right_point << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}