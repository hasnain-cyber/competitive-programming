#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    ListNode* temp = new ListNode(14);
    temp->val = 14;
    cout << temp->val << endl;
}