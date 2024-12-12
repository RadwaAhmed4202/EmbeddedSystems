/*PHONE SYSTEM ->DATA STRUCTER PROJECT feb 2021*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct node
{
    char name[20];
    long int phone_no;
    char gender[20];
    char mail[100];
    char city[20];
    struct node* next;
}*front=NULL, *rear=NULL;
int counter=0;
void enqueue(char name[20], long int phone_no, char gender[20], char mail[100],char city[20]);
void dequeue();
void delast();
void deall();
void display(struct node* n);
void peak();
void printlast(char name[20], long int phone_no, char gender[20], char mail[100],char city[20]);
void search();
void count();
void edit();
int main()
{
    int c;
    long int phone_no;
    char name[20], gender[20], mail[100], city[20];
    printf("\t\t*****PHONEBOOK*****\n");
    while(1)
    {
    printf("\n\aChoose your operation:\n1.Add a new contact\n2.Delete a contact from the first\n3.Delete a contact from the last\n");
    printf("4.Delete all the contacts\n5.Show all the contacts\n6.Show the first contact\n7.Show the last contact\n");
    printf("8.Search for a contact\n9.Count the number of the contacts\n10.Edit an element\n11.Exit\n");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
        {
            printf("Enter the name of the contact: ");
            scanf("%s", name);
            printf("Enter the phone number of the contact: ");
            scanf("%ld", &phone_no);
            printf("Enter the gender of the contact(male or female): ");
            scanf("%s", gender);
            printf("Enter the e-mail of the contact: ");
            scanf("%s", mail);
            printf("Enter the city of the contact: ");
            scanf("%s", city);
            enqueue(name, phone_no, gender, mail, city);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            delast();
            break;
        }
        case 4:
        {
            deall();
            break;
        }
        case 5:
        {
            display(front);
            break;
        }
        case 6:
        {
            peak();
            break;
        }
        case 7:
        {
            printlast(name, phone_no, gender, mail, city);
            break;
        }
        case 8:
        {
            search();
            break;
        }
        case 9:
        {
            count();
            break;
        }
        case 10:
        {
            edit();
            break;
        }
        case 11:
        {
            printf("Exiting...\n");
            return 0;
        }
        
        default:
        {
            printf("Wrong, choose a valid number.\n");
        }
    }
    }
    return 0;
}
void enqueue(char name[20], long int phone_no, char gender[20], char mail[100],char city[20])
{
    struct node*n = NULL;
    n = (struct node*)malloc(sizeof(struct node));
    strcpy(n->name, name);
    n->phone_no = phone_no;
    strcpy(n->gender, gender);
    strcpy(n->mail, mail);
    strcpy(n->city, city);
    if(front == NULL&&rear == NULL)
    {
        front= rear = n;
    }
    else
    {
        rear-> next = n;
        rear = n;
    }
    counter++;
}
void dequeue()
{
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        struct node* t = front;
        front = front->next;
        printf("The deleted contact is:\nThe name: %s\nThe phone number: %ld\n", t->name, t->phone_no);
        printf("The gender: %s\nThe e-mail: %s\nThe city: %s\n", t->gender, t->mail, t->city);
        free(t);
        counter--;
    }
}
void delast()
{
    struct node* h, *sh;
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        h = front;
        sh = front;
    while(h->next!=NULL)
    {
        sh = h;
        h = h->next;
    }
    if(h==front)
    {
        front = NULL;
    }
    else
    {
        sh->next = NULL;
    }
    printf("The deleted contact is:\nThe name: %s\nThe phone number: %ld\n", h->name, h->phone_no);
    printf("The gender: %s\nThe e-mail: %s\nThe address: %s\n", h->gender, h->mail, h->city);
    free(h);
    counter--;
    }
}
void deall()
{
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
    struct node* n;
    while(front!=NULL)
    {
        n = front;
        front = front->next;
        free(n);
        counter--;
    }
      front = NULL;
      rear = NULL;
      printf("All the contacts are deleted.\n");
    }
}
void display(struct node* n)
{
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else{
        printf("The list:\n");
    while(n!=NULL)
    {
        printf("***\nThe name: %s\nThe phone number: %ld\nThe gender: %s\n", n->name, n->phone_no, n->gender);
        printf("The e-mail: %s\nThe city: %s\n***\n", n->mail, n->city);
        n = n->next;
    }
    }
}
void peak()
{
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("***The first contact***\nThe name: %s\nThe phone number: %ld\n", front->name, front->phone_no);
        printf("The gender: %s\nThe e-mail: %s\nThe city: %s\n", front->gender, front->mail, front->city);
    }
}
void printlast(char name[20], long int phone_no, char gender[20], char mail[100],char city[20])
{
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
    printf("***The last contact***\nThe name: %s\nThe phone number: %ld\n", name, phone_no);
    printf("The gender: %s\nThe e-mail: %s\nThe city: %s\n", gender, mail, city);
    }
}
void search()
{
    struct node* n=front;
    long int ph;
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
    printf("Enter the phone number of the contact that you want to search for: ");
    scanf("%ld", &ph);
    while(n->phone_no!=ph)
    {
        n = n->next;
    if(n == NULL)
    {
        printf("Not found\n");
        return;
    }
    }
    if(n->phone_no==ph)
    {
        printf("**The contact**\nThe name: %s\nThe phone number: %ld\n", n->name, n->phone_no);
        printf("The gender: %s\nThe e-mail: %s\nThe city: %s\n", n->gender, n->mail, n->city);
    }
    }
}
void edit()
{
    struct node* n=front;
    long int ph;
    long int phone_no;
    char name[20], gender[20], mail[100], city[20];
    if(front==NULL&&rear==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
    printf("Enter the phone number of the contact that you want to edit: ");
    scanf("%ld", &ph);
    while(n->phone_no!=ph)
    {
        n = n->next;
    if(n == NULL)
    {
        printf("Not found\n");
        return;
    }
    }
    if(n->phone_no==ph)
    {
        struct node* temp;
        struct node* n2;
        
        printf("Enter the name of the contact: ");
        scanf("%s", name);
        printf("Enter the phone number of the contact: ");
        scanf("%ld", &phone_no);
        printf("Enter the gender of the contact(male or female): ");
        scanf("%s", gender);
        printf("Enter the e-mail of the contact: ");
        scanf("%s", mail);
        printf("Enter the city of the contact: ");
        scanf("%s", city);
        strcpy(n->name, name);
        n->phone_no = phone_no;
        strcpy(n->gender, gender);
        strcpy(n->mail, mail);
        strcpy(n->city, city);
        temp = n;
        n = n2;
        n2 = temp;
    }
    }
}
void count()
{
    if(front==NULL&&rear==NULL)
    {
        printf("The number of the contacts is 0.\n");
    }
    else
    {
    printf("The number of the contacts: %d.\n", counter);
    }
}
