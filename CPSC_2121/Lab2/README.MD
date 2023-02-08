Download the starter code and implement the infixToPostfix function in infixToPostfix.cpp to convert an infix arithmetic expression to postfix. This function takes 3 parameters, the first being an array of strings where each string is each part of the expression:

Infix expression: 2 + 3 -> string infix[]: { "2", "+", "3"}

The second parameter is the length of this array, for the array above this will be 3.

The third parameter is where the postfix expression will be written in the same format, the function will assume that this array is at least the same size as the array for the first parameter.

The infix expression 2 + 3 will generate the postfix expression 2 3 + represented in string postfix[]: { "2", "3", "+"}

The value returned by the function will be the length of the postfix expression if no error occured, for 2 + 3 -> 2 3 + the return value is 3.

An error occurs when the function encounters a mismatched parenthesis, in these cases 0 should be returned. Examples of where this would happen would be ( 2 * (3 + 5) and ( 2 + 3 ) * 5).

Other invalid expressions do not need to be accounted for (and a nonzero value may be returned) such as multiple consecutive operator symbols (2 + * 3), expressions missing/without operator symbols (2 3), or expressions with unspecified operator symbols (2 ^ 3).

Operator symbols:
( : left parenthesis, all operations between this and ")" take place first
) : right parenthesis, all op.s back to previous "(" take place first
* : multiplication, higher precedence - takes place before "+" and "-"
/ : division, higher precedence - takes place before "+" and "-"
% : remainder, higher precedence - takes place before "+" and "-"
+ : addition, lower precedence - takes place after "*" , "/" , "%"
- : subtraction, lower precedence - takes place after "*" , "/" , "%"
The function is not specified to work with any other operator symbols.
Any string in infix may be assumed to be an integer operand if none of the above symbols.

A main function is provided to test the infixToPostfix function providing the expression 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8 which should convert to 2 3 4 * + 5 6 - 7 + 8 * +. You may use the STL stack class in the function, the <stack> header file is already #include'd. Submit infixToPostfix.cpp with the implemented infixToPostfix function.
