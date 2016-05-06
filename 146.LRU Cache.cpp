//low efficiency
struct node
{
	int use;
	int index;
};
class LRUCache {
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void set(int key, int value);
private:
	int _capacity;
	int _size;
	int *mem;
	unordered_map<int, int> hashmap;
	vector<node> maxheap;
};

LRUCache::LRUCache(int capacity):_capacity(capacity),_size(0)
{
	mem = new int[2 * _capacity];
}

LRUCache::~LRUCache()
{
	delete[] mem;
}

int LRUCache::get(int key)
{
	
	if(hashmap.find(key)==hashmap.end())
		return -1;
	int index = hashmap[key];
	for (size_t i = 0; i < _size; ++i)
	{
		if (maxheap[i].index == index)
			maxheap[i].use = 0;
		else
			++maxheap[i].use;
	}
	make_heap(maxheap.begin(), maxheap.begin()+_size, [](node a, node b)->bool {return a.use < b.use ? true : false; });
	return *(2*index+mem+1);
}

void LRUCache::set(int key, int value)
{
	if (hashmap.find(key) != hashmap.end())//find
	{
		int index = hashmap[key];
		*(2 * index + mem + 1) = value;
		for (size_t i = 0; i < _size; ++i)
		{
			if (maxheap[i].index == index)
				maxheap[i].use = 0;
			else
				++maxheap[i].use;
		}
		//make_heap(maxheap.begin(), maxheap.begin() + _size, [](node a, node b)->bool {return a.use < b.use ? true : false; });
	}
	else//cannot find
	{
		if (_size < _capacity)//free mem exist
		{
			++_size;
			*(2 * (_size-1) + mem + 1) = value;
			*(2 * (_size-1) + mem) = key;
			hashmap[key] = _size-1;//insert new key
			node new_node;
			new_node.use = 0;
			new_node.index = _size - 1;
			maxheap.push_back(new_node);
			for (size_t i = 0; i < _size-1; ++i)
				++maxheap[i].use;
			//make_heap(maxheap.begin(), maxheap.begin()+_size, [](node a, node b)->bool {return a.use < b.use ? true : false; });
		}
		else//no free mem
		{
			int replace_index = maxheap[0].index;
			*(2 * replace_index + mem + 1) = value;
			hashmap.erase(*(2 * replace_index + mem));//delete the replaced key-value
			*(2 * replace_index + mem) = key;
			hashmap[key] = replace_index;//insert new key
			maxheap[0].use = 0;
			for (size_t i = 1; i < _size; ++i)
				++maxheap[i].use;
			//make_heap(maxheap.begin(), maxheap.begin() + _size, [](node a, node b)->bool {return a.use < b.use ? true : false; });
		}
	}
	make_heap(maxheap.begin(), maxheap.begin() + _size, [](node a, node b)->bool {return a.use < b.use ? true : false; });
}

//high efficiency
class LRUCache
{
public:
	LRUCache(int capacity) :_capacity(capacity), _size(0) {};
	int get(int key);
	void set(int key, int value);
private:
	int _capacity;
	int _size;
	unordered_map<int, pair<int, list<int>::iterator>> hashmap;
	list<int> linked_list;
};

int LRUCache::get(int key)
{

	if (hashmap.find(key) == hashmap.end())
		return -1;
	auto iter = hashmap[key].second;
	linked_list.erase(iter);
	linked_list.push_front(key);
	hashmap[key] = make_pair(hashmap[key].first, linked_list.begin());
	return hashmap[key].first;
}

void LRUCache::set(int key, int value)
{
	if (hashmap.find(key) != hashmap.end())//find
	{
		auto iter = hashmap[key].second;
		linked_list.erase(iter);
		linked_list.push_front(key);
		hashmap[key] = make_pair(value, linked_list.begin());
	}
	else//cannot find
	{
		if (_size < _capacity)//free mem exist
		{
			++_size;
			linked_list.push_front(key);
			hashmap[key] = make_pair(value, linked_list.begin());
		}
		else//no free mem
		{

			int replace_key = linked_list.back();
			linked_list.erase(hashmap[replace_key].second);
			linked_list.push_front(key);
			hashmap.erase(replace_key);//delete the replaced key-value
			hashmap[key] = make_pair(value, linked_list.begin());

		}
	}
}