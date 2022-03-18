#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <vector>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++)
        cin >> arr[i];

    num answer_arr[n];
    for (num i = 0; i < n; i++)
        answer_arr[arr[i] - 1] = i + 1;

    for (num i = 0; i < n; i++)
        cout << answer_arr[i] << " ";
}

// correct