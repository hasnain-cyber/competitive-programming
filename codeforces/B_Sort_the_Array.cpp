#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    num starting_index = -1, ending_index = -1;
    for (num i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            starting_index = i;
            break;
        }
    }
    for (num i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            ending_index = i;
            break;
        }
    }

    num new_arr[n];
    for (num i = 0; i < starting_index; i++)
        new_arr[i] = arr[i];

    for (num i = starting_index; i < ending_index + 1; i++)
        new_arr[i] = arr[ending_index - (i - starting_index)];

    for (num i = ending_index + 1; i < n; i++)
        new_arr[i] = arr[i];

    sort(arr, arr + n);
    bool flag = true;
    for (num i = 0; i < n; i++) {
        if (arr[i] != new_arr[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "yes" << endl;
        if (starting_index == -1 && ending_index == -1)
            cout << 1 << " " << 1 << endl;
        else
            cout << starting_index + 1 << " " << ending_index + 1 << endl;
    } else
        cout << "no" << endl;
}

// correct