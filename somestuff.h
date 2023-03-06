#ifndef SOMESTUFF_H
#define SOMESTUFF_H
#include "__LIB_M_.h"


struct Friend{
    int i;
    Friend(){
        i = 0;
    }


    int apporach(int init){
        return rand()%init;
    }

    //this function is just one large incerment with a size check to see if it reaches the end of the string.
    int conversation(bool a, std::string f){
        if(f.size() == i && a){
            return -1;
        }
        else if(a){
            return i;
        }

        i = 1 + i * 2;
        if(i > INT32_MAX){
            hi:
            conversation(true, f);
        }


        if(i > 1){
            i = i%(i-1);
            goto hi;
        }
        else{
            conversation(true, f);
        }
    
    }

    bool Fistbump(){
        return true;
    }


    void handshake(char& a, bool b){
        if(b == false){
            b = Fistbump();
        }
        //simply char - 2^3
        a = (char)((int)a - (std::pow(2,(int)(std::sqrt((double)a)+156)/(int)(std::sqrt((double)a) - 53))));
    }

};

#endif
