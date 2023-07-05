
#include <cstddef>
#include <stdexcept>
#include <algorithm>

// Class Constructor
template<typename ItemType>
Queue<ItemType>::Queue(): qSize(0), frontt(nullptr), back(nullptr){}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template<typename ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue): qSize(aQueue.size()), frontt(nullptr), back(nullptr){
    if(aQueue.frontt != nullptr){
        frontt = new QNode;
        frontt->data = aQueue.frontt->data;
        QNodePtr newPtr = frontt;
        for(QNodePtr origPtr = aQueue.frontt->next; origPtr != nullptr; origPtr = origPtr ->next){
            newPtr ->next = new QNode;
            newPtr = newPtr -> next;
            newPtr -> data = origPtr->data;
        }
        newPtr->next = nullptr;
    }
}

// Class Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist
template<typename ItemType>
Queue<ItemType>::~Queue(){
    while(!isEmpty())
        dequeue();
}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template<typename ItemType>
const Queue<IteType> &Queue<ItemType>::operator= (const Queue<ItemType>& rhs){
    if(this != &rhs) {
        Queue<ItemType> tmp(rhs);                      //DO I DELETE THIS? WHY IS IT HERE?? NVR USE
        std::swap(qSize, tmp.qSize);
        std::swap(frontt, tmp.frontt);
        std::swap(back, tmp.back);
    }
    return *this;
}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
template<typename ItemType>
bool Queue<ItemType>::isEmpty() const{
    return frontt == nullptr;
}

// enqueue
// enqueues an item to back of the queue.
// pre:  DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
template<typename ItemType>
void Queue<ItemType>::enqueue(const ItemType& item){
    QNodePtr tmp = new QNode;
    tmp->data = item;
    tmp->next = nullptr;
    if(frontt== nullptr){
        frontt = back = tmp;
    }
    else {
        back->next = tmp;
        back = tmp;
    }
    qSize++;
}

// dequeue
// dequeues the front item off the queue
// pre:  DblQueue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
template<typename ItemType>
void Queue<ItemType>::dequeue(){
    QNodePtr tmp = frontt;
    if(frontt == nullptr) {
        throw std::underflow_error("Empty Stack");
    }
    if(frontt == back)
        frontt = back = nullptr;
    else
        frontt = frontt -> next;
    qSize--;
    delete tmp;
    tmp = nullptr;
}

// front
// Returns the front item of the queue without dequeueing it.
// pre:  DblQueue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
template<typename ItemType>
ItemType Queue<ItemType>::front() const{
    if(isEmpty()) {
        throw std::underflow_error("Empty Queue");
    }
    else {
        return frontt->data;

    }
}

// size
// Returns the number of items on the queue.
template<typename ItemType>
size_t Queue<ItemType>::size() const{
    return qSize;
}



