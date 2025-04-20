#include <iostream>
#include <algorithm>    // used for random num generator
#include <random>       // used for random num generator
using namespace std;


// RANDOM NUMBER GENERATOR START
// RANDOM NUMBER GENERATOR START
// RANDOM NUMBER GENERATOR START
enum RANDOM {UNIFORMINT, UNIFORMREAL, NORMAL, SHUFFLE};
class Random {
public:
    Random(){}
    Random(int min, int max, RANDOM type=UNIFORMINT, int mean=50, int stdev=20) : m_min(min), m_max(max), m_type(type)
    {
        if (type == NORMAL){
            //the case of NORMAL to generate integer numbers with normal distribution
            m_generator = std::mt19937(m_device());
            //the data set will have the mean of 50 (default) and standard deviation of 20 (default)
            //the mean and standard deviation can change by passing new values to constructor 
            m_normdist = std::normal_distribution<>(mean,stdev);
        }
        else if (type == UNIFORMINT) {
            //the case of UNIFORMINT to generate integer numbers
            // Using a fixed seed value generates always the same sequence
            // of pseudorandom numbers, e.g. reproducing scientific experiments
            // here it helps us with testing since the same sequence repeats
            m_generator = std::mt19937(10);// 10 is the fixed seed value
            m_unidist = std::uniform_int_distribution<>(min,max);
        }
        else if (type == UNIFORMREAL) { //the case of UNIFORMREAL to generate real numbers
            m_generator = std::mt19937(10);// 10 is the fixed seed value
            m_uniReal = std::uniform_real_distribution<double>((double)min,(double)max);
        }
        else { //the case of SHUFFLE to generate every number only once
            m_generator = std::mt19937(m_device());
        }
    }
    void setSeed(int seedNum){
        // we have set a default value for seed in constructor
        // we can change the seed by calling this function after constructor call
        // this gives us more randomness
        m_generator = std::mt19937(seedNum);
    }
    void init(int min, int max){
        m_min = min;
        m_max = max;
        m_type = UNIFORMINT;
        m_generator = std::mt19937(10);// 10 is the fixed seed value
        m_unidist = std::uniform_int_distribution<>(min,max);
    }
    void getShuffle(vector<int> & array){
        // this function provides a list of all values between min and max
        // in a random order, this function guarantees the uniqueness
        // of every value in the list
        // the user program creates the vector param and passes here
        // here we populate the vector using m_min and m_max
        for (int i = m_min; i<=m_max; i++){
            array.push_back(i);
        }
        shuffle(array.begin(),array.end(),m_generator);
    }

    void getShuffle(int array[]){
        // this function provides a list of all values between min and max
        // in a random order, this function guarantees the uniqueness
        // of every value in the list
        // the param array must be of the size (m_max-m_min+1)
        // the user program creates the array and pass it here
        vector<int> temp;
        for (int i = m_min; i<=m_max; i++){
            temp.push_back(i);
        }
        std::shuffle(temp.begin(), temp.end(), m_generator);
        vector<int>::iterator it;
        int i = 0;
        for (it=temp.begin(); it != temp.end(); it++){
            array[i] = *it;
            i++;
        }
    }

    int getRandNum(){
        // this function returns integer numbers
        // the object must have been initialized to generate integers
        int result = 0;
        if(m_type == NORMAL){
            //returns a random number in a set with normal distribution
            //we limit random numbers by the min and max values
            result = m_min - 1;
            while(result < m_min || result > m_max)
                result = m_normdist(m_generator);
        }
        else if (m_type == UNIFORMINT){
            //this will generate a random number between min and max values
            result = m_unidist(m_generator);
        }
        return result;
    }

    double getRealRandNum(){
        // this function returns real numbers
        // the object must have been initialized to generate real numbers
        double result = m_uniReal(m_generator);
        // a trick to return numbers only with two deciaml points
        // for example if result is 15.0378, function returns 15.03
        // to round up we can use ceil function instead of floor
        result = std::floor(result*100.0)/100.0;
        return result;
    }

    string getRandString(int size){
        // the parameter size specifies the length of string we ask for
        // to use ASCII char the number range in constructor must be set to 97 - 122
        // and the Random type must be UNIFORMINT (it is default in constructor)
        string output = "";
        for (int i=0;i<size;i++){
            output = output + (char)getRandNum();
        }
        return output;
    }
    
    int getMin(){return m_min;}
    int getMax(){return m_max;}
    private:
    int m_min;
    int m_max;
    RANDOM m_type;
    std::random_device m_device;
    std::mt19937 m_generator;
    std::normal_distribution<> m_normdist;//normal distribution
    std::uniform_int_distribution<> m_unidist;//integer uniform distribution
    std::uniform_real_distribution<double> m_uniReal;//real uniform distribution
};
// RANDOM NUMBER GENERATOR END
// RANDOM NUMBER GENERATOR END
// RANDOM NUMBER GENERATOR END

















