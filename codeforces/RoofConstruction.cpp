#include <math.h>

#include <iostream>
#include <vector>

typedef int i16;
typedef long int i32;
typedef long long int i64;

using namespace std;

int main() {
    i64 t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;

        vector<i64> answer_arr;
        i64 k = floor(log2(n - 1));
        for (i64 i = pow(2, k) - 1; i >= 0; i--) {
            answer_arr.push_back(i);
        }
        for (i64 i = pow(2, k); i <= n - 1; i++) {
            answer_arr.push_back(i);
        }

        for (int i = 0; i < answer_arr.size(); i++) std::cout << answer_arr.at(i) << ' ';
        cout << endl;
    }
}

// correct