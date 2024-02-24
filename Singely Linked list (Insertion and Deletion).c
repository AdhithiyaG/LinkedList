#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void createlist();
void displaylist();
void beginsert();
void middleinsert();
void lastinsert();
void begindelete();
void middledelete();
void lastdelete();
void search();
void main(){
    createlist();
    int ch;
    while(1){
    printf("\n\t\t------------\t\n\t1.To dislpay the list.\n\t2.To insert at Beginning.\n\t3.To insert at Middle.\n\t4.To insert at last.\n\t5.To delete at beginning.\n\t6.To delete at middle.\n\t7.To delete at last.\n\t8.Search an element.\n\t9.Exit.\n\t\t-----------\n");
    printf("\nEnter your choice:\n");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        displaylist();
        break;
    case 2:
        beginsert();
        break;
    case 3:
        middleinsert();
        break;
    case 4:
        lastinsert();
        break;
    case 5:
        begindelete();
        break;
    case 6:
        middledelete();
        break;
    case 7:
        lastdelete();
        break;
    case 8:
        search();
        break;
    case 9:
        exit(1);
        break;
    default :
        printf("Enter Correct choice.");
    }
}
}
void createlist(){
    if(head == NULL){
        int n;
        printf("Enter the number of node to be in the list:");
        scanf("%d",&n);
        if(n!=0){
                struct node *newnode,*temp;
                temp = (struct node *)malloc(sizeof(struct node));
                newnode = (struct node *)malloc(sizeof(struct node));
                int data,i;
                head = newnode;
                temp = head;
                printf("Enter the Element to be inserted as head:");
                scanf("%d",&data);
                head -> data = data;
                for(i=2;i<=n;i++){
                    newnode = (struct node *)malloc(sizeof(struct node));
                    temp -> next = newnode;
                    printf("Enter the element to insert:");
                    scanf("%d",&data);
                    newnode -> data = data;
                    temp = temp -> next;
                }
                printf("The list is created.");
        }
        else{
        printf("The list is already created.");
        }
    }
}
void displaylist(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Please create the list at first.");
    }
    else{
        temp = head;
        while(temp != NULL){
            printf("The element at the node is : %d \n", temp->data);
            temp = temp -> next;
        }
       printf("The all elements at the list are Displayed.\n");
    }
}
void beginsert(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        head = newnode;
    }
    else{
        int x;
        printf("Enter the element:");
        scanf("%d",&x);
        newnode -> data = x;
        newnode -> next = head;
        head = newnode ;
        printf("The element is inserted.\n");
    }
}
void middleinsert(){
    struct node *newnode,*t1,*t2,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    t1 =(struct node *)malloc(sizeof(struct node));
    t2 = (struct node *)malloc(sizeof(struct node));
    temp = (struct node *)malloc(sizeof(struct node));
    int i,pos,x;
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the element to place in the given position.");
    scanf("%d",&x);
    temp = head;
        if(head == NULL){
            head = newnode;
        }
        else{
            for(i = 1;i<pos;i++){
                    t1 = temp -> next;
                    t2 = temp -> next -> next;
            }
            newnode -> data = x;
            newnode -> next = t2;
            t1 -> next = newnode;
            printf("Element inserted at the given position.");
    }
}
void lastinsert(){
    int x;
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to insert at last position:");
    scanf("%d",&x);
    newnode -> data = x;
    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
    }
    newnode -> next = NULL;
    temp -> next = newnode;
    printf("Given Element is inserted at the last position.");
}
void begindelete(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    head = head -> next;
    free(temp);
    printf("The Element at the beginning is deleted.");
}
void middledelete(){
    //by value deletion
    int val;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to Delete in the middle.");
    scanf("%d",&val);
    temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
    printf("The entered value is deleted from its position.");
}
void lastdelete(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while( temp ->next->next != NULL){
        temp = temp -> next;
    }
    temp ->next=NULL;
    printf("The Last element is deleted.");
}
void search()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    int item,i=0,flag;
    temp = head;
    if(temp == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (temp!=NULL)
        {
            if(temp->data == item)
            {
                printf("item found at location %d.",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            temp = temp -> next;
        }
        if(flag==1)
        {
            printf("Item not found\n");
        }
    }
}
