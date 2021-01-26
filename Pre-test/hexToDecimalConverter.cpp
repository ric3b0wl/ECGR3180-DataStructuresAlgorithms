/*
ECGR 3180 Fall 2020
Pre-test
Question 1:

The following problem involves the design of an unsigned hexadecimal/hex (base-16) to decimal (base-10) converter. The conversion can be done using the decimal equivalent of each hex digit multiplied by the weight of the digit. More information on the conversion and a calculator can be found at: https://www.binaryhexconverter.com/hex-to-decimal-converter
All variable names will be given in double quotes in the prompt below to ensure all variables are named correctly.


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

using namespace std;

class hex
{
	private:
		struct digit
		{
			char value;
			digit* next;
		};

		digit* head;
		digit* tail;
		int count;

		digit* iterator;
	public:
		hex() {
			head = new digit{ '\0', nullptr };
			tail = head;
			count = 0;
		}

		void resetIterator() {
			iterator = head;
		}

		char incIterator() {
			char value = iterator->value;
			iterator = iterator->next;
			return value;
		}

		char getIteratorValue() {
			return iterator->value;
		}

		bool isIteratorEnd() {
			return iterator == nullptr;
		}

		void addDigit(char nextDigit) {
			// note that the head must always point to a valid node
			// meaning we cant put in a dummy node that sits at the head
			// nor can we have a state where the head and tail is nullptr
			if (count == 0) {
				head->value = nextDigit;
			} else {
				tail->next = new digit{ nextDigit, nullptr };
				tail = tail->next;
			}
			count++;
		}

		int getCount() {
			return count;
		}
};

/*******************************************************************/

int main() 
{
	
	// WRITE TEST CODE HERE, THE MORE TESTS THE BETTER.
	// ADD COMMENTS FOR EACH TEST CASE.
	
}