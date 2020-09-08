// Copyright 2019
// Wednesday Nov, 6
// By: Danny Lisamay and Dheera Vuppala
#include "RingBuffer.hpp"
#include <iostream>
RingBuffer::RingBuffer(int cap) {
    if (cap < 1) {
        std::cout << ("RB constructor: capacity must be greater than zero.")
        <<std::endl;
        throw std::invalid_argument
            ("RB constructor:capacity must be greater than zero.");
    }
    this->cap = cap;
    front = rear = -1;
    arrCirc = new int[cap];
    sizeOfArr = 0;
}
int RingBuffer::size() {
    return sizeOfArr;
}
bool RingBuffer::isEmpty() {
    if (sizeOfArr == 0)
        return true;
    return false;
}
bool RingBuffer::isFull() {
    auto lambaSize = [](int arrSize, int cap) {
        if (arrSize == cap) return true;
        return false;
    };
    return lambaSize(sizeOfArr, cap);
}
void RingBuffer::enqueue(int16_t x) {
    if ((front == 0 && rear == cap -1) || (rear ==(front-1)%(cap-1))) {
        std::cout << "enqueue: can't enqueue to a full ring" << std::endl;
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    } else if (front == -1) {
        front = rear = 0;
        arrCirc[rear] = x;
    } else if (rear == cap - 1 && front != 0) {
        rear = 0;
        arrCirc[rear] = x;
    } else {
        rear++;
        arrCirc[rear] = x;
    }
    sizeOfArr++;
}
int16_t RingBuffer::dequeue() {
    if (front == -1) {
        std::cout << "Ring is empty" << std::endl;
        throw std::runtime_error("Ring is empty");
    }
    int data = arrCirc[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == cap -1) {
        front = 0;
    } else {
        front++;
    }
    sizeOfArr--;
    return data;
}
int16_t RingBuffer::peek() {
    if (front == -1) {
        std::cout << "Ring is empty" << std::endl;
        throw std::runtime_error("Ring is empty");
    }
    int data = arrCirc[front];
    return data;
}
