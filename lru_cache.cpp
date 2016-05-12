//uri:	https://leetcode.com/problems/lru-cache/

/*
 *	借用双向链表+unordered_map。如果使用list替代双向链表会出错，原因是list插入或者删除会影响unordered_map中存储的迭代器，
 *	而使用map则不会影响，然后map存储速度要比unordered_map慢。
 *	空间复杂度：(n).
 *	时间复杂度：O(1).
 * */

class LRUCache{
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    };
    
    LRUCache(int capacity) {
        this -> capacity = capacity;
        real_capacity = 0;
		head = nullptr;
		tail = nullptr;
    }
    
    int get(int key) {
        auto p = _map.find(key);
        if ( p == _map.end() ) { return -1; }
        erase(p -> second);
        add(p -> second);

        return p -> second -> val;
    }
    
    void erase(Node* p) {
    	if ( p == head ) {
    		head = head -> next;
    		if ( head ) head -> prev = nullptr;
    		return;
    	}

    	if ( p -> prev ) { p -> prev -> next = p -> next; }
        if ( p -> next ) { p -> next -> prev = p -> prev; }
        if ( p == tail ) { tail = p -> prev; }
    }
    
    void add(Node* p) {
        p -> next = head;
		if ( head ) { head -> prev = p; }
		else { tail = p; }
        p -> prev = nullptr;
        head = p;
    }
    
    void set(int key, int value) {
        auto p = _map.find(key);
        Node* node = new Node(key, value);
        if ( p != _map.end() ) {
            erase(p -> second);
            real_capacity -= 1;
        }
        
        if ( real_capacity >= capacity ) {
            _map.erase(tail -> key);
            erase(tail);
            real_capacity -= 1;
        }
        
        add(node);
        _map[key] = node;
        real_capacity += 1;
    }
    
private:
    int capacity;
    int real_capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> _map;
};
