#include <stdio.h>
#include <stdlib.h>
struct Node
{
int roll;
struct Node *left, *right;
};
int main()
{
struct Node *root = NULL, *temp, *parent;
struct Node *newNode, *current, *successor, *successorParent;
int choice, roll;
do
{
printf("\n1. Add Student");
printf("\n2. Remove Student");
printf("\n3. Search Student");
printf("\n4. Inorder Traversal");
printf("\n5. Preorder Traversal");
printf("\n6. Postorder Traversal");
printf("\n7. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter roll number: ");
scanf("%d", &roll);
newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL)
{
printf("Memory allocation failed!\n");
break;
}
newNode->roll = roll;
newNode->left = newNode->right = NULL;
if (root == NULL)
root = newNode;
else
{
current = root;
parent = NULL;
while (current != NULL)
{
parent = current;
if (roll < current->roll)
current = current->left;
else if (roll > current->roll)
current = current->right;
else
break;
}
if (current != NULL)
{
printf("Roll number already exists!\n");free(newNode);
}
else if (roll < parent->roll)
parent->left = newNode;
else
parent->right = newNode;
}
break;
case 2:
printf("Enter roll number to remove: ");
scanf("%d", &roll);
current = root;
parent = NULL;
while (current != NULL && current->roll != roll)
{
parent = current;
if (roll < current->roll)
current = current->left;
else
current = current->right;
}
if (current == NULL)
printf("Student not found.\n");
else
{
if (current->left != NULL && current->right != NULL)
{
successorParent = current;
successor = current->right;
while (successor->left != NULL)
{
successorParent = successor;
successor = successor->left;
}
current->roll = successor->roll;
current = successor;
parent = successorParent;
}
if (current->left != NULL)
temp = current->left;
else
temp = current->right;
if (parent == NULL)
root = temp;
else if (parent->left == current)
parent->left = temp;
else
parent->right = temp;
free(current);
printf("Student record removed.\n");
}
break;
case 3:
printf("Enter roll number to search: ");
scanf("%d", &roll);
current = root;
while (current != NULL && current->roll != roll)
{
if (roll < current->roll)current = current->left;
else
current = current->right;
}
if (current == NULL)
printf("Student not found.\n");
else
printf("Student found.\n");
break;
case 4:
printf("Inorder: ");
{
struct Node *stack[1000];
int top = -1;
current = root;
while (current != NULL || top != -1)
{
while (current != NULL)
{
stack[++top] = current;
current = current->left;
}
current = stack[top--];
printf("%d ", current->roll);
current = current->right;
}
}
printf("\n");
break;
case 5:
printf("Preorder: ");
if (root != NULL)
{
struct Node *stack[1000];
int top = -1;
stack[++top] = root;
while (top != -1)
{
current = stack[top--];
printf("%d ", current->roll);
if (current->right != NULL)
stack[++top] = current->right;
if (current->left != NULL)
stack[++top] = current->left;
}
}
printf("\n");
break;
case 6:
printf("Postorder: ");
if (root != NULL)
{
struct Node *stack1[1000], *stack2[1000];
int top1 = -1, top2 = -1;
stack1[++top1] = root;
while (top1 != -1)
{
current = stack1[top1--];
stack2[++top2] = current;
if (current->left != NULL)
stack1[++top1] = current->left;if (current->right != NULL)
stack1[++top1] = current->right;
}
while (top2 != -1)
printf("%d ", stack2[top2--]->roll);
}
printf("\n");
break;
case 7:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice!\n");
}
} while (choice != 7);
return 0;
}
