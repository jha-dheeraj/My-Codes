#include<iostream>
#include<vector>
#include<queue>
#include<stack>

class Node
{
    public:
        int data;
        int tempr;
        Node* lchild;
        Node* rchild;

        Node():tempr(0){}
};

class HandleTree
{
    private:
        Node *Root;
    public:
        HandleTree():Root(nullptr){}
        Node *getRoot()
        {
            return Root;
        }
        void createTree();
        void Preorder(Node *Root);
        void Preorder();
        void Inorder(Node *Root);
        void Inorder();
        void Postorder(Node *Root);
        void Postorder();
};

void HandleTree::createTree()
{
    int val;
    Node *temp;
    std::queue<Node*> Queue;
    std::cout<<"Enter the value for node or -1 to exit:"<<std::endl;
    std::cin>>val;
    if(val==-1)
        return;
    Root = new Node();
    Root->data=val;
    Root->lchild=nullptr;
    Root->rchild=nullptr;
    Queue.push(Root);
    while(!Queue.empty())
    {
        temp=Queue.front();
        Queue.pop();
        
        
        std::cout<<"Enter data for left child or -1 to exit:"<<std::endl;
        std::cin>>val;
        if(val==-1)
            break;
        temp->lchild=new Node();
        temp->lchild->data=val;
        temp->lchild->lchild=nullptr;
        temp->lchild->rchild=nullptr;
        Queue.push(temp->lchild);
        
        std::cout<<"Enter data for right child or -1 to exit:"<<std::endl;
        std::cin>>val;
        if(val==-1)
            break;
        temp->rchild=new Node();
        temp->rchild->data=val;
        temp->rchild->lchild=nullptr;
        temp->rchild->rchild=nullptr;
        Queue.push(temp->rchild);
        
    }
    
}
void HandleTree::Preorder(Node *Root)
{
    if(Root!=NULL)
    {
        std::cout<<Root->data<<" ";
        this->Preorder(Root->lchild);
        this->Preorder(Root->rchild);
    }

}

void HandleTree::Preorder()
{
    if(Root==nullptr)
        return;
    Node *temp=Root;
    std::vector<int> values;
    std::stack<Node*> stack;

    while(!stack.empty() || temp!=nullptr)
    {
        if(temp!=nullptr)
        {
            values.push_back(temp->data);
            stack.push(temp);
            temp=temp->lchild;
        }else
        {
            temp=stack.top();
            stack.pop();
            temp=temp->rchild;

        }
    }

    for(std::vector<int>::iterator it=values.begin();it<values.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
    
}

void HandleTree::Inorder(Node *Root)
{
    if(Root!=nullptr)
    {
        this->Inorder(Root->lchild);
        std::cout<<Root->data<<" ";
        this->Inorder(Root->rchild);
    }
}


void HandleTree::Inorder()
{
    if(Root==nullptr)
        return;
    std::vector<int> values;
    std::stack<Node*> stack;
    Node* temp=Root;

    while(!stack.empty() || temp!=nullptr)
    {
        if(temp!=nullptr)
        {
            stack.push(temp);
            temp=temp->lchild;

        }else
        {
            temp=stack.top();
            stack.pop();
            values.push_back(temp->data);
            temp=temp->rchild;
        }
    }

    for(std::vector<int>::iterator it=values.begin(); it<values.end(); it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
}

void HandleTree::Postorder(Node *Root)
{
    if(Root!=nullptr)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        std::cout<<Root->data<<" ";
    }
}

void HandleTree::Postorder()
{
    std::cout<<"start of the program....";
    if( Root == nullptr )
        return;
    std::vector< int > values;
    std::stack< Node* > stack;
    std::cout<<"before Assigning....";
    Node *temp=Root;
    
    while(!stack.empty() || temp!=nullptr)
    {
        if(temp!=nullptr)
        {
            stack.push(temp);
            temp=temp->lchild;
        }else
        {
            temp=stack.top();
            stack.pop();
            temp=temp->rchild;
            std::cout<<"Before checking....";
            if(temp->tempr < 0)
            {
                std::cout<<"After checking....in if";
                values.push_back(temp->data);
                temp=nullptr;
            }else
            {
                std::cout<<"After checking....in else";
                temp->tempr = -1;
                stack.push(temp);
                temp=temp->rchild;
            }

        }
    }

    for(std::vector<int>::iterator it=values.begin();it<values.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

}
int main()
{
    HandleTree *obj = new HandleTree();
    obj->createTree();
    std::cout<<"Preorder Traversal of given tree will be:"<<std::endl;
    obj->Preorder(obj->getRoot());
    std::cout<<"\n";
    std::cout<<"Preorder Traversal of given tree with will be:"<<std::endl;
    obj->Preorder();

    std::cout<<"Inorder Traversal of given tree will be:"<<std::endl;
    obj->Inorder(obj->getRoot());
    std::cout<<"\n";
    std::cout<<"Inorder Traversal of given tree with will be:"<<std::endl;
    obj->Inorder();

    std::cout<<"Postorder Traversal of given tree will be:"<<std::endl;
    obj->Postorder(obj->getRoot());
    std::cout<<"\n";
    std::cout<<"Postorder Traversal of given tree will be:"<<std::endl;
    obj->Postorder();
    return 0;
}