//dfs
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
	    if(prerequisites.empty())
	    {
	        vector<int> res(numCourses);
	        for(int i=0;i<numCourses;++i)
	            res[i]=i;
	        return res;
	    }
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<bool> checked(numCourses, false);
		vector<int> res;
		for (int i = 0; i < numCourses; ++i)
		{
			if (checked[i])
				continue;
			unordered_set<int> visited;
			if (!dfs(graph, i, checked, visited, res))
				return vector<int>();
		}
		reverse(res.begin(), res.end());
		return res;
	}
private:
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	bool dfs(vector<unordered_set<int>> &graph, int beg, vector<bool> &checked, unordered_set<int> &visited, vector<int> &res)
	{
		if (checked[beg]) return true;//为什么只要checked==true就能直接返回了呢？因为在进入dfs之前，就已经检测过visited.find(*iter) != visited.end()了
									  //能执行这一句意味着本点在此次dfs中尚未visited，但是之前已经检测过了
		checked[beg] = true;
		visited.insert(beg);
		
		for (auto iter = graph[beg].begin(); iter != graph[beg].end(); ++iter)
		{
			if (visited.find(*iter) != visited.end() || !dfs(graph, *iter, checked, visited, res))
				return false;
		}
		visited.erase(beg);//很重要。本次dfs完成意味着以此node开始，没有找到环，需要恢复visited，因为本node可能会用于其他dfs
		res.push_back(beg);
		return true;
	}
};

//bfs
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		if (prerequisites.empty())
		{
			vector<int> res(numCourses);
			for (int i = 0; i < numCourses; ++i)
				res[i] = i;
			return res;
		}
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<int> res;
		vector<int> indegree(numCourses, 0);
		calcIndegree(graph, indegree);
		for (int j = 0; j < numCourses; ++j)
		{
			int i = 0;
			for (; i < indegree.size(); ++i)
			{
				if (indegree[i] == 0)
					break;
			}
			if (i == indegree.size())//cannot find a node whose indegree==0, it means that cycle exists.
				return vector<int>();
			indegree[i] = -1;
			res.push_back(i);
			for (int next : graph[i])
				--indegree[next];
		}
		return res;
	}
private:
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}
	void calcIndegree(vector<unordered_set<int>> &graph, vector<int> &indegree)
	{
		for (auto &nodes : graph)
			for (int next : nodes)
				++indegree[next];
		return;
	}
};