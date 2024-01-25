
#include <iostream>
#include <string>

using namespace std;

int s1, s2, s4;
bool hamCode[7];
bool* m = hamCode;  //pointer to hamCode for easier access

void strToArr(string);
int errorCheck(bool, bool, bool, bool);
void errorLoc(int, int, int);
void displayMessage(bool*);
void translateMessage(bool, bool, bool, bool);

int main()
{
    cout << "Enter desired Hamming Code: ";
    string line;           //take input as string literal then use strToArr to change it to a bool array
    getline(cin, line);
    strToArr(line);
    //algorithm for Hamming Code
    s1 = errorCheck(hamCode[0], hamCode[2], hamCode[4], hamCode[6]);
    s2 = errorCheck(hamCode[1], hamCode[2], hamCode[5], hamCode[6]);
    s4 = errorCheck(hamCode[3], hamCode[4], hamCode[5], hamCode[6]);

    errorLoc(s1, s2, s4);
    displayMessage(m);
    translateMessage(hamCode[2], hamCode[4], hamCode[5], hamCode[6]);
}

void strToArr(string s) {
    for (int i = 0; i < 7; i++) {    //take first 7 inputs and translate to bool array[7] 
        if (s[i] == '1') {
            m[i] = 1;
        }
        else {
            m[i] = 0;        //NO EXCEPTION HANDLING IN CODE, so false to all non-1 inputs handles them for the purpose of this lab
        }
    }
}
int errorCheck(bool a, bool b, bool c, bool d) {  //input the 4 bits to check
    int res = 0;
    if (a == 1) {
        res += 1;
    }
    if (b == 1) {
        res += 1;
    }
    if (c == 1) {
        res += 1;
    }
    if (d == 1) {
        res += 1;
    }
    res = res % 2;
    return res;
}
void errorLoc(int s1, int s2, int s4) {
    int loc = 0;
    loc += (s1 * 1);   //worth 2^0
    loc += (s2 * 2);   //worth 2^1
    loc += (s4 * 4);   //worth 2^2

    if (loc == 0) {
        cout << "No error in code delivered." << endl;
    }
    else {
        cout << "Error found in bit " << loc << endl;     //display bit that is corrupted
        hamCode[loc - 1] = !hamCode[loc - 1];             //flip the affected bit
        cout << "Corrected code is ";
        for (int k = 0; k < 7; k++) {
            hamCode[k];
        }
    }
}
void displayMessage(bool* m) {     //uses bool pointer to determine and display message bits
    cout << "Message in binary is:  ";
    cout << m[2] << m[4] << m[5] << m[6] << endl;
}
void translateMessage(bool m3, bool m5, bool m6, bool m7) {
    int total = 0;
    if (m3 == 1) {    //bit 3 worth 2^3
        total += 8;
    }
    if (m5 == 1) {    //bit 5 worth 2^2
        total += 4;
    }
    if (m6 == 1) {    //bit 6 worth 2^1
        total += 2;
    }
    if (m7 == 1) {    //bit 7 worth 2^0
        total += 1;
    }
    cout << "The translated message in decimal is:  " << total << endl;
}
