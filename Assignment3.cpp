#include <iostream>
using namespace ::std;

struct Node {
    int data;
    Node* next;
};

void push(Node** ptr, int n) // I added myself. I think it's much more good like that.
{
    Node* newNode = new Node;
    newNode->data = n;
    (*ptr)->next = newNode;
    *ptr = newNode;
}

Node * arrayToList(const int arr[], size_t size) 
{
    Node* list = new Node;
    list->data = arr[0];

    if (size <= 1) return list;
    for (size_t i = 1; i < size; i++)
    {
        push(&list, arr[i]);
    }
    return list;
}

void del(Node** headRef) //I also added myself
{
    Node* current = *headRef;
    Node* next;

    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = nullptr;
}

Node* removeOdd(Node* head)
{
    while (head != nullptr)
    {
        if (head->data % 2 == 1)
        {
            cout << "Del:" << head << " ";
            del(&head);
        }
        if (head)
            head = head->next;
    }
    return head;
}

void showList(const Node* head) 
{
    const Node* ptr = head;
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void deleteList(Node*& head) 
{
    Node* next = nullptr;

    while (head != nullptr)
    {
        next = head->next;
        free(head);
        head = next;
    }   
    *&head = nullptr;
}

int main()
{
    int arr[] = { 1,2,3,4,5,6 };
    size_t size = sizeof(arr) / sizeof(*arr);
    Node* head = arrayToList(arr, size);
    showList(head);
    head = removeOdd(head);
    showList(head);
    deleteList(head);
    showList(head);
}

