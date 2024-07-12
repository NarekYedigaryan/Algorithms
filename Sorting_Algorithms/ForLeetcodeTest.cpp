#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> splitString(const string& str, char delimiter) 
{
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter)) 
    {
      result.push_back(item);
    }

    return result;
}

string sortSentence(string s) {
    vector<string> tokens = splitString(s, ' ');

    sort(tokens.begin(), tokens.end(), [](const string& a, const string& b) {
        return a.back() < b.back();
    });

    string result;
    for (int i = 0; i < tokens.size(); ++i) {
        result += tokens[i].substr(0, tokens[i].size() - 1); 
        if (i != tokens.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string s = "is2 sentence4 This1 a3";
    cout << sortSentence(s) << endl;

    return 0;
}