class Matrix{

public:
    Matrix(int row=3, int col=3){
        if(row>1 && row<=10 && col>1 && col<=10){
            m_row = row;
            m_col = col;
        }
        else{
            m_row = 3;
            m_col = 3;
        }
        PopulateMatrix();    // then we call display matrix to populate the matrix
    }
    void PopulateMatrix(){
        Random r(1, 51);      // min is 0 max is 50
        for(int i=0; i<m_row; i++){
            for(int j=0; j<m_col; j++){
                m_matrix[i][j] = r.getRandNum();
            }
        }
    }
    void DisplayMatrix(){
        for(int i=0; i<m_row; i++){
            cout << "|";
            for(int j=0; j<m_col; j++){
                if(m_matrix[i][j] != 0)
                    cout << m_matrix[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
    void DisplayBothMatrix(int matrix[][10], int row, int col){
        cout << "\033[33mFIRST MATRIX\033[0m" << endl;
        for(int i=0; i<m_row; i++){
            cout << "|";
            for(int j=0; j<m_col; j++){
                if(m_matrix[i][j] != 0)
                    cout << m_matrix[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "\033[33mSECOND MATRIX\033[0m" << endl;
        for(int i=0; i<row; i++){
            cout << "|";
            for(int j=0; j<col; j++){
                if(m_matrix[i][j] != 0)
                    cout << matrix[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
    void MatrixAddition(int matrix[][10], int row, int col){
        cout << "\033[34m*****PERFORMING MATRIX ADDITION...*****\033[0m" << endl;
        if(!((row>1 && row<=10 && col>1 && col<=10) && (row == col && m_row == m_col && m_row == row && m_col == col)) ){
            cout << "\033[31mCANNOT PERFORM Matrix addition, needs same dimensions!\033[0m" << endl;
            return;
        }
        DisplayBothMatrix(matrix, row, col);    // display both matrices
        /*
        A: |1 3|      B: |2 4|
           |5 7|         |6 8|
        
        A+B:|1+2 3+4|   |3 7|
            |5+6 7+8|   |11 15|
        */
       // perform matrix addition
       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               m_matrix[i][j] = m_matrix[i][j] + matrix[i][j];
            }
        }
        // display the current matrix again
        cout << "\033[32mFINAL MATRIX\033[0m" << endl;
        DisplayMatrix();
    }
    void ScalarMatrixMultiplication(int scalar){
        cout << "\033[34m*****PERFORMING MATRIX SCALAR MULTIPLICATION...*****\033[0m" << endl;
        if(scalar > 1000000){
            cout << "\033[31mCANNOT PERFORM Matrix scalar multiplication, scalar too big!\033[0m" << endl;
            return;
        }
        cout << "\033[33mORIGINAL MATRIX\033[0m" << endl;
        DisplayMatrix();
        cout << "\033[33mSCALAR:\033[0m " << scalar << endl;
        /*
        A: |1 3|    scalar = 2
           |5 7|
           
           A+B:|1*2 3*2|  => |2 6|
            |5*2 7*2|  => |10 14|
            */
       // perform scalar multiplication
       for(int i=0; i<m_row; i++){
           for(int j=0; j<m_col; j++){
               m_matrix[i][j] = m_matrix[i][j] * scalar;
            }
        }
        // display the current matrix again
        cout << "\033[32mFINAL MATRIX\033[0m" << endl;
        DisplayMatrix();
    }
    void MatrixMultiplication(int matrix[][10], int row, int col){
        cout << "\033[34m*****PERFORMING MATRIX MULTIPLICATION...*****\033[0m" << endl;
        if(!((row>1 && row<=10 && col>1 && col<=10) && (row == col && m_row == m_col && m_row == row && m_col == col)) ){
            cout << "\033[31mCANNOT PERFORM Matrix multiplication, needs same dimensions!\033[0m" << endl;
            return;
        }
        DisplayBothMatrix(matrix, row, col);    // display both matrices
        /*
        A: |1 2|      B: |5 6|
           |3 4|         |7 8|
        
        A+B:|(1)(5)+(2)(7) (1)(6)+(2)(8)|   |19 22|
            |(3)(5)+(4)(7) (3)(6)+(4)(8)|   |43 50|
        */
       // perform matrix multiplication
       for(int i=0; i<row-1; i++){
           for(int j=0; j<col-1; j++){
               m_matrix[i][j] = (m_matrix[i][j] * matrix[i][j]) + (m_matrix[i+0][j+1] * matrix[i+1][j+0]);
            }
        }
        // display the current matrix again
        cout << "\033[32mFINAL MATRIX\033[0m" << endl;
        DisplayMatrix();
    }
    void MatrixTransposal(){
        cout << "\033[34m*****PERFORMING MATRIX TRANSPOSAL...*****\033[0m" << endl;
        int tempMatrix[10][10];
        cout << "\033[33mORIGINAL MATRIX\033[0m" << endl;
        DisplayMatrix();
        // the copy process
        for(int i=0; i<m_row; i++){
            for(int j=0; j<m_col; j++){
                tempMatrix[j][i] = m_matrix[i][j];
            }
        }
        for(int i=0; i<m_row; i++){
            for(int j=0; j<m_col; j++){
                m_matrix[i][j] = 0;
            }
        }
        // we now swap the values of the row and col
        int temp = m_row;
        m_row = m_col;
        m_col = temp;
        for(int i=0; i<m_row; i++){
            for(int j=0; j<m_col; j++){
                m_matrix[i][j] = tempMatrix[i][j];
            }
        }
        cout << "\033[32mFINAL MATRIX\033[0m" << endl;
        DisplayMatrix();
    }

private:
    int m_row;
    int m_col;
    int m_matrix[10][10];

};






int main(){
    Matrix m(3, 3);
    // m.DisplayMatrix();
    const int row = 3;
    const int col = 3;
    int matrix[row][10] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    m.MatrixAddition(matrix, row, col);
    cout << endl;
    m.ScalarMatrixMultiplication(2);
    cout << endl;
    m.MatrixMultiplication(matrix, row, col);
    cout << endl;
    m.MatrixTransposal();
    cout << endl;

    return 0;
}
