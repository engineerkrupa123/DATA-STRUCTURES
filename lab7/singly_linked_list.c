
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

struct node* createList() {
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return head;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node* concatenate(struct node *head1,
                         struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

int main() {
    int choice;

    do {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Sort List 1 (Ascending)\n");
        printf("4. Sort List 2 (Ascending)\n");
        printf("5. Reverse List 1\n");
        printf("6. Reverse List 2\n");
        printf("7. Concatenate Lists\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                head1 = createList();
                printf("\nList 1 after creation:\n");
                display(head1);
                break;

            case 2:
                head2 = createList();
                printf("\nList 2 after creation:\n");
                display(head2);
                break;

            case 3:
                sortList(head1);
                printf("\nList 1 after sorting:\n");
                display(head1);
                break;

            case 4:
                sortList(head2);
                printf("\nList 2 after sorting:\n");
                display(head2);
                break;

            case 5:
                head1 = reverseList(head1);
                printf("\nList 1 after reversing:\n");
                display(head1);
                break;

            case 6:
                head2 = reverseList(head2);
                printf("\nList 2 after reversing:\n");
                display(head2);
                break;

            case 7:
                head1 = concatenate(head1, head2);
                head2 = NULL;

                printf("\nList after concatenation:\n");
                display(head1);
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 8);

    return 0;
}


