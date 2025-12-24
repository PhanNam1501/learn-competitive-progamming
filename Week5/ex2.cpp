#include <bits/stdc++.h>
using namespace std;

//Quy tắc đó là chúng ta sẽ cho người sao cho thời gian kết thúc của họ gần
// nhất với thời gian bắt đầu của 1 phim cbi được chiếu, tại sao lại làm như vậy
// đó là bởi vì cta nên tối ưu bằng các cho các thành viên đều được xem phim ở thời gian bé, 
// bởi vì có thể là nếu cta có một bộ phim hiện tại mà sau khi 1 bộ phim vừa kết thúc gần nhất
// ví dụ: 
// Phim1: 57 -> 69
// Phim2: 35 -> 72
// Phim3: 53 -> 78
// Có 2 phim cbi được chiếu là 77 -> 79, 49 -> 87
// nếu ta gán luôn phim 77 cho người thứ 4 thì tức là ra vừa bỏ qua 1 phim có xuất chiếu sớm -> phí mà phim 77 có thể cho người vừa mới kết thúc phim được
int main() {
    int n, k;
    cin >> n >> k;  

    vector<pair<long long, long long>> movies(n);  

    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;  
    }

    sort(movies.begin(), movies.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });



    int count = 0;
    long long s = 0;
    multiset <long long> mySet;
    for (int i = 0; i < k; i++) {
        mySet.insert(0);
    }
    for (int i = 0; i < n; i++) {
            auto it = mySet.upper_bound(movies[i].first); 
            
            if (it != mySet.begin()) {
                // cout << i << " " << *it << "\n";
                --it; 
                // cout << i << " " << *it << "\n";
                mySet.erase(it);      
                mySet.insert(movies[i].second);
                count++;
            } 
        
    }

    cout << count;
    return 0;
}
