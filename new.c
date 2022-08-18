#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int z[100][100];

struct queue
{
    int front , rear;
    int a[30];
}q;

struct node
{
    int data;
    struct node* next;
};

struct Queue
{
    struct node *Front , *Rear;
};



void insertarr(int p)
{
    if(q.rear == 29) {
        printf("QUEUE OVERFLOW\n");
        return ;
    }
    if(q.front == -1) q.front = 0;
    q.a[++q.rear] = p;
    printf("ELEMENT INSERTED SUCCESSFULLY\n");
    //fflush(stdout);
}

void deletearr()
{
    if(q.rear < q.front || q.rear == -1) {
        printf("QUEUE UNDERFLOW\n");
        return ;
    }
    q.front++;
    printf("ELEMENT DELETED SUCCESSFULLY\n");
}

void displayarr()
{
    if(q.rear == -1 || q.front > q.rear) {
        printf("QUEUE IS EMPTY\n");
        return ;
    }
    printf("ELEMENTS IN QUEUE ARE : ");
    for(int i = q.front ;  i<=q.rear ; i++) {
        printf("%d " , q.a[i]);
    }
    printf("\n");

}

struct node* new_node(int p)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = p;
    return temp;
}

void enqueue(struct Queue* Q , int p)
{
    struct node* temp = new_node(p);
    printf("ELEMENT INSERTED SUCCESSFULLY : \n");
    if(Q->Rear == NULL) {
        Q->Front = Q->Rear = temp;
        return ;
    }
    Q->Rear->next = temp;
    Q->Rear = Q->Rear->next;
    fflush(stdout);
}

void dequeue(struct Queue* Q)
{
    if(Q->Front == NULL) {
        printf("QUEUE UNDERFLOW \n");
        return ;
    }
    Q->Front = Q->Front->next;

}

void Display(struct Queue* Q)
{
    struct node* temp = Q->Front;
    if(Q->Front == NULL) {
        printf("QUEUE IS EMPTY : \n");
        return ;
    }
    printf("ELEMENTS ARE : ");
    while(temp != NULL) {
        printf("%d " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}




void main()
{
    q.front = q.rear = -1;
    struct Queue* Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->Front = Q->Rear = NULL;
    int y = 1;
    while(y == 1) {
        system("cls");
        printf("1. QUEUE THROUGH ARRAY :\n2. QUEUE THROUGH LINKED LIST :\n3. EXIT\n ENTER YOUR CHOICE : ");
        int x;
        scanf("%d" , &x);
        while(x == 1) {
            printf("1. INSERT\n2. DELETE\n3. PRINT THE QUEUE \n4. EXIT\nENTER YOUR CHOICE : ");
            fflush(stdout);
            int f;
            scanf("%d",&f);
            if(f == 1) {
                printf("ENTER THE NO. ");
                int a;
                scanf("%d " , &a);
                insertarr(a);
            }
            else if(f == 2) deletearr();
            else if(f == 3) displayarr();
            else {
               q.front = q.rear = -1; x = 4;
            }
        }
        while(x == 2) {
            system("cls");
            printf("1. INSERT\n2. DELETE\n3. PRINT THE QUEUE \n4. EXIT\nENTER YOUR CHOICE : ");
            int f;
            scanf("%d", &f);
            switch(f) {
                case 1 : printf("ENTER THE NO. "); int a; scanf("%d " , &a); enqueue(Q , a); break;
                case 2 : dequeue(Q); break;
                case 3 : Display(Q); break;
                case 4 : Q->Front = Q->Rear = NULL; x = 4;
            }
        }
        if(x == 3) {
            system("cls");
            printf("EXISTING PROGRAM....");
            y = 2;
        }
    }



}