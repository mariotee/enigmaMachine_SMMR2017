/*Programmer: Mario Torres
 *Date Created: 05.16.2017
 *Last Updated: 05.18.2017
 *Description:  this is the cpp file that will hold the implementations
 *              for the class Rotor, which will simulate the rotors used for Enigma M3
 */
#include "rotorClass.h"

Rotor::Rotor( int wiring, int start )
{   //set position, should be from 1-26 if main program works correctly
    this->position = start;
    //depending on user input, different wirings will be used for each rotor
    switch( wiring )
    {
        case 1:
            this->letters = {'e', 'k', 'm', 'f', 'l', 'g', 'd', 'q', 'v', 'z', 'n', 't', 'o',
                             'w', 'y', 'h', 'x', 'u', 's', 'p', 'a', 'i', 'b', 'r', 'c', 'j'};
            this->turnover = 'q';
            break;
        case 2:
            this->letters = {'a', 'j', 'd', 'k', 's', 'i', 'r', 'u', 'x', 'b', 'l', 'h', 'w',
                             't', 'm', 'c', 'q', 'g', 'z', 'n', 'p', 'y', 'f', 'v', 'o', 'e'};
            this->turnover = 'e';
            break;
        case 3:
            this->letters = {'b', 'd', 'f', 'h', 'j', 'l', 'c', 'p', 'r', 't', 'x', 'v', 'z',
                             'n', 'y', 'e', 'i', 'w', 'g', 'a', 'k', 'm', 'u', 's', 'q', 'o'};
            this->turnover = 'v';
            break;
        case 4:
            this->letters = {'e', 's', 'o', 'v', 'p', 'z', 'j', 'a', 'y', 'q', 'u', 'i', 'r',
                             'h', 'x', 'l', 'n', 'f', 't', 'g', 'k', 'd', 'c', 'm', 'w', 'b'};
            this->turnover = 'j';
            break;
        case 5:
            this->letters = {'v', 'z', 'b', 'r', 'g', 'i', 't', 'y', 'u', 'p', 's', 'd', 'n',
                             'h', 'l', 'x', 'a', 'w', 'm', 'j', 'q', 'o', 'f', 'e', 'c', 'k'};
            this->turnover = 'z';
            break;
        default:
            cerr << "ERROR: invalid wiring! using default mapping 1\n";
            this->letters = {'e', 'k', 'm', 'f', 'l', 'g', 'd', 'q', 'v', 'z', 'n', 't', 'o',
                             'w', 'y', 'h', 'x', 'u', 's', 'p', 'a', 'i', 'b', 'r', 'c', 'j'};
            this->turnover = 'q';
            break;
    }
}

char Rotor::getChar( int n )
{
    return letters[n];
}

int Rotor::findIndex( char c )
{
    int i = 0;
    vector<char>::iterator it = letters.begin();

    while( *it != c ){++i;++it;}

    return i;
}
