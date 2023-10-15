// #include <bits/stdc++.h>

// // #define MOD 1000000007
// #define MOD 998244353
// #define infinity numeric_limits<int>::max()

// #define int long long int
// #define double long double

// #define endl '\n'

// using namespace std;

// template <typename T>
// void print_arr(vector<T>& arr) {
//     for (T element : arr)
//         cout << element << ' ';
//     cout << endl;
// }

// void solve_testcase() {
//     int n;
//     cin >> n;
//     vector<int> a1(n);
//     for (int i = 0; i < n; i++) cin >> a1[i];
//     vector<int> a2(n);
//     for (int i = 0; i < n; i++) cin >> a2[i];

//     int m;
//     cin >> m;
//     vector<int> b1(n);
//     for (int i = 0; i < m; i++) cin >> b1[i];
//     vector<int> b2(n);
//     for (int i = 0; i < m; i++) cin >> b2[i];

//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++) mp[a1[i]] += a2[i];

//     int common = 0;
//     for (int i = 0; i < m; i++) {
//         int value = mp[b1[i]];
//         if (value - b2[i] < 0) {
//             cout << 0 << endl;
//             return;
//         }
//         else if (value - b2[i] == 0) {
//             common++;
//         }
//     }

//     int ans = 1;
//     for (int i = 0; i < mp.size() - common; i++) ans = (ans * 2) % MOD;
//     cout << ans << endl;
// }

// int32_t main() {
//     int t;
//     t = 1;
//     while (t--) {
//         solve_testcase();
//     }
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef vector<pair<ld, ld>> vpd;
typedef map<int, vector<int>> mvi;
typedef map<ll, vector<ll>> mvl;
typedef map<int, int> mi;
typedef map<ll, ll> ml;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

#define sz(x) (int)x.size();
#define pb push_back
#define all(x) x.begin(),x.end()

int p = 998244353;

void presum(vl& v, ll a[], int n) {
    v[0] = a[0];
    for (int i = 1;i < n;i++) {
        v[i] = v[i - 1] + a[i];
    }
}

void solve() {

    int n; cin >> n;
    int a[n], b[n];
    mi ma, mb;
    ll ans = 1;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> b[i];
        ma[a[i]] = b[i];
    }

    int m; cin >> m;
    int c[m], d[m];
    for (int i = 0;i < m;i++) {
        cin >> c[i];
    }
    bool flag = false;
    for (int i = 0;i < m;i++) {
        cin >> d[i];
        mb[c[i]] = d[i];
        if (ma[c[i]] < mb[c[i]]) {
            flag = true;
        }
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0;i < n;i++) {
        if (mb[a[i]] == 0) {
            ans *= 2;
            ans %= p;
        }
        else {
            if (mb[a[i]] != ma[a[i]]) {
                ans *= 2;
                ans %= p;
            }
        }
    }
    cout << ans << endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //   int t; cin>>t;
    //   while(t--){
    solve();
    //   }

    return 0;
}