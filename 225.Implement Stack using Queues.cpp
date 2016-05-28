class Stack {
public:
	// Push element x onto stack.
	void push(int x)
	{
		if (q.empty())
			q2.push_back(x);
		else
			q.push_back(x);
		++sz;
		return;
	}

	// Removes the element on top of the stack.
	void pop()
	{
		if (q.empty())
		{
			for (int i = 0; i < sz - 1; ++i)
			{
				q.push_back(q2.front());
				q2.pop_front();
			}
			q2.pop_front();
			--sz;
			return;
		}
		else
		{
			for (int i = 0; i < sz - 1; ++i)
			{
				q2.push_back(q.front());
				q.pop_front();
			}
			q.pop_front();
			--sz;
			return;
		}
	}

	// Get the top element.
	int top()
	{
		if (q.empty())
		{
			for (int i = 0; i < sz - 1; ++i)
			{
				q.push_back(q2.front());
				q2.pop_front();
			}
			int res = q2.front();
			q.push_back(res);
			q2.pop_front();
			return res;
		}
		else
		{
			for (int i = 0; i < sz - 1; ++i)
			{
				q2.push_back(q.front());
				q.pop_front();
			}
			int res = q.front();
			q2.push_back(res);
			q.pop_front();
			return res;
		}
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return !sz;
	}
	Stack() :sz(0) {}
private:
	deque<int> q;
	deque<int> q2;
	int sz;
};