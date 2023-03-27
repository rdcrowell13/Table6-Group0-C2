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
#include <ratio>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <bitset>
#include <cstddef>
using namespace std;

// I believe these globals are empty initialized and compiler default them to 0
int calls_1 =0 ;
int calls_2;
int calls_3;
int calls_4;
char allow; // if allow != '\0' then inputing '5' to the terminal will call 'tryguess'

string clean_name = "lolnohintshereweatherboy.bmp";
string winstrings[] = {
    "Yeah, as if.",                                                                                                                                  // 0
    "Yeah, sure pal.",                                                                                                                               // 1
    "Life is never that easy.",                                                                                                                      // 2
    "Not gonna happen.",                                                                                                                             // 3
    "Really? This wouldn\'t even be a challenge.",                                                                                                   // 3
    "Ok, you can stop trying. No point in spamming.",                                                                                                // 4
    "Did you not read the messages?",                                                                                                                // 5
    "They say the definition of insanity is doing the same thing over and over again and expecting different results. You\'re starting to qualify.", // 6
    "Ok STOP! What\'s wrong with you, choosing the same option over and over? It\'s a useless program! Exit out already.",                           // 7
    "Alright, fine, whatever. If you absolutely insist, here\'s something to get you off my back. Can you go choose something else now?",            // 8
    "Didn\'t I already give you another option? Go away."                                                                                            // 9
};
string hex_1 = "424D2C2A0000000000008A0400007C00000064000000740000000100080001000000A2250000000000000000000000010000000100000100FF0000FE0100FE000100010101FE4246527280C3F42860B81F142185EB00413233128167672640666707A09998083C0AD602245D8E3200010000000001000001000005010100010001000101010000000100FFFFFF001D1C1D002A69F10069696701050506000B0A0C012C2C2C0000000000FEFEFE00FCFCFC00F2F2F20023232200DADADA006060600017171600D2D2D200FAFAFA00F6F6F600C8C8C8002E71FF0077777700BEBEBE00E6E6E60033333300B5B6B600A3A3A30011111200ACACAC00E0E0E000ECECEC00393939008C8C8C006F6F6F0088888800828282003F3F3F0095969600080E2200535454004D4D4D0059595900464646009C9D9D002B6AF800234BA7007C7C7C002B65E800919191002654BD000E1B3D00285BD100152858001D3C8800172F67000C152F00204396001C37780012224B006D97F3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000..."; /* TRUNCATED STRING LITERAL */

