#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <math.h>
#include <memory>
#include <vector>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <functional>
#include <chrono>
#include <fstream>
using namespace std;

int calls_1 = 0;
int calls_2; //intitilization unknown **still looking **
string clean_name = "lolnohintshereweatherboy.bmp";
string winstrings[] = {
    "Yeah, as if.", //0
    "Yeah, sure pal.", //1
    "Life is never that easy.", //2
    "Not gonna happen.", //3
    "Really? This wouldn\'t even be a challenge.", //3
     "Ok, you can stop trying. No point in spamming.", //4
     "Did you not read the messages?", //5
     "They say the definition of insanity is doing the same thing over and over again and expecting different results. You\'re starting to qualify.", //6
     "Ok STOP! What\'s wrong with you, choosing the same option over and over? It\'s a useless program! Exit out already.", //7
     "Alright, fine, whatever. If you absolutely insist, here\'s something to get you off my back. Can you go choose something else now?", //8
     "Didn\'t I already give you another option? Go away." //9
     };
string hex_1 = "424D2C2A0000000000008A0400007C00000064000000740000000100080001000000A2250000000000000000000000010000000100000100FF0000FE0100FE000100010101FE4246527280C3F42860B81F142185EB00413233128167672640666707A09998083C0AD602245D8E3200010000000001000001000005010100010001000101010000000100FFFFFF001D1C1D002A69F10069696701050506000B0A0C012C2C2C0000000000FEFEFE00FCFCFC00F2F2F20023232200DADADA006060600017171600D2D2D200FAFAFA00F6F6F600C8C8C8002E71FF0077777700BEBEBE00E6E6E60033333300B5B6B600A3A3A30011111200ACACAC00E0E0E000ECECEC00393939008C8C8C006F6F6F0088888800828282003F3F3F0095969600080E2200535454004D4D4D0059595900464646009C9D9D002B6AF800234BA7007C7C7C002B65E800919191002654BD000E1B3D00285BD100152858001D3C8800172F67000C152F00204396001C37780012224B006D97F3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000..."; /* TRUNCATED STRING LITERAL */

