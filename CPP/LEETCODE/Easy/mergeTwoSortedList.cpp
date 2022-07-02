/*
You are given the heads of two sorted linked 
lists list1 and list2.

Merge the two lists in a one sorted list. 
The list should be made by splicing together the 
nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/

#include<iostream>

class Node
{
    private:
        int data;
        Node *next;
    public:
        void Insert(Node** Head);
        void print(Node *Head);
};

void Node::Insert(Node** Head)
{
    Node *node = new Node();
    node->data=14;
    node->next=NULL;
    (*Head)=node;
}

void Node::print(Node *Head)
{
    std::cout<< this->data <<std::endl;
}
int main()
{
    Node obj;
    Node *Head=NULL;
    obj.Insert(&Head);
    obj.print(Head);
    
    return 0;
}