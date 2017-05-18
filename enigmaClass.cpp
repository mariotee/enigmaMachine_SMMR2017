/*Programmer: Mario Torres
 *Date Created: 05.16.2017
 *Last Updated: 05.18.2017
 *Description:  this is the cpp file that will hold the implementations
 *              for the class Enigma, which will simulate the Enigma M3 machine
 */
#include "enigmaClass.h"

const int ALPHA = 26;
const int ASCII = 97;

Enigma::Enigma( int r1, int r2, int r3, int s1, int s2, int s3 ) :
    rotor1{Rotor(r1,s1-1)},
    rotor2{Rotor(r2,s2-1)},
    rotor3{Rotor(r3, s3-1)}
    {}

void Enigma::plugboardSetup()
{
    int c;  //user choice
    cout << "The user must choose a reflector to use for this machine.\n";
    cout << "This piece of equipment will increase randomness.\n";
    cout << "Choose a reflector by entering a number and hitting ENTER.\n";
    cout << "(1) Wehrmacht or (2)Lluftwaffe: ";
    cin >> c;
    cin.ignore();
    switch(c)
    {   //creates reflector map based on user input
        case 1:
            reflector.emplace('a','y');
            reflector.emplace('b','r');
            reflector.emplace('c','u');
            reflector.emplace('d','h');
            reflector.emplace('e','q');
            reflector.emplace('f','s');
            reflector.emplace('g','l');
            reflector.emplace('h','d');
            reflector.emplace('i','p');
            reflector.emplace('j','x');
            reflector.emplace('k','n');
            reflector.emplace('l','g');
            reflector.emplace('m','o');
            reflector.emplace('n','k');
            reflector.emplace('o','m');
            reflector.emplace('p','i');
            reflector.emplace('q','e');
            reflector.emplace('r','b');
            reflector.emplace('s','f');
            reflector.emplace('t','z');
            reflector.emplace('u','c');
            reflector.emplace('v','w');
            reflector.emplace('w','v');
            reflector.emplace('x','j');
            reflector.emplace('y','a');
            reflector.emplace('z','t');
            break;
        case 2:
            reflector.emplace('a','f');
            reflector.emplace('b','v');
            reflector.emplace('c','p');
            reflector.emplace('d','j');
            reflector.emplace('e','i');
            reflector.emplace('f','a');
            reflector.emplace('g','o');
            reflector.emplace('h','y');
            reflector.emplace('i','e');
            reflector.emplace('j','d');
            reflector.emplace('k','r');
            reflector.emplace('l','z');
            reflector.emplace('m','x');
            reflector.emplace('n','w');
            reflector.emplace('o','g');
            reflector.emplace('p','c');
            reflector.emplace('q','t');
            reflector.emplace('r','k');
            reflector.emplace('s','u');
            reflector.emplace('t','q');
            reflector.emplace('u','s');
            reflector.emplace('v','b');
            reflector.emplace('w','n');
            reflector.emplace('x','m');
            reflector.emplace('y','h');
            reflector.emplace('z','l');
            break;
        default:
            cerr << "ERROR! that was not a choice. using default Wehrmacht setting.\n";
            reflector.emplace('a','y');
            reflector.emplace('b','r');
            reflector.emplace('c','u');
            reflector.emplace('d','h');
            reflector.emplace('e','q');
            reflector.emplace('f','s');
            reflector.emplace('g','l');
            reflector.emplace('h','d');
            reflector.emplace('i','p');
            reflector.emplace('j','x');
            reflector.emplace('k','n');
            reflector.emplace('l','g');
            reflector.emplace('m','o');
            reflector.emplace('n','k');
            reflector.emplace('o','m');
            reflector.emplace('p','i');
            reflector.emplace('q','e');
            reflector.emplace('r','b');
            reflector.emplace('s','f');
            reflector.emplace('t','z');
            reflector.emplace('u','c');
            reflector.emplace('v','w');
            reflector.emplace('w','v');
            reflector.emplace('x','j');
            reflector.emplace('y','a');
            reflector.emplace('z','t');
            break;
    }

    cout << "Now the user must set up the plugboard.\n";
    cout << "The plugboard is an interface that will swap two letters after the initial encryption.\n";
    cout << "This provides an even higher level of encryption for your message.\n";
    cout << "There are ten pairs of letters that you will be selecting. Please type one lowercase letter at a time and hit ENTER (no duplicates)\n";
    char letters[20];
    vector<char> lettersUsed;
    for( int i = 0; i < 20; ++i )
    {
        cout << "input a letter for pair #" << (i+2)/2 << ": " << endl; //to get clean numbers 1-10
        cin >> letters[i];
        cin.ignore();
        while( std::find(lettersUsed.begin(),lettersUsed.end(),letters[i]) != lettersUsed.end() )
        {
            cout << "that seems to be a duplicate\n";
            cout << "input a letter for pair #" << (i+2)/2 << ": " << endl;
            cin >> letters[i];
            cin.ignore();
        }
        lettersUsed.push_back(letters[i]);
    }
    //set up plugboard mapping each pair to each other
    //pair#1
    plugboardPairs.emplace(letters[0],letters[1]);
    plugboardPairs.emplace(letters[1],letters[0]);
    //pair#2
    plugboardPairs.emplace(letters[2],letters[3]);
    plugboardPairs.emplace(letters[3],letters[2]);
    //pair#3
    plugboardPairs.emplace(letters[4],letters[5]);
    plugboardPairs.emplace(letters[5],letters[4]);
    //pair#4
    plugboardPairs.emplace(letters[6],letters[7]);
    plugboardPairs.emplace(letters[7],letters[6]);
    //pair#5
    plugboardPairs.emplace(letters[8],letters[9]);
    plugboardPairs.emplace(letters[9],letters[8]);
    //pair#6
    plugboardPairs.emplace(letters[10],letters[11]);
    plugboardPairs.emplace(letters[11],letters[10]);
    //pair#7
    plugboardPairs.emplace(letters[12],letters[13]);
    plugboardPairs.emplace(letters[13],letters[12]);
    //pair#8
    plugboardPairs.emplace(letters[14],letters[15]);
    plugboardPairs.emplace(letters[15],letters[14]);
    //pair#9
    plugboardPairs.emplace(letters[16],letters[17]);
    plugboardPairs.emplace(letters[17],letters[16]);
    //pair#10
    plugboardPairs.emplace(letters[18],letters[19]);
    plugboardPairs.emplace(letters[19],letters[18]);
}

