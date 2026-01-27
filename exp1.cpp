#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void complexRec(int n, long long &count) {
    if (n <= 2) return;

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            count++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
    }

    reverse(small.begin(), small.end());

    complexRec(n / 2, count);
    complexRec(n / 2, count);
    complexRec(n / 2, count);
}

int main() {
    int n;
    cin >> n;

    long long count = 0;
    auto start = high_resolution_clock::now();
    complexRec(n, count);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "time taken = " << duration.count() << "\n";
    cout << "ops = " << count << "\n";
    return 0;
}
//Reccurance relation = 3T(n/2) + O(nlogn)
//Time complexity = O(n^(log3)) 
//depth of recusion tree = logn