# This is HW8, the matrix library is done in C++ and in C


##To compile my code just do the regular compilation commands for c++ and c files:
#For C++:
g++ -Wall matrix.cpp -o matrix1
#for C
gcc -Wall matrix.c -o matrix2


##For trying out different types of matrices, just alter it in the main.
#For C++:
1. Change the value to your prefered matrix size (line 3(25-26) ):
const int row = 3;
const int col = 3;
2. Then have your matrix match your new matrix accordingly:
int matrix[row][10] = {
  {1,2,3},
  {4,5,6},
  {7,8,9},
};
3. Some of these operations cannot work on matrices with different rows and
columns values, such as row mult or addition, so just change the matrices
accordingly.
#For C:
1. To change the dimensions, you can just change it directly from the constant
variables with the #defined as the keyword.
2. That's all the change you need to do because I regenerate new random data for
both matrices so, nothing else to do.
   

