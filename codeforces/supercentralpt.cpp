/*
165A. Supercentral Point

One day Vasya painted a Cartesian coordinate system on a piece of paper and marked some set of points (x1, y1), (x2, y2), ..., (xn, yn). Let's define neighbors for some fixed point from the given set (x, y):

    point (x', y') is (x, y)'s right neighbor, if x' > x and y' = y
    point (x', y') is (x, y)'s left neighbor, if x' < x and y' = y
    point (x', y') is (x, y)'s lower neighbor, if x' = x and y' < y
    point (x', y') is (x, y)'s upper neighbor, if x' = x and y' > y 

We'll consider point (x, y) from the given set supercentral, if it has at least one upper, at least one lower, at least one left and at least one right neighbor among this set's points.

Vasya marked quite many points on the paper. Analyzing the picture manually is rather a challenge, so Vasya asked you to help him. Your task is to find the number of supercentral points in the given set.
Input

The first input line contains the only integer n (1 ≤ n ≤ 200) — the number of points in the given set. Next n lines contain the coordinates of the points written as "x y" (without the quotes) (|x|, |y| ≤ 1000), all coordinates are integers. The numbers in the line are separated by exactly one space. It is guaranteed that all points are different.
Output

Print the only number — the number of supercentral points of the given set.

8
1 1
4 2
3 1
1 2
0 2
0 1
1 0
1 3

2


5
0 0
0 1
1 0
0 -1
-1 0

1
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count(0);
    cin >> n;
    vector<int> x(n), y(n);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++) {
        bool r(false), l(false), u(false), d(false);

        for(int j = 0; j < n; j++){
            if (x[j] > x[i] && y[j] == y[i]) {
                r = true;
            } else if (x[j] < x[i] && y[j] == y[i]) {
                l = true;
            } else if (x[j] == x[i] && y[j] < y[i]) { 
                u = true;
            } else if (x[j] == x[i] && y[j] > y[i]) {
                d = true;
            }
        }
        if (r && l && u && d) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
