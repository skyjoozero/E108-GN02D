#include <stdio.h>
#include "gps.h"

int main() {
//    systemReboot("1", "2");
//    return 0;

    char * line = "hello, world";
    char buffer[32]; // ok, this array is big enough for our operation

    int i;
    for (i = 0; i < strlen(line) + 1; i++)
    {
        buffer[i] = line[i];
    }

    printf("buffer : %s", buffer);

    return 0;
}