string hex_2 = "424D0A270000000000008A0400007C0000006400000065000000010008000100000080220000000000000000000000010000000100000000FF0001FF0100FE000001000101FE4346527380C3F52861B91E142185EB00403232128067662641666607A09999083D0BD602255D8F3200000000000100000001010004010100010101010001010000010000F7F7F70066686C0076797C00F2F2F300727579003C3F40007F818500797C80016E7175006A6D71006367690037383A015A5F610056595D014E515500616365004245470046484B012E3132004A4C4E0002030400262B2B015255590021232301181D1D0010121500A5A5A700ECEEEE00C4C7C600E5E5E40087898B00999B9D01B6B9B900AEAEB1018E919300FCFDFD00BDBFC100DDDCDC01CCCFCF00D4D5D701546599004D65BD00626D8700010000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000..."; /* TRUNCATED STRING LITERAL */
string hex_3 = "424D764700000000000036000000280000005000000039000000010020000000000000000000C40E0000C40E00000000000000000000FEFEFFFEFFFFFFFEFEFEFEFFFEFFFFFEFFFEFFFEFEFFFFFEFEFEFEFEFEFFFEFEFEFFFFFEFEFFFFFEFFFEFEFFFEFFFFFEFFFFFEFEFFFFFFFEFEFEFEFFFEFFFFFEFEFEFEFEFEFFFEFEFFFEFEFFFEFFFFFEFFFFFEFEFFFFFFFEFEFEFEFEFEFFFEFEFEFFFEFEFFFFFFFEFFFEFFFEFEFFFFFEFEFEFFFEFEFFFFFEFFFEFEFFFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFFFFFBFBFDFFE2E3EFFFE4E6F3FFE9EAF5FFFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFFBCBBD9FF7275A2FF3F3F8EFF0F1073FF0C0F78FF020576FF0C178CFF141C98FF272FA8FF2730A4FF6D72BFFFB3B8E7FFE2E6F7FFFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBEBF6FF9494..."; /* TRUNCATED STRING LITERAL */
string hex_4 = "424D523800000000000036000000280000004B0000003F00000001001800000000001C380000C40E0000C40E00000000000000000000FEFEFFFEFFFFFFFEFEFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEB5ABA80845510D4854949292FEFFFEFEFFFFFEFFFEFFFFFEFFFEFFFEFEFFFFFEFFFEFEFFFFFFFFFEFEFEFEFEFEFFFEFEFFFEFEFFFEFFFFFEFFFFFEFEFFFFFFFEFEFEFEFEFEFFFEFEFFFFFFFEFFFFFFFEFFFEFEFEFEFFFFFEFFFEFEFFFFFFFFFEFEFEFEFEFEFFFEFEFEFEFFFEFFFFFFFEFFFFFFFFFEFFFFFEFFFFFFFFFEFFFFFEFEFEFEFEFEFFFEFEFFFFFFFFFEFFFFFEFEFEFFFFFEFFFFFEFEFEFFFEFEFFFFFEFFFEFEFFFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4C5C2065E7000EDFF02EAFF00546BF3DBD7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAD9C970094B405E9FF08E4FF00A2C5A06E64D0BDB9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF2F03C4D5200AFD600C4E105CAF2001019005D728C8684FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8DEDC7F848654646801384505D0EC03E7FF00728FA0837EFFFFFFFFFFFFFFFFFFFF..."; /* TRUNCATED STRING LITERAL */
string hex_5 = "424D66400000000000003600000028000000450000004F000000010018000000000030400000C40E0000C40E00000000000000000000FFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFDADADBB4B5B5FEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFE00FEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFDFCFC4F4E4F1B1A1B0E0E0F161717E4E5E4F4F5F4F5F5F4FFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEECECECE5E4E4DFDEDFEDECEDFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFE00FFFEFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFE000000C8C8C9FEFEFF7C7D7D6263628E8F8E616160999898EAEAEAFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEE8E8E83E3E3E3332322E2F2F515051FCFCFCFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFEFEFEFEFFFE00FFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEFEFEFEFFFEFEFEFFFFFFFEFFFEFEFFFEFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFFFFFFFEFFFEFEFEFEDCDCDCAFAEAE6F6E6F979697FEFEFEB3B3B34041409899984B4B4A272626636262D7D6D6FEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F8C2C2C2444444B2B2B2C6C6C64D4D4DB5B5B5FCFCFCF6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF787878383838909090535353FBFBFBCECECE5858588A8A8A8D8D8D898989575757878787FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5252528C8C8C..."; /* TRUNCATED STRING LITERAL */

void tryguess()
{
    long Hash = -0x2dd708b93d82e611;
    cout << "enter the final key\n";
    cin.ignore(0x100, 0xa); // ignore new line characters
    string incomming;
    getline(cin, incomming);

    hash<std::string> hasher;
    long TheHash = hasher(incomming);

    string Message = "Psst. If you\'re reading this, here\'s a hint. Be senstitive about your cases..."; // hint in code

    if (TheHash == Hash)
    {
        cout << "You have found the key and won. Enjoy your prize:\n";
        cout << "tinyurl.com/" + incomming << endl; // may be a hint; rickroll link maybe (3acwfenx)
    }
    else
    {
        cout << "Invalid key" << endl;
    }
}

void win()
{
    int limit = 10;
    int stringIndex = min(calls_1, limit);
    cout << winstrings[stringIndex] << endl;
    calls_1++;
}

//-- Start of tryname suite
/** This function does nothing of value*/
void getfile(string Input)
{
    ifstream infile(Input);
    if (infile.fail() == '\0')
    {

        string fromfile;
        infile >> fromfile;
        fromfile.append("ff"); // Data0010408d has this info stored as f f and the end character. This may complete a hex in one of the files for a hint?
        // possible other append?

        if (fromfile.capacity() < 101)
        {
            if (fromfile.capacity() < 51)
            {
                string Sub = fromfile.substr(0, fromfile.size()); // first item is 0 second item is unclear but has to do with the size. No math done of RCX which came from result of size()
                fromfile.append(Sub);                             // still unclear the order
            }
            else
            {
                fromfile = fromfile.substr(0, 49); // EDX = 0, ECX = 0x31
            }
        }
        // only issue with this function is that in trynmae the input gets deleted and then realocated again. It also does not fit the passby reference pattern. May be this function serves no purpose
    }
}



// Writes global variable hex_2 into a file "vroom.txt" if you input that
void stripfile(string filename)
{
    if (filename == "vroom.txt")
    {
        ofstream file(filename);
        file << hex_2; // running the actual executable should give the full, untruncated string
        calls_2++;
    }
    return;
}

