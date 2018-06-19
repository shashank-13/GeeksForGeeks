/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    unordered_map<UndirectedGraphNode *,UndirectedGraphNode *>myMap;
    queue<UndirectedGraphNode *>myQueue;
    myQueue.push(node);
    UndirectedGraphNode *head=new UndirectedGraphNode(node->label);
    myMap.insert(make_pair(node,head));
    while(!myQueue.empty())
    {
        UndirectedGraphNode *f = myQueue.front();
        myQueue.pop();
        UndirectedGraphNode *temp = myMap[f];
        for(int i=0;i<(int)f->neighbors.size();i++)
        {
          if(myMap.find(f->neighbors[i])!=myMap.end())
          {
              temp->neighbors.push_back(myMap[f->neighbors[i]]);
          }
          else
          {
              UndirectedGraphNode *temp1 = new UndirectedGraphNode(f->neighbors[i]->label);
              myMap.insert(make_pair(f->neighbors[i],temp1));
              myQueue.push()
          }
        }
    }
}
