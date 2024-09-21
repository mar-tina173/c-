#include <iostream>
#include <vector>  
#include <string>  
using namespace std;

int main()
{
    int rowsA, colsA, rowsB, colsB;
    string input; 
    
   
    cout << "Enter the number of rows and columns in the A Matriz (rows*columns): ";
    cin >> input;

   
    size_t pos = input.find('*');
    if (pos != string::npos) 
    {
        rowsA = stoi(input.substr(0, pos)); 
        colsA = stoi(input.substr(pos + 1));
    } 
    else
    {
        cout << "Invalid format! try again.";
        return 1; 
    }


    cout << "Enter the number of rows and columns in the B Matriz (rows*columns): ";
    cin >> input;

   
    pos = input.find('*');
    if (pos != string::npos) 
    {
        rowsB = stoi(input.substr(0, pos));  
        colsB = stoi(input.substr(pos + 1)); 
    }
    else 
    {
        cout << "Invalid format! try again.";
        return 1;  
    }

    vector<vector<int>> A(rowsA, vector<int>(colsA)); 
    vector<vector<int>> B(rowsB, vector<int>(colsB));  

 
    cout << "Enter the elements of matrix A (" << rowsA << "x" << colsA << "):\n";
    for (int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> A[i][j];
        }
    }

   
    cout << "Enter the elements of matrix B (" << rowsB << "x" << colsB << "):\n";
    for (int i = 0; i < rowsB; i++) 
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> B[i][j];
        }
    }

  
    do {
        if (rowsA == rowsB && colsA == colsB)
        {
            cout << "Addition of matrices A and B:\n";
            for (int i = 0; i < rowsA; i++) 
            {
                for (int j = 0; j < colsA; j++) 
                {
                    cout << A[i][j] + B[i][j] << " ";
                }
                cout << endl;
            }
        }
        else 
        {
            cout << "Addition not permitted: matrices have different dimensions.\n";
        }
    } while (false);


    do 
    {
        if (rowsA == rowsB && colsA == colsB)
        {
            cout << "Subtraction of matrices A and B:\n";
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < colsA; j++)
                {
                    cout << A[i][j] - B[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Subtraction not permitted: matrices have different dimensions.\n";
        }
    } while (false);

    do
    {
        if (colsA == rowsB)
        {
            vector<vector<int>> result(rowsA, vector<int>(colsB, 0));  
            cout << "Multiplication of matrices A and B:\n";
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < colsB; j++) 
                {
                    for (int k = 0; k < colsA; k++) 
                    {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Multiplication not permitted: number of columns of A must equal number of rows of B.\n";
        }
    } while (false);

    return 0;
}
