#include <stdio.h>
#include <string.h>

#define MAX 50

int main()
{
    char backStack[MAX][100];
    char forwardStack[MAX][100];
    char currentPage[100] = "Home Page";
    char page[100];

    int backTop = -1;
    int forwardTop = -1;
    int choice;

    do
    {
        printf("\n===== BROWSER NAVIGATION =====\n");
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);switch(choice)
        {
            case 1:
                /* Visit New Page */
                printf("Enter webpage: ");
                scanf(" %[^\n]", page);

                backTop++;
                strcpy(backStack[backTop], currentPage);

                strcpy(currentPage, page);

                /* Clear Forward Stack */
                forwardTop = -1;

                printf("Visited: %s\n", currentPage);
                break;

            case 2:
                /* Back Navigation */
                if(backTop == -1)
                {
                    printf("No previous page available.\n");
                }
                else
                {
                    forwardTop++;strcpy(forwardStack[forwardTop], currentPage);

                    strcpy(currentPage, backStack[backTop]);
                    backTop--;

                    printf("Back to: %s\n", currentPage);
                }
                break;

            case 3:
                /* Forward Navigation */
                if(forwardTop == -1)
                {
                    printf("No forward page available.\n");
                }
                else
                {
                    backTop++;
                    strcpy(backStack[backTop], currentPage);

                    strcpy(currentPage, forwardStack[forwardTop]);
                    forwardTop--;

                    printf("Forward to: %s\n", currentPage);
                }
                break;case 4:
                /* Display Current Page */
                printf("Current Page: %s\n", currentPage);
                break;

            case 5:
                printf("Exiting Browser...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}