#include <iostream>
using namespace std;

int main(){
    long long n;
    int lucky(0);
    cin >> n;
    while(n != 0){
        if((n % 10 == 4) || (n % 10 == 7)){
            lucky++;
        }
        n /= 10;
    }
    if((lucky == 4) || (lucky == 7)){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}
