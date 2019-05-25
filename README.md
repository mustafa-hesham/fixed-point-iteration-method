# fixed-point-iteration-method
A C++ code to find the root of a function using fixed point iteration method
The program asks the user to input each term of the function separately to find the root using fixed point iteration method.
I have updated the code in order to loop through the function terms and avoid terms which give calculation errors (NaN).
The code tests if the relative error of the current iteration is less or greater than the relative error of the previous iteration to output if the function is convergent or divergent.
