#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool verify(vector<string> arr, int i, int j, char c) {
    for (int k = 0; k < 9; k++)
        if (arr[i][k] == c) return false;
    for (int k = 0; k < 9; k++)
        if (arr[k][j] == c) return false;

    for (int k1 = (i / 3) * 3; k1 < (i / 3) * 3 + 3; k1++) {
        for (int k2 = (j % 3) * 3; k2 < (j % 3) * 3 + 3; k2++) {
            if (arr[k1][k2] == c) return false;
        }
    }

    return true;
}

void print_arr(vector<string> arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < 9; i++) cout << "___";
    cout << endl;
}

void solve(vector<string> &arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == '.') {
                for (char k = '1'; k <= '9'; k++) {
                    if (verify(arr, i, j, k)) {
                        arr[i][j] = k;
                        solve(arr);
                        arr[i][j] = '.';
                    }
                }
                return;
            }
        }
    }

    print_arr(arr);
    return;
}

int main() {
    vector<string> arr = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    solve(arr);
}