#include <iostream>
#include <time.h>
using namespace std;

void ThirdMatrix(int **a1, int **a2, int r1, int c1, int r2, int c2)
{
    srand(time(NULL));
    int **arr3 = new int *[r1];
    for (int i = 0; i < r1; i++)
    {
        arr3[i] = new int[c2];
    }
    
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < r2; k++)
            {
                arr3[i][j] += a1[i][k] * a2[k][j]; // a1 - в одной строке по разным столбцам, а2 - в столбце по каждой строке
            }
        }
    }
    
    cout<<"___________________"<<endl<<endl;
    
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<r1; j++)
        {
            cout<<arr3[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=0; i<r1; i++)
    {
        delete [] *(a1 + i);
    }
    delete [] a1;
    
    for(int i=0; i<r2; i++)
    {
        delete [] *(a2 + i);
    }
    delete [] a2;
}

int main(int argc, const char * argv[])
{
    int cols1; // по-вертикали
    cout<<"Количество столбцов 1 матрицы-> "<<endl;
    cin >> cols1;

    int rows1; // по-горизонтали
    cout<<"Количество строк 1 матрицы-> "<<endl;
    cin >> rows1;

    int cols2; // по-вертикали
    cout<<"Количество столбцов 2 матрицы-> "<<endl;
    cin >> cols2;

    int rows2; // по-горизонтали
    cout<<"Количество строк 2 матрицы->"<<endl;
    cin >> rows2;
    
    cout<<endl;
    
    if(cols1 == rows2)
    {
        int **arr1 = new int *[rows1];
        for(int i=0; i<rows1; i++)
        {
            *(arr1 + i) = new int [cols1];
        }
        for(int i=0; i<rows1; i++)
        {
            for(int j=0; j<cols1; j++)
            {
                arr1[i][j] = rand() % 10 + 1;
            }
        }
        
        int **arr2 = new int *[rows2];
        for(int i=0; i<rows2; i++)
        {
            *(arr2 + i) = new int [cols2];
        }
        for(int i=0; i<rows2; i++)
        {
            for(int j=0; j<cols2; j++)
            {
                arr2[i][j] = rand() % 10 + 1;
            }
        }
        
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols1; j++)
            {
                cout<<arr1[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"____________________"<<endl;
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < cols2; j++)
            {
                cout<<arr2[i][j]<<"\t";
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        ThirdMatrix(arr1, arr2, rows1, cols1, rows2, cols2);
    }
    else
    {
        cout<<"Error!"<<endl;
    }
    
    
}

