#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i, int j);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
    srand((unsigned)time(NULL));

    int low = -42;
    int high = 51;

    int rowCount = 7;
    int colCount = 6;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, low, high, 0, 0);
    Print(a, rowCount, colCount, 0, 0);
    Sort(a, rowCount, colCount, 0, 0);
    Print(a, rowCount, colCount, 0, 0);

    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int low, const int high, int i, int j)
{
    a[i][j] = low + rand() % (high - low + 1); 

    if (j < colCount - 1) {
        Create(a, rowCount, colCount, low, high, i, j + 1); 
    }
    else if (i < rowCount - 1) {
        Create(a, rowCount, colCount, low, high, i + 1, 0); 
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];

    if (j < colCount - 1) {
        Print(a, rowCount, colCount, i, j + 1); 
    }
    else {
        cout << endl;
        if (i < rowCount - 1) {
            Print(a, rowCount, colCount, i + 1, 0);
        }
        else {
            cout << endl;
        }
    }
}

void Sort(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i < rowCount - 1) {
        if (j < rowCount) {
            if (a[i][0] > a[j][0] ||
                (a[i][0] == a[j][0] && a[i][1] < a[j][1]) ||
                (a[i][0] == a[j][0] && a[i][1] == a[j][1] && a[i][2] > a[j][2])) {
                Change(a, i, j, colCount, 0); 
            }
            Sort(a, rowCount, colCount, i, j + 1);
        }
        Sort(a, rowCount, colCount, i + 1, i + 2);
    }
}


void Change(int** a, const int row1, const int row2, const int colCount, int j)
{
    if (j < colCount) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
        Change(a, row1, row2, colCount, j + 1); 
    }
}


void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (!(a[i][j] > 0 && a[i][j] % 5 == 0)) {
        S += a[i][j];  
        k++;          
        a[i][j] = 0;    
    }

    if (j < colCount - 1) {
        Calc(a, rowCount, colCount, S, k, i, j + 1); 
    }
    else {
        if (i < rowCount - 1) {
            Calc(a, rowCount, colCount, S, k, i + 1, 0); 
        }
    }
}