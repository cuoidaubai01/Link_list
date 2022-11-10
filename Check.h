#ifndef _CHECK_H_
#define _CHECK_H_

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*******************************************************************************
 * Prototypes
 *******************************************************************************/

/*******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************/
/* Public function*/

/**
 * @brief: Check character by line in hex file
 * @param BufferData: A character array that stores the data of a line
 * @return Bool
 */
bool checkCharacter(uint8_t *Buff);

/**
 * @brief: Check RecordType by line in hex file
 * @param BufferData: Value of RecordType
 * @return Bool
 */
bool checkRecordType(uint8_t tempRecordType);

/**
 * @brief: Check StartCode by line in hex file
 * @param BufferData: Value of StartCode
 * @return Bool
 */
bool checkStartCode(uint8_t startCode);

#endif /*_CHECK_H_*/
