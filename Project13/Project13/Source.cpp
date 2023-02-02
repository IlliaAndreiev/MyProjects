#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string s = "dvdf";
        string answer = "";
        int length = 0;
        set<char> s1;
        int i = 0;
        while (i < s.size()) {
            if (s1.find(s[i]) == s1.end()) {
                answer += s[i];
                s1.insert(s[i]);
            }
            else {
                if (answer.size() > length) length = answer.size();
                cout << answer << endl;
                s1.erase(s1.begin(), s1.end());
                i = i - answer.size() + 1;
                answer = "";
                answer += s[i];
                s1.insert(s[i]);
            }
            i++;
        }
        if (answer.size() > length) length = answer.size();
        cout << length << endl;
        return 0;
    }

/*int lengthOfLongestSubstring(string s) {
        string answer = "";
        int length = 0;
        set<char> s1;
        for(int i=0; i<s.size(); i++){
            if(s1.find(s[i]) == s1.end()){
                answer += s[i];
                s1.insert(s[i]);
            } else{
                if(answer.size() > length) length = answer.size();
                answer = "";
                s1.erase(s1.begin(), s1.end());
                answer += s[i];
                s1.insert(s[i]);
            }
        }
        if (answer.size() > length) length = answer.size();
        return length;
    }*/