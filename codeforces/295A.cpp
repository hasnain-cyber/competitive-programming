#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n, m, k;
    cin >> n >> m >> k;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    vector<num> operations_arr[m];
    for (num i = 0; i < m; i++) {
        num l, r, d;
        cin >> l >> r >> d;
        operations_arr[i].push_back(l);
        operations_arr[i].push_back(r);
        operations_arr[i].push_back(d);
    }

    num operation_application_arr[m];
    for (num i = 0; i < m; i++) operation_application_arr[i] = 0;
    for (num i = 0; i < k; i++) {
        num x, y;
        cin >> x >> y;
        operation_application_arr[x - 1] += 1;
        if (y < m)
            operation_application_arr[y] -= 1;
    }

    num operation_application_arr_prefix_sum[m];
    operation_application_arr_prefix_sum[0] = operation_application_arr[0];
    for (num i = 1; i < m; i++)
        operation_application_arr_prefix_sum[i] = operation_application_arr_prefix_sum[i - 1] + operation_application_arr[i];

    num change_arr[n];
    for (num i = 0; i < n; i++) change_arr[i] = 0;
    for (num i = 0; i < m; i++) {
        vector<num> operation = operations_arr[i];
        num l = operation[0], r = operation[1], d = operation[2] * operation_application_arr_prefix_sum[i];

        change_arr[l - 1] += d;
        if (r < n)
            change_arr[r] -= d;
    }

    num prefix_sum_change_arr[n];
    prefix_sum_change_arr[0] = change_arr[0];
    for (num i = 1; i < n; i++)
        prefix_sum_change_arr[i] = prefix_sum_change_arr[i - 1] + change_arr[i];

    for (num i = 0; i < n; i++)
        arr[i] += prefix_sum_change_arr[i];

    for (num i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// correct