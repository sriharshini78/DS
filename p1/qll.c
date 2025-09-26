#include<stdio.h>
#include<stdlib.h>
void enQueue(int ele);
void deQueue();
void display();
struct node
 {
 int data;
 struct node*next;
 };
 struct node*front = NULL,*rear=NULL;
 int main()
 {
enQueue(12);
enQueue(34);
display();
deQueue();
display();
return 0;
}
void enQueue(int ele)
{
struct node*newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data=ele;
 newnode->next=NULL;
 if(rear == NULL){
 rear = newnode;
 front = newnode;
 }
 else
 {
 rear->next = newnode;
 rear = newnode;
 }
 }
 void deQueue()
 {
 if(front == NULL)
 {
 printf(" queue is underflow  , not possible for to delete");
 return;
 }
 else
 {
 struct node*temp = front;
 printf("\nThe element to be deleted is : %d ",temp->data);
 if(front->next == NULL){
 front = NULL;
 rear = NULL;
 }
 else{
 front =front->next;
 temp->next=NULL;
 }
 free(temp);
 }
 }
 void display(){
   if(front == NULL)
 {
 printf(" queue is underflow  , not possible for to display");
 return;
 }
 else{
 struct node*temp = front;
 printf("\n The elements in the queue are : ");
 while(temp != NULL){
 printf("%d\t ",temp->data);
 temp = temp->next;
 }
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 

 
