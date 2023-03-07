
#include "somestuff.h"

using namespace std;


//Idea: argument could be key?
std::string argument = "";

struct Funroom{
    shared_ptr<string> str;
    Funroom(){
    }
    string cake(string s){
        //a for loop without a for loop
        int i = 0;
        char temp;
        if(s.size() == 0){
            return s;
        }
        str = make_shared<string>(s);
        //jumps to top of for loop.
        t10952:
        
        //swaps the first half of leters with the second half of leters except for the last leter if uneven.
        //extra messy with references to s and str
        temp = str->at(i+str->size()/2);
        str->at(i+str->size()/2) = s[i];
        str->at(i) = temp;

        //increment
        i++;
        //check if still in size range
        if(i < str->size()/2){
            goto t10952;
        }
        else{
            return *str;
        }
    }
    void ballon(string& inp){
        if(inp.size()%2 == 1 && inp.size() >= 2){
            inp += inp.substr(0,2); // if uneven add first 4 to end
        }
        if(inp.size() == 8){
            FalsAns = "Congratulations";
        }
    }


};


unique_ptr<Funroom> funptr;

string extra;

//final string: rename
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
        if(inp.size() == 0){
            return inp;
        }
        //if not at max size have a ceser sipher change the text
        tochange = inp[f->i];
        f->handshake(tochange, (bool)f->approach(2));
        inp[f->i] = tochange;
        //check if string is finished
        if(f->conversation(false, inp) == (int)n){
            break;
        }

    }
    delete f;
    FalsAns+= "you";
    return inp;
}
string fun(string inp){
    funptr->ballon(inp);
    inp = funptr->cake(inp);
    return inp;
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
    getline(cin, input);
    stringstream strstm(input);
    vector<string> ToHash;
    string temp;
    int i =0;
    funptr = make_unique<Funroom>();
    while(getline(strstm,temp, ' ')){
        if(i%2 == 1){
            ToHash.push_back(fun(temp));
        }
        else{
            ToHash.push_back(party(temp));
        }
        i++;
    }
    if(argc < 2){
        return 0;
    }
    argument = argv[1];
    FalsAns += "win!";
    
    //TODO: to be removed wheh finished **************************
    for(int i = 0; i < ToHash.size(); i++){
        cout << ToHash[i] << endl;
    }

}