string hex_2 = "424D0A270000000000008A0400007C0000006400000065000000010008000100000080220000000000000000000000010000000100000000FF0001FF0100FE000001000101FE4346527380C3F52861B91E142185EB00403232128067662641666607A09999083D0BD602255D8F3200000000000100000001010004010100010101010001010000010000F7F7F70066686C0076797C00F2F2F300727579003C3F40007F818500797C80016E7175006A6D71006367690037383A015A5F610056595D014E515500616365004245470046484B012E3132004A4C4E0002030400262B2B015255590021232301181D1D0010121500A5A5A700ECEEEE00C4C7C600E5E5E40087898B00999B9D01B6B9B900AEAEB1018E919300FCFDFD00BDBFC100DDDCDC01CCCFCF00D4D5D701546599004D65BD00626D8700010000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000..."; /* TRUNCATED STRING LITERAL */
string hex_3 = "424D764700000000000036000000280000005000000039000000010020000000000000000000C40E0000C40E00000000000000000000FEFEFFFEFFFFFFFEFEFEFEFFFEFFFFFEFFFEFFFEFEFFFFFEFEFEFEFEFEFFFEFEFEFFFFFEFEFFFFFEFFFEFEFFFEFFFFFEFFFFFEFEFFFFFFFEFEFEFEFFFEFFFFFEFEFEFEFEFEFFFEFEFFFEFEFFFEFFFFFEFFFFFEFEFFFFFFFEFEFEFEFEFEFFFEFEFEFFFEFEFFFFFFFEFFFEFFFEFEFFFFFEFEFEFFFEFEFFFFFEFFFEFEFFFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFFFFFBFBFDFFE2E3EFFFE4E6F3FFE9EAF5FFFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFBCBBD9FF7275A2FF3F3F8EFF0F1073FF0C0F78FF020576FF0C178CFF141C98FF272FA8FF2730A4FF6D72BFFFB3B8E7FFE2E6F7FFFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBEBF6FF9494..."; /* TRUNCATED STRING LITERAL */
string hex_4 = "424D523800000000000036000000280000004B0000003F00000001001800000000001C380000C40E0000C40E00000000000000000000FEFEFFFEFFFFFFFEFEFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEB5ABA80845510D4854949292FEFFFEFEFFFFFEFFFEFFFFFEFFFEFFFEFEFFFFFEFFFEFEFFFFFFFFFEFEFEFEFEFEFFFEFEFFFEFEFFFEFFFFFEFFFFFEFEFFFFFFFEFEFEFEFEFEFFFEFEFFFFFFFEFFFFFFFEFFFEFEFEFEFFFFFEFFFEFEFFFFFFFFFEFEFEFEFEFEFFFEFEFEFEFFFEFFFFFFFEFFFFFFFFFEFFFFFEFFFFFFFFFEFFFFFEFEFEFEFEFEFFFEFEFFFFFFFFFEFFFFFEFEFEFFFFFEFFFFFEFEFEFFFEFEFFFFFEFFFEFEFFFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4C5C2065E7000EDFF02EAFF00546BF3DBD7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAD9C970094B405E9FF08E4FF00A2C5A06E64D0BDB9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF2F03C4D5200AFD600C4E105CAF2001019005D728C8684FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8DEDC7F848654646801384505D0EC03E7FF00728FA0837EFFFFFFFFFFFFFFFFFFFF..."; /* TRUNCATED STRING LITERAL */
string hex_5 = "424D66400000000000003600000028000000450000004F000000010018000000000030400000C40E0000C40E00000000000000000000FFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFDADADBB4B5B5FEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFE00FEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFDFCFC4F4E4F1B1A1B0E0E0F161717E4E5E4F4F5F4F5F5F4FFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEECECECE5E4E4DFDEDFEDECEDFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFE00FFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFE000000C8C8C9FEFEFF7C7D7D6263628E8F8E616160999898EAEAEAFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEE8E8E83E3E3E3332322E2F2F515051FCFCFCFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFE00FFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEDCDCDCAFAEAE6F6E6F979697FEFEFEB3B3B34041409899984B4B4A272626636262D7D6D6FEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8C2C2C2444444B2B2B2C6C6C64D4D4DB5B5B5FCFCFCF6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF787878383838909090535353FBFBFBCECECE5858588A8A8A8D8D8D898989575757878787FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5252528C8C8C..."; /* TRUNCATED STRING LITERAL */




void win(){
    int loc1 = 10;
    int loc14 = min(calls_1, loc1);
    cout << (string)(winstrings[loc14]) << endl;
    calls_1++;
}
void fakewin(string inputString){
    bool correctFileName = (inputString == "ancientkey.txt");
    if(correctFileName){
        ofstream file(inputString);
        file << hex_4;
        calls_2++;
        file.close();
    }
    return;
}

void select(string Inputstring){
    if(Inputstring == "dashdot.txt"){
        ofstream file(Inputstring);
        file << hex_5;
        calls_2++;
        file.close();
    }
}

void getfile(string Input){

}

void tryname(string& Input){
 
    getfile(Input);

    stripfile(Input);

    select(Input);

    functionalfunction(Input);

    getImage(Input);

    printhelper(Input);

    fakewin(Input);


}

void imfile(){
    string input;
    cout << "Give me a name, and you may get a reward." << endl;
    cin >> input;

    tryname(input);

}


int main(){
    bool b1 = false;
    auto currentTime = chrono::system_clock::now();
    int i1 = 1;
    while(0 < i1){
        auto time2 = chrono::_V2::system_clock::now();

        cout << "\nMain Menu:" << endl;
        cout << "\tOption1: choose me to win instanty!" << endl;

    }
}
