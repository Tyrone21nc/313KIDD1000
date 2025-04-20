#include <stdio.h>
#include <stdlib.h>


struct Matrix{
int row;
int col;
int matrix[10][10];
};


void PopulateMatrix(int matrix[][10], int row, int col){
    int num = (rand() % 51) + 1;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrix[i][j] = num;
        }
    }
}

void DisplayMatrix(int matrix[][10], int row, int col){
    for(int i=0; i<row; i++){
        print("|");
        for(int j=0; j<col; j++){
            if(matrix[i][j] != 0)
            printf("%d ", matrix[i][j]);
        }
        print("|");
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



void MaitrixAddition(int matrix[][10], int row, int col){




}





int main(){
    printf("SOME WORDS");

    struct Matrix m;
    MaitrixAddition(m.matrix, m.row, m.col);


    return 0;
}





