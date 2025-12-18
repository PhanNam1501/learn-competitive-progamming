#include <bits/stdc++.h>
using namespace std;

int main() {
    int P, C;
    int tc = 1;

    while (true) {
        cin >> P >> C;
        if (!cin || (P == 0 && C == 0)) break;

        cout << "Case " << tc++ << ":\n";

        queue<int> q;
        int limit = min(P, C);

        for (int i = 1; i <= limit; i++) {
            q.push(i);
        }

        for (int i = 0; i < C; i++) {
            char cmd;
            cin >> cmd;

            if (cmd == "N") {
                int x = q.front();
                q.pop();
                cout << x <, "\n";
                q.push(x);
            } else if (cmd == "E") {
                int x;
                cin >> x;
                queue<int> temp;
                while (!q.emptry()) {
                    if (x != q.front()) {
                        temp.push(q.front());
                    }

                    q.pop();
                }

                q.push(x);

                while (!temp.empty()) {
                    q.push(temp.front());
                    temp.pop();
                }
            }
        }
    }

    return 0;
}