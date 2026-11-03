
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void createList(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int value, i;

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void deleteFromFirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;
    free(temp);

    printf("First element deleted successfully\n");
}

void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Last element deleted\n");
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Last element deleted successfully\n");
}

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 0) {
        deleteFromFirst(head);
        return;
    }

    struct Node *temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position out of range!\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Element deleted at position %d\n", position);
}

void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, n, position;

    do {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create a linked list\n");
        printf("2. Delete at beginning\n");
        printf("3. Delete at end\n");
        printf("4. Delete at specified position\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Number of elements cannot be negative\n");
                } else {
                    createList(&head, n);
                }
                break;

            case 2:
                deleteFromFirst(&head);
                break;

            case 3:
                deleteFromEnd(&head);
                break;

            case 4:
                printf("Enter position index (starting from 0): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 5:
                printf("Linked list contents:\n");
                display(head);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again\n");
        }
    } while (choice != 6);
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
