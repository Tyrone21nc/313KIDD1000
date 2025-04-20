#include <stdio.h>
#include <stdlib.h>


struct Matrix{
int row;
int col;
int matrix[10][10];
};


void PopulateMatrix(int matrix[][10], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int num = (rand() % 51) + 1;
            matrix[i][j] = num;
        }
    }
}

void DisplayMatrix(int matrix[][10], int row, int col){
    for(int i=0; i<row; i++){
        printf("|");
        for(int j=0; j<col; j++){
            if(matrix[i][j] != 0)
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

void DisplayBothMatrix(int matrix1[][10], int row1, int col1, int matrix2[][10], int row2, int col2) {
    printf("\033[33mFIRST MATRIX\033[0m\n");
    for (int i = 0; i < row1; i++) {
        printf("|");
        for (int j = 0; j < col1; j++) {
            if (matrix1[i][j] != 0)
                printf("%d ", matrix1[i][j]);
        }
        printf("|\n");
    }

    printf("\033[33mSECOND MATRIX\033[0m\n");
    for (int i = 0; i < row2; i++) {
        printf("|");
        for (int j = 0; j < col2; j++) {
            if (matrix2[i][j] != 0)
                printf("%d ", matrix2[i][j]);
        }
        printf("|\n");
    }
}


void MatrixAddition(int matrix1[][10], int row1, int col1, int matrix2[][10], int row2, int col2) {
    printf("\033[34m*****PERFORMING MATRIX ADDITION...*****\033[0m\n");

    if (!((row1 > 1 && row1 <= 10 && col1 > 1 && col1 <= 10) &&
          (row1 == col1 && row2 == col2 && row1 == row2 && col1 == col2))) {
        printf("\033[31mCANNOT PERFORM Matrix addition, needs same dimensions!\033[0m\n");
        return;
    }

    DisplayBothMatrix(matrix1, row1, col1, matrix2, row2, col2);

    // Perform matrix addition
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Display result
    printf("\033[32mFINAL MATRIX\033[0m\n");
    DisplayMatrix(matrix1, row1, col1);
}
void ScalarMatrixMultiplication(int scalar, int matrix[][10], int row, int col){
    printf("\033[34m*****PERFORMING MATRIX SCALAR MULTIPLICATION...*****\033[0m\n");
    if(scalar > 1000000){
        printf("\033[31mCANNOT PERFORM Matrix scalar multiplication, scalar too big!\033[0m\n");
        return;
    }
    printf("\033[33mORIGINAL MATRIX\033[0m\n");
    DisplayMatrix(matrix, row, col);
    printf("\033[33mSCALAR:\033[0m %d\n", scalar);
    /*
    A: |1 3|    scalar = 2
       |5 7|
       
       A+B:|1*2 3*2|  => |2 6|
        |5*2 7*2|  => |10 14|
        */
   // perform scalar multiplication
   for(int i=0; i<row; i++){
       for(int j=0; j<col; j++){
           matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    // display the current matrix again
    printf("\033[32mFINAL MATRIX\033[0m\n");
    DisplayMatrix(matrix, row, col);
}

void MatrixMultiplication(int matrix1[][10], int row1, int col1, int matrix2[][10], int row2, int col2) {
    printf("\033[34m*****PERFORMING MATRIX MULTIPLICATION...*****\033[0m\n");

    if (!(row1 > 1 && row1 <= 10 && col1 > 1 && col1 <= 10 &&
          col1 == row2)) {
        printf("\033[31mCANNOT PERFORM Matrix multiplication, dimensions must match (A: row x **col**, B: **row** x col)!\033[0m\n");
        return;
    }

    DisplayBothMatrix(matrix1, row1, col1, matrix2, row2, col2);

    int result[10][10] = {0};

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Copy result back to matrix1
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            matrix1[i][j] = result[i][j];
        }
    }

    printf("\033[32mFINAL MATRIX\033[0m\n");
    DisplayMatrix(matrix1, row1, col2);
}
void MatrixTransposal(int matrix[][10], int row, int col) {
    printf("\033[34m*****PERFORMING MATRIX TRANSPOSAL...*****\033[0m\n");

    int tempMatrix[10][10];

    printf("\033[33mORIGINAL MATRIX\033[0m\n");
    DisplayMatrix(matrix, row, col);

    // Transpose into tempMatrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            tempMatrix[j][i] = matrix[i][j];
        }
    }

    // Clear original matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
    int temp = row;
    row = temp;
    col = temp;
    // Copy transposed values back (swapped loop dimensions)
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }

    printf("\033[32mFINAL MATRIX\033[0m\n");
    DisplayMatrix(matrix, col, row);
}




int main(){
    struct Matrix m1;
    struct Matrix m2;

    #define ROW1 3
    #define COL1 3
    #define ROW2 3 
    #define COL2 3
    #define SCALAR 2
    PopulateMatrix(m1.matrix, ROW1, COL1);
    PopulateMatrix(m2.matrix, ROW2, COL2);
    printf("\n");
    // DisplayMatrix(m2.matrix, ROW2, COL2);
    MatrixAddition(m1.matrix, ROW1, COL1, m2.matrix, ROW2, COL2);
    // after the addition generate new numbers (to delete the addition process)
    PopulateMatrix(m1.matrix, ROW1, COL1);
    PopulateMatrix(m2.matrix, ROW2, COL2);
    MatrixMultiplication(m1.matrix, ROW1, COL1, m2.matrix, ROW2, COL2);
    // after the multiplication, generate new number (to delete the multiplication process)
    PopulateMatrix(m1.matrix, ROW1, COL1);
    PopulateMatrix(m2.matrix, ROW2, COL2);
    ScalarMatrixMultiplication(SCALAR, m1.matrix, ROW1, COL1);
    // after the scaling, we reset the numbers
    PopulateMatrix(m1.matrix, ROW1, COL1);
    PopulateMatrix(m2.matrix, ROW2, COL2);
    MatrixTransposal(m1.matrix, ROW1, COL1);
    // then we reset again in case we want to do more applications
    PopulateMatrix(m1.matrix, ROW1, COL1);
    PopulateMatrix(m2.matrix, ROW2, COL2);



    return 0;
}





