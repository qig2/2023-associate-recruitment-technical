#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string cur;
    vector<int> shop(2004, 0);
    vector<int> req(2004, 0);
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (cur.back() == 'S') {
            shop[1000 - (cur.size() - 1)]++;
        } else if (cur.back() == 'L') {
            shop[1002 + cur.size() - 1]++;
        } else if (cur == "M") {
            shop[1001]++;
        } else {
            printf("error\n");
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (cur.back() == 'S') {
            req[1000 - (cur.size() - 1)]++;
        } else if (cur.back() == 'L') {
            req[1002 + cur.size() - 1]++;
        } else if (cur == "M") {
            req[1001]++;
        } else {
            printf("error\n");
        }
    }
    int cursum = shop[2003];
    for (int i = 2002; i >= 0; i--) {
        shop[i] += cursum;
        cursum = shop[i];
    }
    cursum = req[2003];
    for (int i = 2002; i >= 0; i--) {
        req[i] += cursum;
        if (req[i] > shop[i]) {
            cout << "No" << endl;
            return 0;
        }
        cursum = req[i];
    }
    cout << "Yes" << endl;
    return 0;
}