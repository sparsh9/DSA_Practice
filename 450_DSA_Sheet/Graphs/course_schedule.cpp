// Here we are applying Kahn's algorithm for topological sorting using BFS
// As we see there are some courses which have to be done before the chosen course
// and also a vector of vectors is given for all the courses and their prerequistes
// therefore first we make a adjacency list which will make it as a graph and then apply the topo sort on it
// also while pushing the zero degrees to the queue in the process, we will reduce the numCourse variable
// as while pushing, we consider it to be chosen
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> graph(numCourses);
            vector<int> degree(numCourses, 0);
            queue<int> zeroDegree;
            // making the adjaceny list for topo sort and 
            // also making the zerodegree vector with their values
            for(int i = 0; i<prerequisites.size(); i++){
                graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
                degree[prerequisites[i][0]]++;
            }
            // Pushing all the zero degrees to the queue 
            // and decreasing the count of number of courses we can take
            for(int i = 0; i<degree.size(); i++){
                if(degree[i] == 0){
                    zeroDegree.push(i);
                    numCourses--;
                }
            }
            // Implementation of BFS topo sort
            while(!zeroDegree.empty()){
                int node = zeroDegree.front();
                zeroDegree.pop();
                for(int i = 0; i<graph[node].size(); i++){
                    int connectedNode = graph[node][i];
                    degree[connectedNode]--;
                    if(degree[connectedNode] == 0){
                        zeroDegree.push(connectedNode);
                        numCourses--; // Whenever we push to the queue, we decrease the count as it is considered to be chosen
                    }
                }
            }
            
            return numCourses == 0; // tells if it is zero or not (which means if it possible or not to complete all the courses)
            // if the numCourses > 0 then it means some courses could not be completed
            // otherwise if numCourses < 0, it means that there might be duplicate courses in the prerequisites
    } 
}; 