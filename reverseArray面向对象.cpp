#include <iostream>
#include <iomanip>

template <typename T>
class Array
{
public:
    Array(int size) : size_(size), data_(new T[size_]) {}
    ~Array() { delete[] data_; }

    void reverse()
    {
        int left = 0;
        int right = size_ - 1;
        while (left < right)
        {
            T temp = data_[left];
            data_[left] = data_[right];
            data_[right] = temp;
            left++;
            right--;
        }
    }

    void input()
    {
        for (int i = 0; i < size_; i++)
        {
            std::cin >> data_[i];
        }
    }

    void output() const
    {
        for (int i = 0; i < size_; i++)
        {
            std::cout << data_[i] << " ";
        }
    }

private:
    int size_;
    T *data_;
};

template <typename T>
void reverseArray(int size)
{
    Array<T> inputArray(size);
    inputArray.input();
    inputArray.reverse();
    inputArray.output();
}

int main()
{
    int dataType;
    int size;
    while (std::cin >> dataType >> size)
    {
        if (dataType == 1)
        {
            reverseArray<int>(size);
        }
        else if (dataType == 2)
        {
            reverseArray<long>(size);
        }
        else if (dataType == 3)
        {
            reverseArray<double>(size);
        }
    }
    return 0;
}