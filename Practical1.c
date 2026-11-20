#include<stdio.h>
int main()
{
int marks[20], i, n, j, found, choice, element, key, del;
do
{ 
printf("\n==Menu==");
printf("\n 1.Insert Element\n 2.Display\n 3.Delete\n 4.Linear Search\n 5.Binary search\n 6.Exit\n");
printf("\n Enter the Choices:");
scanf("%d", &choice);
switch(choice)
{ 
case 1: //Insert
printf("\n Enter the size of array");
scanf("%d", &n);
printf("\n Enter the marks");
for(i=0; i<n; i++)
{ 
scanf("%d", &marks[i]);
}
break;

case 2://display
printf("Marks:");
for(i=0; i<n; i++)
{
printf("\n%d",marks[i]);
}
break;

case 3://delete
printf("Enter the position of marks to be deleted:");
scanf("%d", &element);
del=marks[element];
for(i=element; i<n; i++)
{
marks[i] = marks[i+1];
}
n=n-1;
printf("Marks %d deleted successfully", del); 
break;

case 4://linear search
printf("Enter the marks of student");
scanf("%d", &key);
for(i=0; i<n; i++)
{
if(marks[i]==key)
{ printf("Marks found at position %d",i+1);
found = 1;
break;
} 
} 
if(found == 0)
{ 
printf("Marks not found");
}for( int i=0; i<n-1; i++)
{ 
for(int j=i+1; j<n; j++)
{ 
int tem = marks[i] ;
marks[i] = marks[j];
marks[j] = tem;
}
}

printf("Sorted marks");
for(i=0; i<n; i++)
{
printf("%d",marks[i]);
}
break;

case 5://binary search
int low=0, high = n-1, mid;
found = 0;
printf("Enter the marks for binary search");
scanf("%d",&key);
while(low <= high)
{
mid=(low+high)/2;
if(marks[mid] == key)
{ 
printf("The marks is found at the position:%d",mid+1 );
found = 1;
break;
}
else if(marks[mid]<key)
{
low = mid+1;
}
else
{
high=mid-1;
}
}
if(found==0)
{ 
printf("Marks not found");
}
return 0;
break;

case 6://exit
break;
} 
}
while(choice!=6); 
}