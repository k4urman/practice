#include <iostream>
using namespace std;

int main() {
    int n, out, in, x(0), count(0);
    cin >> n;

    while (n--) {
        cin >> out >> in;
        x = (x - out) + in;
        if (count < x) {
            count = x;
        }
    }

    cout << count << endl;
    return 0;
}
