#include <stdio.h>
#include "gps.h"

int main() {
    systemReboot("4", "2");
    return 0;

//    char * line = "hello, world";
//    char buffer[32]; // ok, this array is big enough for our operation
//
//    int i;
//    for (i = 0; i < strlen(line) + 1; i++)
//    {
//        buffer[i] = line[i];
//    }
//
//    printf("buffer : %s", buffer);
//
//    return 0;

//    char *a = "asdf";
//    char *b = "qwer";
//    char *c = (char *) malloc(sizeof(char) * 1);
//    appendString(a, b, &c);
//
//    printf("%s", c);
//    free(c);
//
//    return 0;

//    char *a = "aPGKC030,3,1";
////    uint8_t b = getChecksum(a);
//
//    char check[3];
//    sprintf(check, "%X", getChecksum(a));
//
//    printf("%s", check);
//
//    return 0;
}
