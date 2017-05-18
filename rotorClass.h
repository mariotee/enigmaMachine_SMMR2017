/*Programmer: Mario Torres
 *Date Created: 05.16.2017
 *Last Updated: 05.18.2017
 *Description:  this is the header file that will hold the definition
 *              for the class Rotor, which will simulate the rotors used for Enigma M3
 */
#ifndef ROTORCLASS_h
#define ROTORCLASS_h

#include <iostream>
#include <vector>

using namespace std;

class Rotor
{
public:
    //constructor
    Rotor( int wiring, int start );
    //getters and setters
    int getcurrentPos(){return position;}
    char getTurnover(){return turnover;}
    //other methods/functions to be implemented in cpp file
    char getChar( int n ); //to get letter from this rotor
    void rotorStep(){++position; if(position>25){position=0;}}
    int findIndex( char c );     //to get index in letters from char
private:
    //members
    int position;
    vector<char> letters;
    char turnover;
};

#endif // ROTORCLASS_h
