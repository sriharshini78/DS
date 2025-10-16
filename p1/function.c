#include<stdio.h>
void insert_beg(int ele);
void insert_end(int ele);
void insert_pos(int ele);
void delete_beg();
void delete_end();
void delete_pos();
void display();
int a[10];
int count=-1;
void main(){
int e,i;
printf("enter the array elements:");
for(i=0;i<=1;i++){
scanf("%d",&a[i]);
count++;
}
display();
insert_beg(30);
display();
insert_end(40);
display();
insert_pos(25);
display();
}
void display()
{
printf("\nthe elements in the array are :\n");
for(int i=0;i<=count;i++)
printf("%d\t",a[i]);
}
void insert_beg(int ele)
{
if(count==-1){
a[0]=ele;
}
else{
for(int i =count;i>=0;i--){
a[i+1]=a[i];
}
a[0]=ele;
count++;
}
}
void insert_end(int ele)
{
if(count==-1){
a[0]=ele;
}
else{
a[count+1]=ele;
count++;
}
}
void insert_pos(int ele)
{
int pos;
printf("enter the position:");
scanf("%d",&pos);
if(count==-1){
a[0]=ele;
}
else{
for(int i=count;i>=pos;i--)
{
a[i+1]=a[i];
}
a[pos]=ele;
count++;
}
}
void delete_beg()
{
for(int i=0;i<count;i++)
{
a[i]=a[i+1];
}
count--;

}
void delete_end() {
    if(count == -1) {
        printf("Array is empty!\n");
        return;
    }
    count--;
}

void delete_pos() {
    int pos;
    printf("Enter position to delete (0 to %d): ", count);
    scanf("%d", &pos);
    if(pos < 0 || pos > count) {
        printf("Invalid position!\n");
        return;
    }
    for(int i = pos; i < count; i++)
        a[i] = a[i+1];
    count--;
}
