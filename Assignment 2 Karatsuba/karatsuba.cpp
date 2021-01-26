/* Karatsuba multiplication */
#include <iostream>
#include <math.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int numDigits(int num);
int pow10(int n);



int karatsuba(int x, int y){
    /* Wikipedia Pseudocode
        
    if (num1 < 10) or (num2 < 10)
    return num1 × num2
    
    //~ Calculates the size of the numbers.
    m = min(size_base10(num1), size_base10(num2))
    m2 = floor(m / 2) 
    //~ m2 = ceil(m / 2) will also work 
    
    //~ Split the digit sequences in the middle.
    high1, low1 = split_at(num1, m2)
    high2, low2 = split_at(num2, m2)
    
    //~ 3 calls made to numbers approximately half the size.
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)
    
    return (z2 × 10 ^ (m2 × 2)) + ((z1 - z2 - z0) × 10 ^ m2) + z0

    */

    //* assume x = 5678, y = 1234
        //* a = 56, b = 78, c = 12, d = 34
        //* x*y = (10^(n/2))*(a*c) + (10^(n/2)*(a*d + b*c) + (b*d)

    //# compute a*c, a*d, b*c, b*d
    int xDigit = numDigits(x);
    int yDigit = numDigits(y);

    int largerDigit = MAX(xDigit, yDigit);

    if(largerDigit < 10 ){ return x*y;}
    largerDigit = (largerDigit / 2) + (largerDigit % 2); //first digits + last digit

    int high1 = x / pow10(largerDigit);
    int low1 = x - (high1 * pow10(largerDigit));
    int high2 = y / pow10(largerDigit);
    int low2 = y - (high2 * largerDigit);

    int z0 = karatsuba(low1, low2);
    int z1 = karatsuba((low1 + high1), (low2 + high2));
    int z2 = karatsuba(high1, high2);


    //# compute x*y and return
    int z = ((z1 - z2 - z0) * pow10(largerDigit)) + (z2 * pow10(2 * largerDigit)) + z0;
    return z; // z = x*y

}

// Helper function - returns number of digits
int numDigits(int num) {
    int count = 0;

    //# count down to 0, if not count++
    while(true){
        if (num != 0){
            count++;
            num = num / 10;
        }
        else{
            break;
        }
    }

    //# return number of digits (count)
    return count;
}

// Helper function - integer exponentiation
int pow10(int n) {

    // pow() in <math.h> only can be use with double, float & long double
    return (int)pow(10.0, (float)n); // casting to int from float
    
}





