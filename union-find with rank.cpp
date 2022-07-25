class Solution {
public:
    
    /*
        INITIALIZING PARENT AND RANKING VECTOR
            PAR [1,2,3,4,5] // every node is independent initially
            RANK [1,1,1,1,1] // every node has rank 1 i.e. graph component contains 1 node
            
        WE KEEP JOINING COMPONENTS AND UPDATE PAR & RANKS.
        SMALLER RANK COMPONENT IS JOINED W/ HIGHER RANK COMPONENT.
    
    */
    
    // FINDING PARENT OF A NODE
    int find(int n, vector<int> &par) {
        int p = n;
        while(p!=par[p]) {
            // OPTIMIZATION
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    
    // UNION 2 COMPONENTS
    bool unionF(int n1, int n2, vector<int> &par, vector<int> &rank) {
        int p1 = find(n1, par);
        int p2 = find(n2, par);
        
        // ELEMENTS HAVE SAME PARENT, SO REDUNDANT NODE FOUND, RETURN
        if(p1 == p2)
            return false;
        
        // SMALLER RANK COMPONENT IS JOINED W/ HIGHER RANK COMPONENT
        if(rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1, 0);
        vector<int> rank(n+1, 1);
        for(int i=1; i<=n; i++) {
            par[i]=i;
        }
        
        for(vector<int> &e: edges) {
            if(!unionF(e[0], e[1], par, rank))
                return e;
        }
        return {-1,-1};
    }
};
