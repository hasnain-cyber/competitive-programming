#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n, m;
    cin >> n >> m;
    map<string, string> correspondance_map;
    for (num i = 0; i < m; i++) {
        string key, value;
        cin >> key >> value;
        correspondance_map.insert({key, value});
    }
    string arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    string answer_arr[n];
    for (num i = 0; i < n; i++) {
        string word = arr[i];
        string corresponding_word;

        if (correspondance_map.count(word))
            corresponding_word = correspondance_map[word];
        else
            corresponding_word = word;

        if (word.size() <= corresponding_word.size())
            answer_arr[i] = word;
        else
            answer_arr[i] = corresponding_word;
    }

    for (num i = 0; i < n; i++)
        cout << answer_arr[i] << " ";
}

// correct