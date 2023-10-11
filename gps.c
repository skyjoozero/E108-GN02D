//
// Created by skyjoozero on 2023-10-11.
//


#include "gps.h"

char *header = "$PGKC";
char *footer = "\x0d\x0a";

char *responseMsg(char *commandOfMsg, char *arg) {

}

char *systemReboot(char *arg1, char *arg2) {

    char *commandString = (char *) malloc(sizeof(char ) * 1);
    char *command = "030";

    appendString(header, command, &commandString);
    appendString(commandString, ",", &commandString);

    appendString(commandString, arg1, &commandString);
    appendString(commandString, ",", &commandString);

    appendString(commandString, arg2, &commandString);
    //for here command string, get checksum
    char check[3];
    sprintf(check, "%02X", getChecksum(commandString));

    appendString(commandString, "*", &commandString);
    appendString(commandString, check, &commandString);

    appendString(commandString, footer, &commandString);

    printf("%s", commandString);

    free(commandString);

}

char *ereaseAuxiliaryInform() {
    char *commandString = (char *) malloc(sizeof(char ) * 1);
    char *command = "040";

    appendString(header, command, &commandString);

    char check[3];
    sprintf(check, "%02X", getChecksum(commandString));

    appendString(commandString, "*", &commandString);
    appendString(commandString, check, &commandString);

    appendString(commandString, footer, &commandString);

    printf("%s", commandString);

    free(commandString);

}

char *lowPowerMode(char *arg1) {

    char *commandString = (char *) malloc(sizeof(char ) * 1);
    char *command = "051";

    appendString(header, command, &commandString);
    appendString(commandString, ",", &commandString);

    appendString(commandString, arg1, &commandString);
    char check[3];
    sprintf(check, "%02X", getChecksum(commandString));

    appendString(commandString, "*", &commandString);
    appendString(commandString, check, &commandString);

    appendString(commandString, footer, &commandString);

    printf("%s", commandString);

    free(commandString);

}

char *setMessageInterval(char *arg1) {
    char *commandString = (char *) malloc(sizeof(char ) * 1);
    char *command = "101";

    appendString(header, command, &commandString);
    appendString(commandString, ",", &commandString);

    appendString(commandString, arg1, &commandString);
    char check[3];
    sprintf(check, "%02X", getChecksum(commandString));

    appendString(commandString, "*", &commandString);
    appendString(commandString, check, &commandString);

    appendString(commandString, footer, &commandString);

    printf("%s", commandString);

    free(commandString);
}

char *periodicLowPowerMode(char *arg1, char *arg2, char *arg3) {
    char *commandString = (char *) malloc(sizeof(char ) * 1);
    char *command = "105";

    if(strcmp(arg1, "8") == 0) {

        appendString(header, command, &commandString);
        appendString(commandString, ",", &commandString);

        appendString(commandString, arg1, &commandString);
        char check[3];
        sprintf(check, "%02X", getChecksum(commandString));

        appendString(commandString, "*", &commandString);
        appendString(commandString, check, &commandString);

        appendString(commandString, footer, &commandString);

        printf("%s", commandString);

        free(commandString);

    } else {

        appendString(header, command, &commandString);
        appendString(commandString, ",", &commandString);

        appendString(commandString, arg1, &commandString);
        appendString(commandString, ",", &commandString);

        appendString(commandString, arg2, &commandString);
        appendString(commandString, ",", &commandString);

        appendString(commandString, arg3, &commandString);
        //for here command string, get checksum
        char check[3];
        sprintf(check, "%02X", getChecksum(commandString));

        appendString(commandString, "*", &commandString);
        appendString(commandString, check, &commandString);

        appendString(commandString, footer, &commandString);

        printf("%s", commandString);

        free(commandString);

    }
}






void appendString(char *str1, char *str2, char **returnStr) {

    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    realloc(*returnStr, sizeof(char) * (str1Len + str2Len + 1));
//    *returnStr = (char *) malloc(sizeof(char) * (str1Len + str2Len + 1));

    if (returnStr == NULL) {
        returnStr = NULL;
    }

    memcpy(*returnStr, str1, str1Len);
    memcpy(*returnStr + str1Len, str2, str2Len + 1);

}


uint8_t getChecksum(char *string) {

    //string[0] = $, it is not include
//    string = &string[1];

    uint8_t check = 0;

    for(int i = 1; i < strlen(string); i++) {
        check ^= (uint8_t) string[i];
    }

    return check;
}