#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b1, b2;
        for (int i = 0; i < n; ++i) {
            b1.push_back(i);
        }
        b2.push_back(1);
        for (int i = 1; i < n; ++i) {
            cout << i << ' ' << i + 1 << endl;
        }
        int q;
        cin >> q;
        while (q--) {
            int d;
            cin >> d;
            d++;
            if (b1.size() == d) {
                cout << "-1 -1 -1\n";
            }
            else if (b1.size() < d) {
                d = d - b1.size();
                vector<int> qq(b2.end() - d, b2.end());
                int u = b2[b2.size() - d];
                int v1 = b2[b2.size() - d - 1];
                int v2 = b1.back();
                cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << '\n';
                for (int i = 0; i < d; ++i) b2.pop_back();
                for (auto i : qq) b1.push_back(i);
            }
            else {
                d = b1.size() - d;
                vector<int> qq(b1.end() - d, b1.end());
                int u = b1[b1.size() - d];
                int v1 = b1[b1.size() - d - 1];
                int v2 = b2.back();
                cout << u + 1 << ' ' << v1 + 1 << ' ' << v2 + 1 << '\n';
                for (int i = 0; i < d; ++i) b1.pop_back();
                for (auto i : qq) b2.push_back(i);
            }
        }
    }
}