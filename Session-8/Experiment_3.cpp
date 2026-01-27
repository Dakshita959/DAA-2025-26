#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cout << "Enter number of attendance records (N): ";
    cin >> N;

    unordered_map<int,int> mp;
    mp[0] = -1;

    int sum = 0;
    int ans = 0;
    char ch;

    cout << "Enter " << N << " attendance records (P or A):" << endl;
    for (int i = 0; i < N; i++) {
        cin >> ch;      

        if (ch == 'P') sum += 1;
        else if (ch == 'A') sum -= 1;

        if (mp.count(sum)) {
            ans = max(ans, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout << "Maximum length of stable attendance window: " << ans << endl;
    return 0;
}
