# Rational-Number-Representation-Using-Class
Book practice project from Problem Solving With C++ Chapter 11. Project 2.

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	rational-number-representation-using-class.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 11. Project 2.
Defining a class to represent rational numbers. Must represent rational numbers as two values of tpe int, one for the numerator and one for the denominator. Demonstrates the ability to use constructors with two arguments that can be used to set the member variables of an object to any legitimate value and to use a constructor with a single paramenter of type int so that the object will be initialized to the rational number wholenumber/1. A default constructor that initializes an object to 0 is also used.  The ability to overload input and output operators is also demonstrated in this program.

Written using Microsoft Visual Studio. 

## Algorithm

- Rational number represented with 2 int values, one for numerator and one for denominator
- Default constructor (init. 0/1); 1-arg constructor (int wholeNumber, init. wholeNumber/1); 2-arg constructor (int x, int y; init. x/y)
- Overload i/o operators - input to take numerator then denominator, output to output "numerator/denominator"
- Overload binary operators ==, <, <=, >, >=, +, -, *, /
- Write test program

    1. Define class RationalNumber
      1.1 (public) RationalNumber(); //initializes object to 0/1
      1.2 (public) RationalNumber(int wholeNumber); //initializes object to wholeNumber/1
      1.3 (public) RationalNumber(int numerator, int denominator); //initializes object to numerator/denominator
      1.4 (public) friend variables
      1.5 (private) int numerator, denominator;
      1.6 (private) void normalize(); //normalizes the object so that if negative, the numerator is negative & the denominator
   2. Declare functions
   3. Int Main
   4. Define Class Functions
    

## Requirements
No requirements or modules needed for running this program. 
