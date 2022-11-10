#ifndef  _LINK_LIST_H_
#define  _LINK_LIST_H_
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief:  create a node
  * @param1: Array name
  * @param2: Array id
  * @param1: Array account
  * @param2: float gpa
  */
struct ListSV *createNode(char name[],char id[],char account[],float gpa);
/**
  * @brief:  Print linked list
  * @param1: node head
  */
void out_Put(node head);
/**
  * @brief:  sort gpa in linked list
  * @param1: node head
  */
void sort_Gpa(node head);
/**
  * @brief:  sort account in linked list
  * @param1: node head
  */
void sort_Name(node head);
/**
  * @brief:  delete a node
  * @param1: pointer head
  * @param2: position want delete
  */
void del_Pos(struct ListSV *head,uint32_t pos);
/**
  * @brief:  add a node to any position
  * @param1: pointer node
  * @param2: pointer head
  * @param3: position want add
  */
void add_Any(struct ListSV *node,struct ListSV **head,uint32_t pos);
/**
  * @brief:  search a person in list
  * @param1: pointer head
  * @param2: name of person want find
  */
void searchname(node head, char name[]);
/**
  * @brief:  initizelation a node head
  * @param1: pointer head
  */
void init(node *head);
#endif
