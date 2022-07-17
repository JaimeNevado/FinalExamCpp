/* **************************************************************/
/*       .-.      _______                 			*/
/*      {}``; |==|_______D                	Jaime Nevado	*/
/*      / ('        /|\                    			*/
/*  (  /  |        / | \         	  	1.pascal.cpp	*/
/*  \(_)_]]      /  |  \                   			*/
/*                                        			*/
/* ************************************************************ */
 
#include <iostream>
#include <array>
using namespace std;
 
const int N = 7;
 
typedef array<int, N> TRow;
typedef array<TRow, N> TSqMat;
 
TSqMat fillMatrix();
void printMatrix(TSqMat a);
 
int main()
{
    printMatrix(fillMatrix());
    return 0;
}
 
TSqMat fillMatrix()
{
    TSqMat a;
    for (int row = 1 ; row < N ; row++)
        for (int col = 1 ; col < N ; col++)
            a[row][col] = 0;
 
    for (int i = 0 ; i < N ; i++)
        a[0][i] = a[i][0] = 1;
 
    for (int row = 1 ; row < N ; row++)
        for (int col = 1 ; col < N - row ; col++)
            a[row][col] = a[row][col - 1] + a[row - 1][col];
 
    return a;
}
 
void printMatrix(TSqMat a)
{
    for (int row = 0 ; row < N ; row++) {
        for (int col = 0 ; col < N ; col++)
            if (a[row][col] != 0)
                cout << a[row][col] << " ";
        cout << endl;
    }
}
