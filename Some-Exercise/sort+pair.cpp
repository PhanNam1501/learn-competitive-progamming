1️⃣ Sắp xếp pair theo mặc định (rất hay dùng)
vector<pair<int,int>> v = {
    {3, 4},
    {1, 5},
    {3, 2},
    {1, 2}
};

sort(v.begin(), v.end());

👉 Quy tắc mặc định:

So sánh first

Nếu first bằng nhau → so sánh second

➡️ Kết quả:

(1,2)
(1,5)
(3,2)
(3,4)


📌 Tương đương logic:

a < b ⇔
a.first < b.first ||
(a.first == b.first && a.second < b.second)

2️⃣ Sắp xếp theo first tăng, second giảm

Dùng lambda (cách hiện đại & khuyên dùng):

sort(v.begin(), v.end(), [](const pair<int,int>& a,
                            const pair<int,int>& b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
});


➡️ Ví dụ:

(1,5)
(1,2)
(3,4)
(3,2)

3️⃣ Chỉ sắp xếp theo second
sort(v.begin(), v.end(), [](auto &a, auto &b) {
    return a.second < b.second;
});


📌 auto giúp code gọn hơn (C++14+)

4️⃣ Sắp xếp giảm dần toàn bộ
sort(v.begin(), v.end(), greater<pair<int,int>>());


⚠️ greater<> vẫn tuân theo thứ tự mặc định của pair
(chỉ là đảo chiều)

5️⃣ Dùng struct comparator (hay gặp trong contest / code cũ)
struct cmp {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b) const {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

sort(v.begin(), v.end(), cmp());

6️⃣ Sắp xếp pair<long long, long long> (rất hay gặp trong CP)
vector<pair<long long, long long>> a;

sort(a.begin(), a.end()); // vẫn OK


Không có gì khác với int.

7️⃣ Trong set / map / multiset
set<pair<>> mặc định:
set<pair<int,int>> s;


➡️ Tự động sort giống sort() mặc định.

Custom comparator cho set:
set<pair<int,int>, cmp> s;