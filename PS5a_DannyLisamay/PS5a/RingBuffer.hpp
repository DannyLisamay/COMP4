#include <stdint.h>
class RingBuffer{
    public:
    RingBuffer(int);
    int size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t);
    int16_t dequeue();
    int16_t peek();

    private:
    int sizeOfArr, cap, rear, front;
    int *arrCirc;
};
