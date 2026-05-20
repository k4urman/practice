/*
151A. Soft Drinking

This winter is so cold in Nvodsk! A group of n friends decided to buy k bottles of a soft drink called "Take-It-Light" to warm up a bit. Each bottle has l milliliters of the drink. Also they bought c limes and cut each of them into d slices. After that they found p grams of salt.

To make a toast, each friend needs nl milliliters of the drink, a slice of lime and np grams of salt. The friends want to make as many toasts as they can, provided they all drink the same amount. How many toasts can each friend make?
Input

The first and only line contains positive integers n, k, l, c, d, p, nl, np, not exceeding 1000 and no less than 1. The numbers are separated by exactly one space.
Output

Print a single integer — the number of toasts each friend can make.

3 4 5 10 8 100 3 1
2

5 100 10 1 19 90 4 3
3

10 1000 1000 25 23 1 50 1
0
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int mltoasts = (k * l)/ nl;
    int limes = c * d;
    int salt = p/np;

    cout << (min({mltoasts, limes, salt}))/n << endl;
    return 0;
}
