/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//bfs
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node) return nullptr;
		UndirectedGraphNode *dup_node = new UndirectedGraphNode(node->label);
		hashmap[node->label] = dup_node;
		deque<UndirectedGraphNode *> queue;
		queue.push_back(node);//save original node
		while (!queue.empty())
		{
			auto curr = queue.front();
			queue.pop_front();
			for (auto neighbor : curr->neighbors)
			{
				if (hashmap.find(neighbor->label) == hashmap.end())//new neighbor
				{
					auto new_neighbor = new UndirectedGraphNode(neighbor->label);
					hashmap[new_neighbor->label] = new_neighbor;
					queue.push_back(neighbor);//save original node
				}
				hashmap[curr->label]->neighbors.push_back(hashmap[neighbor->label]);
			}
		}
		return dup_node;
	}
private:
	unordered_map<int, UndirectedGraphNode *> hashmap;
};

//dfs
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node) return nullptr;
		UndirectedGraphNode *dup_node = new UndirectedGraphNode(node->label);
		hashmap[node->label] = dup_node;
		dfs(node, dup_node);
		return dup_node;
	}
private:
	unordered_map<int, UndirectedGraphNode *> hashmap;
	void dfs(UndirectedGraphNode *ori_node, UndirectedGraphNode *dup_node)
	{
		for (size_t i = 0; i < ori_node->neighbors.size(); ++i)
		{
			if (hashmap.find(ori_node->neighbors[i]->label) == hashmap.end())//new node
			{
				UndirectedGraphNode *new_node = new  UndirectedGraphNode(ori_node->neighbors[i]->label);
				hashmap[ori_node->neighbors[i]->label] = new_node;
				dfs(ori_node->neighbors[i], new_node);
			}
			dup_node->neighbors.push_back(hashmap[ori_node->neighbors[i]->label]);
		}

	}
};