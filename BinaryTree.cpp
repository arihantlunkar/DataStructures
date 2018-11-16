#include <iostream>
#include <queue>

using namespace std;


struct Node
{
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

class BinaryTree
{
    struct Node *root = nullptr;

    Node* createNode(int d) const
    {
        struct Node* node = new Node;
        node->data = d;

        return node;
    }

public:

    ~BinaryTree()
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
            bool inserted = false;

            queue<struct Node*> queueObj;

            queueObj.push(root);

            while(!inserted)
            {
                struct Node* node = queueObj.front();
                queueObj.pop();

                if(node->left == nullptr)
                {
                    node->left = createNode(d);
                    inserted = true;
                }
                else if(node->right == nullptr)
                {
                    node->right = createNode(d);
                    inserted = true;
                }
                else
                {
                    queueObj.push(node->left);
                    queueObj.push(node->right);
                }
            }

        }
        else
        {
            root = createNode(d);
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
    
    void deletion(struct Node* root, int key) 
    {
        if(!isEmpty())
        {
            bool isKeyPresent = false;
            
            queue<struct Node*> queueObj;
            struct Node* node = nullptr; 
            struct Node* keyNode = nullptr;

            queueObj.push(root);

            while(!queueObj.empty())
            {
                node = queueObj.front();
                
                if(node->data == key)
                {
                    keyNode = node;
                    isKeyPresent = true;
                }

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
            
            if(isKeyPresent)
            {
                struct Node* parentNode = nullptr;
                
                (void)getParent(root, node->data /*or key*/, parentNode);
                
                if(parentNode)
                {
                    if(parentNode->right && parentNode->right->data == node->data)
                    {                        
                        keyNode->data = parentNode->right->data;
                        parentNode->right = nullptr;     
                    }
                    
                    else if(parentNode->left && parentNode->left->data == node->data)
                    {                        
                        keyNode->data = parentNode->left->data;
                        parentNode->left = nullptr;
                    }
                }
                
                delete node;
                node = nullptr;
            }
        }
    }
};

int main()
{
    BinaryTree* binaryTreeObj = new BinaryTree;

    binaryTreeObj->insert(1);
    binaryTreeObj->insert(2);
    binaryTreeObj->insert(3);
    binaryTreeObj->insert(4);
    binaryTreeObj->insert(5);
    binaryTreeObj->insert(6);
    binaryTreeObj->insert(7);

    binaryTreeObj->printDFSInorder(binaryTreeObj->getRoot());

    cout << endl;

    binaryTreeObj->printDFSPreorder(binaryTreeObj->getRoot());

    cout << endl;

    binaryTreeObj->printDFSPostorder(binaryTreeObj->getRoot());

    cout << endl;

    binaryTreeObj->printBFS();

    cout << endl;
    
    binaryTreeObj->deletion(binaryTreeObj->getRoot(), 2);
    
    binaryTreeObj->printBFS();

    cout << endl;
    
    struct Node * parent = nullptr;
    (void)binaryTreeObj->getParent(binaryTreeObj->getRoot(), 6, parent);
    
    if(parent)
        cout << "Parent of 6 is " << parent->data << endl;
    
    delete binaryTreeObj;
    binaryTreeObj = nullptr;

    return 0;
}
