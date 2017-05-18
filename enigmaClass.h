/*Programmer: Mario Torres
 *Date Created: 05.16.2017
 *Last Updated: 05.18.2017
 *Description:  this is the header file that will hold the definition
 *              for the class Enigma, which simulates the Enigma M3 machine
 */
#ifndef ENGIMACLASS_h
#define ENGIMACLASS_h

#include "rotorClass.h"

#include <utility>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

class Enigma
{
public:
    //constructor
    Enigma( int r1, int r2, int r3, int s1, int s2, int s3 );
    //getters and setters

    Rotor getRotor1(){return rotor1;}
    Rotor getRotor2(){return rotor2;}
    Rotor getRotor3(){return rotor3;}

    //other methods/functions to be implemented in cpp file
    void plugboardSetup();  //to set up plugboard pairs
    void write( string message );   //to write a message (will also be used to decrypt
    char writeRotorF( Rotor r, char c );
    char writeRotorR( Rotor r, char c );

private:
    //members
    Rotor rotor1;
    Rotor rotor2;
    Rotor rotor3;
    unordered_map<char, char> plugboardPairs;
    unordered_map<char,char> reflector;
};

#endif // ENGIMACLASS_h
