#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<stdbool.h>
#include "Check.h"
#include "IntelHex.h"

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*******************************************************************************
 * Prototypes
 *******************************************************************************/

/**
 * @brief: Print the status of a line
 * @param Buff: A character array that stores the data of a line
 * @param check: Struct is used to check the error of a line in a hex file
 * @param hexStruct: Struct data form of a line in hex file
 * @return NULL;
 */
void printStateLine(uint8_t *Buff,Status_t check,HexFormData_t hexStruct);

/*******************************************************************************
 * Variables
 *******************************************************************************/

/*******************************************************************************
 * Code
 *******************************************************************************/

int main(int agrc, char *argv[])
{
    FILE *fp;
    Status_t check;
    HexFormData_t hexStruct;
    uint8_t BufferData[521];
    fp = fopen(argv[1],"r+");
    if(fp == NULL)
    {
        printf("FAIL TO OPEN FILE\n");
    }
    else
    {
        while(fgets(BufferData,521,fp) != NULL)
        {
           checkLine(BufferData,&check,&hexStruct);
           printStateLine(BufferData,check,hexStruct);
           if(hexStruct.recordType==1)
           {
               break;
           }
        }
    }
    return 0;
    fclose(fp);
}

void printStateLine(uint8_t *Buff,Status_t check,HexFormData_t hexStruct)
{
    int i;

    printf("\n%s",Buff);
    if(check.stateHexLine == false)
    {
        printf("      --->> Incorrect!!");
    }
    else
    {
        if(hexStruct.recordType == 1)
        {
            printf("-->> END OF FILE -- > DONE");
        }
        else
        {
            printf("      --->> Correct!!");
            printf("\n      ---------Result---------");
            printf("\n      Record Type: 0X%.2X",hexStruct.recordType);
            printf("\n      Data: ");
            for(i = 0 ; i < hexStruct.byteCount ; i++)
            {
                printf("%.2X-",hexStruct.data[i]);
            }
            printf("\n      Address:0X%X",hexStruct.address);
        }
    }
}
