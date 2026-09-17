class MedianFinder {

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);

        int topEle = maxHeap.top();
        maxHeap.pop();
        minHeap.push(topEle);

        if (maxHeap.size() < minHeap.size()) {
            int te = minHeap.top();
            minHeap.pop();
            maxHeap.push(te);
        }

        return;
    }

    double findMedian() {
        double ans;

        if (minHeap.size() == maxHeap.size()) {
            ans = (minHeap.top() + maxHeap.top()) * 1.0 / 2;
        } else {
            ans = maxHeap.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */