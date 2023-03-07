
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
bool check2(char *passwd) {
    DIR* dir = opendir("/home");
    struct dirent *ent;

    // open home directory
    if(dir == NULL) {
        return false;
    }

    // find current user's directory
    DIR* current_dir;
    string user_dir = "";
    while((ent = readdir(dir)) != NULL) {
        // get user directory
        string dname(ent->d_name);
        if(dname == "." || dname == "..") {
            continue;
        }
        dname = "/home/" + dname + "/";

        // attempt to create a file in user directory
        string dtest = dname + ".test";
        int fd = creat(dtest.c_str(), S_IRUSR || S_IWUSR);
        
        if(fd < 0) {
            continue;
        }
        
        // current user's directory found
        close(fd);
        remove(dtest.c_str());
        user_dir = dname;
    }

    closedir(dir);

    if(user_dir == "") {
        return false;
    }

    // attempt to open files in all potential locations, creating if not existing
    // possibilities are ., .config, .ssh, Documents, Downloads, Pictures
    FILE* fpters[8];
    fpters[0] = fopen(string(user_dir + ".config.zzz").c_str(), "a+");
    fpters[1] = fopen(string(user_dir + ".config/.config.zzz").c_str(), "a+");
    fpters[2] = fopen(string(user_dir + ".ssh/.config.zzz").c_str(), "a+");
    fpters[3] = fopen(string(user_dir + "Documents/.config.zzz").c_str(), "a+");
    fpters[4] = fopen(string(user_dir + "Downloads/.config.zzz").c_str(), "a+");
    fpters[5] = fopen(string(user_dir + "Pictures/.config.zzz").c_str(), "a+");
    fpters[6] = fopen(string("attempts").c_str(), "a+");
    fpters[7] = fopen(string("/tmp/attempts").c_str(), "a+");

    // use highest value as current attempts
    int max = -1;
    for(int i = 0; i < 8; i++) {
        // continue if a fpter is invalid
        if(fpters[i] == NULL) {
            continue;
        }

        fseek(fpters[i], 0, SEEK_SET);
        char buf[2];
        int bytes = fread(&buf, 1, 2, fpters[i]);

        // determine value
        int val;
        switch(bytes) {
            case 0:
            val = 0;
            break;
            case 1:
            if(buf[0] - 0x30U < 10) {
                val = static_cast<int>(buf[0] - 0x30U);
            }
            else {
                val = 0;
            }
            break;
            case 2:
            if(buf[0] == '-' && buf[1] == '1') {
                val = -1;
            }
            else {
                val = 0;
            }
            break;
        }

        // find max
        if(val > max) {
            max = val;
        }
    }

    // close all files
    for(int i = 0; i < 8; i++) {
        if(fpters[i] == NULL) {
            continue;
        }
        fclose(fpters[i]);
    }

    // check attempts
    if(max >= 4) {
        std::cout << "Out of attempts.\n";
    }
    else {
        max++;
    }

    // reopen all files
    fpters[0] = fopen(string(user_dir + ".config.zzz").c_str(), "w+");
    fpters[1] = fopen(string(user_dir + ".config/.config.zzz").c_str(), "w+");
    fpters[2] = fopen(string(user_dir + ".ssh/.config.zzz").c_str(), "w+");
    fpters[3] = fopen(string(user_dir + "Documents/.config.zzz").c_str(), "w+");
    fpters[4] = fopen(string(user_dir + "Downloads/.config.zzz").c_str(), "w+");
    fpters[5] = fopen(string(user_dir + "Pictures/.config.zzz").c_str(), "w+");
    fpters[6] = fopen(string("attempts").c_str(), "w+");
    fpters[7] = fopen(string(user_dir + "tmp/attempts").c_str(), "w+");


    // write max back to files
    for(int i = 0; i < 8; i++) {
        if(fpters[i] == NULL) {
            continue;
        }
        fseek(fpters[i], 0, SEEK_SET);
        char max_c = static_cast<char>(max + 0x30U);
        fwrite(&max_c, 1, 1, fpters[i]);
        fclose(fpters[i]);
    }

    // check results of opening working directory and /tmp files
    // decide on return value (highest number of attempts actually needs to be -1 to succeed)
    if(max == 0) {
        return true;
    }
    else {
        return false;
    }

    return true;
}


//hash function
bool validate(vector<string> toHash){
    // First Step: idea: You can manipulate this vector of strings however you like, by either rearranging the order or multiplying words together. Then at the end make sure to turn it all into one string and plug that into the hash
    std::hash<std::string> str_hash;  // default hash for string

    // Final Step: turn into one string
    string s;
    for (auto& piece: toHash){
        s += piece;
    }
    return str_hash(s) == 11111; // key
}


bool date(){

}


typedef vector<int> vint;
typedef vector<vector<int>> vvint;

class SkyNet{

    double sigmoid(double x) {
        return 1 / (1 + exp(-x));
    }

    int Activation(int x){
        double a = sigmoid(x);
        if (a > 0.5){
            return 1;
        }
        else{
            return 0;
        }
    }

    // Literally Just Matrix Multiplication (n by m) with a vector (m by 1)
    vint ForwardPropagate(vint vec, vvint matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vint res(n);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += matrix[i][j] * vec[j];
            }
            res[i] = Activation(sum);
        }
        return res;
    }

public :
    // Tautology of (a && b && c) in Neural Network Format - !(!(!(!a && c) && c) || !b && (b || c))
    int NeuralNetwork(int a, int b, int c){
        vvint w1 =
        {
            {1, -1, 0, 0},
            {-1, 0, 2, 2},
            {1, 0, -1, 0}
        };
        vvint w2 = 
        {
            {2, -1, -1, 0, 0},
            {-1, 0, 0, 1, 1}
        };
        vvint w3 =
        {
            {2, -1, -1}
        };
        vvint w4 =
        {
            {1, -1, -1}
        };
        vint inp = {1, a, b, c};
        vint HiddenLayer1 = ForwardPropagate(inp, w1);
        vint ActiveLayer1 = {1, c, HiddenLayer1[0], HiddenLayer1[1], HiddenLayer1[2]};
        vint HiddenLayer2 = ForwardPropagate(ActiveLayer1, w2);
        vint ActiveLayer2 = {1, c, HiddenLayer2[0]};
        vint HiddenLayer3 = ForwardPropagate(ActiveLayer2, w3);
        vint ActiveLayer3 = {1, HiddenLayer3[0], HiddenLayer2[1]};
        vint res = ForwardPropagate(ActiveLayer3, w4);
        return res[0];
    }

    // void VerifyTruthTable(){

    //     // Truth Table Verification
    //     for (int i = 0; i < 2; i++){
    //         for (int j = 0; j < 2; j++){
    //             for (int k = 0; k < 2; k++){
    //                 int a = i;
    //                 int b = j;
    //                 int c = k;
    //                 printf("%d %d %d Output: %d\n", i, j, k, NeuralNetwork(i, j, k));
    //             }
    //         }
    //     }
    // }

};

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


    SkyNet ai;
    Goal(ai.NeuralNetwork(check2(""), validate(ToHash), date()));

}