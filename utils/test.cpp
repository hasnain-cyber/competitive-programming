#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

vector<int> solve(vector<int> &arr, int k) {
    int n = arr.size();

    map<int, int> current_indices;
    for (int i = 0; i < n; i++) current_indices[arr[i]] = i;

    for (int i = 0; i < n && k > 0; i++) {
        int current_index = current_indices[n - i];
        if (current_index != i) {
            // swap
            swap(arr[current_index], arr[i]);
            current_indices[arr[i]] = i;
            current_indices[arr[current_index]] = current_index;
            k--;
        }
    }

    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    for (auto element : solve(arr, 1)) cout << element << " ";
    cout << endl;
}