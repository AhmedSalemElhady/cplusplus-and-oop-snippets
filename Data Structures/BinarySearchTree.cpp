#include <iostream>

using namespace std;

class Node
{

public:
    Node(int val)
    {
        value = val;
        rightChild = nullptr;
        leftChild = nullptr;
    }
    int value;
    Node *leftChild;
    Node *rightChild;
};

class BinarySearchTree
{

    Node *root;

    void postOrderPrintRecursive(Node *node)
    {

        //* Exit Condition
        if (node == nullptr)
            return;
        postOrderPrintRecursive(node->rightChild);
        cout << " " << node->value << " ";
        postOrderPrintRecursive(node->leftChild);
    }

    void preOrderPrintRecursive(Node *node)
    {

        //* Exit Condition
        if (node == nullptr)
            return;

        preOrderPrintRecursive(node->leftChild);
        cout << " " << node->value << " ";
        preOrderPrintRecursive(node->rightChild);
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int newValue)
    {

        //* First: check if root is null
        if (root == nullptr)
        {
            root = new Node(newValue);
            return;
        }

        Node *currentNode = root;

        while (currentNode != nullptr)
        {

            if (currentNode->value >= newValue)
            {

                if (currentNode->leftChild == nullptr)
                {
                    currentNode->leftChild = new Node(newValue);
                    break;
                }
                else
                {
                    currentNode = currentNode->leftChild;
                }
            }
            else
            {
                if (currentNode->rightChild == nullptr)
                {
                    currentNode->rightChild = new Node(newValue);
                    break;
                }
                else
                {
                    currentNode = currentNode->rightChild;
                }
            }
        }
    }

    bool search(int valueToFind)
    {
        Node *currentNode = root;
        while (currentNode != nullptr)
        {

            if (valueToFind == currentNode->value)
            {
                return true;
            }
            else if (valueToFind > currentNode->value)
            {
                currentNode = currentNode->rightChild;
            }
            else
            {
                currentNode = currentNode->leftChild;
            }
        }
        return false;
    }

    void deleteNode(int valueToDelete)
    {

        if (root == nullptr)
            return;

        // * First, we need to find the node we are searching for
        Node *theNodeWeAreSearchingFor = nullptr;
        Node *parent = nullptr;
        Node *currentNode = root;
        while (currentNode != nullptr)
        {

            if (valueToDelete == currentNode->value)
            {
                theNodeWeAreSearchingFor = currentNode;
                break;
            }
            else if (valueToDelete > currentNode->value)
            {
                currentNode = currentNode->rightChild;
                parent = currentNode;
            }
            else
            {
                currentNode = currentNode->leftChild;
                parent = currentNode;
            }
        }

        if (theNodeWeAreSearchingFor == nullptr)
        {
            cout << "There is no node with value " << valueToDelete << " TO delete!\n";
            return;
        }

        // * Hena e7na la2ena el node!
        //* Case 1: The node was the root:
        if (parent == nullptr)
        {
            cout << "deleting a root\n";
            int newRootValue = findMaximumNodeInSubTree(root->leftChild);
            deleteNode(newRootValue); // * I know it is leaf node
            root->value = newRootValue;
        }
        //* Case 2:
        if (theNodeWeAreSearchingFor->leftChild != nullptr || theNodeWeAreSearchingFor->rightChild != nullptr)
        {
            cout << "deleting internal node\n";
            int newNodeValue = findMaximumNodeInSubTree(root->leftChild);
            deleteNode(newNodeValue); // * I know it is leaf node
            theNodeWeAreSearchingFor->value = newNodeValue;
        }else{
            cout << "deleting leaf";
        }
        

            //* Case 3: If it is a leaf node, just delete it;
            if (parent->rightChild == theNodeWeAreSearchingFor)
            {
                delete theNodeWeAreSearchingFor;
                parent->rightChild = nullptr;
            }
            else
            {
                delete theNodeWeAreSearchingFor;
                parent->leftChild = nullptr;
            }
        
    }

    int findMaximumNodeInSubTree(Node *node)
    {

        while (node->rightChild != nullptr)
        {

            node = node->rightChild;
        }
        return node->value;
    }

    void printByPreOrderTraversal()
    {
        preOrderPrintRecursive(root);
    }

    void printByPostOrderTraversal()
    {
        postOrderPrintRecursive(root);
    }
};

int main()
{

    BinarySearchTree mennaBST;
    /*  
                79
        60               85
    53       71       80    132  
      57   66  75       83     150
                                 
    */
    mennaBST.insert(79);
    mennaBST.insert(60);
    mennaBST.insert(53);
    mennaBST.insert(57);
    mennaBST.insert(71);
    mennaBST.insert(66);
    mennaBST.insert(75);
    mennaBST.insert(85);
    mennaBST.insert(80);
    mennaBST.insert(83);
    mennaBST.insert(132);
    mennaBST.insert(150);
    cout << "Pre-Order Traversal:\n";
    // * Expected: 53, 57, 60, 66, 71, 75, 79, 80, 83, 85, 132, 150
    // !           53  57  60  66  71  75  79  80  83  85  132  150
    mennaBST.printByPreOrderTraversal();
    cout << "\nPost-Order Traversal:\n";
    // * Expected: 150, 132, 85, 83, 80, 79, 75, 71, 66, 60, 57, 53
    mennaBST.printByPostOrderTraversal();

    cout << "\nWhat value are you searching for? ";
    int val;
    cin >> val;
    bool isFound = mennaBST.search(val);
    if (isFound)
    {
        cout << "Element " << val << " is Found!\n";
    }
    else
    {
        cout << "Element " << val << " is NOT Found!\n";
    }

    mennaBST.deleteNode(150);
    mennaBST.printByPreOrderTraversal();
    cout << endl;
    mennaBST.deleteNode(71);
    mennaBST.printByPreOrderTraversal();
    cout << endl;
    mennaBST.deleteNode(79);
    mennaBST.printByPreOrderTraversal();
}
