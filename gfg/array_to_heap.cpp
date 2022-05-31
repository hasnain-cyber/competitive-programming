#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

class Heap {
   private:
    vector<ll> heap;

    void swap(ll i, ll j) {
        ll temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

   public:
    void print_heap() {
        for (ll i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void insert(ll element) {
        // insert the element first.
        heap.push_back(element);

        // now bubble it to the top, for max-heap.
        ll i = heap.size();
        while (i / 2 > 0) {
            ll parent = i / 2;
            if (heap[parent - 1] < heap[i - 1]) {
                swap(parent - 1, i - 1);
            }

            i /= 2;
        }
    }
};

int main() {
    ll arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    ll n = sizeof(arr) / sizeof(arr[0]);

    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    Heap h = Heap();
    for (auto element : arr) {
        h.insert(element);
    }
    h.print_heap();
}