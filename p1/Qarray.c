#include<stdio.h>
#define size 10
void enQueue(int value);
void deQueue();
void display();
int Queue[size];
int front = -1 , rear = -1;
int main()
{
enQueue(12);
enQueue(34);
display();
deQueue();
display();
return 0;
}
void enQueue(int value)
{
if(rear == size-1){
printf("Queue is overflow");
return;
}
else{
	if(front == -1 && rear ==-1){
		front = 0;
		rear=0;
	}
	else{
		rear++;
		}
	Queue[rear] = value;
}
}
void deQueue()
{
if((front == -1) ||(front>rear))
{
printf("Queue is overflow");
return;
}
else{
printf("\n the deleted element from the queue is : %d",Queue[front]);
front++;
}
}
void display()
{
 if((front == -1) ||(front >rear)){
 printf("Queue is underflow , not possible to print");
 return;
}
else{
printf("the elements in the queue are : \n");
for(int i = front; i<=rear ; i++)
{
printf("%d\t",Queue[i]);
}
}
}  

		


