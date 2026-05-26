#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int s1, s2, s3;
    double a, b, c;

    cin >> s1 >> s2 >> s3;
    a = sqrt((s1*s2)/s3);
    b = sqrt((s1*s3)/s2);
    c = sqrt((s2*s3)/s1);
    int result = 4 * (int)(a + b + c);

    cout << result << endl;
    return 0;
}
