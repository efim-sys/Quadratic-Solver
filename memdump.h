#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

const char* colorCodes[] = {
    "39", "30", "31", "32", "33", "34", "35", "36", "37", "90", "91", "92", "93", "94", "95", "96", "97"
};

enum Colors {
    DEFAULT = 0,
    BLACK,
    DARKRED,
    DARKGREEN,
    DARKYELLOW,
    BARKBLUE,
    DARKPURPLE,
    DARKCYAN,
    LIGHTGRAY,
    DARKGRAY,
    RED,
    GREEN,
    ORANGE,
    BLUE,
    PURPLE,
    CYAN,
    WHITE
};

void setTermFG(enum Colors color);

void memdump(const char* a, size_t len, size_t offset, unsigned int bpl);

void memdump(const char* a, size_t len, size_t offset, unsigned int bpl) {
    assert(bpl != 0);
    assert(a != NULL);
    
    putchar('\n');
    for(int i = 0; i < 15; i++) putchar(' ');

    for(unsigned int i = 0; i < bpl; i++) {
        printf("%02X ", i);
    }

    setTermFG(GREEN);

    puts("ASCII text");

    char* ascii = (char*) calloc(bpl + 1, sizeof(char));

    for(const char* block = a; block < a + len; block += bpl) {
        setTermFG(ORANGE);
        printf("%014lX ", (size_t) block - offset);

        memset(ascii, 0, bpl + 1);
        
        unsigned int t = 0;

        setTermFG(CYAN);

        for(const char* byte = block; byte < block + bpl; byte++) {
            if(byte < a + len) {
                printf("%02X ", ((unsigned int) *byte) & 0xFF);
                ascii[t++] = *byte;
            }
            else printf("   ");
        }

        setTermFG(GREEN);

        for(unsigned int i = 0; i < bpl && i < t; i++) {
            char c = ascii[i];
            if(' ' <= c && c <= '~') putchar(c);
            else putchar('.');
        }

        putchar('\n');
    }

    free(ascii);
}

void setTermFG(enum Colors color) {
    fputs("\033[", stdout);
    fputs(colorCodes[color], stdout);

    putchar('m');
}