#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
    public:
        int myAtoi(string str) {
            if (str.empty()) return 0;
            int blank = 0;
            while (str[blank] == ' ')
                blank++;
            str = str.substr(blank);
            bool negative = false;
            if (str[0] == '-') {
                negative = true;
                str = str.substr(1);
            } else if (str[0] == '+')
                str = str.substr(1);

            int zero = 0;
            while (str[zero] == '0')
                zero++;
            str = str.substr(zero);
            for (int i = 0; i < str.size(); ++i)
                if (str[i] < '0' || str[i] > '9')
                    str = str.substr(0, i);
            if (str == "2147483648") {
                if (negative)
                    return -2147483648;
                else
                    return 0;
            }
            int plusRes = 0;
            for (int i = 0; i < str.size(); ++i)
                plusRes = plusRes * 10 + str[i] - '0';
            int check = plusRes;
            for (int i = str.size()-1; i >= 0; --i) {
                int digit = check % 10;
                check /= 10;
                if (digit + '0' != str[i])
                    return negative ? -2147483648: 2147483647;
            }
            return negative ? -plusRes : plusRes;
        }
};

int main(int argc, char ** argv) {
    string s = "123";
    if (argc >= 2)
        s = argv[1];
    Solution sol;
    int i = sol.myAtoi(s);
    cout << i << endl;
    return 0;
}
