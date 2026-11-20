#include <stdio.h>
#define MAX 100
struct Patient
{
int id, time;
};
int main()
{
struct Patient q[MAX];
int front = 0, rear = -1, count = 0;
int choice, id, time, i, index;
do
{
printf("\n1. Add Patient");
printf("\n2. Attend Patient");
printf("\n3. View Patients");
printf("\n4. Check Queue Empty");
printf("\n5. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
if (count == MAX)
printf("Queue is full!\n");
else
{
printf("Enter Patient ID: ");
scanf("%d", &id);
printf("Enter Arrival Time: ");
scanf("%d", &time);
rear = (rear + 1) % MAX;
q[rear].id = id;
q[rear].time = time;
count++;
printf("Patient added successfully.\n");
}
break;
case 2:
if (count == 0)
printf("Queue is empty!\n");
else
{
printf("Attending Patient ID: %d, Arrival Time: %d\n",
q[front].id, q[front].time);
front = (front + 1) % MAX;
count--;
}
break;
case 3:
if (count == 0)
printf("No patients waiting.\n");
else
{
printf("Patients waiting:\n");
for (i = 0; i < count; i++){
index = (front + i) % MAX;
printf("ID: %d, Time: %d\n",
q[index].id, q[index].time);
}
}
break;
case 4:
if (count == 0)
printf("Queue is empty.\n");
else
printf("Queue is not empty.\n");
break;
case 5:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice!\n");
}
} while (choice != 5);
return 0;
}
