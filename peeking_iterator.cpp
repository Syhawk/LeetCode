//uri:	https://leetcode.com/problems/peeking-iterator/

/*
 *	设置int变量value和bool变量has分别用来存储值与是否存在下一个数。
 *	每次next取值的时候，事先把下一个要取的值取出来。这样，每次peek的时候直接把
 *	已经提前取出来的值直接返回即可。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int tmp = value;
		has = Iterator::hasNext();
		if(has)
			value = Iterator::next();

	    return tmp;
	}

	bool hasNext() const {
	    return has;
	}
private:
	int value;
	bool has;
};
