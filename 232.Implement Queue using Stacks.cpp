class Queue {
public:
	// Push element x to the back of queue.
	void push(int x)
	{
		s1.push(x);
		++sz;
		return;
	}

	// Removes the element from in front of queue.
	void pop(void)
	{
		stack<int> s2;
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		--sz;
		return;
	}

	// Get the front element.
	int peek(void)
	{
		stack<int> s2;
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		int res = s2.top();
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return res;
	}

	// Return whether the queue is empty.
	bool empty(void)
	{
		return !sz;
	}
	Queue() :sz(0) {};
private:
	stack<int> s1;
	int sz;
};