#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr1 = { 1, 2, 3, 4 };
    vector<int> arr2 = { 2, 3, 4, 5 };

    int min_value = arr1[0] + arr2[0];
    for (int i = 0; i < min(arr1.size(), arr2.size()); i++) {
        min_value = min(min_value, arr1[i] + arr2[i]);
    }
    cout << min_value << endl;
}