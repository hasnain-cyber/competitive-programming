#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int counter1 = 0, counter2 = 0;
        int running_product = 1;
        for (int i = 0; i < n; i++) {
            running_product *= arr[i];

            if (running_product > 0) {
                counter1++;
                running_product = 1;
            } else {
                counter2++;
                running_product = -1;
            }
        }

        int positive_ans = 0, negative_ans = 0;
        positive_ans += (counter1 * (counter1 - 1)) / 2 + (counter2 * (counter2 - 1)) / 2 + counter1;
        negative_ans += counter1 * counter2 + counter2;

        cout << negative_ans << " " << positive_ans << endl;
    }
}