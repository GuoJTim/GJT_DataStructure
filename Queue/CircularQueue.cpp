#include "CircularQueue.h"

template<class T>
CircularQueue<T>::CircularQueue(int queueCapacity){
    capacity = queueCapacity;
    size = 0;
    head = 0;
    rear = 0;
    queue = new T[capacity];
} 

template<class T>
bool CircularQueue<T>::IsEmpty() const{
    return size == 0;
}

template <class T>
T& CircularQueue<T>::Front() const{
    if (IsEmpty()) throw "error";
    return queue[head];
}

template <class T>
T& CircularQueue<T>::Rear() const{
    if (IsEmpty()) throw "error";
    return queue[(rear + capacity - 1) % capacity];
}

template<class T>
void CircularQueue<T>::Push(const T& item){
    if (size == capacity){
        T *temp = new T[capacity*2];
        int index = head;
        int i = 0;
        temp[i++] = queue[index];
        index = (index + 1) % capacity;
        while(index != rear){
            index = (index + 1 ) % capacity;
        }
        capacity *= 2;
        queue = temp;
        head = 0;
        rear = i;
    }
    size++;
    queue[rear] = item;
    rear = (rear + 1) % capacity;
}

template <class T>
void CircularQueue<T>::Pop(){
    if (IsEmpty()){
        throw "error";
    }
    
    head = (head + 1) % capacity;
    size--;
}

