#ifndef SOMESTUFF_H
#define SOMESTUFF_H
#include "__LIB_M_.h"


//fake global variable to make them think need to build the flag string in the program
std::string FalsAns = "";



struct Friend{
    int i;
    Friend(){
        i = 0;
    }


    int approach(int init){
        return rand()%init;
    }

    //this function is just one large incerment with a size check to see if it reaches the end of the string.
    int conversation(bool a, std::string f){
        int x = 0;
        if(f.size() == i && a){
            return -1;
        }
        else if(a){
            return i;
        }
        x = 1 + i * 2;
        if(i > INT32_MAX){
            hi:
            return conversation(true, f);
        }
        if(x > 1){
            i += x%(x-1);
            goto hi;
        }
        else{
            i++;
            return conversation(true, f);
        }
        return i;
    }

    bool Fistbump(){
        return true;
    }


    void handshake(char& a, bool b){
        if(b == false){
            b = Fistbump();
        }
        //simply char - 2^3
        a = (char)((int)a - abs(std::pow(2,(int)(std::sqrt((double)a)+156) / (int)(std::sqrt((double)a) - 52))));
    }

};


#endif
