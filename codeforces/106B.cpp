#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <vector>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    vector<num> arr[n];
    for (num i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        num x;
        while (ss >> x)
            arr[i].push_back(x);
        arr[i].push_back(i + 1);
    }

    bool discarded_laptops[n];
    for (num i = 0; i < n; i++)
        discarded_laptops[i] = false;

    for (num i = 0; i < n; i++) {
        if (discarded_laptops[i])
            continue;

        for (num j = 0; j < n; j++) {
            if (arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1] && arr[i][2] > arr[j][2]) {
                discarded_laptops[j] = true;
            } else if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1] && arr[i][2] < arr[j][2]) {
                discarded_laptops[i] = true;
                break;
            }
        }
    }

    num min_price = numeric_limits<num>::max(), min_price_index = -1;
    for (num i = 0; i < n; i++) {
        if (discarded_laptops[i])
            continue;

        if (arr[i][3] < min_price) {
            min_price = arr[i][3];
            min_price_index = arr[i][4];
        }
    }
    cout << min_price_index << endl;
}

// wrong answer