void select(string Inputstring)
{
    if (Inputstring == "dashdot.txt")
    {
        ofstream file(Inputstring);
        file << hex_5;
        calls_2++;
        file.close();
    }
}

void functionalfunction(string input)
{
    if (input == "sanguinepiscene.txt")
    {
        ofstream file(input);
        file << hex_3;
        calls_2++;
    }
    return;
}

// 95% sure this is correct, cross checked with Ghidra after compilation
void getImage(string filename) // seems to do nothing
{
    string name = filename.substr(0, filename.find_last_of('.'));
    name += ".png";
    ifstream file(name);
    string FileContent;
    file >> FileContent;
    size_t a = FileContent.find_first_not_of('0');
    return;
}

void printhelper(string filename)
{

    if (filename == "pizzapizza.txt")
    {
        ofstream file(filename);
        file << hex_1;
        calls_2++;
    }
    return;
}

void fakewin(string inputString)
{
    bool correctFileName = (inputString == "ancientkey.txt");
    if (correctFileName)
    {
        ofstream file(inputString);
        file << hex_4;
        calls_2++;
        file.close();
    }
    return;
}

// Verified - matched Ghidra's signature
void tryname(string Input)
{
    getfile(Input); // doesn't do anything, might reveal hint when given the right filename?
    stripfile(Input);
    select(Input);
    functionalfunction(Input);
    getImage(Input);
    printhelper(Input);
    fakewin(Input);
}

void imfile()
{
    string input;
    cout << "Give me a name, and you may get a reward." << endl;
    cin >> input;

    tryname(input);
}

// Correctness Verified
FILE* stegosaurus_helper_1(string filename)
{
    FILE* fh = fopen(filename.c_str(), "rb");
    return fh;
}

FILE* stegosaurus_helper_2(string input){
    // does not show this in code but is revield in sego4 and make sence since fopen automaticly assigned RAX so no special return is detected
    return fopen(input.c_str(), "wb"); 
}

/**
 * returns the the unsigned int max size if the file is pressent and loaded. 
*/
off_t stegosaurus_helper_3(string fileName){

    struct stat file; 

    int fileID = stat(fileName.c_str(), &file);

    if(fileID != 0){
        file.st_size = UINT32_MAX;
    }
    return file.st_size;
}

long stegosaurus_helper_4(string input1, string input2){
    sizeof(string);
    //not sure on this but it looks like they flip the strings around here
    string temp = input2;
    input2 = input1;
    input1 = temp;
    //file reference
    FILE* FileRef1 = stegosaurus_helper_1(temp); // likely inputing input1 but optimized using themp instead
    //file size

    temp = input2;
    input2 = input1;
    input1 = temp;

    int fileSize = stegosaurus_helper_3(temp);
    //this code does nothing but tries to make you make an error
    temp = input1;
    input2 = input2;
    input1 = temp;

    FILE* FileRef2 = stegosaurus_helper_2(temp);

    //read bytes from one file and move to other file
    byte readFile;
    for(int i =0; i < 54; i++){
        fread(&readFile,1 ,1, FileRef1);
        fwrite(&readFile, 1, 1, FileRef2);
    }
    //Block cypher
    byte readFile2;
    for(int i =0; i < fileSize - 54; i++){
        fread(&readFile2, 1,1, FileRef1);
        readFile = (readFile2) & static_cast<byte>(0xfe);
        fwrite(&readFile, 1, 1, FileRef2);
    }
    //does nothing
    for(int i = 0; i < 0; i++){ //??
        fread(&readFile,1 ,1, FileRef1);
        fwrite(&readFile, 1, 1, FileRef2);
    }
    return 0;

}

long stegosourance(string p1, string p2, string p3){
    string& par1 = p1;
    string& par2 = p2;
    string& par3 = p3;
    
    p3 = par1;
    string temp = p2;                                           //Guessing but only thing that makes sence (used memory address to assign)
    p2 = p3;
    p1 = temp; 
    // p2 for first input
    FILE* file1 = stegosaurus_helper_1(temp);

    p3 = par1;
    temp = p2;
    p2 = p3;
    p1 = temp;
    //p3 for second input
    int FileLength = stegosaurus_helper_3(temp);

    p3 = par2;
    temp = p2;
    p2 = p3;
    p1 = temp;
    //p2 for second input?
    FILE* file2 = stegosaurus_helper_2(temp);


    byte fileout;
    for(int i = 0; i <54; i++){
        fread(&fileout, 1, 1, file1);
        fwrite(&fileout, 1, 1, file2);
    }
    cout << "Secret message is " << p3;// << //????
}


