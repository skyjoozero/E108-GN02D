//
// Created by skyjoozero on 2023-10-11.
//

#ifndef E108_GN02D_GPS_H
#define E108_GN02D_GPS_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h> //todo: remove later


char *responseMsg(char *commandOfMsg, char *arg);   //todo: not write
//        arg
//          "1": the received message is not supported
//          "2": valid message, but incorrect execution
//          "3": valid message, and executed correctly
//
//        example
//              Example: Send a single GPS command: $PGKC115,1,0,0,0*2B<CR><LF>
//              Reply message: $PGKC001,115,3,1,0,0,0,0,1*28<CR><LF>


char *systemReboot(char *arg1, char *arg2);
//        arg1
//            "1": warm start
//            "2": warm start
//            "3": cold start
//            "4": full cold start
//        arg2
//            "1": software restart
//            "2": hardware restart
//            "3": clear nvram, keep flash reboot
//        example
//                Full cold start command: $PGKC030,4,2*2A<CR><LF>Hot start command: $PGKC030,1,1*2C<CR><LF>
//                Remarks: Arg2 is set to 1 for both warm start and warm start, and Arg2 is 1, 2, and 3 for full cold start.
//                In general, the cold start is the full cold start mode, Arg1 is set to 4, Arg2 is set to 2, and the hardware boot mode is not used.


char *ereaseAuxiliaryInform();
//        example:
//            $PGKC040*2B<CR><LF>


char *lowPowerMode(char *arg1);
//        arg1
//            "0": stop mode
//        example
//                $PGKC051,0*37<CR><LF>
//        This command can be woken up by sending any command, invalid commands can also be used,
//        the hardware can be woken up by plugging and unplugging the serial port, and the original low-power command can be sent directly.


char *setMessageInterval(char *arg1);
//        arg1
//            100-10000
//        example
//            $PGKC101,1000*02<CR><LF>
//        The command set is to output NMEA data every 1000ms, which is 1s.
//        Remarks: When setting the message interval output above 2HZ, first increase the baud rate to above 115200 to ensure high-frequency NMEA message output.
//        This command is not saved in Flash, and will be restored to the original NMEA output frequency after power failure;
//        baud rate Modification requires firmware version 3.0 or above to support configuration, and NMEA frequency does not support saving.


char *periodicLowPowerMode(char *arg1, char *arg2, char *arg3);
//        arg1
//            "0": normal operating mode
//            "1": period ultra-low power tracking mode
//            "4": directly enter ultra-low power tracking mode
//            "8": low power consumption mode, you can wake up by sending commands through the serial port
//        arg2
//            Run time (ms), this parameter has effect in periodic mode with Arg1 = 1.
//        arg3
//            Sleep time (milliseconds), in periodic mode where Arg1 is 1, this parameter works.
//        example
//                $PGKC105,8*3F<CR><LF>
//                $PGKC105,1,5000,8000*3B<CR><LF>
//        Note: In low-power mode, the CPU will sleep and can be woken up through the serial port; in ultra-low-power tracking mode,
//        when the CPU is powered off, it will automatically wake up periodically for positioning output.




char* appendStrings(const char* first, ...);

//void appendString(char *str1, char *str2, char **returnStr);

uint8_t getChecksum(char *string);


#endif //E108_GN02D_GPS_H
