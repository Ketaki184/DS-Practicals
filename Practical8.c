#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
// Initialize hash table
void initialize()
{
int i;
for(i = 0; i < SIZE; i++)
{
hashTable[i] = -1;
}
}
// Insert book ID
void insert(int id)
{
int index = id % SIZE;
int start = index;
while(hashTable[index] != -1)
{
index = (index + 1) % SIZE;
if(index == start)
{
printf("Hash Table is Full!\n");
return;
}
}
hashTable[index] = id;
printf("Book ID %d inserted at index %d\n", id, index);
}
// Search book ID
void search(int id)
{
int index = id % SIZE;
int start = index;
while(hashTable[index] != -1)
{
if(hashTable[index] == id){
printf("Book ID %d found at index %d\n", id, index);
return;
}
index = (index + 1) % SIZE;
if(index == start)
break;
}
printf("Book ID %d not found\n", id);
}
// Display hash table
void display()
{
int i;
printf("\nHash Table:\n");
for(i = 0; i < SIZE; i++)
{
printf("Index %d : ", i);
if(hashTable[i] == -1)
printf("Empty\n");
else
printf("%d\n", hashTable[i]);
}
}
int main()
{
int choice, id;
initialize();
do
{
printf("\n--- Library Book Indexing ---\n");
printf("1. Insert Book ID\n");
printf("2. Search Book ID\n");
printf("3. Display Hash Table\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);switch(choice)
{
case 1:
printf("Enter Book ID: ");
scanf("%d", &id);
insert(id);
break;
case 2:
printf("Enter Book ID to search: ");
scanf("%d", &id);
search(id);
break;
case 3:
display();
break;
case 4:
printf("Exiting Program...\n");
break;
default:
printf("Invalid Choice!\n");
}
} while(choice != 4);
return 0;
}