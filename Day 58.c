# There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize) {

    int indegree[numCourses];
    int graph[numCourses][numCourses];

    
    for (int i = 0; i < numCourses; i++) {
        indegree[i] = 0;

        for (int j = 0; j < numCourses; j++) {
            graph[i][j] = 0;
        }
    }

    
    for (int i = 0; i < prerequisitesSize; i++) {

        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];

        graph[pre][course] = 1;
        indegree[course]++;
    }

    
    int queue[numCourses];
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    
    while (front < rear) {

        int course = queue[front++];
        count++;

        for (int next = 0; next < numCourses; next++) {

            if (graph[course][next]) {

                indegree[next]--;

                if (indegree[next] == 0) {
                    queue[rear++] = next;
                }
            }
        }
    }

    return count == numCourses;
}
