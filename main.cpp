/*Programmer: Mario Torres
 *Date Created: 05.02.2017
 *Last Updated: 05.17.2017
 *Description:  main.cpp is the main file for a simulation of the enigma machine
 *              that Alan Turing helped to solve during World War II
 *  based on the Enigma M3, this program will assume the following behaviour:
 *  only lower case letters
 *  three gears: increment every character, turns over when reaches certain character
 *
 *  Gear Wirings (based on Enigma M3)
 *  I:   EKMFLGDQVZNTOWYHXUSPAIBRCJ
 *  II:  AJDKSIRUXBLHWTMCQGZNPYFVOE
 *  III: BDFHJLCPRTXVZNYEIWGAKMUSQO
 *  IV:  ESOVPZJAYQUIRHXLNFTGKDCMWB
 *  V:   VZBRGITYUPSDNHLXAWMJQOFECK
 *
 *  Rotor Turnover (based on Enigma M3)
 *  I:    Q
 *  II:   E
 *  III:  V
 *  IV:   J
 *  V:    Z
 *
 *  Refelctors (based on Wehrmacht & Luffwaffe)
 *  B:  YRUHQSLDPXNGOKMIEBFZCWVJAT
 *  C:  FVPJIAOYEDRZXWGCTKUQSBNMHL
 *
 *  plugboard settings are 10 pairs of letters that will be swapped
 *  (after the first encryption)
 */
#include "rotorClass.h"     //contains <iostream> & <vector>
#include "enigmaClass.h"    //contains <utility> & <unordered_map> & <algorithm> & <cstring>

int checkChoiceR( int c, int defR );    //to check for invalid rotor inputs
int checkChoiceS( int c );      //to check for invalid start positions

using namespace std;

int main( void )
{   //ask user to input the rotors to be used and starting positions
    cout << "This is a simulation for the Enigma M3 encryption machine. This machine utilises three out of five possible rotors.\n";
    cout << "You will choose the three you would like to use by typing in numbers from 1 - 5 and hitting ENTER (no duplicates)\n";
    int choice, r1, r2, r3;
    int defaultRotor = 1;       //in case user inputs invalid input
    cout << "Please pick the first rotor: ";
    cin >> choice;
    cin.ignore();
    r1 = checkChoiceR(choice, defaultRotor);
    ++defaultRotor;
    cout << "Please pick the second rotor: ";
    cin >> choice;
    cin.ignore();
    r2 = checkChoiceR(choice, defaultRotor);
    ++defaultRotor;
    cout << "Please pick the third rotor: ";
    cin >> choice;
    cin.ignore();
    r3 = checkChoiceR(choice, defaultRotor);

    cout << "Now you will pick the three starting positions for each rotor. Each rotor has 26 letters, so pick numbers from 1-26\n";
    int s1, s2, s3;
    cout << "Pick the first starting position: ";
    cin >> choice;
    cin.ignore();
    s1 = checkChoiceS(choice);
    cout << "Pick the second starting position: ";
    cin >> choice;
    cin.ignore();
    s2 = checkChoiceS(choice);
    cout << "Pick the third starting position: ";
    cin >> choice;
    cin.ignore();
    s3 = checkChoiceS(choice);
    cout << endl;
    //create enigma instance to use the encryption machine
    Enigma enigma(r1,r2,r3,s1,s2,s3);
    //setup plugboard settings (pairs of letters to swap)
    enigma.plugboardSetup();
    cout << "\nGreat! Let's get started.\n";
    cout << "Type the message you would like to encrypt and hit ENTER\n";
    string message;
    getline(cin, message);

    enigma.write(message);

    return 0;
 }

int checkChoiceR( int c, int defR )
{
    if( c >= 1 && c <= 5 )
    {
        return c;
    }
    else
    {
        cerr << "ERROR: invalid input! using default rotor " << defR << endl;
        return defR;
    }
}

int checkChoiceS( int c )
{
    if( c >= 1 && c <= 26 )
    {
        return c;
    }
    else
    {
        cerr << "ERROR: invalid input! using default position\n";
        return 1;
    }
}
