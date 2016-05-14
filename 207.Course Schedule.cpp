class Solution {
public:
	//dfs
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<bool> checked(numCourses, false);
		for (int i = 0; i < numCourses; ++i)
		{
			if (checked[i] || graph[i].empty())
				continue;
			unordered_set<int> visited;
			if (!dfs(graph, i, checked, visited))
				return false;
		}
		return true;
	}
private:
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	bool dfs(vector<unordered_set<int>> &graph, int beg, vector<bool> &checked, unordered_set<int> &visited)
	{
		if (checked[beg]) return true;//为什么只要checked==true就能直接返回了呢？因为在进入dfs之前，就已经检测过visited.find(*iter) != visited.end()了
                                      //能执行这一句意味着本点在此次dfs中尚未visited，但是之前已经检测过了
        checked[beg] = true;
		visited.insert(beg);
		for (auto iter = graph[beg].begin(); iter != graph[beg].end(); ++iter)
		{
			if (visited.find(*iter) != visited.end()||!dfs(graph, *iter, checked, visited))
				return false;
		}
		visited.erase(beg);//很重要。本次dfs完成意味着以此node开始，没有找到环，需要恢复visited，因为本node可能会用于其他dfs
		return true;
	}
};

/*others solution*/
//bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
}; 