#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    int l = 0;

    while (l < n) {
        int r = l + 1;
        bool hasTwo = (a[l] == 2);
        bool hasMiddleZero = false;

        while (r < n) {
            if (r - 1 > l && a[r - 1] == 0) {
                hasMiddleZero = true;
            }
            if (a[r] == 2) {
                hasTwo = true;
            }
            bool good = (!hasMiddleZero) && (hasTwo || a[l] != 0 || a[r] != 0);
            if (!good) {
                break;
            }

            r++;
        }
        l = r;
        ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}
