#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
};

Node* getNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* head = NULL;

// --------------------------------------------PRINTS THE DOUBLY LINKED LIST--------------------------------------------------

// Prints the list
void printList(){
    Node* temp = head;
    
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n\n";
}

// Prints the list using recursion
void printListRec(Node* temp){
    if (temp == NULL)
    {
        cout << "\n\n";
        return ;
    }
    cout << temp->data << " ";
    printListRec(temp->next);
}

// Prints the list in reverse order using recursion
void printListRevRec(){
    Node* temp = head;
    if (temp == NULL)
    {
        return ;
    }
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}

// Returns the length of the doubly linked list
int length(){
    Node* temp = head;
    if(temp==NULL) return 0;
    int n=1;
    while (temp->next!=NULL)
    {
        temp=temp->next;
        n++;
    }
    return n;
}

// --------------------------------------------INSERTING ELEMENTS IN DOUBLY LINKED LIST--------------------------------------------------

// Inserts at the head of the doubly linked list
void insertHead(int data){
    cout << "Inserting " << data << " at head of the list...\n";
    Node* temp = getNode(data);
    temp->next = head;
    if(head != NULL){
        head->prev=temp;
    }
    head = temp;
    printList();
}

// Inserts at the tail of the list
void insertTail(int data){
    cout << "Inserting " << data << " at tail of the list...\n";
    Node* newNode = getNode(data);
    if (head == NULL)
    {
        insertHead(data);
        return ;
    }
    
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    printList();
}

// Inserts at the nth position
void insertPos(int data, int n){
    cout << "Inserting " << data << " at " << n << "th position of the list...\n";
    Node* newNode = getNode(data);
    Node* temp = head;

    if (n==1 || temp==NULL)
    {
        insertHead(data);
        return ;
    }

    if(n>length()){
        cout << "List has less number of elements than " << n << ". Therefore, cannot insert at position " << n << ".\n\n";
        return ;
    }

    for (int i = 0; i <n-2; i++)
    {
        temp = temp->next;
    }
    
    if (temp==NULL || temp->next==NULL)
    {
        insertTail(data);
        return ;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printList();
}

// Inserts after the nth position
void insertAfter(int data, int n){
    cout << "Inserting " << data << " after " << n << "th position...\n";
    if (head == NULL)
    {
        insertHead(data);
        return ;
    }
    
    Node* newNode = getNode(data);
    Node* temp = head;
    for (int i = 0; i < n-1; i++)
    {
        temp = temp->next;
    }
    if (temp==NULL || temp->next==NULL)
    {
        insertTail(data);
        return ;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printList();
}

// Inserts before the nth position
void insertBefore(int data, int n){
    cout << "Inserting " << data << " before " << n << "th position...\n";
    Node* newNode = getNode(data);
    Node* temp = head;
    
    if (n==1 || temp==NULL)
    {
        insertHead(data);
        return ;
    }
    
    for (int i = 1; i < n-2; i++)
    {
        temp = temp->next;
    }

    if (temp==NULL)
    {
        insertTail(data);
        return ;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printList();
}

// Inserts after the data whose value is 'x'
void insertAfterx(int data, int x){
    cout << "Inserting " << data << " after " << x << "...\n";
    Node* newNode = getNode(data);
    Node* temp = head;
    if (temp==NULL)
    {
        insertHead(data);
        return ;
    }
    
    while (temp->data != x)
    {
        temp = temp->next;
    }
    if (temp==NULL || temp->next==NULL)
    {
        insertTail(data);
        return ;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printList();
}

// Inserts before the node whose value is 'x'
void insertBeforex(int data, int x){
    cout << "Inserting " << data << " before " << x << "...\n";
    if (head->data == x)
    {
        insertHead(data);
        return ;
    }
    
    Node* newNode = getNode(data);
    Node* temp = head;
    if (temp == NULL)
    {
        insertHead(data);
        return ;
    }
    
    while (temp->data != x)
    {
        temp = temp->next;
    }
    
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    printList();
}

// --------------------------------------------DELETING THE ELEMENTS FROM THE DOUBLY LINKED LIST--------------------------------------------------

// Deletes the first node
void deleteHead(){
    cout << "Deletes the head node of the doubly linked list...\n";
    Node* temp = head;
    if (head == NULL)
    {
        cout << "Empty list...deletion not possible.\n";
        return ;
    }
    head = head->next;
    head->prev = NULL;
    delete(temp);
    printList();
}

// Deletes the last node
void deleteLast(){
    cout << "Deletes the last node of the doubly linked list...\n";
    Node* temp = head;
    if (temp==NULL)
    {
        cout << "Empty list..deletion not possible.\n";
        return ;
    }
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp==head)
    {
        deleteHead();
        return ;
    }
    
    temp->prev->next = NULL;
    delete(temp);
    printList();
}

// Deletes the node at the nth position
void deleten(int n){
    cout << "Deletes the node at " << n << "th position in the list...\n";
    Node* temp = head;
    if (temp==NULL)
    {
        cout << "Empty list.. deletion not possible.\n";
        return ;
    }
    
    if (n==1)
    {
        deleteHead();
        return ;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        temp = temp->next;
    }
    if (temp==NULL)
    {
        return ;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);
    printList();
}

// Deletes the node after the nth position
void deleteAfter(int n){
    cout << "Deletes the node after " << n << "th position in the list...\n";
    Node* temp = head;
    if (head==NULL)
    {
        cout << "Empty list..deletion not possible.\n";
        return ;
    }
    
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }
    if (temp->next==NULL)
    {
        deleteLast();
        return ;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);
    printList();
    return ;
}


int main()
{
    cout << length() << "\n";
    insertHead(10);
    insertHead(20);
    insertTail(40);
    insertTail(50);
    insertPos(30, 8);
    insertPos(60, 2);
    insertAfter(100, 3);
    insertBefore(200, 4);
    insertAfterx(300, 100);
    insertBeforex(400, 60);
    deleteHead();
    deleteLast();
    deleten(3);
    return 0;
}
