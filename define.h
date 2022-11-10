#ifndef _DEFINE_H_
#define _DEFINE_H_
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
 
 /**
  * @brief:  define a struct sinhvien
  * @param1: node head
  * @param2: Array char id
  * @param3: Array char name
  * @param4: float gpa
  */
struct Student
{
    char id[10];
    char name[30];
    char account[10];
    float gpa;
};
typedef struct Student SV;
 /**
  * @brief:  define a node ListSV
  * @param1: data sv
  * @param2: pointer next
  */
struct ListSV
{
   SV sv;
   struct ListSV *next;
};
 typedef struct ListSV *node;

#endif
