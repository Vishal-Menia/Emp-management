#include<stdio.h>
#include<stdlib.h>
#define size 5
int head=-1,tail=-1,a[size];
int enqueue(){
    if(tail==size){
        printf("Queue Overflow");
    }
    else if(tail==-1){
        head++;
        tail++;
        printf("Enter element : ");
        scanf("%d",&a[tail]);
    }
    else{
        tail++;
        printf("Enter element : ",head);
        scanf("%d",&a[tail]);
    }
}

int dequeue(){
    if(head==tail==-1){
        printf("Queue Underflow");
    }
    else if(head==tail){
        printf("Queue underflow");
    }
    else{
        head++;
    }
}

int display(){
    if(head==tail){
        printf("Queue Underflow");
    }
    else{
        for(int i=head;i<=tail;i++){
            printf("%d ",a[i]);
        }
    }
}

int main(){
    int ch;
    while(1){
        printf("\n   MENU\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            enqueue();
            break;
            
            case 2:
            dequeue();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            exit(0);

            default:
            printf("Wrong choice!!");
        }
    }
    return 0;
}