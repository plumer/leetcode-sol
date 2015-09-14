#include <iostream>
#include <cstdlib>
using std::cout;

class Solution {
    public:
        int reverse(int x) {
            if (x < 0)
                return 0 - reversePlus(-x);
            else
                return reversePlus(x);
        }
        int reversePlus(int x) {
            int buf[10] = {0};
            int index = 0;
            while (x > 0) {
                buf[index++] = x % 10;
                x /= 10;
            }
            int reverseNumber = 0;
            for (int j = 0; j < index; ++j)
                reverseNumber = reverseNumber * 10 + buf[j];
            if (reverseNumber < 0)
                return 0;
            int checker = reverseNumber;
            for (int j = index - 1; j >= 0; --j) {
                int digit = checker % 10;
                checker /= 10;
                if (buf[j] != digit)
                    return 0;
            }
            return reverseNumber;
        }
};

int main(int argc, char ** argv) {
    int i = 123;
    if (argc >= 2)
        i = atoi(argv[1]);
    Solution sol;
    int res = sol.reverse(i);
    cout << res << '\n';
    return 0;
}
