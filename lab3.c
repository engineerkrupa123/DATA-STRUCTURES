#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void insert(){
    int element;
    if (rear==MAX-1){
            printf("Queue Overflow");
    }
    else{
        printf("Enter the element to be inserted");
        scanf("%d",&element);
        if(front==-1){
                front=0;
        }
        rear+=1;
        queue[rear]=element;
        printf("Element inserted successfully");
}
}
void delete(){
    int element;
    if(front==-1){
            printf("Queue Empty");
    }
    else{
            element=queue[front];
            printf("The element deleted is %d",element);
            front+=1;
            if(front>rear){
                    front=-1;
                    rear=-1;
            }
                    printf("The element deleted is %d",element);
            }
}
void display(){
    int i;
    if(front==-1||front>rear){
        printf("Queue Empty");
    }
    else{
        printf("\nThe Elements are\n");
        for(i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
        printf("\n");
}
}
int main(){
    int choice;
    while(1){
    printf("\n-----QUEUE MENU----\n");
    printf("ENTER 1 FOR INSERT\n");
    printf("ENTER 2 FOR DELETE\n");
    printf("ENTER 3 FOR DISPLAY\n");
    printf("ENTER 4 TO EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting.......");
            return 0;
        default:
            printf("Invalid choice");
}
}
}