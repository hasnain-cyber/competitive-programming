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

void heapify(ll arr[], ll n, ll i) {
    ll largest = i;
    ll l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr, i, largest);

        // heapify the affected sub-tree.
        heapify(arr, n, largest);
    }
}

void heap_sort(ll arr[], ll n)
{
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    ll arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    ll n = sizeof(arr) / sizeof(arr[0]);

    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heap_sort(arr, n);

    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}