#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "dog cat cat dog";
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    // In ra để kiểm tra
    for (const auto &w : words) {
        cout << w << "\n";
    }

    return 0;
}
