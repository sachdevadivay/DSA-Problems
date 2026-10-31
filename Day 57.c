# Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

struct Node *dfs(struct Node *node, struct Node **visited) {

    if (node == NULL)
        return NULL;

   
    if (visited[node->val] != NULL)
        return visited[node->val];

    
    struct Node *copy = malloc(sizeof(struct Node));

    copy->val = node->val;
    copy->numNeighbors = node->numNeighbors;

    copy->neighbors =
        malloc(node->numNeighbors * sizeof(struct Node *));

    
    visited[node->val] = copy;

    
    for (int i = 0; i < node->numNeighbors; i++) {
        copy->neighbors[i] =
            dfs(node->neighbors[i], visited);
    }

    return copy;
}


struct Node *cloneGraph(struct Node *s) {

    if (s == NULL)
        return NULL;

    struct Node *visited[101] = {NULL};

    return dfs(s, visited);
}
