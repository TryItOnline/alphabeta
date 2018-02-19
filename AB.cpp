#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Num_char = 0;
int Position = 0;
int NewPosition = 0;

int Character;
string Program[10000];

string Result;
int Register1 = 0;
int Register2 = 0;
int Register3 = 0;
int Register4[] = { 0, 0 };
int Mode = 0;
int Memory[1024];
int Temp;

int main(int argc, char *argv[])
{
    FILE * FileInd;
    
    FileInd = fopen(argv[1],"r");
    
    do {
        Character = getc(FileInd);
        Program[Num_char] = Character;
        Num_char ++;
        
        } while ( Character != EOF );
    
    fclose(FileInd);
    
    do {
        NewPosition = Position;

        if ( Program[Position] == "a" ) { Register1 += 1 ;}
        if ( Program[Position] == "b" ) { Register1 -= 1 ;}
        if ( Program[Position] == "c" ) { Register1 += 10 ;}
        if ( Program[Position] == "d" ) { Register1 -= 10 ;}
        if ( Program[Position] == "e" ) { Register1 += 100 ;}
        if ( Program[Position] == "f" ) { Register1 -= 100 ;}
        if ( Program[Position] == "g" ) { Register2 += 1 ;}
        if ( Program[Position] == "h" ) { Register2 -= 1 ;}
        if ( Program[Position] == "i" ) { Register2 += 10 ;}
        if ( Program[Position] == "j" ) { Register2 -= 10 ;}
        if ( Program[Position] == "k" ) { Register2 += 100 ;}
        if ( Program[Position] == "l" ) { Register2 -= 100 ;}
        if ( Program[Position] == "m" ) { Register3 = !Register1 ;}
        if ( Program[Position] == "n" ) { Register3 = !Register2 ;}
        if ( Program[Position] == "o" ) { Register3 = Register1 and Register2 ;}
        if ( Program[Position] == "p" ) { Register3 = Register1 or Register2 ;}
        if ( Program[Position] == "q" ) { Register3 = Register1 xor Register2 ;}
        if ( Program[Position] == "q" ) { Register3 = Register1 xor Register2 ;}
        if ( Program[Position] == "r" ) { Register3 = Register1 + Register2 ;}
        if ( Program[Position] == "s" ) { Register3 = Register1 - Register2 ;}
        if ( Program[Position] == "t" ) { Register3 = Register1 * Register2 ;}
        if ( Program[Position] == "u" ) { Register3 = Register1 / Register2 ;}
        if ( Program[Position] == "v" ) { Register3 = Register1 % Register2 ;}
        if ( Program[Position] == "w" ) { Register3 = Register1 ^ Register2 ;}
        if ( Program[Position] == "x" ) { Register1 = 0 ;}
        if ( Program[Position] == "y" ) { Register2 = 0 ;}
        if ( Program[Position] == "z" ) { Register3 = 0 ;}
        if ( Program[Position] == "A" ) { Register2 = Register1 ;}
        if ( Program[Position] == "B" ) { Register1 = Register2 ;}
        if ( Program[Position] == "C" ) { Register3 = Register1 ;}
        if ( Program[Position] == "D" ) { Register3 = Register2 ;}
        if ( Program[Position] == "E" ) { Register1 = Register3 ;}
        if ( Program[Position] == "F" ) { Register2 = Register3 ;}
        if ( Program[Position] == "G" ) { Register1 = Memory[Register4[0]] ;}
        if ( Program[Position] == "H" ) { Register2 = Memory[Register4[0]] ;}
        if ( Program[Position] == "I" ) { Memory[Register4[0]] = Register3 ;}
        if ( Program[Position] == "J" ) { if (( Temp = getchar()) != EOF ) Register1 = Temp ;}
        if ( Program[Position] == "K" ) { if (( Temp = getchar()) != EOF ) Register2 = Temp ;}
        if ( Program[Position] == "L" ) { cout << char(Register3) ;}
        if ( Program[Position] == "M" ) { cout << int(Register3) ;}
        if ( Program[Position] == "N" ) { if ( Register1 == Register2 ) NewPosition = Register4[1];}
        if ( Program[Position] == "O" ) { if ( Register1 != Register2 ) NewPosition = Register4[1];}
        if ( Program[Position] == "P" ) { if ( Register1 >= Register2 ) NewPosition = Register4[1];}
        if ( Program[Position] == "Q" ) { if ( Register1 <= Register2 ) NewPosition = Register4[1];}
        if ( Program[Position] == "R" ) { if ( Register3 == 0 ) NewPosition = Register4[1] - 1;}
        if ( Program[Position] == "S" ) { Register4[Mode] += 1 ;}
        if ( Program[Position] == "T" ) { Register4[Mode] -= 1 ;}
        if ( Program[Position] == "U" ) { Register4[Mode] += 10 ;}
        if ( Program[Position] == "V" ) { Register4[Mode] -= 10 ;}
        if ( Program[Position] == "W" ) { Register4[Mode] += 100 ;}
        if ( Program[Position] == "X" ) { Register4[Mode] -= 100 ;}
        if ( Program[Position] == "Y" ) { Register4[Mode] = 0 ;}
        if ( Program[Position] == "Z" ) { Mode = ( Mode + 1 ) % 2 ;}
        
        Position = (Position == NewPosition) ? Position + 1 : NewPosition;
        } while ( Position <= Num_char );
        
    return ( 1 );
}
