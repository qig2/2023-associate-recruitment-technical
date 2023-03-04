#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool allValid = true;
    vector<string> errors;
    
    for (int i = 0; i < n; i++) {
        string id, isValid;
        string err;
        cin >> id >> isValid;
        if (isValid == "false") {
            cin >> err;
            errors.push_back(err);
        }
        allValid = allValid && (isValid == "true");
    }

    if (allValid) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
        for (int i = 0; i < errors.size(); i++) {
            if (i == 0) cout << errors[i];
            else cout << " " << errors[i];
        }
        cout << endl;
    }
    return 0;
}