/* **************************************************************/
/*       .-.      _______                 			*/
/*      {}``; |==|_______D                	Jaime Nevado	*/
/*      / ('        /|\                    			*/
/*  (  /  |        / | \         	  	     ej1.cpp	*/
/*  \(_)_]]      /  |  \                   			*/
/*                                        			*/
/* ************************************************************ */
 
#include <iostream>
#include <array>

using namespace std;
 
const int NRows = 2;
const int NCols = 3;
 
typedef array<int,NCols> TRow;
typedef array<TRow,NRows> TMat;
typedef array<TRow,2*NRows> TMat2;
 
void print(TMat m);
void print2(TMat2 m);
 
TMat2 scaleup(TMat m);
 
int main()
{
    TMat m = {{
        {{3, 2, 5}},
        {{6, 5, 3}}
    }};
    print(m);
    cout << "->" << endl;
    print2(scaleup(m));
 
    return 0;
}
 
int mean(TMat m);
int avrg(TMat2 m, int mMean, int row, int col);
 
TMat2 scaleup(TMat m)
{
    TMat2 r;
 
    // 1. mMean
    int mMean = mean(m);
 
    // 2. copy even rows
    for (int row = 0; row < NRows; ++row)
        r[2*row] = m[row];
 
    // 3.
    for (int row = 1; row < 2*NRows; row+=2)
        for (int col = 0; col < NCols; ++col)
            r[row][col] = 0;
 
    for (int row = 1; row < 2*NRows; row+=2)
        for (int col = 0; col < NCols; ++col)
            r[row][col] = avrg(r, mMean, row, col);
    return r;
}
 
void addornot(int& r, int& cnt, int mMean, TMat2 m, int row, int col);
 
int avrg(TMat2 m, int mMean, int row, int col)
{
    int cnt = 0;
    int r = 0;
    for (int drow = -1; drow <= 1; ++drow)
        for (int dcol = -1; dcol <= 1; ++dcol)
            if (not(drow == 0 and dcol == 0))
                addornot(r, cnt, mMean, m, row+drow, col+dcol);
    return r/cnt;
}
 
void addornot(int& r, int& cnt, int mMean, TMat2 m, int row, int col)
{
    if (row >= 0 and row < 2*NRows and
        col >= 0 and col < NCols) {
        ++cnt;
        r += (m[row][col] != 0)? m[row][col] : mMean;
    }
}
 
int mean(TMat m)
{
    int s = 0;
    for (int row = 0; row < NRows; ++row)
        for (int col = 0; col < NCols; ++col)
            s += m[row][col];
    return s/(NRows*NCols);
}
 
void print(TMat m)
{
    for (int row = 0; row < NRows; ++row) {
        for (int col = 0; col < NCols; ++col)
            cout << m[row][col] << " ";
        cout << endl;
    }
}
 
void print2(TMat2 m)
{
    for (int row = 0; row < 2*NRows; ++row) {
        for (int col = 0; col < NCols; ++col)
            cout << m[row][col] << " ";
        cout << endl;
    }
}
 
