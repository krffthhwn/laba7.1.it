#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** R, const int rowCount, const int colCount);
void Sort(int** R, const int rowCount, const int colCount);
void Change(int** R, const int col1, const int col2, const int rowCount);
void Sum_Count_Replace(int** R, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    int Low = -6;
    int High = 31;
    int rowCount = 7;
    int colCount = 5;
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];
    cout << "Start Matrix: " << endl;
    Create(R, rowCount, colCount, Low, High);
    Print(R, rowCount, colCount);
    cout << "Sorted Matrix: " << endl;
    Sort(R, rowCount, colCount);
    Print(R, rowCount, colCount);
    int S = 0;
    int k = 0;
    Sum_Count_Replace(R, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << " " << endl;
    cout << "Modified Matrix: " << endl;
    Print(R, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;
    return 0;
}

void Create(int** R, const int rowCount, const int colCount, const int Low,
    const int High)
{
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            R[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** R, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << R[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** R, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = R[i][col1];
        R[i][col1] = R[i][col2];
        R[i][col2] = tmp;
    }
}

void Sort(int** R, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((R[0][j1] < R[0][j1 + 1]) ||
                (R[0][j1] == R[0][j1 + 1] && R[1][j1] > R[1][j1 + 1]) ||
                (R[0][j1] == R[0][j1 + 1] && R[1][j1] == R[1][j1 + 1] && R[2][j1] < R[2][j1 + 1]))
                Change(R, j1, j1 + 1, rowCount);
}

void Sum_Count_Replace(int** R, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (R[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
                S += R[i][j];
                k++;
                R[i][j] = 0;
            }
        }
    }
}