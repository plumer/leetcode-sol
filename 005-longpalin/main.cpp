#include <iostream>
#include <string>

using std::string;
using std::cout;

class Solution {
    public:
        string longestPalindrome(string s) {
            int palinBegin = 0, palinEnd = 0;
            int longestPalinBegin = 0, longestPalinEnd = 0;
            int axis = 0;

            for (axis = 0; axis < s.size(); ++axis) {
                palinBegin = axis;
                palinEnd = axis;
                while (palinBegin>0 && palinEnd<s.size()-1 &&
                        s[palinBegin-1] == s[palinEnd+1]) {
                    palinBegin--;
                    palinEnd++;
                }
                if (palinEnd - palinBegin > longestPalinEnd - longestPalinBegin) {
                    cout << "longer palin: \'" <<
                        s.substr(palinBegin, palinEnd-palinBegin+1) <<
                        "\'\n";
                    longestPalinBegin = palinBegin;
                    longestPalinEnd = palinEnd;
                }
                palinBegin = axis;
                palinEnd = axis+1;
                if (palinEnd >= s.size() || s[palinEnd] != s[palinBegin])
                    continue;
                while (palinBegin>0 && palinEnd<s.size()-1 &&
                        s[palinBegin-1] == s[palinEnd+1]) {
                    palinBegin--;
                    palinEnd++;
                }
                if (palinEnd - palinBegin > longestPalinEnd - longestPalinBegin) {
                    cout << "longer palin: \'" <<
                        s.substr(palinBegin, palinEnd-palinBegin+1) <<
                        "\'\n";
                    longestPalinBegin = palinBegin;
                    longestPalinEnd = palinEnd;
                }
            }
            return s.substr(longestPalinBegin,
                    longestPalinEnd - longestPalinBegin + 1);
        }
};



int main(int argc, char ** argv) {
    string source = "madamne";
    if (argc >= 2)
        source = argv[1];
    Solution sol;
    string palin = sol.longestPalindrome(source);
    cout << palin;
    return 0;
}
