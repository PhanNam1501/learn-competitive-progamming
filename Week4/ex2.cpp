#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;   
    priority_queue <long long, vector <long long>, greater <long long>> pqMin;
    priority_queue<long long, vector<long long>, greater<long long>> pqSave;


    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long vi;
            cin >> vi;
            pqMin.push(vi);
        }
        else if (type == 2) {
            long long vi;
            cin >> vi;
            pqSave.push(vi);
        }
        else if (type == 3) {
            while (!pqMin.empty() && !pqSave.empty() && pqMin.top() == pqSave.top()) {
                pqMin.pop();
                pqSave.pop();
            }
            cout << pqMin.top() << "\n";
        }
    }

    return 0;
}

// Kĩ thuật lưu trữ heap tạm thời
// Nếu muốn xóa 1 phần tử nào ở heap thì ta tạo 1 heap tạm thời, 
// delete v thì ta sẽ push vào heap tạm thời, giả sử lấy min của heap
// nếu min của 2 cái đang giống nhau ta sẽ pop nên khi nào ko bằng sau đó lấy 
// min ra là được