void Enigma::write( string message )
{   //create a character array of size message (will ignore null terminating char)
    char characters[message.size()];
    //copy string to char array
    strcpy(characters, message.c_str());

    for( int i = 0; i < message.size(); ++i )
    {   //first check for turnover
        bool rotorFlag1 = false;
        bool rotorFlag2 = false;
        if( rotor3.getTurnover() == char(ASCII + rotor3.getcurrentPos()) )
        {
            rotorFlag1 = true;
        }
        //get original input
        char input = characters[i];
        if( input == ' ' )
        {
            cout << ' ';
        }
        else
        {
            //initial swap
            (plugboardPairs[input] == '\0')? input = input : input = plugboardPairs[input];
            //cout << "PB: " << input << endl;
            input = writeRotorF(rotor3,input);
            //cout << "Post Rotor3: " << input << endl;
            input = writeRotorF(rotor2,input);
            //cout << "Post Rotor2: " << input << endl;
            input = writeRotorF(rotor1,input);
            //cout << "Post Rotor1: " << input << endl;
            //reflector stage
            input = reflector[input];
            //back through rotors
            //cout << "Post Reflector: " << input << endl;
            input = writeRotorR(rotor1,input);
            //cout << "Post Rotor1: " << input << endl;
            input = writeRotorR(rotor2,input);
            //cout << "Post Rotor2: " << input << endl;
            input = writeRotorR(rotor3,input);
            //cout << "Post Rotor3: " << input << endl;
            //final swap
            (plugboardPairs[input] == '\0')? input = input : input = plugboardPairs[input];
            //cout << "PB: " << input << endl;
            /*KEEP this line to write message*/
            cout << input;
            //deal with rotor steps
            rotor3.rotorStep();     //turns rotor
            if(rotorFlag1)
            {   //if this is on its turnover positon, rotor2 turns after encrypts char
                rotor2.rotorStep();
            }
            //check for double step
            if( rotor2.getTurnover() == char(ASCII + rotor2.getcurrentPos()) )
            {
                rotorFlag2 = true;
            }
            if(rotorFlag2)
            {   //if this is on its turnover positon, rotor1 turns after encrypts char
                rotor1.rotorStep();
            }
        }
    }
}

char Enigma::writeRotorF( Rotor r, char c )
{
    int thisP = r.getcurrentPos();     //save current position
    int n = (int(c) - ASCII + thisP)%ALPHA;        //convert to index for vector
    char output = r.getChar(n);
    output = (output - thisP < ASCII)? output - (thisP - ALPHA) : output - thisP;

    return output;
}

char Enigma::writeRotorR( Rotor r, char c )
{
    int thisP = r.getcurrentPos();     //save current position
    char n = ((c + thisP) > (ASCII-1+ALPHA))? (c + (thisP - ALPHA)) : c + thisP;
    int index = r.findIndex(n);
    char output = (index - thisP < 0 )? index - (thisP - ALPHA) + ASCII : index - thisP + ASCII;

    return output;
}
