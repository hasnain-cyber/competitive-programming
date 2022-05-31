#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

void swap(ll arr[], ll i, ll j) {
    ll temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

ll partition(ll arr[], ll low, ll high) {
    ll pivot = arr[low];
    ll i = low, j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high)
            i++;
        while (arr[j] >= pivot && j > low)
            j--;
        if (i < j)
            swap(arr, i, j);
    }

    if (j != low) {
        swap(arr, j, low);
    }

    return j;
}

void quick_sort(ll arr[], ll low, ll high) {
    if (low < high) {
        ll pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main() {
    ll arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    ll n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}