#include<stdio.h>
void push(int ele);
int pop();
int peek();
void display();
int stack[10];
int top=-1;
int main()
{
int ch,ele;
do{
printf("menu\n1.push\n2.pop\n3.peek\n4.display\n");
printf("enter the choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("enter the value to be pushed : ");
 scanf("%d",&ele);
 push(ele);
 break;
 case 2:
 printf("enter the value to be poped : ");
 scanf("%d",&ele);
 pop();
 break;
 case 3:
 printf("the value on the top is : ");
 scanf("%d",&ele);
 peek();
 break;
 case 4:
 display();
 break; 
 default:
 printf("wrong choice");
 }
 }while(ch<=4);
 return 0;
 }
 void push(int ele)
 {
 if(top==9)
 {
 printf("stack is full");
 return;
 }
 else ;
 {
 top++;
 stack[top] = ele;
 }
 }
 int pop()
 {
 if(top == -1){
 printf("stack is empty");
 return -1;
 }
 int e = stack[top];
 top--;
 return e;
 }
 int peek()
 {
 if (top==-1)
 {
 printf("stack is empty");
 return -1;
 }
 return stack[top];
 }
 void display()
 {
 if(top ==-1)
 {
 printf("stack is empty");
 }
 else{
 printf("the elements in the stack are : ");
 for(int i =top;i>=0;i--){
 printf("%d\t",stack[i]);
 }
 }
 }
 
 
