
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;
struct node *front=NULL;
struct node *rear=NULL;


void push(int n){
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data=n;
    newnode->next=top;
    top=newnode;
}


void pop(){
    struct node *temp;

    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }

    temp=top;
    int value=top->data;
    top=top->next;

    free(temp);

    printf("Data popped out is: %d\n",value);
}


void stackdisplay(){
    struct node *temp;

    if(top==NULL){
        printf("Stack empty\n");
        return;
    }

    temp=top;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}


void enqueue(int val){
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data=val;
    newnode->next=NULL;

    if(front==NULL){
        front=newnode;
        rear=newnode;
        return;
    }

    rear->next=newnode;
    rear=newnode;
}

void dequeue(){
    struct node *temp;

    if(front==NULL){
        printf("Queue Empty\n");
        return;
    }

    int val=front->data;
    temp=front;
    front=front->next;

    if(front==NULL){
        rear=NULL;
    }

    free(temp);

    printf("Deleted element is: %d\n",val);
}

void queuedisplay(){
    struct node *temp;

    if(front==NULL){
        printf("Queue Empty\n");
        return;
    }

    temp=front;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}

int main(){

    while(1){

        int choice,sta,que;

        printf("\n\n1. PUSH ELEMENT");
        printf("\n2. POP ELEMENT");
        printf("\n3. DISPLAY STACK");
        printf("\n4. ENQUEUE");
        printf("\n5. DEQUEUE");
        printf("\n6. DISPLAY QUEUE");
        printf("\n7. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter element: ");
                scanf("%d",&sta);
                push(sta);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("The elements of stack are:\n");
                stackdisplay();
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d",&que);
                enqueue(que);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                printf("The elements of queue are:\n");
                queuedisplay();
                break;

            case 7:
                return 0;

            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
