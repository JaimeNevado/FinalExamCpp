/* **************************************************************/
/*       .-.      _______                 			*/
/*      {}``; |==|_______D                	Jaime Nevado	*/
/*      / ('        /|\                    			*/
/*  (  /  |        / | \         	       2.inorder.cpp	*/
/*  \(_)_]]      /  |  \                   			*/
/*                                        			*/
/* ************************************************************ */

// Design a program that asks the user for a series of words until the word
// "end" is entered.  Saving the non-repeated words that are
// inOrder, that is the words for which their letters are all in order
// (there can be repeated letters in those words).
// Example:
 
// [INPUT]
// Enter a series. end finishes the input:
// i know how all of it is no half of it it is not to do nor aim any end
// [OUTPUT]
// Unique sorted words:
// i know how all it is no not do nor aim any
 
// For this program suppose: (1) There can be an infinite number on the input;
// (2) a final end word will be entered; (3) all the words are lowercase
// (and unlimited in the number of chars); (4) there will be no more than
// MAXNUMSORTEDDIFFWORDS inOrder different words; (5) in between words
// there will be only spaces.
 
 
#include <iostream>
#include <array>

using namespace std;

#include <sstream>
// stringstream str_strm("in a village of la mancha the name of which i have no desire to call to mind \
// there lived not long since one of those gentlemen that keep a lance in the end");

stringstream str_strm("i know how all of it is no half of it is not to do nor aim any end");
 
const int MAXNUMSORTEDDIFFWORDS = 500;
typedef array<string,MAXNUMSORTEDDIFFWORDS> TWords;
 
void add(TWords& ws, string w);
 
int main()
{
    TWords ws;
    string w;
    while (str_strm >> w and w != "end")
        add(ws, w);
 
    int i = 0;
    while (i < MAXNUMSORTEDDIFFWORDS and ws[i] != "")
        cout << ws[i++] << " ";
    cout << endl;
    return 0;
}

bool inOrder(string w);
bool isIn(TWords ws, string w);
void addEnd(TWords& ws, string w);
 
void add(TWords& ws, string w)
{
    if (not isIn(ws, w) and inOrder(w))
        addEnd(ws, w);
}
bool inOrder(string w){
    int i = 1;
    while (i < w.size() and w[i] >= w[i-1])
        ++i;
    return i >= w.size();
}
bool isIn(TWords ws, string w){
    int i = 0;
    while (i < MAXNUMSORTEDDIFFWORDS and ws[i] != "" and ws[i] != w)
        ++i;
    return i < MAXNUMSORTEDDIFFWORDS and ws[i] != "";
}
void addEnd(TWords& ws, string w){
    int i = 0;
    while (i < MAXNUMSORTEDDIFFWORDS and ws[i] != "")
        ++i;
    ws[i] = w;
}
 
