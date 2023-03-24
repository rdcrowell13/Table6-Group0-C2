#include <iostream>
#include <string>
#include <vector>

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

int main()
{
    long Hash = -0x2dd708b93d82e611;
    string morse = "MLFKQVMLOQXYIBMLIVDLK";

    hash<std::string> hasher;
    for (int i = 0; i < morse.size(); i++)
    {
        string msg = morse.substr(0, i);
        vector<string> list;
        generateAllCaps(msg, 0, list);
        for (string &word : list)
        {
            long TheHash = hasher(word);
            if (TheHash == Hash)
            {
                cout << "You have found the key and won. Enjoy your prize:\n";
                cout << "tinyurl.com/" + word << endl; // may be a hint; rickroll link maybe (3acwfenx)
            }
        }
    }
}