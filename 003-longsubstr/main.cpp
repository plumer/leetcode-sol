#include <string>
#include <cstring>
#include <iostream>

using std::cout;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int flag[256];
        memset(flag, 0, sizeof(flag));

        int longest = 0;
        int longestStart = 0;
        int start = 0, length;
        int repeatFlag, repeatIndex;
        int i;
        while (start < s.size()) {
            memset(flag, 0, sizeof(flag));
            length = 0;
            repeatFlag = 0;
            for (int i = start; i < s.size(); ++i) {
                if (flag[s[i]]) {
                    //cout << "repeat found: " << s.substr(start, length) << '\n';
                    repeatFlag = 1;
                    start = flag[s[i]];
                    repeatIndex = flag[s[i]];
                    //cout << "next time, start from " << start << '\n';
                    break;
                } else {
                    flag[ s[i] ] = i+1;
                    length++;
                    //cout << "\'"<<s.substr(start, length)<<"\'\t";
                }
            }
            if (length > longest) {
                longest = length;
                longestStart = start;
            }
            if (!repeatFlag)start++;
        }
        return longest;
    }
};

int main(int argc, char ** argv) {
    string s = "abcabcbb";
    if (argc >= 2)
        s = argv[1];
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s);
    return 0;
}
