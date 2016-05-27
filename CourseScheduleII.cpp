class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        // an array to track visited node, initially all false
        bool visited[numCourses];
        bool onPath[numCourses];
        for (int i = 0; i < numCourses; i++) {
            visited[i] = false;
            onPath[i] = false;
        }
        
        // build adjancency list
        vector< vector<int> > adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        // make sure every node will be visited
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                bool cycle = DFS(i, adj, visited, onPath, order);
                if (cycle) return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
    
    bool DFS(int v, vector< vector<int> > &adj, bool visited[], bool onPath[], vector<int> &order) {
        onPath[v] = true;
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            if (onPath[adj[v][i]]) {
                return true;
            }
            if (!visited[adj[v][i]]) {
                bool cycle = DFS(adj[v][i], adj, visited, onPath, order);
                if (cycle) return true;
            }
        }
        onPath[v] = false;
        order.push_back(v);
        return false;
    }
};