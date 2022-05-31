#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
   public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n) {
        Node* temp = new Node;
        temp->data = n;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void print_list(Node* head) {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    LinkedList list;
    list.add_node(1);
    list.add_node(2);
    list.add_node(5);
    list.add_node(-1);

    list.print_list(list.head);
    list.head = list.reverse(list.head);
    list.print_list(list.head);
}