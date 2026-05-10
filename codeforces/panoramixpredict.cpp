#include <iostream>
using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int nextPrime(int y) {
    int p = y;
    bool found = false;
    while(!found) {
        p++;
        if(isPrime(p)) {
            found = true;
        }
    }
    return p;
}

int main(){
    int n, m;
    cin >> n >> m;
    int a = nextPrime(n);
    if(a == m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
