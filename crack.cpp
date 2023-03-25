#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void generateAllCaps(string s, int i, vector<string> &list)
{
    // Base case: if i has reached the end of the string, print the result
    if (i == s.length())
    {
        list.push_back(s);
        return;
    }

    // Recursive case: generate all possible combinations of capitalized and non-capitalized letters
    // For each character, generate two recursive calls: one with the character capitalized and one with it non-capitalized
    s[i] = toupper(s[i]);
    generateAllCaps(s, i + 1, list);
    s[i] = tolower(s[i]);
    generateAllCaps(s, i + 1, list);
}

int printAllKLengthRec(char set[], string prefix, int n, int k)
{

    // Base case: k is 0,
    // print prefix
    if (k == 0)
    {
        // cout << (prefix) << endl;
        hash<std::string> hasher;
        long TheHash = hasher(prefix);
        if (TheHash == -0x2dd708b93d82e611)
        {
            cout << (prefix) << endl;
            return 1;
        }
        return 0;
    }

    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (int i = 0; i < n; i++)
    {
        string newPrefix;

        // Next character of input added
        newPrefix = prefix + set[i];

        // k is decreased, because
        // we have added a new character
        if (printAllKLengthRec(set, newPrefix, n, k - 1) == 1)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    size_t Hash = 15143625630316042735;
    string morse = "PizzaPizza";

    hash<std::string> hasher;
    vector<string> list;

    // for(int f = 0; f < morse2.size() - 7; f++){
    // string morse = morse2.substr(f, 7);

    // hash<std::string> hasher;
    for (int i = 0; i < morse.size(); i++)
    {
        string msg = morse.substr(0, i);
        vector<string> list;
        generateAllCaps(msg, 0, list);
        for (string &word : list)
        {
            // cout << word << endl;
            long TheHash = hasher(word);
            if (TheHash == Hash)
            {
                cout << "You have found the key and won. Enjoy your prize:\n";
                cout << "tinyurl.com/" + word << endl; // may be a hint; rickroll link maybe (3acwfenx)
            }
        }
    }
    //}

    // brute force
    srand(time(NULL));
    char alph[] = "abcdefghijklmnopqrstuvwxyz"
                  "0123456789"
                  "ABCDEFGHIJKLMNOPQURTUVWXYZ";
    string testHash = "";
    // hash<std::string> hasher;
    //  for(long i =0; i < pow(62,7); i++)
    //  {
    //      testHash = "";
    //      for(int k =0; k < 7; k++){
    //          testHash +=(alph[(rand()% (sizeof(alph)-1))]);
    //      }
    //      //cout << testHash << "      " << endl;
    //      long TheHash = hasher(testHash);
    //      //testHash =
    //      if (TheHash == Hash)
    //      {
    //          cout << "You have found the  brute key and won. Enjoy your prize:\n";
    //          cout << "tinyurl.com/" + testHash << endl; // may be a hint; rickroll link maybe (3acwfenx)
    //          return 0;
    //      }
    //  }
    // printAllKLengthRec(alph, "", 62, 7);

    cout << "done! " << endl;
}

// int main()
// {
//     size_t Hash = 15143625630316042735;
//     string morse = "MLFKQVMLOQXYIBMLIVDLK";
//     morse = "thiskeyiswaytooold";
//     morse = "thefishisred";
//     morse = "thisisfordrivingnotsolving";

//     hash<std::string> hasher;
//     vector<string> list;
//     generateAllCaps(morse, 0, list);
//     for (string &word : list)
//     {
//         // cout << word << endl;
//         size_t TheHash = hasher(word);
//         if (TheHash == Hash)
//         {
//             cout << "You have found the key and won. Enjoy your prize:\n";
//             cout << "tinyurl.com/" + word << endl; // may be a hint; rickroll link maybe (3acwfenx)
//         }
//     }
// }