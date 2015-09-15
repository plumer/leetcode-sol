#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int longest = 0, currentLength = 0, start = 0, position[128] = {0};
    int i, j;
    for(i = 0; s[i]; position[s[i]] = ++i, currentLength++) {

        printf("bef: longest = %d, currentLength = %d, start = %d\n",
                longest, currentLength, start);
        for (j = 0; j < 128; ++j) {
            if (position[j]) {
                printf("pos[%c] = %d ", j, position[j]);
            }
        }
        printf("\n");

        if(position[s[i]] > start) {
            longest = (longest > currentLength) ? longest : currentLength;
            start = position[s[i]];
            currentLength = i - position[s[i]];
        }

        printf("aft: longest = %d, currentLength = %d, start = %d\n",
                longest, currentLength, start);
        for (j = 0; j < 128; ++j) {
            if (position[j]) {
                printf("pos[%c] = %d ", j, position[j]);
            }
        }
        printf("\n");
    }
    return (longest > currentLength) ? longest : currentLength;
}

int main(int argc, char **argv) {
    char * s = "multimonial";
    if (argc >= 2) s = argv[1];
    printf("%d", lengthOfLongestSubstring(s));
    return 0;
}
