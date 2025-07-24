#include <iostream>

template <typename T>
class DynamicArray
{
public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}

    ~DynamicArray()
    {
        delete[] data;
    }

    void push_back(const T &value)
    {
        if (size >= capacity)
        {
            /* not enought space left to add new value
           if capacity is zero, set it to 1 else double it*/
            size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
            resize(new_capacity);
        }
        data[size++] = value;
    }

    void print() const
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << data[i] << " ,";
        }
        std::cout << "\n";
    }

private:
    T *data;
    size_t size;
    size_t capacity;

    void resize(size_t new_size)
    {
        T *new_data = new T[new_size];

        for (size_t i = 0; i < size; ++i)
        {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_size;
    }
};

int main()
{
    DynamicArray x = DynamicArray<int>();
    x.push_back(3);
    x.push_back(4);
    x.push_back(6);
    x.print();
    return 0;
}