// Correctness Verified
void unstegno(void)
{
    unsigned char fOutput;
    FILE *fp;
    //   basic_string filename [8];
    //   basic_string builder [10]; this is a temporary string variable

    string filename;
    cout << "Enter answer" << endl;
    cin >> filename;
    fp = stegosaurus_helper_1(filename); // opens filename
    // Seems to be some sort of character waster where you want to ignore the first 54 characters of a file, prepping for the relevant file read in the builder
    for (int i = 0; i < 54; i++)
    {
        fread(&fOutput, 1, 1, fp); // fOutput - buffer, 1 - bytes read of file, 1 - size of buffer, fp - file pointer
    }
    calls_4++; //! Increment global variable. Not really relevant since all it does is unlock a printing 'Option 5 unlocked' but no actual code is affected, I think. I only checked calls_4 in unstegno, not other functions for it
    // The below seems to parse a text file with a pattern.
    // Will attempt to read 1024*8 bytes. Every 8 characters acts as one-pseudo byte which is ascii_check. So there are 1024 pseduo bytes. Terminates if it reads a pseudo-byte of '\t'
    string builder; // perhaps the key? It gets printed out in the end
    for (int i = 0; i < 1024; i++)
    { // 2^5 = 1024
        char ascii_check = '\0';
        // encodes a binary string of up to 8 bits, so 1 byte. The decimal value of the byte is stored into ascii_check. Note, we are evaluating character numerical value, not literally '1' and '0's
        for (int j = 0; j < 8; j++)
        {
            fread(&fOutput, 1, 1, fp);
            fOutput &= 1;                // fOutput will always be either a 1 or a 0
            ascii_check += fOutput << j; // adds either 0, or 2^j, depending on fOutput=1,0. Basically evaluating the decimal value of a binary string
        }
        if (ascii_check == '\t') // when ascii_check =  2^0 + 0 + 0 + 2^3 + 0 + 0 + 0 + 0, or the binary string is 00001001 will this be true
        {
            cout << builder;
            return;
        }
        builder += ascii_check;
    }
    cout << builder;
}

void hextofile(string a, string b)
{
    //   bool bVar1;
//   basic_istream *pbVar2;
//   long lVar3;
//   long in_FS_OFFSET;
//   basic_string local_3b8 [32];
//   ios_base aiStack_338 [272];
//   basic_string local_228 [129];
//   char local_23;
//   char cStack_22;
//   undefined local_21;
//   long local_20;
  
//   local_20 = *(long *)(in_FS_OFFSET + 0x28);
//   std::operator|(4,0x10);
//   std::basic_ofstream<char,std::char_traits<char>>::basic_ofstream(local_228,param_1);
//   local_21 = 0;
//   std::operator|(0x10,8);
//                     /* try { // try from 00103df6 to 00103dfa has its CatchHandler @ 00103ed7 */
//   std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
//   basic_stringstream(local_3b8,param_2);
//   std::ios_base::flags(aiStack_338,8);
//   while( true ) {
//     bVar1 = std::basic_ios::operator.cast.to.bool((basic_ios *)aiStack_338);
//     if (!bVar1) break;
//                     /* try { // try from 00103e26 to 00103e8b has its CatchHandler @ 00103ebf */
//     pbVar2 = std::operator>>((basic_istream *)local_3b8,&local_23);
//     std::operator>>(pbVar2,&cStack_22);
//     lVar3 = strtol(&local_23,(char **)0x0,0x10);
//     std::operator<<((basic_ostream *)local_228,(uchar)lVar3);
//   }
//   std::__cxx11::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::
//   ~basic_stringstream((basic_stringstream<char,std::char_traits<char>,std::allocator<char>> *)
//                       local_3b8);
//   std::basic_ofstream<char,std::char_traits<char>>::~basic_ofstream
//             ((basic_ofstream<char,std::char_traits<char>> *)local_228);
//   if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
//                     /* WARNING: Subroutine does not return */
//     __stack_chk_fail();
//   }
//   return;
}

string gethex(string input){
    // local variables
    char local[8];
    string filename = input;
    string hex_result;
    //open file
    ifstream file(filename);
    //if success
    if(!file.fail()){
        file >> local;
        hex_result = local;
    }
    //else fail
    else{
        cout << "bad name" << endl;
    }
    //return
    return hex_result;
}


