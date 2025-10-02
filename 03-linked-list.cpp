#include <iostream>

// A lot wrong with this
// Need to revisit

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};


void insertAtEnd(Node*& head, int val);
void insertAtHead(Node*& head, int val);
void printList(Node*& head);


int main()
{
    Node *head = new Node(10);
    // Node *head = nullptr;

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtHead(head, 0);
    printList(head);

    std::cout << "Value at head: " << head->value << std::endl;
    std::cout << "Next node addr: " << head->next << std::endl;

    delete head;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

/// Append at end

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (not head){
        head = newNode;
        return;
    }
    
    Node *accessHead = head;




    while (accessHead->next)
    {
        accessHead = accessHead->next;
    }
    accessHead->next = newNode;
}

// Append at index
// Print list
void printList(Node *&head)
{
    Node *accessHead = head;
    while (accessHead->next)
    {
        std::cout << accessHead->value << "-";
        accessHead = accessHead->next;
    }
    std::cout << std::endl;
}

// Delete a node (go to on n-1, copy ptr to n and move it to next of n-1 th)