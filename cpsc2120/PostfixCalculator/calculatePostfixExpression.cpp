/*
    Keenan Grant
    CPSC 2070: 002
    9/27/22
*/

#include <string>
#include <stack>
#include <stdexcept>

#include <iostream>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length) {
    stack<string> calculator;
    int num1 = 0;
    int num2 = 0;
    int operand = 0;
    int symbol = 0;

    for (int i = 0; i < length; i++) {
        //Pushes numbers into stack
        if (isdigit(expression[i][0])) {
            calculator.push(expression[i]);
            operand++;
        }

        //Tests if the string is an operator and gathers the numbers to apply them on
        else if (expression[i] == "*" || expression[i] == "/" || expression[i] == "%" || expression[i] == "+" || expression[i] == "-") {
            symbol++;
            if (calculator.size() == 2) {
                num2 = stoi(calculator.top());
                calculator.pop();
                num1 = stoi(calculator.top());
                calculator.pop();
            }

            /*Calculates the postfix expression and
            pushes the answer into the stack*/
            if (expression[i] == "*") {
                calculator.push(to_string(num1 * num2));
            }
            if (expression[i] == "/") {
                if (num2 == 0) {
                    return 0;
                }
                calculator.push(to_string(num1 / num2));
            }
            if (expression[i] == "%") {
                if (num2 == 0) {
                    return 0;
                }
                calculator.push(to_string(num1 % num2));
            }
            if (expression[i] == "+") {
                calculator.push(to_string(num1 + num2));
            }
            if (expression[i] == "-") {
                calculator.push(to_string(num1 - num2));
            }
        }
    }
    if (calculator.empty()) {
        return 0;
    }
    else if (operand != symbol + 1) {
        return 0;
    }
    //Returns final answer
    else {
        return stoi(calculator.top());
    }
}