string getHexString(string input){
     //grab size of input
    size_t paramsize = input.size();
    //other local vars within ghidra
    string RSI;
    string local_68;
    string local_48;
    //if input size < 0xff
    if(paramsize < 0xff){
        RSI += "ff";
        local_68 = getHexString(local_48);
        RSI = local_48;
    }

    //basic_string((basic_string*)CONCAT44(in_register_0000003c, input));
    input = local_68 + input;
    //return (basic_string *)CONCAT44(in_register_0000004c, input);

    return input;
}

// Verified with Ghidra, 99% sure it matches
void de0x()
{
    string filename;
    cout << "File name: ";
    cin >> filename;
    string hex_result = gethex(filename);
    filename = filename.substr(0, filename.find_last_of('.'));
    filename += ".bmp";

    if (!hex_result.empty())
    {
        hextofile(filename, hex_result);
    }
    calls_3++;
    return;
}

int main()
{
    bool FlwCtrlCheck; // truth seems to depend on the flow of operations
    bool TmDifCheck;   // truth seems to depend on time difference between chrono::now() calls and partially on flow of operations at the bottom
    //std::chrono::duration<long, std::milli> time_diff;
    std::chrono::time_point<std::chrono::system_clock> program_start;
    std::chrono::time_point<std::chrono::system_clock> loop_start;
    //type tVar4;
    //undefined4 extraout_var;
    //undefined4 extraout_var_00;
    //undefined4 extraout_var_01;
    //undefined4 extraout_var_02;
    int looper;
    //undefined8 local_30;
    //undefined8 local_28;
    //undefined8 time3;
    //undefined8 local_18;

    FlwCtrlCheck = false;
    program_start = std::chrono::system_clock::now();
    looper = 1;
    while (0 < looper)
    {
        loop_start = std::chrono::system_clock::now();
        // -- Print Menu
        cout << "\nMain Menu:" << endl;
        cout << "\tOption 1: choose me to win instantly!" << endl;
        // Global variable checks to detect unlocking options
        if (9 < calls_1)
        {
            cout << "\tOption 2: unlocked!" << endl;
        }
        if (4 < calls_2)
        {
            cout << "\tOption 3: unlocked!" << endl;
        }
        if (4 < calls_3)
        {
            cout << "\tOption 4: unlocked!" << endl;
        }
        if ((4 < calls_4) && (allow != '\0'))
        {
            cout << "\tOption 5: unlocked!" << endl;
        }
        cout << "\t-1 to quit." << endl
             << endl;

        // Process Input
        cin >> looper;
        cout << endl;

        // Check Function Calls
        switch (looper)
        {
        case -1:
            break;
        case 1:
            win();
            break;
        case 2:
            imfile();
            break;
        case 3:
            de0x();
            break;
        case 4:
            unstegno();
            break;
        case 5:
            if (allow)
            {
                tryguess();
            }
            break;
        default:
            cout << "Invalid selection, quitting." << endl;
        }

        // The below is a puzzle of its own in order to set allow=1 to allow calling 'tryguess()'
        // Incomplete
        if (allow == 0)
        {
            std::chrono::time_point<std::chrono::system_clock> check_start = std::chrono::system_clock::now();
            auto time_diff = check_start - loop_start;

            auto test_duration = std::chrono::duration<long, std::milli>(100);
            TmDifCheck = time_diff < test_duration;

            // Time difference check 1
            if ((!TmDifCheck) || (FlwCtrlCheck))
            {
                if (FlwCtrlCheck)
                {
                    if (TmDifCheck)
                    {
                        std::cout << "\nAren\'t you supposed to avoid integer overflows?\n";
                    }
                    else if (!TmDifCheck)
                    {
                        FlwCtrlCheck = false;
                        program_start = std::chrono::system_clock::now();
                    }
                }
                else
                {
                    program_start = std::chrono::system_clock::now();
                }
            }
            else
            {
                program_start = std::chrono::system_clock::now();
                FlwCtrlCheck = true;
            }
            // Time difference check 2
            check_start = std::chrono::system_clock::now();
            time_diff = check_start - loop_start;
            
            auto test_duration2 = std::chrono::duration<long, ratio<1l,1l>>(5);
            TmDifCheck = time_diff > test_duration2;

            if ((TmDifCheck) && (FlwCtrlCheck))
            {
                TmDifCheck = true;
            }
            else
            {
                TmDifCheck = false;
            }
            // Unlocking this if statement unlocks 'tryguess()'
            if (TmDifCheck)
            {
                //std::basic_ios<char, std::char_traits<char>>::clear(0x12c170);
                allow = '\x01';
                std::cout << "\nOverflow corrected and secret function unlocked. Don\'t do it again.\n";
            }
        }
    }

    return 0;
}