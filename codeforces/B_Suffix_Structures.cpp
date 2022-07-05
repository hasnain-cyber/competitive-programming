#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_ans(int code) {
    if (code == 0)
        cout << "automaton" << endl;
    else if (code == 1)
        cout << "array" << endl;
    else if (code == 2)
        cout << "both" << endl;
    else
        cout << "need tree" << endl;
}

bool find_subsequence(string &s1, string &s2, int i, int j) {
    if (j < 0)
        return true;
    else if (i < 0)
        return false;

    if (s1[i] == s2[j])
        return find_subsequence(s1, s2, i - 1, j - 1);
    else
        return find_subsequence(s1, s2, i - 1, j);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    if (find_subsequence(s1, s2, s1.size() - 1, s2.size() - 1))
        print_ans(0);
    else {
        map<char, int> m1, m2;
        for (int i = 0; i < s1.size(); i++) m1[s1[i]]++;
        for (int i = 0; i < s2.size(); i++) m2[s2[i]]++;

        if (m1 == m2)
            print_ans(1);
        else {
            for (auto it : m2) {
                m1[it.first] -= it.second;
            }

            bool flag = true;
            for (auto it : m1) {
                if (it.second < 0) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                print_ans(2);
            else
                print_ans(3);
        }
    }
}