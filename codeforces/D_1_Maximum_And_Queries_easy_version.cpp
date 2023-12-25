#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        int low = 0, high = 1e18, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int req = 0;
            int nb = log2(mid) + 1;
            for (int i = 0; i < n; i++) {
                if ((arr[i] & mid) == mid) continue;

                int value = (arr[i] & (1 << nb) - 1);

                int temp = mid;
                while ((value & temp) != mid && temp < value) temp *= 2;
                req += temp - value;

                if (mid == 2) {
                    cout << "here: " << arr[i]  << " " << value << " " << temp - value << endl;
                }
            }

            std::cout << mid << " " << k << " " << req << endl;
            if (req <= k) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}