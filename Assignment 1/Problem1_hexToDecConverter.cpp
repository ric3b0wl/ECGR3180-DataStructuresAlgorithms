/*
Design a singly linked list where each node is a char named "value" and has a pointer named "link" pointing to the next node in the list. The link of the last node in the list points to NULL. Write code for the following: 

- The struct described above, name it "digit".

- A class named "hex" to implement a singly-linked list that will contain any number of nodes, dependent on how many digits the user enters. The user will enter the hex digits one at a time and press the Enter key after every digit. When done, the user will enter -1 to signify the end of the linked list.

- When a new digit is entered, it will be stored as a node at the end of the linked list. Create a function named "addDigit" that will implement this functionality.

- The hex class will have a private variable named "count" to keep track of the number of nodes in the linked list and increase it every time a new node is added at the end of the list.

- The first node will have a pointer pointing to it named "head" that will never change its pointing. It points to the MOST SIGNIFICANT digit in the hexadecimal number. This will have an exponent value of count-1.

- A function named "convertToDecimal" that will iterate through all hex digits and convert the value to decimal and return it as an int. See the link at the top of this question for the procedure. The basic procedure is to multiply the hex digit (or its decimal equivalent if above 9) by the weight of each digit (this will be 16 "to the power of" the digit location). For example: hex number 2D9E in decimal is: 2*16^3 + D*16^2 + 9*16^1 + E*16^0 = 2*16^3 + 13*16^2 + 9*16^1 + 14*16^0 = 11678.

- The user may enter only valid hex digits (0 through F), no other input is allowed. If the value entered by the user is invalid, output an error message to the console and store the number entered so far without the invalid input.
*/


#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Hex{
    
private:
    struct digit{

        char value;
        digit* next;

    };
    
    digit* head;
    digit* tail;
    int count;

    digit* iterator;


public:
    Hex(){
        head = new digit{'\0', nullptr};
        tail = head;
        count = 0;
    }
    

    void addDigit(char nextDigit){
        // head MUST point to a valid node
        // NO dummy node can be point to the head
        // NO store state in head or tail where is nullptr

        if (count == 0){
            head -> value = nextDigit;
        }
        else{
            tail -> next = new digit{ nextDigit, nullptr};
            tail = tail -> next;
        }
        count++;
    }

    int getCount(){
        return count;
    }

    ~Hex() {    
        if(count != 0) {
            digit* node = nullptr;

            while(head) {
                node = head->next;
                delete head;
                head = node;
            }
            node = nullptr;
        }

        head = nullptr;
        tail = nullptr;
        iterator = nullptr;
    }

    void resetIterator(){
        iterator = head;
    }

    char getIteratorValue(){
        return iterator -> value;    
    }

    // char incIterator() { //move iterator to next node
	// 	char value = iterator -> value;
	// 	iterator = iterator -> next;
    //     return value;
    // }

    // bool isIteratorValue(){
    //     return iterator == nullptr;
    // }


};


/***********************************************************/
int charToVal(char iteratorValue){
    if (iteratorValue == '0') { return 0; }
    if (iteratorValue == '1') { return 1; }
    if (iteratorValue == '2') { return 2; }
    if (iteratorValue == '3') { return 3; }
    if (iteratorValue == '4') { return 4; }
    if (iteratorValue == '5') { return 5; }
    if (iteratorValue == '6') { return 6; }
    if (iteratorValue == '7') { return 7; }
    if (iteratorValue == '8') { return 8; }
    if (iteratorValue == '9') { return 9; }
    if (iteratorValue == 'a' || iteratorValue == 'A') { return 10; }
    if (iteratorValue == 'b' || iteratorValue == 'B') { return 11; }
    if (iteratorValue == 'c' || iteratorValue == 'C') { return 12; }
    if (iteratorValue == 'd' || iteratorValue == 'D') { return 13; }
    if (iteratorValue == 'e' || iteratorValue == 'E') { return 14; }
    if (iteratorValue == 'f' || iteratorValue == 'F') { return 15; }
    else {return -1;}
}

int convertToDecimal(Hex &number){
    int convertedNumber = 0;
    int exponent = 0;

    number.resetIterator();

    for (int i = 0; i < number.getCount(); ++i){
        exponent = number.getCount() - i - 1;

        int intIteratorValue;
        intIteratorValue = charToVal(number.getIteratorValue());
        convertedNumber += intIteratorValue * pow(16, exponent);
    }

    return convertedNumber;
}


int main(){
    Hex num = Hex();
    char hexDigit;

    while(true){
        cout << "Enter only valid hex digit (0 through F): "  << endl;
        cin >> hexDigit;

        if (hexDigit == '-'){
            cout << "Converted decimal: ";
            break;
        }
        else if (charToVal(hexDigit) == -1){
            cout << "Invalid Digit" << endl;
            break;
        }
        
        num.addDigit(hexDigit);
        
    }
    
    cout << convertToDecimal(num);
}
