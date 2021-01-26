#include <iostream>

using namespace std;

int sumDigits(int num){ //* assume digit, d = 123 
    
    //# if sum is 0; return 0
    if (num == 0){
        return 0;
    }
    else{
        //# d = num % 10, get right most digit
        int endDigit = num % 10; //* 123 % 10 = 3
        
        //# next_num = num / 10, int only keep the most whole number
        int next_num = num / 10; //* 123 / 10 = 12

        //# return d + sumDigit(next_num)
        return (endDigit + sumDigits(next_num));

    }
}


int main(){
    //~ int testingDigit = 5823; // 5 + 8 + 2 + 3 = 18

    int inputDigit;
    cout << "Enter Digit: ";
    cin >> inputDigit;

    //~ cout << sumDigits(testingDigit) << endl;
    cout << "Sum of Digit: " << sumDigits(inputDigit) << endl;
}