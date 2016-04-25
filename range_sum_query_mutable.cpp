//uri:	https://leetcode.com/problems/range-sum-query-mutable/

/*
 *	普通做法超时，可以采用树状数组或者线段树来做。
 *	空间复杂度：O(n).
 *	时间复杂度：O(logn).
 * */

class NumArray {
public:
    NumArray(vector<int> &nums) {
        ptr = &nums;
        origin = nums;
        
        int size = nums.size();
        for ( int i = 0; i < size; ++ i ) { add(origin[i], i + 1 + lowbit(i + 1)); }
    }
    
    int lowbit(int pos) {
        return pos & (-pos);
    }
    
    void add(int val, int pos) {
        int size = ptr -> size();
        while ( pos <= size ) {
            (*ptr)[pos - 1] += val;
            pos += lowbit(pos);
        }
    }

    void update(int i, int val) {
        int dif = val - origin[i];
        origin[i] = val;
        (*ptr)[i] += dif;
        add(dif, i + 1 + lowbit(i + 1));
    }
    
    int sum(int pos) {
        int val = 0;
        while ( pos ) {
            val += (*ptr)[pos - 1];
            pos -= lowbit(pos);
        }
        
        return val;
    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
    
private:
    vector<int>* ptr;
    vector<int> origin;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


class NumArray {
public:
    NumArray(vector<int> &nums) {
    	tree = vector<Node> (nums.size() * 3);
        if ( nums.size() ) { buildTree(1, nums, 0, nums.size() - 1); }
    }
    
    int buildTree(int idx, vector<int>& nums, int left, int right) {
        tree[idx].left = left;
        tree[idx].right = right;
        
        if ( left == right ) {
            tree[idx].val = nums[left];
            return tree[idx].val;
        }
        
        int mid = (left + right) >> 1;
        tree[idx].val = buildTree(idx << 1, nums, left, mid);
        tree[idx].val += buildTree((idx << 1) + 1, nums, mid + 1, right);
        
        return tree[idx].val;
    }
    
    void update(int idx, int i, int val) {
        if ( tree[idx].left == tree[idx].right ) {
            tree[idx].val = val;
            return;
        }
        
        int mid = (tree[idx].left + tree[idx].right) >> 1;
        if ( mid < i ) { update((idx << 1) + 1, i, val); }
        else { update(idx << 1, i, val); }
        
        maintain(idx, idx << 1, (idx << 1) + 1);
    }
    
    void maintain(int idx, int left_child, int right_child) { tree[idx].val = tree[left_child].val + tree[right_child].val; }

    void update(int i, int val) { update(1, i, val); }
    
    int query(int idx, int left, int right) {
        if ( tree[idx].left == left && tree[idx].right == right ) { return tree[idx].val; }
        
        int mid = (tree[idx].left + tree[idx].right) >> 1;
        if ( mid < left ) { return query((idx << 1) + 1, left, right); }
        else if ( mid >= right ) { return query(idx << 1, left, right); }
        return query(idx << 1, left, mid) + query((idx << 1) + 1, mid + 1, right);
    }

    int sumRange(int i, int j) { return query(1, i, j); }
    
private:
	class Node {
    public:
        int val;
        int left;
        int right;
    };
    vector<Node> tree;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
