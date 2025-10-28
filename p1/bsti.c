#include<stdio.h>
#include<stdlib.h>
struct node*insertion(struct node*root, int val);
struct node*inorder(struct node*root);
struct node*search(struct node*root,int key);
struct node*find_minimum(struct node*root);
struct node*delete(struct node*root,int x);
int Height(struct node*root);
struct node{
int data;
struct node*left;
struct node*right;
};
struct node*root=NULL;
struct node*insertion(struct node*root, int val){
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
if(root == NULL){
root = newnode;
}
else{
struct node*nodeptr = root;
struct node*parentptr= NULL;
while(nodeptr!= NULL){
parentptr = nodeptr;
if(val< nodeptr->data){
nodeptr = nodeptr->left;
}
else{
nodeptr = nodeptr->right;
}
}
if(val<parentptr->data){
parentptr->left= newnode;
}
else{
parentptr->right= newnode;
}
}
return root;
}
struct node*inorder(struct node*root){
if(root!=NULL){
inorder(root->left);
printf("%d\n",root->data);
inorder(root->right);
}
}
//function to search
struct node*search(struct node*root,int key){
	if(root == NULL || root->data==key)
		return root;
	if(key<root->data)
		return search(root->left,key);
	else
		return search(root->right,key);
		}
struct node*find_minimum(struct node*root){
if(root = NULL)
	return NULL;
else if(root->left!=NULL)
	return find_minimum(root->left);
return root;
}
struct node*delete(struct node*root,int x){
if(root == NULL)
return NULL;
if(x> root->data)
root->right = delete(root->right,x);
else if(x<root->data)
root->left=delete(root->left,x);
else if(x == root->data)
{
if(root->left == NULL && root->right == NULL)
{
free(root);
return NULL;
}
else if (root->left == NULL || root->right == NULL)
{
struct node*temp;
if(root->left == NULL)
temp = root->right;
else
temp = root->left;
free(root);
return temp;
}
else{
struct node*temp = find_minimum(root->right);
root->data = temp->data;
root -> right=delete(root->right,temp->data);
}
}
return root;
}
int max(int a , int b)
{
if(a>b)
return a;
return b;
}
int Height(struct node*root)
{
int lh,rh;
if(root == NULL)
return 0;
return max(Height(root->left),Height(root->right))+1;
}

void main(){
printf("...Binary search tree...");
root=insertion(root,5);
root=insertion(root,1);
root=insertion(root,15);
root=insertion(root,9);
root=insertion(root,7);
root=insertion(root,12);
root=insertion(root,30);
root=insertion(root,25);
root=insertion(root,40);
root=insertion(root,45);
root=insertion(root,42);
printf("Inorder traversal is :");
inorder(root);
printf("\n");
printf("\nthe height of the tree is : %d",Height(root));
root=delete(root,1);
printf("\nafter element 1 deletion the inorder traversal is :");
inorder(root);
root=delete(root,45);
printf("\nafter element 45 deletion the inorder traversal is :");
inorder(root);
printf("\n");
int n;
printf("enter the search element: \n");
scanf("%d",&n);
int pos=search(root,n);
if (pos!=0){
printf("search element %d found at %d",n,pos);
}
else
printf("search element not found");

}


