//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

// ====================================================
//Your name: Nathaniel VandenBerg
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
  //Starting at the front destructor will go from each node and delete the information until pointer is NULL
  Node *q = new Node();
  q = front;
  Node *p = front; 
  
  while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    front = NULL;
    rear = NULL;
    return;  
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    if(front != NULL)
      return true;
    else
      return false;
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
  Node *p = front;  
  int cnt = 0;
  while(p != NULL)
    {
      cnt++;
      p = p->next;
    }
  return cnt;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

/*
addRear will take the passed value and add it to the end of the LinkedList.
If the list is empty it will add the value to the front and update the front
and rear pointers to point to the new Node. Otherwise, it will traverse the 
list until the next ponter is NULL and add the Node to the ende of the list. 
The previous Node next pointer will be updated to point to the new Node. Same
for the rear pointer. Node count is then increased by 1.
*/
void LinkedList::addRear(T val) {
  if(front == NULL)
    {
      Node *p = new Node(val);
      front = p;
      rear = p;
      return;
    }
  
	Node *p = new Node(val);
  Node* temp = front;
  
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = p;
  rear = p;
  count++;
  return;
}

/*
addFront will take the passed value and add it to the front of the LinkedList.
If the list is empty it will add the value to the front and update the front
and rear pointers to point to the new Node. Otherwise, the new Node's next pointer
will point to the previous front and update the front pointer to the new Node.
Node count is then increased by 1.
*/
void LinkedList::addFront(T val) {
    if(front == NULL)
    {
      Node *p = new Node(val);
      front = p;
      rear = p;
      return;
    }
	Node *p = new Node(val);
  p->next = front;
  front = p;
  count++;
} 

/*
deleteFront will check if there is a list to delete. If front is NULL it will 
return false. Otherwise it will first update the front pointer to the next Node
then delete the original front node. If the list contains only one Node it will
also update the front and rear pointers to NULL. Node count is then reduced by 1.
*/
bool LinkedList::deleteFront(T &OldNum) {
  if (front == NULL)
    return false;
  
  Node* p = new Node();
  p = front;
  OldNum = p->val;
  front = front->next;
  p = NULL;
  delete p;
  
  if (count == 1)
  {front = rear = NULL;}
  
  count--;

  return (OldNum);
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

/*
deleteRear will check if there is a list to delete. If front is NULL it will 
return false. If there is only a list of 1 Node it will call deleteFront(); 
Otherwise it will traverse the list getting the previous node as well as the 
current nude until the current Node's next pointer is NULL. It will then delete
the current(Rear Node), update the rear pointer to point to the previous nude,
and update the new rear Node's next pointer to NULL. Node count is reduced by 1.
*/
bool LinkedList::deleteRear(T &OldNum) {
  if (front == NULL)
    return false;
  if (count == 1)
    deleteFront(OldNum);
  
  Node* p = new Node();
  Node* q = front;
  while(q->next->next != NULL)
      q = q->next;
  p = q;
  p->next = NULL;
  OldNum = p->val;
  rear = q;
  p = NULL;
  delete p;
  
  count--;

  return (OldNum);
} 

/* --- harder ones for test 2 and 3 -- */

/**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
/*
deleteAt will check if there is a list to delete. If front is NULL it will 
return false. If the position passed to this function is outside the range of
count it will return false. If the pos is 1 Node it will call deleteFront(); If
the pos is the same as the count it will call deleteRear();. Otherwise it will 
traverse the list getting the previous node as well as the current nude until 
the current Node's next pointer is NULL. It will then delete the current(Rear Node),
update the rear pointer to point to the previous nude, and update the new rear 
Node's next pointer to NULL. Node count is reduced by 1.
*/
bool LinkedList::deleteAt(int pos, T &val) {
  if (front == NULL)
    return false;
  if ((pos > count)||(pos < 1))
    return false;
  if (pos == 1)
    deleteFront(val);
  if (pos == count)
    deleteRear(val);
  
  Node* a = front;
  Node* b = new Node();
  b = a->next;
  Node* c = b->next;
  for (int i = 0; i < pos-2; i++)
    {
      a = a->next;
      b = b->next;
      c = c->next;
    }
  a->next = c;
  val = b->val;
  b = NULL;
  delete b;  
    
  return val;
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of deleting the first node and the last node
    // Do not forget to set value.
}

/**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
     * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
     * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
bool LinkedList::insertAt(int pos, T val) {
  if (front == NULL)
    return false;
  if ((pos > count+1)||(pos < 0))
    return false;
  if (pos == 0)
    {
      addFront(val);
      return true;
    }
  if (pos == count+1)
    {
      addRear(val);
      return true;
    }
  
  Node* a = front;
  Node* b = new Node();
  for (int i = 0; i < pos-1; i++)
      a = a->next;
  b->next = a->next;
    
  return true;
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of inserting the first node and the last node
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
    // TODO: Add code here. Interate through the other list and add a new node to this list
    // for each node in the other list. The new node should have the same value as the other node.

}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other) {
    if(this != &other) { // check if the same object
        // Delete all nodes in this list
      /*
      if(this == &other)//check if asked to create list to same mem address
        return;

      Node* node = l1.head;
      while(node!=NULL)
      {
      addRear(node->val);
      node = node->next;
      }
      */
        // TODO: Add code here
        // Interate through the other list and add a new node to this list
        // Be sure to set the front and rear pointers to the correct values
        // Be sure to set the count to the correct value
        // TODO: Add code here
    }
    return *this;
}

