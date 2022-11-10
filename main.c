#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "define.h"
#include "link_list.h"
#include "main_func.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/

int main()
{
/*define a node head*/
    node head;
    struct ListSV *b;
/*initialization head node*/
    init(&head);

/*array buffer*/
    char name[40];
    char id[10];
    char account[10];
    float gpa;
    char val_search[20];


/*initialization variable */
    int i;
    uint32_t flag;
    uint32_t pos;
    uint8_t choose;

/* Main program */

    menu_Display();
    do
    {
        printf("Please choose :\n");
        while(scanf("%d", &choose) != 1)
        {
            printf("Please choose number in the menu!\n");
            fflush(stdin);
        }
        flag = 1;
        fflush(stdin);
        switch(choose)
        {
            case 1:

                /*check flag*/
                while(flag != 0)
                {
                    printf("Enter Name -- ");
                    fflush(stdin);
                    gets(name);
                    /*enter name and check name*/

                    if(check_Name(head,name) == false)
                    {
                        flag = 0;
                        break;
                    }
                    printf("Enter Id --");
                    scanf("%s", &id);
                    fflush(stdin);

                    /*enter id and check id*/
                    if(check_Id(head,id) == false)
                    {
                        flag = 0;
                        break;
                    }
                    printf("Enter Account -- ");
                    scanf("%s", &account);
                    fflush(stdin);

                    /*enter account and check account*/
                    if(check_Account(head,account) == false)
                    {
                        flag = 0;
                        break;
                    }
                    printf("Enter Medium score -- ");

                    /*check input medium score if input type worng,user have to enter again*/
                    while(scanf("%f",&gpa) != 1)
                    {
                        printf("Error in user input, gpa should be in numbers\n");
                        printf("Please enter again Medium score!\n");
                        fflush(stdin);
                    }
                    if(check_Gpaval(gpa) == false)
                    {
                        flag = 0;
                        break;
                    }

                    /*create a node*/
                    b = createNode(name,id,account,gpa);
                    printf("\nChoose Position:\n");
                    while(scanf("%d",&pos) != 1)
                    {
                        printf("Error value position,please enter number,again!\n");
                        fflush(stdin);
                    }
                    add_Any(b,&head,pos);
                    flag = 0;
                }
                break;
            case 2:
                /*check node head if not null return true and do function delete*/
                if(check_Null(head) == true)
                {
                    printf("Please enter position want delete:\n");

                    /*check input pos if input type worng,user have to enter again*/
                    while(scanf("%d",&pos) != 1)
                    {
                        printf("Error in user input, position should be in numbers\n");
                        fflush(stdin);
                    }
                    del_Pos(b,pos);
                    printf("Delete success!\n");
                }
                break;
            case 3:
                /*check node head if not null return true and do function print*/
                if(check_Null(head) == true)
                {
                    out_Put(head);
                }
                break;
            case 4:
                /*check node head if not null return true and do function search*/
                if(check_Null(head) == true)
                {
                    printf("Please enter 'name' want to find!\n");

                    /*check input val search if input type worng,user have to enter again*/
                    while(scanf("%s",&val_search) != 1)
                    {
                        printf("Please enter character!\n");
                        fflush(stdin);
                    }
                    searchname(head,val_search);
                }
                break;
            case 5:
                /*check node head if not null return true and do function sort by account*/
                if(check_Null(head) == true)
                {
                    sort_Name(head);
                    printf("List after sort by account is :\n");
                    out_Put(head);
                }
                break;
            case 6:
                /*check node head if not null return true and do function sort by medium score*/
                if(check_Null(head) == true)
                {
                    sort_Gpa(head);
                    printf("List after sort by medium score is :\n");
                    out_Put(head);
                }
                break;
            case 7:
                printf("Thank for use this program,good bye!\n");
                break;
            default:
                printf("Worng choose!\n");
                fflush(stdin);
                break;
        }
    }while(choose != 7);
}
