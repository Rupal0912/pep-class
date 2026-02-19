// 
#include <iostream>
#include <string>
using namespace std;

string replaceword(string s, string oldword, string newword) {
    size_t pos = 0;

    while ((pos = s.find(oldword, pos)) != string::npos) {
        s.replace(pos, oldword.size(), newword);
        pos += newword.size();
    }

    return s;
}
