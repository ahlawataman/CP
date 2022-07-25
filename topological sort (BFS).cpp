class Solution {
public:
    
    /*
        -> map<int, vector<int>> adjList : [1,0] 1<-0 To do course 1, need to complete course 0 first
        -> vector<int> indegree : indegree count of every node
        -> queue q : contains only nodes with 0 indegree

        1. start bfs from nodes with 0 indegree
        2. keep pushing elements to queue as soon as indegree == 0
        3. finally, check if we traversed all nodes
    
    */

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> preToReq; // pre -> req
        map<int, int> indegree; // indegree of node
        queue<int> q; // containing 0 indegree nodes
        
        // populating connection & indegree count
        for(int i=0; i<prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        // populating elements with 0 indegree to start bfs with
        for(int i=0; i<numCourses; i++) 
            if(indegree[i]==0) 
                q.push(i);
        
        // checking if we can traverse all nodes
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int p = q.front(); q.pop();
                numCourses--; // reducing nodes to visit count
                for(int &x: adjList[p]) {
                    if(--indegree[x] == 0) q.push(x); // inserting only when indegree becomes 0
                }
            }
        }
        
        return numCourses==0;
    }
};
