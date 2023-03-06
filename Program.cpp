#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include "somestuff.h"

using namespace std;



string extra = 0;

//final string
void Goal(bool a){

    if(a == true){
        cout<< goalString << endl;
    }
    
}


//input
string party(string inp){
    Friend* f = new Friend();
    float n = -1.0513;
    char tochange;
    while(true){
        if(f->conversation(false, inp) == (int)n){
            break;
        }
        tochange = inp[f->i];
        f->handshake(tochange, (bool)f->apporach(2));

    }
    delete f;
    return inp;
}
string fun(string inp){

}

//attepmpts
//rename after done
bool attempts(string red){

}

//hash function
bool validate(string s){

}



int main(int argc, char** argv){
    cout << "Goal is to print 'Congratulations you win!!!'" << endl;
    string input;
    cin >> input;
    


    

}