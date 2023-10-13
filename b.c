#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//vishal



struct node
{
    int id;
    char name[20];
    char contact[10];
    float salary;
    struct node *next;
} *new, *temp, *temp1, *head, *tail;

int eid;
char ename[20];
char econtact[10];
float esalary;


int menu()
{
    int ch;
    printf("=========================================================================================\n|\t\t\t\t\tMain Menu\t\t\t\t\t|\n=========================================================================================\
    \n|\t\t1. Adding employee records                                              |\
    \n|\t\t2. For displaying record of all the employees                           |\
    \n|\t\t3. For displaying record of a particular employee                       |\
    \n|\t\t4. For deleting record of a particular employee                         |\
    \n|\t\t5. For deleting record of all the employees                             |\
    \n|\t\t6. For modification in a record                                         |\
    \n|\t\t7. For displaying the payroll of employees                              |\
    \n|\t\t8. For exit                                                             |\
    \n=========================================================================================");
    printf("\nEnter your choice : ");
    scanf("%d", &ch);
    printf("\n");
    //printf("hello world");
    return ch;
}

void add()
{
    char c = 'y';
    while (c == 'y' || c == 'Y')
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter employee id      : ");
        scanf("%d", &eid);
        printf("Enter employee name    : ");
        scanf("%s", ename);
        printf("Enter employee contact : ");
        scanf("%s", econtact);
        printf("Enter employee salary  : ");
        scanf("%f", &esalary);
        new->id = eid;
        strcpy(new->name, ename);
        strcpy(new->contact, econtact);
        new->salary = esalary;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = new;
        }
        printf("\nDo you want to add more data? (y/n) : ");
        scanf(" ");
        scanf("%c", &c);
        printf("\n");
    }
}

void disp_all()
{
    temp = head;
    printf("=========================================================\n");
    printf("|  ID\t|\t\bName\t|\t\b\bContact\t|\t\b\bSalary\t|\n");
    printf("=========================================================\n");
    while (temp != NULL)
    {
        printf("|  %d\t| ", temp->id);
        printf("   %s\t|  ", temp->name);
        printf(" %s  |\t", temp->contact);
        printf("\b\b%.f\t|\n", temp->salary);
        temp = temp->next;
    }
    printf("=========================================================\n");
    printf("\n");
}

void disp_one()
{
    int n;
    printf("Enter employee id : ");
    scanf("%d", &n);
    temp = head;
    printf("=========================================================\n");
    printf("|  ID\t|\t\bName\t|\t\b\bContact\t|\t\b\bSalary\t|\n");
    printf("=========================================================\n");
    while (temp != NULL)
    {
        if (temp->id == n)
        {
            printf("|  %d\t| ", temp->id);
            printf("   %s\t|  ", temp->name);
            printf(" %s  |\t", temp->contact);
            printf("\b\b%.f\t|\n", temp->salary);
            printf("=========================================================\n");
            break;
        }
        temp = temp->next;
    }
}

int del_one()
{
    int n;
    printf("Enter employee id : ");
    scanf("%d", &n);
    temp = head;
    if (head->id == n)
    {
        head = head->next;
        temp->next = NULL;
        return 0;
    }

    while (temp != NULL)
    {
        if (temp->next->id == n)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void del_all()
{
    /*temp=temp1=head;
    while(temp!=NULL){
        temp=temp->next;
        temp1->next=NULL;
        temp1=temp;
    }*/
    head = NULL;
    tail = NULL;
    printf("Data of all the employees deleted successfully.\n");
}

void modify()
{
    int n;
    printf("Enter employee id of the data you want to modify : ");
    scanf("%d", &n);
    temp = head;
    printf("\nEnter new data.");
    while (temp != NULL)
    {
        if (temp->id == n)
        {
            printf("\nEnter employee id    : ");
            scanf("%d", &eid);
            printf("Enter employee name    : ");
            scanf("%s", ename);
            printf("Enter employee contact : ");
            scanf("%s", econtact);
            printf("Enter employee salary  : ");
            scanf("%f", &esalary);
            temp->id = eid;
            strcpy(temp->name, ename);
            strcpy(temp->contact, econtact);
            temp->salary = esalary;
            printf("Data of empolyee id : %d was updated successfully.\n", n);
            break;
        }
        temp = temp->next;
    }
}

void emp_payroll()
{
    temp = head;
    printf("=================================================================================================================================================================\n");
    printf("|  ID\t|\t\bName\t|\t\b\bContact\t|\t\b\bBasic salary\t|\tDA\t|\tHRA\t|\t\bGross Salary\t|\t\bTax\t|\tNet Salary\t|\n");
    printf("=================================================================================================================================================================\n");
    while (temp != NULL)
    {
        float a = temp->salary;
        printf("|  %d\t| ", temp->id);
        printf("   %s\t|  ", temp->name);
        printf(" %s  |\t", temp->contact);
        printf("%.2f \t|", temp->salary);
        printf("     %.2f\t|", a * 0.5);
        printf("     %.2f\t|", a * 0.35);
        printf("\t%.2f\t|", a + a * 0.5 + a * 0.35);
        printf("     %.2f\t|", a * 0.2);
        printf("\t%.2f\t|\n", a + a * 0.5 + a * 0.35 - a * 0.2);
        temp = temp->next;
    }
    printf("=================================================================================================================================================================\n");
}

int main()
{
    while (1)
    {
        int ch = menu();

        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:
            disp_all();
            break;

        case 3:
            disp_one();
            break;

        case 4:
            del_one();
            printf("Employee data deleted successfully\n");
            break;

        case 5:
            del_all();
            break;

        case 6:
            modify();
            break;

        case 7:
            emp_payroll();
            break;

        case 8:
            exit(0);

        default:
            printf("WRONG CHOICE!!\nPlease enter a number from 1 to 8 according to your choice.\n");
            break;
        }
    }

    return 0;
}
