#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

void merge(ll arr[], ll low, ll mid, ll high) {
    ll pointer1 = low, pointer2 = mid + 1;
    vector<ll> new_arr;
    while (pointer1 <= mid && pointer2 <= high) {
        if (arr[pointer1] < arr[pointer2]) {
            new_arr.push_back(arr[pointer1]);
            pointer1++;
        } else if (arr[pointer1] > arr[pointer2]) {
            new_arr.push_back(arr[pointer2]);
            pointer2++;
        } else {
            new_arr.push_back(arr[pointer1]);
            new_arr.push_back(arr[pointer2]);
            pointer1++;
            pointer2++;
        }
    }
    for (ll i = pointer1; i <= mid; i++) {
        new_arr.push_back(arr[i]);
    }
    for (ll i = pointer2; i <= high; i++) {
        new_arr.push_back(arr[i]);
    }

    for (ll i = low; i <= high; i++) {
        arr[i] = new_arr[i - low];
    }
}

void merge_sort(ll arr[], ll low, ll high) {
    if (low < high) {
        ll mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    ll arr[] = {4, 2, 2, 5, 7, 9, 1, 3};
    ll n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}