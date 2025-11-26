#include<stdio.h>
#include<stdlib.h>

 struct node*create(int ele);
 void insert_beg(int ele);
 void insert_end(int ele);
void insert_pos(int ele);
 void delete_beg();
 void delete_end();
 void delete_pos();
 void display();
 struct node
 {
 int data;
 struct node*next;
 struct node*prev;
 };
 struct node*head = NULL;
 int main()
 {
 insert_beg(3);
 insert_end(2);
 insert_end(6);
 insert_pos(5);
 //delete_beg();
 //delete_end();
 display();
 }
 struct node*create(int ele)
 {
 struct node*newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data = ele;
 newnode->next=NULL;
 newnode->prev=NULL;
 return newnode;
 }
 void insert_beg(int ele)
 {
 struct node* newnode=create(ele);
 if(head==NULL){
 head=newnode;
 }
 else{
 newnode->next=head;
 head->prev=newnode;
 head=newnode;
 }
 }
 
 void insert_end(int ele)
 {
 struct node*newnode = create(ele);
 if(head==NULL){
 head=newnode;
 }
 else{
 struct node*temp = head;
 while(temp->next!=NULL){
 temp = temp->next;
 }
 newnode->prev=temp;
 temp->next=newnode;
 }
 }
 void insert_pos(int ele)
 {
 struct node*temp1=head;
 struct node*newnode = create(ele);
 int pos;
 printf("enter the position");
 scanf("%d",&pos);
 int count=0;
 if(pos==0)
 {
 newnode->next=head;
 head=newnode;
 }
 else{
 struct node*temp = head;
 while(count<pos-1 && temp->next!=NULL)
 {
 temp=temp->next;
 count++;
 }
 if(temp->next!=NULL)
 {
 newnode->prev=temp1->next;
 newnode->next= temp->next;
 temp1->next = newnode;
 temp->prev = newnode;
 }
 else{
 printf("position node not found");
 }
 }
 }
 
 void delete_beg()
 {
 struct node*temp = head;
 if(head == NULL)
 {
 printf("DLL is empty, not possible to delete");
 return;
 }
 else if(head->next==NULL)
 {
 head = NULL;
 }
 else{
 head = head->next;
 temp->next=NULL;
 head->prev=NULL;
 }
 free(temp);
 }
 void delete_end()
 {
 struct node*prev,*temp=head;
 if(head==NULL)
 {
 printf("DLL is empty");
 return;
 }
 else if(head->next==NULL)
 {
 head = NULL;
 }
 else{
 while(temp->next!=NULL)
 {
 prev = temp;
 temp = temp->next;
 }
 prev->next=NULL;
 temp->prev=NULL;
 }
 free(temp);
 }
 void delete_pos()
 {
 struct node*prev,*temp=head;
 int pos;
 printf("enter the position");
 scanf("%d",&pos);
 int count=0;
 if(head==NULL)
 {
 printf("empty");
 return;
 }
 else if(pos=1 && head->next==NULL)
 {
 head =NULL;
 }
 else
 {
 if(pos==1)
 {
 head=temp->next;
 temp->next=NULL;
 }
 else
 {
 int count =1;
 while(count!=pos && temp->next!=NULL)
 {
 prev =temp;
 temp=temp->next;
 count++;
 }
 
 if(count== pos)
 {
 prev->next=NULL;
 }
 }
 }
 free(temp);
 }
void display()
 {
 struct node*temp=head;
 if(head==NULL)
 {
 printf("dLL is empty,not possible to print");
 return;
 }
 while(temp!=NULL)
 {
 printf("%d\t",temp->data);
 temp=temp->next;
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
