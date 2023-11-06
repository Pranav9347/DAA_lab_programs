/*Name: Pranav Vijay Nadgir
Roll no: C22B1034*/
//BFS and DFS
#include <stdio.h>
#include <stdlib.h>

//Stack ADT required for DFS
typedef struct node
{
    struct node* next;
    int vertex;
}node;
node* top = NULL;
node* front = NULL, *rear = NULL;
void enqueue(int);
int dequeue();
void push(int);
void pop(void);
int peek(void);
int is_not_empty(void);
int q_not_empty(void);

//DFS helpers
int not_visited(int);
int adj_vertex_is_unvisited(int);
void DFS(void);

//BFS helpers:
void enqueue_unvisited_neighbours(int);
void BFS(void);

int *visited = NULL;
int adj_matrix[50][50] = {0};
int n = 0;
void print_matrix(void);

int main()
{
    int m = 0;
    FILE* fileptr = fopen("input_file.txt","r");
    printf("Enter the number of vertices: ");
    fscanf(fileptr,"%d\n",&n);
    printf("Enter the number of edges: ");
    fscanf(fileptr,"%d\n",&m);
    int x = 0, y = 0;
    printf("Enter each source to destination edge: ");
    for(int i = 0; i < m; i++)
    {
        fscanf(fileptr,"%d %d\n",&x,&y);
        adj_matrix[x][y] = 1;
    }
    print_matrix();
    DFS();
    BFS();
    fclose(fileptr);
    return 0;
}
void print_matrix(void)
{
    printf("The adjacency matrix: \n");
    for(int i = 0; i < n; i++)
    {
        printf("  ");
        for(int j = 0; j < n; j++)
        {
            printf("%d ",adj_matrix[i][j]);
        }
        printf("\n");
    }
    return;
}
void push(int data)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->vertex = data;
    new_node->next = top;
    top = new_node;
    return;
}
void pop(void)
{
    node* temp = top;
    top = top->next;
    free(temp);
    return;
}
int peek(void)
{
    if(top == NULL)
    return -1;
    else
    return top->vertex;
}
int not_visited(int x)
{
    int i = 0;
    while(visited[i] != -1)
    {
        if(visited[i] == x)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void DFS(void)
{
    //Initializing visited array:
    visited = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    visited[i] = -1;
    int j = 0;
    
    //DFS starting point:
    int start_from = 0;
    printf("Start DFS from: ");
    scanf("%d",&start_from);
    
    //DFS algorithm:
    int vertex = start_from;
    do
    {
        push(vertex);//push unvisited vertex
        visited[j] = vertex;//mark vertex as visited
        j++;
        vertex = adj_vertex_is_unvisited(vertex);
        while(vertex == -1)
        {
            pop();
            vertex = adj_vertex_is_unvisited(peek());
        }
    }while(is_not_empty());
    
    printf("\n");
    printf("DFS:\n");
    for(int i = 0; i < n; i++)
    printf("%d ",visited[i]);
    printf("\n");
    return;
}
void BFS(void)
{
    //Initializing visited array:
    visited = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    visited[i] = -1;
    int j = 0;
    //BFS starting point:
    int start_from = 0;
    printf("Start BFS from: ");
    scanf("%d",&start_from);
    
    //BFS algorithm:
    int vertex = start_from;
    enqueue(vertex);
    do
    {
        vertex = front->vertex;
        if(not_visited(vertex))
       { 
        visited[j] = vertex;
        j++;
       }
        enqueue_unvisited_neighbours(vertex);
        dequeue();
        
    } while (q_not_empty());
printf("\n");
    printf("BFS:\n");
    for(int i = 0; i < n; i++)
    printf("%d ",visited[i]);
    printf("\n");
    return;
}
int adj_vertex_is_unvisited(int vertex)
{
    if (vertex == -1)
    {
        return -2;
    }
    
    for(int i = 0; i < n; i++)
    {
        if((adj_matrix[vertex][i] == 1) && not_visited(i))//Then vertex 'i' is adjacent to vertex 'vertex'
        {
            return i;
        }
    }
    return -1;
}
int is_not_empty(void)
{
    if(top == NULL)
    return 0;
    else return 1;
}
int q_not_empty(void)
{
    if(front == NULL)
    {
        return 0;
    }
    return 1;
}
void enqueue(int data)
{
    if(rear == NULL)
    {
        rear = (node*) malloc(sizeof(node));
        rear->vertex = data;
        front = rear;
        return;
    }
    
    rear->next = (node*) malloc(sizeof(node));
    rear = rear->next;
    rear->vertex = data;
    rear->next = NULL;
    return;
}
int dequeue(void)
{
    if(front == NULL)
    {
        return -1;
    }
    int data = front->vertex;
    node* temp = front;
    front = front->next;
    free(temp);
    return data;
}
void enqueue_unvisited_neighbours(int vertex)
{
    for(int i = 0; i < n; i++)
    {
        if(adj_matrix[vertex][i] == 1 && not_visited(i))
        enqueue(i);
    }
    return;
}