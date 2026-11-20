#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// Add connection between two users
void addConnection(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;

    printf("Connection added successfully!\n");
}

// Breadth First Search
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}// Depth First Search
void DFS(int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int choice, u, v, start;

    printf("Enter number of users: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of users! Enter between 1 and %d.\n", MAX);
        return 1;}

    do
    {
        printf("\n--- SOCIAL NETWORK MENU ---\n");
        printf("1. Add Connection\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two users: ");
                scanf("%d %d", &u, &v);

                if (u >= 0 && u < n && v >= 0 && v < n)
                    addConnection(u, v);
                else
                    printf("Invalid user!\n");
                break;case 2:
                printf("Enter starting user: ");
                scanf("%d", &start);

                if (start >= 0 && start < n)
                    BFS(start);
                else
                    printf("Invalid user!\n");
                break;

            case 3:
                printf("Enter starting user: ");
                scanf("%d", &start);

                if (start >= 0 && start < n)
                {
                    for (int i = 0; i < n; i++)
                        visited[i] = 0;

                    printf("DFS Traversal: ");
                    DFS(start);
                    printf("\n");
                }
                else
                    printf("Invalid user!\n");
                break;case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}