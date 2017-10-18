#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>

template <typename T> class stack
{
public:
    stack();
    ~stack();
    stack(const stack&);
    stack<T>& operator=(const stack<T>& other);
    void swap(stack<T>& other);
    size_t count() const;
    size_t array_size() const;
    void push(T const &);
    T pop();


    std::ostream& print(std::ostream& os);

    friend std::ostream& operator<< (std::ostream& os, stack<T>& obj);

private:
    T * array_;
    size_t array_size_;
    size_t count_;
};

template <typename T>
stack<T>::stack() : count_(0), array_size_(0), array_(nullptr)
{}

template <typename T>
size_t stack<T>::count() const
{
    return count_;
}

template <typename T>
size_t stack<T>::array_size() const
{
    return array_size_;
}
template<typename T>
std::ostream& operator <<(std::ostream& os, stack<T> val){
    if (count_ == 0) std::cout << "Stack is empty" << std::endl;
    else
        for(int i=0; i < count_; i++)
            std::cout<< array_[i] << ' ';
    std::cout << std::endl;
    return os;
}


template<typename T>
stack<T>::stack()
{
        count_ = 0;
        array_size_ = 0;
        array_ = new T[array_size_];
}

template<typename T>
stack<T>::~stack()
{
        count_ = 0;
        array_size_ = 0;
        delete[] array_;
}
template<typename T>
stack<T>::stack(const stack<T>& other)
{
        array_size_ = other.array_size_;
        count_ = other.count_;
        array_ = new T[array_size_];
        std::copy(other.array_, other.array_ + other.array_size_, array_);
}

template <typename T>
void stack<T>::swap(stack<T>& other)
{
    std::swap(array_, other.array_);
    std::swap(array_size_, other.array_size_);
    std::swap(count_, other.count_);
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> const &other)
{
    if (this != &other)
    {
        stack<T> temp(other);
        swap(temp);
    }
    return *this;
}

template <typename T>
std::ostream& stack<T>::print(std::ostream& os)
{
    if (count_ == 0) {
        os << "Stack is empty! Try again!\n";
    }
    else {
        for (unsigned int i = 0; i < count_; i++) {
            os << array_[i] << "\t";
        }
    }

    return os;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, stack<T>& obj)
{
    return obj.os(os);
}



template <typename T>
T stack<T>::pop()
{
    if (count_ == 0)
        throw std::logic_error("Stack is empty! Try again!\n");
    else
    {
        T temp = array_[--count_];

        return temp;
    }
}


template <typename T>
void stack<T>::push(T const &val)
{
    if (array_size_ == 0)
    {
        array_size_ = 1;
        array_ = new T[array_size_];
    }
    else if (count_ + 1 >= array_size_)
    {
        array_size_ = array_size_ * 2;
        T* temp = new T[array_size_];
        std::copy(array_, array_ + count_, temp);

        delete[] array_;

        array_ = temp;
    }
    array_[count_++] = val;
}
