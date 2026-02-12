#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char table[n];
    int dist = 0;
    for(int i = 0; i < n; i++){
        cin >> table[i];
        if(i > 0){
            if(table[i-1] == table[i])
                dist++;
        }
    }
    cout << dist;
    return 0;
}
