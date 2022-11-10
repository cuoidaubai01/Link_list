#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "Check.h"

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*******************************************************************************
 * Prototypes
 *******************************************************************************/

/*******************************************************************************
 * Variables
 *******************************************************************************/

/*******************************************************************************
 * Code
 *******************************************************************************/

bool checkCharacter(uint8_t *Buffer)
{
    int i;
    for (i = 0; i < strlen(Buffer) - 1; i++)
    {
        if ((Buffer[i] < '0' || Buffer[i] > '9') &&
            (Buffer[i] < 'a' || Buffer[i] > 'f') &&
            (Buffer[i] < 'A' || Buffer[i] > 'F'))
        {
            return false;
        }
    }

    return true;
}
bool checkRecordType(uint8_t tempRecordType)
{
    if (tempRecordType != 0 && tempRecordType != 1 && tempRecordType != 2 && tempRecordType != 3 && tempRecordType != 4 && tempRecordType != 5)
    {
        return false;
    }

    return true;
}

bool checkStartCode(uint8_t startCode)
{
    if (startCode != ':')
    {
        return false;
    }
    else
    {
        return true;
    }
}
