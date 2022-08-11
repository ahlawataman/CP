int main()  {
    int n = 4;
    vector<vector<pair<int, int>>> adjList(n);
    adjList[0].push_back({1, 4});
    adjList[0].push_back({2, 1});
    adjList[2].push_back({3, 1});
    adjList[3].push_back({1, 1});
    
    int target = 1;
    int ans = 0;
    // finding shortest path from node 0 to node 1
    set<int> s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    // {dist, node}
    minheap.push({0, 0});
    while(!minheap.empty()) {
        pair<int, int> p = minheap.top(); minheap.pop();
        if(p.second == target) {
            ans = p.first;
            break;
        }
        if(s.find(p.second) != s.end())
            continue;
        s.insert(p.second);
        for(auto ptr: adjList[p.second]) {
            minheap.push({ptr.second + p.first, ptr.first});
        }
    }
    cout<<ans;
}
