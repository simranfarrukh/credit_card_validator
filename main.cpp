// Credit Card Validator
// @author Simran

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool numberString(const string s){ //to catch non-numeric inputs
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

int main(){
	string creditcard;
	
	cout << "This program works using the Luhn Algorithm to validation a Credit Card number.\n";
	cout << "Enter 'exit' anytime to quit.\n";
	
	while(true){
		cout << "Please enter the Credit Card you need to validate: ";
		cin >> creditcard; //takes input for credit card number
		
		if(creditcard == "exit") //if exit is entered, program ends
			break;
			
		else if(!numberString(creditcard)){
			cout << "Oops! Bad input. Please enter numbers only.";
			continue;
		}
		
		int len = creditcard.length();
		int doubleEvenSum = 0;
		
		//Step 1: double every second digit, starting from right.
		//if results in 2 digit number, add the digits to obtain single digit number.
		//sum all answers to obtain 'doubleEvenSum'
		
		for(int i = len - 2; i >= 0; i = i - 2){
			int dbl = ((creditcard[i] - 48) * 2);
			if (dbl > 9){
				dbl = (dbl / 10) + (dbl % 10);
			}
			doubleEvenSum += dbl;
		}
		
		//Step 2: add every odd placed digit from right to doubleEvenSum's value
		
		for(int i = len - 1; i >= 0; i = i - 2){
			doubleEvenSum += (creditcard[i] - 48);
		}
		
		//Step 3: check if final 'doubleEvenSum' is multiple of 10
		//if yes, it is valid. 
		
		cout << (doubleEvenSum % 10 == 0 ? "Valid" : "Invalid!") << endl;
		
		continue;
	}
	
	return 0;
}
