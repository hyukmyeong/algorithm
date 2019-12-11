#include <stdio.h>

typedef struct tagNode {
    struct tagNode* prev;
    struct tagNode* next;
    int data;
}  Node;

Node *createNode(int data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->data = data;
    NewNode->prev = NULL;
    NewNode->next = NULL;

    return NewNode;
}

void destroyNode(Node* node)
{
    free(node);
}

void appendNode(Node** head, Node* newNode)
{
    if((*head) == NULL)
    {
        (*head) = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else
    {
        Node* tail = (*head)->prev;

        tail->next->prev = newNode;
        tail->next = newNode;

        newNode->next = (*head);
        newNode->prev = tail;
    }
}

void insertAfterNode(Node* current, Node* newNode)
{
    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;
}

void removeNode(Node** head, Node* remove)
{
    if((*head) == remove)
    {
        (*head)->prev->next = remove->next;
        (*head)->next->prev = remove->prev;

        (*head) = remove->next;

        remove->prev = NULL;
        remove->next = NULL;
    }
    else
    {
        Node* temp = remove;

        remove->prev->next = temp->next;
        remove->next->prev = temp->prev;

        remove->prev = NULL;
        remove->next = NULL;
    }
}

void printAllNodes(Node* head)
{
    Node* current = head; 

    while(current != NULL)
    {
        printf("currnet->data : %d\n", current->data);
        current = current->next;

        if(current == head)
            break;
    }
}

void printNode(Node* node)
{
    if(node->prev == NULL)
        printf("Prev: NULL\n");
    else
        printf("Prev: %d\n", node->prev->data);

    printf("current:%d\n", node->data);

    if(node->next == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", node->next->data);
}

int main()
{
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* newNode = NULL;
	Node* current = NULL;

	for(i=0; i<5; i++)
	{
		newNode = createNode(i);
		appendNode(&list, newNode);
	}

	printAllNodes(list);
}
