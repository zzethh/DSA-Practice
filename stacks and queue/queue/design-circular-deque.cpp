class MyCircularDeque {
public:
    vector<int> buffer;
    int cnt;
    int k1;
    int front;
    int rear;

    MyCircularDeque(int k) {
        vector<int> v(k, 0);
        buffer = v;
        k1 = k;
        front = 0;
        rear = k - 1;
        cnt = 0;
    }

    bool insertFront(int value) {
        if (cnt == k1) {
            return false;
        }
        buffer[front] = value;
        front = (front + 1) % k1;
        ++cnt;
        return true;
    }

    bool insertLast(int value) {
        if (cnt == k1) {
            return false;
        }
        buffer[rear] = value;
        rear = (rear - 1 + k1) % k1;
        ++cnt;
        return true;
    }

    bool deleteFront() {
        if (cnt == 0) {
            return false;
        }
        front = (front - 1 + k1) % k1;
        --cnt;
        return true;
    }

    bool deleteLast() {
        if (cnt == 0) {
            return false;
        }
        rear = (rear + 1) % k1;
        --cnt;
        return true;
    }

    int getFront() {
        if (cnt == 0) {
            return -1;
        }
        return buffer[(front - 1 + k1) % k1];
    }

    int getRear() {
        if (cnt == 0) {
            return -1;
        }
        return buffer[(rear + 1) % k1];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == k1;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */