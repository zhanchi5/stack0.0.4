#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>

template <typename T>
class stack{
public:
    	stack() noexcept;
        size_t count() const noexcept;
    	void push(T const &) /* strong */;
    	void pop()  /*strong*/;
	T top()  /*strong*/;
    	

private:
	void swap(stack<T>& other) noexcept;
   	T * array_;
    	size_t array_size_;
    	size_t count_;
	
};

template <typename T>
stack<T>::stack() noexcept : count_(0), array_size_(0), array_(nullptr){}

template <typename T>
size_t stack<T>::count() const noexcept
{
    return count_;
}



template <typename T>
void stack<T>::swap(stack<T>& other) noexcept
{
    std::swap(array_, other.array_);
    std::swap(array_size_, other.array_size_);
    std::swap(count_, other.count_);
}


template <typename T>
void stack<T>::pop(){
	if (count_ == 0){
		std::cout << "Stack is empty! Try again!" << "\n";
	}
	else{
		--count_;
	}
}

template <typename T>
T stack<T>::top(){
	T temp = array_[--count_];

	return temp;
}


template <typename T>
void stack<T>::push(T const &val){
	
	if (array_size_ == count_){
		
		size_t size_ = array_size_;
		if (size_ == 0){
			size_ = 1;
		}
		else{
			size_ = array_size_ * 2;
		}

		T* temp = new T[size_];
		std::copy(array_, array_ + count_, temp);

		array_size_ = size_;
		delete[] array_;
		array_ = temp;
	}
	array_[count_] = val;
++count_;
}

