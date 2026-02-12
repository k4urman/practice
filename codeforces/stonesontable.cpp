/*
A. Stones on the Table
There are n stones on the table in a row, each of them can be red, green or blue. Count the minimum number of stones to take from the table so that any two neighboring stones had different colors. Stones in a row are considered neighboring if there are no other stones between them.
Input
The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.
The next line contains string s, which represents the colors of the stones. We'll consider the stones in the row numbered from 1 to n from left to right. Then the i-th character s equals "R", if the i-th stone is red, "G", if it's green and "B", if it's blue.
Output
Print a single integer — the answer to the problem.

3
RRG
1

5
RRRRR
4

4
BRBG
0
*/


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
