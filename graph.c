#include <stdio.h>

typedef struct tagLinkedQueue
{
    
} LinkedQueue;

typedef struct tagVertex
{
    int data;
    int visited;
    int index;

    struct tagVertex* next;
    struct tagEdge* adjacencyList;
} Vertex;

typedef struct tagEdge
{
    int weight;
    struct tagEdge* next;
    Vertex* from;
    Vertex* to;
} Edge;

typedef struct tagGraph
{
    Vertex* vertices;
    int vertexCount;
} Graph;  

Graph* createGraph()
{ 
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = NULL;
    graph->vertexCount  = 0;

    return graph;
}

Vertex* createVertex(int data)
{
    Vertex* vertex= (Vertex*)malloc(sizeof(Vertex));
    vertex->data = data;
    vertex->visited = 0;
    vertex->index = -1;

    vertex->next = NULL;
    vertex->adjacencyList = NULL;

    return vertex;
}

void addVertex(Graph* graph, Vertex* vertex)
{
   Vertex* current = NULL;

   if(graph->vertices == NULL)
   {
       graph->vertices = vertex;
   }
   else
   {
       current = graph->vertices; 

       while(current->next != NULL)
           current = current->next;

       current->next = vertex;
   }
   vertex->index = graph->vertexCount++;
}

Edge* createEdge(Vertex* from, Vertex* to, int weight)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));

    edge->from = from;
    edge->to = to;
    edge->weight = weight;
}

void addEdge(Vertex* vertex, Edge* edge)
{
    Edge* current = NULL;

    if(vertex->adjacencyList == NULL)
    {
       vertex->adjacencyList = edge;
    }
    else
    {
        current = vertex->adjacencyList; 

        while(current->next != NULL)
            current = current->next;

        current->next = edge;
    }
}

void DFS(Vertex* vertices)
{
    Edge* edge = NULL;

    printf("%d\n", vertices->data);
    vertices->visited = 1;

    edge = vertices->adjacencyList;

    while(edge != NULL)
    {
        if(edge->to != NULL && edge->to->visited == 0)
            DFS(edge->to);

        edge = edge->next;
    }
}

void BFS(Vertex* v, LinkedQueue* Queue)
{
    printf("BFS start\n");
}

int main()
{
	int i=0, j=0, k=0;
	Graph* graph = createGraph();	

	Vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7;
	v1 = v2 = v3 = v4 = v5 = v6 = v7 = NULL;
//	Vertex* temp;

	v1 = createVertex(1);
	v2 = createVertex(2);
	v3 = createVertex(3);
	v4 = createVertex(4);
	v5 = createVertex(5);
	v6 = createVertex(6);
	v7 = createVertex(7);

	addVertex(graph, v1);
	addVertex(graph, v2);
	addVertex(graph, v3);
	addVertex(graph, v4);
	addVertex(graph, v5);
	addVertex(graph, v6);
	addVertex(graph, v7);

	addEdge(v1, createEdge(v1, v2, 0));
	addEdge(v1, createEdge(v1, v3, 0));

	addEdge(v2, createEdge(v2, v4, 0));
	addEdge(v2, createEdge(v2, v5, 0));

	addEdge(v3, createEdge(v3, v4, 0));
	addEdge(v3, createEdge(v3, v6, 0));

	addEdge(v4, createEdge(v4, v5, 0));
	addEdge(v4, createEdge(v4, v7, 0));

	addEdge(v5, createEdge(v5, v7, 0));

	addEdge(v6, createEdge(v6, v7, 0));

	printf("DFS traversal\n");
	DFS(graph->vertices);

	printf("BFS traversal\n");
	BFS(graph->vertices, NULL);
}
