#include <iostream>

using namespace std;

int main() {
    int n, sum;
    bool even = false, odd = false;
    cin >> n;
    for (int i = 1; i <= 100; i++) {
        if (i + n - 1 <= 100) {
            sum = (n / 2.0) * (i + i + n - 1); // could have used loop instead
            if (sum % 2 == 0)
                even = true;
            else
                odd = true;
        }
    }
        
    if (even && odd)
        cout << "Either";
    else if (even)
        cout << "Even";
    else
        cout << "Odd";

    return 0;
}