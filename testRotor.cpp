/*Programmer: Mario Torres
 *Date Created: 05.16.2017
 *Last Updated: 05.17.2017
 *Description:  this is a test file for the rotor Class that is used in the Enigma machine simulation
 */
#include "rotorClass.h"

int alphaInt( char c );
char intAlpha( int n );

int /*main*/rotorTest( void )
{
    Rotor r(1,0); //wiring, start position
    char input = 'a';
    int thisP = r.getcurrentPos();
    int n = int(input) - 97 + thisP;
    char output1 = r.getChar(n);
    output1-=thisP; //should be 'e'

    input = 'c';
    thisP = r.getcurrentPos();
    n = int(input) - 97 + thisP;
    char output2 = r.getChar(n);
    output2-=thisP; //should be 'e' again (coincidental)

    (output1 == 'e' && output2 == 'e')? cout << "test pass" : cout << "test fail";

    return 0;
}
