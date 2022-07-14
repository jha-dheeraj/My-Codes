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
    public:
        int data;
        Node *next;
};

class LinkedList
{
    private:
        Node *Head;
    
    public:
        LinkedList(){Head=NULL;}
        LinkedList(int arr[], int n);
        ~LinkedList();

        /*void Insert(int index, int data);*/
        void Display();
        static void Display_generic(Node *h1);
        Node *Merge(Node *h1, Node *h2);
        Node *GetHead();

};

LinkedList::LinkedList(int arr[], int n)
{
    Node *newNode, *temp; 
    
    Head = new Node;
    Head->data=arr[0];
    Head->next=NULL;
    temp=Head;

    for(int i=1;i<n;i++)
    {
        newNode=new Node;
        newNode->data=arr[i];
        newNode->next=NULL;
        temp->next=newNode;
        temp=temp->next;
    }
}

void LinkedList::Display()
{
    if(Head!=NULL)
    {
        Node *temp=Head;
        std::cout<<"Printing data for the given list:"<<std::endl;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<"\n";
    }
}

Node *LinkedList::GetHead()
{
    return this->Head;
}

Node *LinkedList::Merge(Node *h1, Node *h2)
{
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    Node *dummy;
    if(h1->data < h2->data)
    {
        dummy=h1;
        h1=h1->next;
    }else
    {
        dummy=h2;
        h2=h2->next;
    }
    Head=dummy;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data < h2->data)
        {
            dummy->next=h1;
            h1=h1->next;
            dummy=dummy->next;
        } else
        {
            dummy->next=h2;
            h2=h2->next;
            dummy=dummy->next;
        }
    }

    if(h1==NULL)
    {
        while(h2!=NULL)
        {
            dummy->next=h2;
            h2=h2->next;
            dummy=dummy->next;
        }
    } else
    {
        while(h1!=NULL)
        {
            dummy->next=h1;
            h1=h1->next;
            dummy=dummy->next;
        }
    }
    return Head;
}

void Display_generic(Node *Head)
{

    if(Head!=NULL)
    {
        Node *temp=Head;
        std::cout<<"Printing data for the given list:"<<std::endl;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<"\n";
    }
}

LinkedList::~LinkedList()
{
    this->Display();
    if(Head!=NULL)
    {
        std::cout<<"Destroying Nodes."<<std::endl;
        Node *temp;
        while(Head!=NULL)
        {
            std::cout<<"Deleting..."<<Head->data<<std::endl;
            temp=Head;
            Head=Head->next;
            delete temp;
		    temp=NULL;
        }
    }
}

int main()
{

    int arr1[]={1,2,5,6,7};
    int arr2[]={3,7,8,9,10};
    LinkedList ll1(arr1,5);
    LinkedList ll2(arr2,5);
    Node *res;

    ll1.Display();
    ll2.Display();
    ll1.Merge(ll1.GetHead(), ll2.GetHead());
    std::cout<<"Displaying After merge:"<<std::endl;
    ll1.Display();

    return 0;
}

