#include<stdio.h>
#include<stdlib.h>
#define size 5
int top=-1,a[size];
int push(){
    if(top==size){
        printf("Stack Overflow");
    }
    else if(top==-1){
        top++;
        printf("Enter element : ");
        scanf("%d",&a[top]);
    }
    else{
        top++;
        printf("Enter element : ");
        scanf("%d",&a[top]);
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        top--;
    }
}

int display(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",a[i]);
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
            push();
            break;
            
            case 2:
            pop();
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