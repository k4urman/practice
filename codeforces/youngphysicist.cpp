




// FINAL ATTEMPT - ACCEPTED
#include <iostream>
using namespace std;

int main()
{
    int n, x, y, z, xsum(0), ysum(0), zsum(0);
    cin >> n;

    while (n--)
    {
        cin >> x >> y >> z;
        xsum += x;
        ysum += y;
        zsum += z;
    }

    if (xsum == 0 && ysum == 0 && zsum == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

/* SECOND ATTEMPT

#include <iostream>
using namespace std;

int main(){
    int n, x, y, z;
    int xsum, ysum, zsum = 0;
    
    cin >> n;
    
    while (n != 0){
        cin >> x >> y >> z;
        xsum += x;
        ysum += y;
        zsum += z;
    }
    
    if((xsum && ysum && zsum) == 0){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}
*/


/* FIRST ATTEMPT

#include <iostream>
using namespace std;

int main(){
    int n, x, y, z;
    int xsum, ysum, zsum = 0;
    
    cin >> n;
    
    while (n != 0){
        cin >> x >> y >> z;
        xsum += x;
        ysum += y;
        zsum += z;
    }
    
    if((xsum && ysum && zsum) == 0){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}

 * */
