class MedianFinder {
public:
    MedianFinder() { stream_size = 0; }

    void addNum(int num) {
        if (left.empty()) {
            left.push(num);
            stream_size++;
            return;
        }

        if (left.top() < num) {
            right.push(num);
            stream_size++;
            if (stream_size % 2 != 0 && left.size() < right.size()) {
                left.push(right.top());
                right.pop();
            }
        } else {
            left.push(num);
            stream_size++;
            if (stream_size % 2 == 0 && left.size() != right.size()) {
                right.push(left.top());
                left.pop();
            }
        }
    }

    double findMedian() {
        if (stream_size % 2 == 0)
            return (double)(left.top() + right.top()) / 2.0;
        return left.top();
    }

private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    size_t stream_size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */