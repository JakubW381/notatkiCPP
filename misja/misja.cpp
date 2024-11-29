#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>

void dfs(int v, const std::vector<std::list<int>> graph, int n , std::vector<int>& destinations) {
    std::vector<bool> visited(n);
    std::stack<int> s;
    s.push(v);
    bool stable = false;
    bool isLoop = true;

    for (int i = 0; i < n; i++)
    {
        if(graph[i].empty()){
                destinations.push_back(i);
                isLoop = false;
            }
    }
    
    while (!s.empty()) {
        int pom = s.top();
        s.pop();

        if (!visited[pom]) {

            visited[pom] = true;

            stable = !stable;
            //std::cout << "Vertice: " << pom << (stable ? " stable": " unstable") <<  std::endl;

            // Przejdź przez wszystkich sąsiadów wierzchołka `pom`
            for (int neighbor : graph[pom]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    if (isLoop)
    {
        std::cout << "petla";
    }   
}
void bfs(std::vector<std::list<int> >& graph, int S,std::vector<int>& par, std::vector<int>& dist){
    // queue to store the nodes in the order they are
    // visited
    std::queue<int> q;
    // Mark the distance of the source node as 0
    dist[S] = 0;
    // Push the source node to the queue
    q.push(S);

    // Iterate till the queue is not empty
    while (!q.empty()) {
        // Pop the node at sthe front of the queue
        int node = q.front();
        q.pop();

        // Explore all the neighbours of the current node
        for (int neighbour : graph[node]) {
            // Check if the neighbouring node is not visited
            if (dist[neighbour] == INT_MAX) {
                // Mark the current node as the parent of
                // the neighbouring node
                par[neighbour] = node;
                // Mark the distance of the neighbouring
                // node as distance of the current node + 1
                dist[neighbour] = dist[node] + 1;
                // Insert the neighbouring node to the queue
                q.push(neighbour);
            }
        }
    }
}

void printShortestDistance(std::vector<std::list<int>>& graph,
                           int S, int D, int V)
{
    // par[] array stores the parent of nodes
    std::vector<int> par(V, -1);

    // dist[] array stores distance of nodes from S
    std::vector<int> dist(V, INT_MAX);

    // function call to find the distance of all nodes and
    // their parent nodes
    bfs(graph, S, par, dist);

    if (dist[D] == INT_MAX) {
        std::cout << "NIE" << std::endl;
        return;
    }

    // vector path stores the shortest path
    std::vector<int> path;
    int currentNode = D;
    path.push_back(D);
    while (par[currentNode] != -1) {
        path.push_back(par[currentNode]);
        currentNode = par[currentNode];
    }

    if (path.size() % 2 != 0)
    {
        std::cout << "TAK" << std::endl;
        for (int i = path.size() - 1; i >= 0; i--)
        std::cout << path[i] << " ";
    }
    else{
        std::cout << "NIE" << std::endl;
    }
    

    // printing path from source to destination
    
}


int main() {
    int t;
    std::cin >> t;
    while (t) {
        int n, m, s;
        std::cin >> n >> m >> s;

        std::vector<std::list<int>> graph(n); // Lista sąsiedztwa reprezentująca graf
        std::vector<int> destinations;

        for (int i = 0; i < m; i++) {
            int x, y;
            std::cin >> x >> y;
            graph[x].push_back(y); // Dodajemy jednokierunkowe połączenie x -> y
        }
        for (int i = 0; i < n; i++)
        {
            graph[i].reverse();
        }
        
        dfs(s,graph,n,destinations);
        
        for (int i = 0; i < destinations.size(); i++)
        {
            //std::cout << "dest " << destinations.at(i) << std::endl;
            printShortestDistance(graph,s,destinations[i],n);
            std::cout << std::endl;

        }
        t--;
    }
    return 0;
}
// 3
// 6 7 3 
// 0 1
// 1 5
// 2 0
// 2 1
// 3 2
// 3 4
// 4 0
// 4 3 0
// 0 1
// 1 2
// 2 3
// 2 2 0
// 0 1
// 1 0