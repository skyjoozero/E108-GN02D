//
// Created by skyjoozero on 2023-10-11.
//


#include "gps.h"

char *commandHeader = "$PGKC";
char *footer = "\x0d\x0a";

char *responseMsg(char *commandOfMsg, char *arg) {



}

char *systemReboot(char *arg1, char *arg2) {

    char *commandString;
    char *command = "030";

    appendString(commandHeader, command, &commandString);
    appendString(commandHeader, ",", &commandString);

    appendString(commandHeader, arg1, &commandString);
    appendString(commandHeader, ",", &commandString);

    appendString(commandHeader, arg2, &commandString);

    printf("%s", commandString);

    free(commandString);

}

char *ereaseAuxiliaryInform() {

}

char *lowPowerMode(char *arg1) {

}








void appendString(char *str1, char *str2, char **returnStr) {

    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    *returnStr = (char *) malloc(sizeof(char) * (str1Len + str2Len + 1));

    if (returnStr == NULL) {
        returnStr = NULL;
    }

    memcpy(*returnStr, str1, str1Len);
    memcpy(*returnStr + str1Len, str2, str2Len + 1);

}