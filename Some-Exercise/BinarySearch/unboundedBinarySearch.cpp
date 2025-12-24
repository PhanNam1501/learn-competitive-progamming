#include<bits/stdc++.h> 
using namespace std;

int binarySearch(int low, int high);

int f(int x) {
    return (x*x - 10*x - 20);
}

int findFirstPositive()
{
    if(f(0) > 0) {
        return 0;
    }

    int i = 1;
    while(f(i) <= 0) {
        i = i*2;
    }

    return binarySearch(i/2, i);
}

int binarySearch(int low, int high)
{
    int mid = low + (high - low)/2;

    while (low <= high) {
        if (f(mid) > 0 && (mid == low || f(mid-1) <= 0) ) {
            return mid;
        }

        if (f(mid) <= 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearch1(int low, int high) {
    if (high >= low) {
        int mid = low + (high - low)/2;

        if (f(mid) > 0 && (mid == low || f(mid-1) <= 0)) {
            return mid;
        }

        if (f(mid) <= 0) {
            return binarySearch1((mid+1), high);
        } else {
            return binarySearch1(low, (mid-1));
        }
    }

    return -1;
}

int main() 
{ 
    cout<<"The value n where f() becomes" <<
        "positive first is "<< findFirstPositive(); 
    return 0; 
}