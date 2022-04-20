//I am slightly editing SO much of this for the next project
#include <iostream>

//define class
class RationalNumber {
public:
	RationalNumber(); //initializes object to 0/1
	RationalNumber(int wholeNumber); //initializes object to wholeNumber/1
	RationalNumber(int numerator, int denominator); //initializes object to numerator/denominator
	friend RationalNumber operator + (const RationalNumber& left, const RationalNumber& right);
	friend RationalNumber operator - (const RationalNumber& left, const RationalNumber& right);
	friend RationalNumber operator * (const RationalNumber& left, const RationalNumber& right);
	friend RationalNumber operator / (const RationalNumber& left, const RationalNumber& right);
	friend bool operator < (const RationalNumber& left, const RationalNumber& right);
	friend bool operator <= (const RationalNumber& left, const RationalNumber& right);
	friend bool operator > (const RationalNumber& left, const RationalNumber& right);
	friend bool operator >= (const RationalNumber& left, const RationalNumber& right);
	friend bool operator == (const RationalNumber& left, const RationalNumber& right);
	friend std::istream& operator >> (std::istream& inStream, RationalNumber& input);
	friend std::ostream& operator << (std::ostream& outStream, const RationalNumber& output);
private:
	int numerator, denominator;
	void normalize(); //normalizes the object so that if negative, the numerator is negative & the denominator is positive
};

//declare functions
void testConditionals(const RationalNumber& first, const RationalNumber& second);
//precondition: first and second are initialized RationalNumber objects
//postcondition: compares first and second with operators <, <=, >, >=, ==; outputs results to screen
void outputCondition(bool aBool); //outputs TRUE to screen if aBool == true; else, outputs FALSE to screen
void testEquations(const RationalNumber& first, const RationalNumber& second);
//precondition: first and second are initialized RationalNumber objects
//postcondition: compares first and second with operators +, -, * and /

//main
int main()
{
	using namespace std;
	RationalNumber zero, five(5), half(1, -2);
	//test constructors and i/o
	cout << zero << endl << five << endl << half << endl
		<< "Enter a new value for half:\n";
	cin >> half;
	cout << "New value: " << half << endl;
	//test conditionals
	testConditionals(zero, half);
	testConditionals(five, half);
	//test equations
	testEquations(five, half);
	testEquations(zero, half);
	return 0;
}

//define class functions
RationalNumber::RationalNumber() : numerator(0), denominator(1) {/*empty*/ }
RationalNumber::RationalNumber(int wholeNumber) : numerator(wholeNumber), denominator(1) {/*empty*/ }
RationalNumber::RationalNumber(int numerator, int denominator) : numerator(numerator), denominator(denominator) { normalize(); }

RationalNumber operator+(const RationalNumber& left, const RationalNumber& right)
{
	long leftDenom = static_cast<long>(left.denominator), rightDenom = static_cast<long>(right.denominator);
	long newDenominator = leftDenom * rightDenom;
	long newNumerator = (static_cast<long>(left.numerator) * rightDenom) + (static_cast<long>(right.numerator) * leftDenom);
	for (long i = newDenominator; i > 1; --i)
	{
		if (newNumerator % i == 0 && newDenominator % i == 0)
		{
			newNumerator /= i;
			newDenominator /= i;
			break;
		}
	}
	return RationalNumber(static_cast<int>(newNumerator), static_cast<int>(newDenominator));
}

RationalNumber operator-(const RationalNumber& left, const RationalNumber& right)
{
	long leftDenom = static_cast<long>(left.denominator), rightDenom = static_cast<long>(right.denominator);
	long newDenominator = leftDenom * rightDenom;
	long newNumerator = (static_cast<long>(left.numerator) * rightDenom) - (static_cast<long>(right.numerator) * leftDenom);
	for (long i = newDenominator; i > 1; --i)
	{
		if (newNumerator % i == 0 && newDenominator % i == 0)
		{
			newNumerator /= i;
			newDenominator /= i;
			break;
		}
	}
	return RationalNumber(static_cast<int>(newNumerator), static_cast<int>(newDenominator));
}

RationalNumber operator*(const RationalNumber& left, const RationalNumber& right)
{
	RationalNumber product(left.numerator * right.numerator, left.denominator * right.denominator);
	return product;
}

RationalNumber operator/(const RationalNumber& left, const RationalNumber& right)
{
	RationalNumber quotient(left.numerator * right.denominator, left.denominator * right.numerator);
	return quotient;
}

bool operator < (const RationalNumber& left, const RationalNumber& right)
{
	return (left.numerator * right.denominator < left.denominator * right.numerator);
}
bool operator <= (const RationalNumber& left, const RationalNumber& right)
{
	return (left.numerator * right.denominator <= left.denominator * right.numerator);
}
bool operator > (const RationalNumber& left, const RationalNumber& right)
{
	return (left.numerator * right.denominator > left.denominator * right.numerator);
}
bool operator >= (const RationalNumber& left, const RationalNumber& right)
{
	return (left.numerator * right.denominator >= left.denominator * right.numerator);
}
bool operator == (const RationalNumber& left, const RationalNumber& right)
{
	return (left.numerator * right.denominator == left.denominator * right.numerator);
}

std::istream& operator >> (std::istream& inStream, RationalNumber& input)
{
	char next;
	inStream >> input.numerator; //should grab #s before /
	inStream.get(next); //should clear /
	inStream >> input.denominator; //should grab #s after /
	input.normalize();
	return inStream;
}

std::ostream& operator << (std::ostream& outStream, const RationalNumber& output)
{
	outStream << output.numerator << "/" << output.denominator;
	return outStream;
}

void RationalNumber::normalize()
{
	//ensure proper positive/negative positions
	if (numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	else if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	//convert to smallest form
	for (int i = denominator; i > 1; --i)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
			break;
		}
	}
	return;
}

//define functions
//uses <iostream>
void testConditionals(const RationalNumber& first, const RationalNumber& second)
{
	using namespace std;
	cout << first << " compared to " << second << endl
		<< first << " less than " << second << "?\n";
	outputCondition(first < second);
	cout << first << " less than/equal to " << second << "?\n";
	outputCondition(first <= second);
	cout << first << " greater than " << second << "?\n";
	outputCondition(first > second);
	cout << first << " greater than/equal to " << second << "?\n";
	outputCondition(first >= second);
	cout << first << " equal to " << second << "?\n";
	outputCondition(first == second);
	return;
}
//uses <iostream>
void outputCondition(bool aBool) 
{	
	if (aBool) std::cout << "TRUE\n"; 
	else /*(if aBool == false)*/ std::cout << "FALSE\n"; 
	return;
}
//uses <iostream>
void testEquations(const RationalNumber& first, const RationalNumber& second)
{
	using namespace std;
	cout << first << " + " << second << " = " << first + second << endl
		<< first << " - " << second << " = " << first - second << endl
		<< first << " * " << second << " = " << first * second << endl
		<< first << " / " << second << " = " << first / second << endl;
	return;
}
