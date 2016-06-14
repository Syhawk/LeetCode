//uri:	https://leetcode.com/problems/find-median-from-data-stream/

/*
 *	采用两个优先队列分别存储当前数组的前半部分与后半部分，其中前半部分元素数目>=后半部分元素数目,且最多只多一个元素。
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlogn).
 * */

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        _max.push(num);
        int var = _max.top();
        _max.pop();
        
        _min.push(var);
        var = _min.top();
        _min.pop();
        
        if ( _max.size() > _min.size() ) { _min.push(var); }
        else { _max.push(var); }
    }

    // Returns the median of current data stream
    double findMedian() {
        return _max.size() > _min.size() ? _max.top() : (_max.top() + _min.top()) / 2.0;
    }
    
private:
    priority_queue<int, vector<int>, less<int>> _min;
    priority_queue<int, vector<int>, greater<int>> _max;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
