#include <bits/stdc++.h>
using namespace std;
int main( ) {
    int n;
    cin >> n;
    int temp = n, x = 0;
    while (temp > 0) {
        //x *= 10;
        x =(x*10)+ (temp % 10);
        temp /= 10;
    }
    cout << n + x << endl;
}
