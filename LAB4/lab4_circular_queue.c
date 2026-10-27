#include<stdio.h>
# define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
void insert(){
    int item;
    if((front==0 && rear==SIZE-1)||(front==rear+1)){
        printf("QUEUE OVERFLOW\n");
        return;
    }
    printf("Enter the element to be inserted");
    scanf("%d",&item);
    if(front==-1){
        front=rear=0;
    }
    else if(rear==SIZE-1){
            rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=item;
    printf("Element inserted successfully\n");
}
void delete(){
if (front==-1){
    printf("QUEUE EMPTY");
    return;
}
printf("Element deleted is %d",queue[front]);
if (front==rear){
    front=rear=-1;
}
else if(front==SIZE-1){
    front=0;
}
else{
    front++;
}
}
void display(){
    int i;
    if (front==-1){
            printf("QUEUE EMPTY");
            return;
    }
printf("Queue Elements are");
for(i=front;i!=rear;i=(i+1)%SIZE){
    printf("%d ",queue[i]);
}
printf("%d\n",queue[rear]);
}
int main(){
    int choice;
    while(1){
        printf("\n---CIRCULAR QUEUE---\n");
        printf("Select 1 to insert an element\n");
        printf("Select 2 to delete an element\n");
        printf("Select 3 to display an element\n");
        printf("Select 4 to exit\n");
        printf("Enter your choice");
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
                return 0;
            default:
                printf("Enter a valid choice\n");
    }
    }
return 0;
}