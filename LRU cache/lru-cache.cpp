class node {
public:
	int key;
	int value;
	node(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

class LRUCache {
public:
	int maxsize;
	list<node> l;
	unordered_map<int, list<node>::iterator> m;
	LRUCache(int capacity) {
		maxsize = capacity;
	}

	int get(int key) {
		if (m.count(key) != 0) {
			auto it = m[key];

			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return value;
		}
		return -1;
	}

	void put(int key, int value) {
		if (m.count(key) != 0) {
			//cout<<key<<" updated"<<endl;
			auto it = m[key];
			it->value = value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
		}
		else {
			if (l.size() == maxsize) {
				node last = l.back();
				cout << last.key << " deleted" << endl;
				m.erase(last.key);
				l.pop_back();
			}
			cout << key << " inserted" << endl;
			node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */