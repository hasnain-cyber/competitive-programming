#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n, q;
    cin >> n >> q;

    vector<queue<int>> application_queue(n, queue<int>());
    queue<pair<int, int>> notification_queue;
    int unread_notifications = 0;
    int counter_first_type_events = 0;
    vector<int> bool_read_notifications;
    while (q--) {
        int event_type;
        cin >> event_type;
        if (event_type == 1) {
            int application_no;
            cin >> application_no;
            notification_queue.push(make_pair(counter_first_type_events, application_no));

            unread_notifications++;
            counter_first_type_events++;
        } else if (event_type == 2) {
            int application_no;
            cin >> application_no;
            
            while(!application_queue[application_no - 1].empty()) {
                int applcation_no = application_queue[application_no - 1].front();
                application_queue[application_no - 1].pop();


                unread_notifications--;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}