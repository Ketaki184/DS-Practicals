#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    struct Contact *next;
};

int main() {
    struct Contact *head = NULL, *newNode, *temp, *prev;
    int choice;
    char searchName[50];

    while (1) {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);switch (choice) {

            case 1:
                newNode = (struct Contact *)malloc(sizeof(struct Contact));

                printf("Enter name: ");
                scanf(" %[^\n]", newNode->name);
                printf("Enter phone number: ");
                scanf("%14s", newNode->phone);

                newNode->next = head;
                head = newNode;

                printf("Contact inserted successfully.\n");
                break;

            case 2:
                newNode = (struct Contact *)malloc(sizeof(struct Contact));

                printf("Enter name: ");
                scanf(" %[^\n]", newNode->name);
                printf("Enter phone number: ");
                scanf("%14s",newNode->phone);

                newNode->next = NULL;

                if (head == NULL) {
                    head = newNode;
                } else {
                    temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }

                printf("Contact inserted successfully.\n");
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf(" %[^\n]", searchName);

                temp = head;
                prev = NULL;while (temp != NULL && strcmp(temp->name, searchName) != 0) {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Contact not found.\n");
                } else {
                    if (prev == NULL) {
                        head = temp->next;
                    } else {
                        prev->next = temp->next;
                    }

                    free(temp);
                    printf("Contact deleted successfully.\n");
                }
                break;

            case 4:
                printf("Enter name tosearch: ");
                scanf(" %[^\n]", searchName);

                temp = head;

                while (temp != NULL && strcmp(temp->name, searchName) != 0) {
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Contact not found.\n");
                } else {
                    printf("Contact found!\n");
                    printf("Name: %s\n", temp->name);
                    printf("Phone Number: %s\n", temp->phone);
                }
                break;
case 5:
                if (head == NULL) {
                    printf("Contact list is empty.\n");
                } else {
                    temp = head;
                    printf("\n----- CONTACT LIST -----\n");

                    while (temp != NULL) {
                        printf("Name: %s\n", temp->name);
                        printf("Phone Number: %s\n", temp->phone);
                        printf("------------------------\n");
                        temp = temp->next;
                    }
                }
                break;

            case 6:
                temp = head;

                while (temp != NULL) {
                    struct Contact *deleteNode = temp;
                    temp = temp->next;
                    free(deleteNode);
                }
printf("Memory freed successfully.\n");
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
