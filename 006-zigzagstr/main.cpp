#include <iostream>
#include <cstdlib>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
    public:
        string convert(string s, int numRows) {
            string zig;
            zig.resize(s.size());
            int zigIndex = 0;
            int p = numRows-1;

            for (int i = 0; i < s.size(); i += 2 * p)
                zig[zigIndex++] = s[i];

            for (int r = 1; r < numRows-1; ++r) {
                for (int i = 0; i < s.size(); i += 2 * p) {
                    if (i+r < s.size()) zig[zigIndex++] = s[i + r];
                    if (i+ 2 * p - r < s.size())zig[zigIndex++] = s[i + 2 * p - r];
                }
            }

            for (int i = p; i < s.size(); i += 2 * p)
                zig[zigIndex++] = s[i];
            return zig;
        }
};


int main(int argc, char ** argv) {
    string source = "paypalishiring";
    if (argc >= 2) source = argv[1];
    int row = 3;
    if (argc >= 3) row = atoi(argv[2]);
    Solution sol;
    string res = sol.convert(source, row);
    cout << res << endl;
    return 0;
}
