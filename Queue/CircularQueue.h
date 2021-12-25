#ifndef CircularQueue_H
#define CircularQueue_H

// implementation with circular list 
// get front is last->next 
// push last 
template<class T>
class CircularQueue{
    private:
        int capacity;
        int size;
        int head;
        int rear;
        T *queue;
    public:
        CircularQueue(int queueCapacity = 10);
        bool IsEmpty() const;
        T& Front() const;
        T& Rear() const;
        void Push(const T& item);
        void Pop();
};


#endif
