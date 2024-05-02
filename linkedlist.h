//CS311 LinkedList.h
//INSTRUCTION:
//Linkedlist class - header file template 
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS 
#pragma once

// =======================================================
// Your name: Nathaniel
// Compiler:  g++ 
// File type: headher file  linkedlist.h
//=======================================================
#include <string>
using namespace std;

// Datatype T : element type definition
typedef int T;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node {
    T val;   // stored value
    Node *next;  // pointer to the next node

    // Constructor
    Node(T val = 0, Node *next = nullptr) {
        this->val = val;
        this->next = next;
    }
};
//---------------------------------------------------------

class LinkedList {
private:
    Node *front;       // pointer to the front node
    Node *rear;        // pointer to the rear node
    int count;        // the number of nodes in the list

public:
    LinkedList() {     // constructor to create an empty list
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~LinkedList();     // destructor to destroy all nodes and release memory

    /**
     * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
     * @param other LinkedList to be copied
     */
    LinkedList(const LinkedList &other);

    /**
     * @brief Overloading of = (returns a reference to a LinkedList)
     * @param other LinkedList to be copied
     * @return reference to a LinkedList
     */
    LinkedList &operator=(const LinkedList &other);


    /**
     * @brief Purpose: Checks if the list is empty
     * @return true if the list is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief  Get the number of nodes in the list
     * @return int The number of nodes in the list
     */
    int length() const;

    /**
     * @brief Convert the contents of the list to a string
     */
    string toString();

    /**
     * @brief  Displays the contents of the list
     *
     */
    void displayAll();

    /*
    addFront will take the passed value and add it to the front of the LinkedList.
    If the list is empty it will add the value to the front and update the front
    and rear pointers to point to the new Node. Otherwise, the new Node's next pointer
    will point to the previous front and update the front pointer to the new Node.
    Node count is then increased by 1.
    */
    void addFront(T val);

    /*
    addRear will take the passed value and add it to the end of the LinkedList.
    If the list is empty it will add the value to the front and update the front
    and rear pointers to point to the new Node. Otherwise, it will traverse the 
    list until the next ponter is NULL and add the Node to the ende of the list. 
    The previous Node next pointer will be updated to point to the new Node. Same
    for the rear pointer. Node count is then increased by 1.
    */
    void addRear(T val);

    /*
    deleteFront will check if there is a list to delete. If front is NULL it will 
    return false. Otherwise it will first update the front pointer to the next Node
    then delete the original front node. If the list contains only one Node it will
    also update the front and rear pointers to NULL. Node count is then reduced by 1.
    */
    bool deleteFront(T &val);

    /*
    deleteRear will check if there is a list to delete. If front is NULL it will 
    return false. If there is only a list of 1 Node it will call deleteFront(); 
    Otherwise it will traverse the list getting the previous node as well as the 
    current nude until the current Node's next pointer is NULL. It will then delete
    the current(Rear Node), update the rear pointer to point to the previous nude,
    and update the new rear Node's next pointer to NULL. Node count is reduced by 1.
    */
    bool deleteRear(T &val);

    /**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 0 to count-1. pos = 0 for the first node, and pos = count-1 for the last node.
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
    bool deleteAt(int pos, T &val);

    /*
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 0 to count.
     * The value will be inserted before the node at the specified position. if pos = 0, the value will be inserted
     * at the front of the list. if pos = count, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
    bool insertAt(int pos, T val);
};
