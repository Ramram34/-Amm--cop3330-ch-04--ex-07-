/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Rami Amm
 */
#include "std_lib_facilities.h"

vector<string> numbers;	// representation of numbers as strings
						// numbers[i] is the string representation for i
						// for numbers[0] to numbers[numbers.size()-1]

void initialize_numbers()
{
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
	numbers.push_back("ten");	// why not? :-)
}

int get_number()
/*
	An apology: To use cin again after a failed read, you need to use a function call "cin.clear();" to "clear" it.
	That isn't explained in the book until chapter 10. Sorry.

	Solutions that do not use this technique can get very complicated.
*/
{
	const int not_a_symbol = numbers.size();	// not_a_symbol is a value that does not correspond
												// to a string in the numbers vector
	int val = not_a_symbol;
	if (cin>>val) return val; // try to read an integer composed of digits

	cin.clear();	// clear string after failed attempt to read an integer
	string s;
	cin>>s;
	for (int i=0; i<numbers.size(); ++i)	// see if the string is in numbers
		if (numbers[i]==s) val = i;
	if (val==not_a_symbol) error("unexpected number string: ",s);
	return val;
}

int main()
try
{
	initialize_numbers();

	cout<< "please enter two floating-point values separated by an operator\n The operator can be + - * / % : ";
	
	while (true) {	// "forever"; that is until we give an unacceptable input or make a computations error
		int val1 = get_number();

		char op = 0;
		cin>>op; // get the operator
		
		int val2 = get_number();

		string oper;	// text appropriate for an operator
		double result;

		switch (op) {
		case '+':
			oper = "sum of ";
			result = val1+val2; 
			break;
		case '-':
			oper = "difference between ";
			result = val1-val2; 
			break;
		case '*':
			oper = "product of ";
			result = val1*val2; 
			break;
		case '/':
			oper = "ratio of ";
			if (val2==0) error("trying to divide by zero");
			result = val1/val2; 
			break;
		case '%':
			oper = "remainder of ";
			if (val2==0) error("trying to divide by zero (%)");
			result = val1%val2; 
			break;
		default:
				error("bad operator");
		}
		cout << oper << val1 << " and " << val2 << " is " << result << '\n';
		cout << "Try again: ";
	}
}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << e.what() << '\n';
	keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << "exiting\n";
	keep_window_open("~");	// For some Windows(tm) setups
}