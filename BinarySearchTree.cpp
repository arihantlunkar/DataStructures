#include <iostream>
#include <queue>

using namespace std;


struct Node
{
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

class BinarySearchTree
{
    struct Node *root = nullptr;

    Node* createNode(int d) const
    {
        struct Node* node = new Node;
        node->data = d;

        return node;
    }

public:

    ~BinarySearchTree()
    {
        if(!isEmpty())
        {
            queue<struct Node*> queueObj;

            queueObj.push(root);

            while(!queueObj.empty())
            {
                struct Node* node = queueObj.front();

                queueObj.pop();

                if(node->left != nullptr)
                {
                    queueObj.push(node->left);
                }
                if(node->right != nullptr)
                {
                    queueObj.push(node->right);
                }                

                cout << "Deleting " << node->data << endl;
                
                delete node;
                node = nullptr;
            }

        }
    }

    struct Node* getRoot() const
    {
        return root;
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void insert(int d) // insert at first free position while doing BFS
    {
        if(!isEmpty())
        {
            insertRecursive(root, d);
        }
        else
        {
            root = createNode(d);
        }
    }
    
    void insertRecursive(struct Node* & temp, int d)
    {        
        if(d >= temp->data && temp->right)
        {
            insertRecursive(temp->right, d);
        }
        else if(d < temp->data && temp->left)
        {
            insertRecursive(temp->left, d);
        }
        else if(d >= temp->data && !temp->right)
        {
            temp->right = createNode(d);
        }
        else if(d < temp->data && !temp->left)
        {
            temp->left = createNode(d);
        }
    }

    void printDFSInorder(struct Node* node) const
    {
        if (node == nullptr)
            return;

        printDFSInorder(node->left);
        cout << node->data << " ";
        printDFSInorder(node->right);
    }

    void printDFSPreorder(struct Node* node) const
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        printDFSPreorder(node->left); ;
        printDFSPreorder(node->right);
    }

    void printDFSPostorder(struct Node* node) const
    {
        if (node == nullptr)
            return;

        printDFSPostorder(node->left);
        printDFSPostorder(node->right);
        cout << node->data << " ";
    }

    void printBFS() const
    {
        if(!isEmpty())
        {            
            queue<struct Node*> queueObj;

            queueObj.push(root);

            while(!queueObj.empty())
            {
                struct Node* node = queueObj.front();

                cout << node->data << " ";

                queueObj.pop();

                if(node->left != nullptr)
                {
                    queueObj.push(node->left);
                }
                if(node->right != nullptr)
                {
                    queueObj.push(node->right);
                }
            }

        }
    }
    
    bool getParent(struct Node* temp, int key, struct Node* & parent) const
    {
        if(temp == nullptr)
            return false;
        
        if(temp->data == key)
            return true;
            
        if(getParent(temp->left, key, parent) || getParent(temp->right, key, parent))
        {
            parent = temp;
            return false;
        }   
        
        return false;
    }
    
    void convertIntoMirrorTree(struct Node* temp)
    {
        if(temp == nullptr)
            return;         
        
        Node* tmp = temp->left;
        temp->left = temp->right;
        temp->right = tmp;
        
        convertIntoMirrorTree(temp->left);
        convertIntoMirrorTree(temp->right);
    }
    
    void printAllNodesAtHeight(struct Node* temp, int height)
    {
       if(temp == NULL)  
          return; 
          
       if( height == 0 ) 
       { 
          cout << temp->data << " "; 
          return ; 
       } 
       else
       {       
          printAllNodesAtHeight( temp->left, height-1 ) ; 
          printAllNodesAtHeight( temp->right, height-1 ) ; 
       } 
    }
};

int main()
{
    BinarySearchTree* binarySearchTreeObj = new BinarySearchTree;

    binarySearchTreeObj->insert(1);
    binarySearchTreeObj->insert(2);
    binarySearchTreeObj->insert(3);
    binarySearchTreeObj->insert(4);
    binarySearchTreeObj->insert(5);
    binarySearchTreeObj->insert(6);
    binarySearchTreeObj->insert(7);

    binarySearchTreeObj->printDFSInorder(binarySearchTreeObj->getRoot());

    cout << endl;

    binarySearchTreeObj->printDFSPreorder(binarySearchTreeObj->getRoot());

    cout << endl;

    binarySearchTreeObj->printDFSPostorder(binarySearchTreeObj->getRoot());

    cout << endl;

    binarySearchTreeObj->printBFS();

    cout << endl;    
        
    binarySearchTreeObj->convertIntoMirrorTree(binarySearchTreeObj->getRoot());   
    
    binarySearchTreeObj->printBFS();

    cout << endl; 
    
    binarySearchTreeObj->printAllNodesAtHeight(binarySearchTreeObj->getRoot(), 2);
    
    cout << endl;
    
    struct Node * parent = nullptr;
    (void)binarySearchTreeObj->getParent(binarySearchTreeObj->getRoot(), 6, parent);
    
    if(parent)
        cout << "Parent of 6 is " << parent->data << endl;
        
    delete binarySearchTreeObj;
    binarySearchTreeObj = nullptr;

    return 0;
}
