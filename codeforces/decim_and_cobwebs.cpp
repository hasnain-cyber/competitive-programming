#include <bits/stdc++.h>

using namespace std;

bool check(int x, int y, int z) {
    for (int value = 1; value <= min(x, min(y, z)); value++) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(x);
        pq.push(y);
        pq.push(z);

        bool flag = true;
        int counter = 0;
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr > value) {
                if (counter == 3) {
                    flag = false;
                    break;
                }

                pq.push(value);
                pq.push(curr - value);
                counter++;
            }
            else if (curr < value) {
                flag = false;
                break;
            }
        }

        if (flag) return true;
    }

    return false;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    if (check(x, y, z)) cout << "YES" << endl;
    else cout << "NO" << endl;
}