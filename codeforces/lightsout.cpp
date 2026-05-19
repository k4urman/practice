#include <iostream>
#include <vector>

using namespace std;

int main() {
    int toggles[5][5] = {0};
    int input;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> input;

            toggles[i][j] += input;
            toggles[i-1][j] += input;
            toggles[i+1][j] += input;
            toggles[i][j-1] += input;
            toggles[i][j+1] += input;
        }
    }

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {

            cout << (toggles[i][j] % 2 == 0 ? 1 : 0);

        }
        cout << endl;
    }

    return 0;
}

