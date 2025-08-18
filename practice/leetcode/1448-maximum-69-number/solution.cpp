

bool isNine(int n){
    if(n == 0){
        return false;
    }
    while (n> 0) {
        if (n % 10 != 9) {
            return false;
        }
        n /= 10;
    }
    return true;
}

class Solution {
public:
    int maximum69Number (int num) {
        if(isNine(num)){
            return num;
        } else if(num > 1000 && num < 9000){
            return num + 3000;
        } else if((num > 100 && num < 900) || (num > 1000 && num < 9900)){
            return num + 300;
        } else if((num > 10 && num < 90) || (num > 100 && num < 990) || (num > 1000 && num < 9990)){
            return num + 30;
        } else if((num > 1 && num < 9) || (num > 10 && num < 99) || (num > 100 && num < 999) || (num > 1000 && num < 9999)){
            return num + 3;
        }
        return 0;
    }
};
