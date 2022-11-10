#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "define.h"

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

node head = NULL;

/*initization node head is begin*/
void init(node *head)
{
    *head = NULL;
}
/*create,allocate a node */
struct ListSV *createNode(char name[],char id[],char account[],float gpa)
{
    /*dynamic allocation*/
    struct ListSV *temp = (struct ListSV*) malloc(sizeof(struct ListSV));
    if (temp == NULL)
    {
        printf("\n Allocation failed \n");
        exit(2);
    }
    /*copy value from array to temp*/
    strcpy(temp->sv.name,name);
    strcpy(temp->sv.id,id);
    strcpy(temp->sv.account,account);
    temp->sv.gpa = gpa;
    
    temp->next = head;
    head = temp;
    return temp ;
}

/*print detail a student*/
void out_Put(node head)
{
    while(head != NULL)
    {
        printf("%-15s %-30s %-20s %s\n","ID","NAME","ACCOUNT","SCORE");
        printf("%-15s %-30s %-20s %0.2lf\n",&head->sv.id,&head->sv.name,&head->sv.account,head->sv.gpa);
        head = head->next;
    }
}

/*sort list by medium score*/
void sort_Gpa(node head)
{
    node ptemp;
    node qtemp;

    /*find the number and swap if it small than*/
    for(ptemp = head; ptemp != NULL; ptemp = ptemp->next)
    {
        for(qtemp = ptemp->next; qtemp != NULL; qtemp = qtemp->next)
        {
            if (ptemp->sv.gpa  > qtemp->sv.gpa)
            {
                /*swap data */
                SV temp = ptemp->sv;
                ptemp->sv = qtemp->sv;
                qtemp->sv = temp;
            }
        }
    }
}

/*sort list by account*/
void sort_Name(node head)
{
    node ptemp;
    node qtemp;

    /*find the account and swap if it small than*/
    for(ptemp = head; ptemp != NULL; ptemp = ptemp->next)
    {
        for(qtemp = ptemp->next; qtemp != NULL; qtemp = qtemp->next)
        {
            if(strcmp(ptemp->sv.account,qtemp->sv.account) < 0)
            {
                /*swap data */
                SV temp = ptemp->sv;
                ptemp->sv = qtemp->sv;
                qtemp->sv = temp;
            }
        }
    }
}

void del_Pos(struct ListSV *head,uint32_t pos)
{
    uint32_t i = 1;
    struct ListSV *index1 = head;
    struct ListSV *index;

    /*check node and position*/
    if((head->next == NULL) || (pos == 1))
    {
        /*if condition is true delete node*/
        head = head->next;
        free(index1);
    }
    else
    {
        while((i < pos) && (index1 != 0))
        {
            i++;
            index = index1;
            index1 = index1->next;
        }
        /*if condition is true delete node*/
        index->next = index1->next;
        free(index1);
    }
}
/*search for a person by name*/
void searchname(node head, char name[])
{
    node temp = head;
    uint8_t i = 0;
    uint8_t *check;

    while(temp != NULL)
    {
        /*Check the string, if it is the same, print it out*/
        check = strstr(temp->sv.name,name);
        fflush(stdin);
        if(check != NULL)
        {
            printf("\n Name found \n");
            printf("\n Details are -\n");
            printf("\n Name            : %s",temp->sv.name);
            printf("\n Id              : %s",temp->sv.id);
            printf("\n Account         : %s",temp->sv.account);
            printf("\n Gpa             : %f\n", temp->sv.gpa);
            printf("------------------------ \n");
            i++;
        }
        temp = temp->next;
    }
    /*If it doesn't match, report an error*/
    if(i == 0)
    {
        printf("This person is not on the list\n");
        fflush(stdin);
    }
}

/*add a node to linked list*/
void add_Any(struct ListSV *node,struct ListSV **head,uint32_t pos)
{
    uint32_t i = 1;
    struct ListSV *index1 = *head;
    struct ListSV *index;
    
    /*check node and position*/
    if(*head == NULL || pos == 1)
    {
        if(*head == NULL)
        {
            *head = node;
            node->next = NULL;
        }
        else
        {
            node->next = *head;
            *head = node;
        }
    }
    else
    {
        while(i < pos && index1 != NULL)
        {
            i++;
            index = index1;
            index1 = index1->next;
        }
        node->next = index1;
        index->next = node;
    }
    printf("Add success!\n");
}
