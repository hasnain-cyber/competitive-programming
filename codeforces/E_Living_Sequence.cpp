#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

// copied this part from a solution on yt, could not fix the wierd offset bugs in the position.
int find_position_in_sequence(int n) {
    int ans = 0;
    string s = to_string(n);
    int m = s.length();

    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';
        int cnt = 0;
        if (digit <= 4) {
            cnt = digit;
        } else {
            cnt = digit - 1;
        }

        cnt = cnt * pow(9, m - i - 1);
        ans += cnt;
        if (s[i] == '4') {
            break;
        }
        if (i == m - 1) {
            ans++;
        }
    }

    return ans - 1;

    // string n_str = to_string(n);
    // int position = 1;

    // // for smaller no. of digits
    // for (int i = 1; i < n_str.size(); i++) {
    //     position += 8 * pow(9, i - 1);
    // }

    // // for same no. of digits
    // // digits less than the first digit
    // int first_digit = n_str[0] - '0';
    // position += (first_digit - (first_digit < 4 ? 1 : 2)) * pow(9, n_str.size() - 1);
    // if (first_digit == 4) {
    //     return position - 1;
    // }

    // // now, for the first digit, place the digit itself, and count the number of such numbers
    // for (int j = 1; j < n_str.size(); j++) {
    //     int digit = n_str[j] - '0';
    //     // do not include no.s containing 4
    //     position += (digit - (digit < 4 ? 0 : 1)) * pow(9, n_str.size() - j - 1);

    //     // do not place 4 in the current position.
    //     if (digit == 4) {
    //         position--;
    //         break;
    //     }
    // }

    // return position;
}

void solve_testcase() {
    int k;
    cin >> k;

    int low = 1, high = 1e16;
    int answer = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        int position = find_position_in_sequence(mid);
        // cout << low << " " << high << " " << mid << ' ' << position << endl;
        if (position >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
        // cout << find_position_in_sequence(4) << endl;
    }
}