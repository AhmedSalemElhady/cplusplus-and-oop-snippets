#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node
{

public:
    Node(int value)
    {
        this->value = value;
    }
    int value;
    bool isVisited;
    vector<Node *> children;
};

class Graph
{

public:
    Node *sourceNode;

    void DepthFirstSearch() // *It should search for a value, but for the sake of explanation, let's make it print everything
    {
        // * Uses stack
        // * Expected Output:
        // ! 1, 2, 4, 7, 11, 8, 12
        // ! 9
        // ! 5,6,3,10
        stack<Node *> traversalStack;
        traversalStack.push(sourceNode);

        while (!traversalStack.empty())
        {

            Node *currentNode = traversalStack.top(); // * Returns element at top of stack
            traversalStack.pop();                     // * Doesnt return element, just removes it

            if (!currentNode->isVisited)
            {
                cout << currentNode->value << ", ";
                currentNode->isVisited = true;
                // * push its elements inside:
                for (int i = currentNode->children.size() - 1; i >= 0; --i)
                {
                    Node *child = currentNode->children[i];
                    traversalStack.push(child);
                }
            }
        }
        //* Ba5azen fel stack el siblings, w a3mel runn lel children el awal--> DFS: child before sibling
    }

    void BreadthFirstSearch()
    {
        //* Ba5azen fel queue el children, w a3mel runn lel sibling el awal--> BFS: sibling before child

        // * Expected Result:
        // ! 1, 2, 5, 3, 4, 6, 7, 8, 10, 11, 12, 9
        queue<Node *> traversalQueue;
        traversalQueue.push(sourceNode);
        while (!traversalQueue.empty())
        {

            Node *currentNode = traversalQueue.front();
            traversalQueue.pop();

            if (!currentNode->isVisited)
            {
                cout << currentNode->value << ", ";
                currentNode->isVisited = true;
                // * push its elements inside:
                for (int i = 0; i < currentNode->children.size(); ++i)
                {
                    Node *child = currentNode->children[i];
                    traversalQueue.push(child);
                }
            }
        }
    }
};

Node *createOurDummyGraph()
{

    Node **nodes = new Node *[12];
    for (int i = 0; i < 12; ++i)
    {
        nodes[i] = new Node(i + 1);
    }

    nodes[0]->children.push_back(nodes[1]);
    nodes[0]->children.push_back(nodes[4]);
    nodes[0]->children.push_back(nodes[2]);

    nodes[1]->children.push_back(nodes[3]);
    nodes[1]->children.push_back(nodes[0]);

    nodes[3]->children.push_back(nodes[6]);
    nodes[3]->children.push_back(nodes[7]);
    nodes[3]->children.push_back(nodes[1]);

    nodes[6]->children.push_back(nodes[10]);
    nodes[6]->children.push_back(nodes[7]);
    nodes[6]->children.push_back(nodes[3]);

    nodes[10]->children.push_back(nodes[6]);
    nodes[10]->children.push_back(nodes[7]);

    nodes[7]->children.push_back(nodes[3]);
    nodes[7]->children.push_back(nodes[6]);
    nodes[7]->children.push_back(nodes[10]);
    nodes[7]->children.push_back(nodes[11]);
    nodes[7]->children.push_back(nodes[8]);

    nodes[11]->children.push_back(nodes[7]);

    nodes[8]->children.push_back(nodes[7]);

    nodes[4]->children.push_back(nodes[0]);
    nodes[4]->children.push_back(nodes[5]);

    nodes[2]->children.push_back(nodes[0]);
    nodes[2]->children.push_back(nodes[5]);

    nodes[5]->children.push_back(nodes[2]);
    nodes[5]->children.push_back(nodes[4]);
    nodes[5]->children.push_back(nodes[9]);

    nodes[9]->children.push_back(nodes[5]);

    return nodes[0];
}

int main()
{

    Graph mennaGraph;
    mennaGraph.sourceNode = createOurDummyGraph();
    cout << "\n--------------------------------\n";
    cout << "Depth First Search Result:\n";
    mennaGraph.DepthFirstSearch();
    cout << "\n--------------------------------\n";
    mennaGraph.sourceNode = createOurDummyGraph();
    cout << "Breadth First Search Result:\n";
    mennaGraph.BreadthFirstSearch();

    return 0;
}