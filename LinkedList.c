/*

Filename: LinkedList
Createdby: Jared
Createdon: 10/14/14
LastModifiedby: Jared
LastModifiedon: 10/28/14

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// creating the node structure for the linked_lists

struct NODE{
  int number;
  struct NODE *next;
} *head = NULL;

// function prototypes

void linked_list();
int deletefirst();
int display_list();
int insertbegin();
int insertend();
int deleteend();
int middleadd(int value_before, int value);
int delete_mid();
int modify_list(int modfiy, int value);



int main(void)
{


  linked_list();


  return(0);

}

void linked_list()
{
 
  // declaring two variables for my menu system and switch case
 
  int boolean2 = 0;
  int input2;
  int previous_value;
  int modify;
  int value;
  int value_before;

  printf("This program initializes a linked list.\n");
  printf("It starts out empty, so the first thing you probably want to do is insert a node.\n");
  printf("\n");

  printf("After that, enjoy trying the various functions.\n");

  printf("Please only enter integer values.\n");


  // menu for making a choice

  while(boolean2 == 0) {
    printf("\nPlease enter your choice.\n");
    printf("1. Insert a node at the END of linklist\n");
    printf("2. Insert a node at the BEGINNING of linklist\n");
    printf("3. Delete a node at the END of linklist\n");
    printf("4. Delete a nod at the BEGINNING of linklist\n");
    printf("5. Insert a node in the MIDDLE of linklist\n");
    printf("6. Delete a node from the MIDDLE of linklist\n");
    printf("7. Modify any node in linklist\n");
    printf("8. Exit\n");
    scanf("%d", &input2);

    switch(input2)
      {
      case 1:
	//end of the list
	insertend();
	display_list();
	break;
      case 2:
	//beginning of list
	insertbegin();
	display_list();
	break;
      case 3:
	//delete a node at the end
	deleteend();
	display_list();
	break;
      case 4:
	// delete a node at the beginning of the linklist
	deletefirst();
	display_list();
	break;
      case 5:
	//insert a node in the middle of linklist
	printf("Enter the value of the node that which you want to insert a new node after it.\n");
	scanf("%d", &value_before);
	printf("Enter the value of new node.\n"); 
	scanf("%d", &value);
	middleadd(value, value_before);
	display_list();
	break;
      case 6:
	// delete a node from the middle of linklist
	delete_mid();
	display_list();
	break;
      case 7:
	// modify any node in linklist
	printf("Enter the value of the node you want to modify\n"); 
	scanf("%d", &modify);
	printf("Enter the new value for this node:\n"); 
	scanf("%d", &value);
	modify_list(modify, value);
	display_list();
	break;
      case 8:
	//exit
	boolean2 = 1;
	break;
      default:
	printf("That is not a valid menu option\n");
	break;

      }

  }
}

// modify_list
// this takes user input about which node will precede the node that you enter.
// the user is then able to enter the value that they want to be entered in the list.

int modify_list(int modify, int value){
  struct NODE *current_node = head;
// setting the current node to head;
// if it is null it means there isn't anything in the list.
  if(current_node == NULL){
    printf("The value can't be found, because there isn't anything in the list.\n");
    return;
  }
// this loops through checking if the value associated with the current node
// equals the input modify value and if the next node is NULL. if both arent, the loop continues.
// as the loop goes along it sets the current node to the next node, essentially moving down the list.

// if the correct node is found the node number is changed to the input value

  while(current_node->number != modify && current_node->next != NULL)
    current_node = current_node->next;
  if(current_node->number == modify)
    current_node->number = value;
  else
    printf("The value you want to modify isn't in the list.\n");
}

// deletes the first node in the linked list
// you need to free up the memory that is used for the temp structure hold.
// sets temp hold to the head, and then moves the head on to the next one.
int deletefirst()
{
// if head is null that means nothing has been added to the list, and thus nothing can be deleted.
  if(head == NULL){
    printf("Empty list. \n");
  }
  // if there is one node in the list before deleting, i figured to put this here
  // because if you don't do it in delete from end you get a segmentation fault.
  else if (head->next == NULL) {
    struct NODE *transition = head;
    free(transition);
    head = NULL;
  }
// normal removing a node from the front
  else{
    struct NODE *hold;

    hold = head;
    head = head->next;

    free(hold);
  }

}

// this deletes the last node in the linked list, because we use two temp variables to temparily store vaules and only use one at the end we use free to free up the memory.

// it sets the temp to head, and loops through checking that the temp is not null
// temp 2 is set to temp, and temp is set to the pointer down.

// temp2's pointer is then set to temps, effectively deleting the node

int deleteend()
{
	// if head is null then there isn't anything in the node to be deleted since its empty
  if(head == NULL){
    printf("Empty list. \n");
  }
  // this takes care of the case when there is one node in the list and you try and delete it.
  // without it, it causes a segmentation fault.
  else if(head->next == NULL){
    struct NODE *transition;
    transition == head;
    free(transition);
    head = NULL;
  }
 // deleting a node from the end
 // while the next value isn't null you loop through updating the values. 
  else{
    struct NODE *temp, *temp2;
    temp = head;
    while(temp->next != NULL)
      {
	temp2 = temp;
	temp = temp->next;
      }
    temp2->next = temp->next;
    free(temp);

  }
}

// delete middle - deletes a node from the middle of the linked list.
// takes user input, and asks what is the preceding node of 
// the one that you would like to delete.

int delete_mid(){
  int preceding_value;
  printf("Enter the value of the node that precedes the node you want to delete\n");
  scanf("%d", &preceding_value);

// if head is null the list is empty.
  if(head == NULL){
    printf("Empty list. \n");
  }
  else {
    // this loops through checking for the entered values
    // when the next node isn't null or the next node value doesn't
    // match the preceding node value you loop though updating temp to the next node.
    struct NODE *temp = head;
    while(temp->next != NULL && temp->number != preceding_value)
      temp = temp->next;

// if you find the preceding node value, everything is shifted one over deleting the node that followed the preceding node.
    if(temp->number == preceding_value){
      struct NODE *transition;
      transition = temp->next;
      temp->next = transition->next;
      free(transition);
    }
    else { // if not found it says it isn't there.
      printf("%d is not in the list \n", preceding_value);
    }

  }
}

// this function goes loops through printing the elements to display them
// it makes a temp node the head node and while the head is not null aka reached the end, it goes through and prints off the values in each node along the way.
int display_list(){

  struct NODE *tempnode;
  tempnode = head;
  printf("The Link list currently has these nodes: \n");
  while(tempnode!=NULL)
    {
      printf("%d->", tempnode->number);
      tempnode = tempnode->next;
    }
}



//inserts a user input num at the beginning of the list.
// initializes two variables, allocates memory for a new node
// stores the user input in the new node, and sets the new node pointer to null.
// checks if the head is null, if it is sets both head and current to newnode
// if not moves to the left of head one space and then reassigns head to new node.
int insertbegin()
{
  struct NODE *new_node;
  new_node = (struct NODE *)malloc(sizeof(struct NODE));

  printf("Enter the value for the node you want to insert at the beginning\n");
  scanf("%d",&new_node->number);
  new_node->next=NULL;
// if the head is null then there isn't anything in the list
  // and you just make the new head.
  if(head == NULL)
    {
      head = new_node;
    }

// else you shift, and add the new head

  else
    {
      new_node->next = head;
      head = new_node;
    }
}

// insert middle

// inserts a value in the middle of a linkedlist immediately after the value that is entered
// through user input. If the list is empty it tells you, and if the value isn't found it tells you.

int middleadd(int value, int value_before){
  struct NODE *newnode = (struct NODE *)malloc(sizeof(struct NODE));
  struct NODE *temp = head;

  // if temp is null then the list is empty.
  if(temp == NULL)
    printf("Empty LinkedList, try adding a node at the beginning or end with the other two methods.\n");
  else{
    while(temp->next != NULL && temp->number != value_before)
      temp = temp->next;
    if(temp->number == value_before){
      newnode->number = value;
      newnode->next = temp->next;
      temp->next = newnode;
    }
    else{
      printf("%d could not be found in the linkedlist, try a different value.\n", value);
    }
  }
}

// inserts a user input num at the end of the list.

// initializes three variables.
// creates memory for a newnode
// takes user input and stores it in the newnodes number
// sets their pointer to null
// if head is null sets head and current to newnode
// if not temp is set to head and you loop through the pointers assigning and reseting them each time
// at the end the temp's pointer is set to newnode which is null and it's number is assigned to the user input in newnode

int insertend()

{
  struct NODE *newnode; //*currentnode;
    struct NODE *temp;

  newnode = (struct NODE *)malloc(sizeof(struct NODE));
  printf("Enter your node in the list\n");
  scanf("%d", &newnode->number);
  newnode->next = NULL;

  if(head == NULL){
    head = newnode;
    //currentnode = newnode;
  }
  else{
    temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

