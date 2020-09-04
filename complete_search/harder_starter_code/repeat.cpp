#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p_len;
    string s, p;
    bool found_pattern;

    cin >> n;
    cin.ignore();

    while (n--) {
        getline(cin, s);
        p_len = 1;
        // TODO: find smallest possible pattern length
        cout << p_len << endl;
    }

    return 0;
}