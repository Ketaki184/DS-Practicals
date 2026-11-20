int main()
{
int n, i, j, temp;
int roll[50];
printf("Enter number of students: ");
scanf("%d", &n);
printf("Enter roll numbers:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &roll[i]);
}
for(i = 0; i < n - 1; i++)
{
for(j = 0; j < n - i - 1; j++)
{
if(roll[j] > roll[j + 1])
{
temp = roll[j];
roll[j] = roll[j + 1];
roll[j + 1] = temp;
}
}
printf("Pass %d: ", i + 1);
for(j = 0; j < n; j++)
{
printf("%d ", roll[j]);
}
printf("\n");
}
printf("Sorted Roll Numbers: ");
for(i = 0; i < n; i++)
{
printf("%d ", roll[i]);
}
return 0;
}
