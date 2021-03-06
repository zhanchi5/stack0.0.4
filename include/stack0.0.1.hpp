#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>

template <typename T>
class stack
{
private:
	void swap(stack<T> &) noexcept;

public:
	stack() noexcept;
	stack(stack<T> const &) /* strong */;
	stack<T>& operator = (stack<T> const &)  noexcept;
	size_t count() const noexcept;
	void push(T const &) /* strong */;
	void pop() /* strong */;
	T top() /* strong */;
	bool empty() const noexcept;

private:
	T* array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() noexcept : count_(0), array_size_(0), array_(nullptr)
{}

template <typename T>
size_t stack<T>::count() const noexcept
{
	return count_;
}

template <typename T>
stack<T>::stack(stack<T> const& copy)
{
	T* temp = new T[copy.array_size_];
	array_size_ = copy.array_size_;
	count_ = copy.count_;	
	array_ = temp;
	try
	{
		std::copy(copy.array_, copy.array_ + count_, array_);	
	}
	catch ( ... )
	{
		std::cerr << "Error! Try again!" << std::endl;
		delete[] array_;
		throw;
	}
	
	
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> const& other) noexcept
{
	if (this != &other)
	{
		stack<T> temp(other);
		swap(temp);
	}
	
	return *this;
}

template <typename T>
void stack<T>::swap(stack<T>& other) noexcept
{
	std::swap(array_, other.array_);
	std::swap(array_size_, other.array_size_);
	std::swap(count_, other.count_);
}

template <typename T>
void stack<T>::push(T const& value)
{
	if (array_size_ == count_)
	{
		size_t size = array_size_;
		if (size == 0)
			size = 1;
		else
			size = array_size_ * 2;

		T* temp = new T[size];
		
		try
		{
			std::copy(array_, array_ + count_, temp);	
		}
		
		catch ( ... )
		{
			std::cerr << "Error! Try again!" << std::endl;
			delete[] temp;
			throw;
		}

		array_size_ = size;
		delete[] array_;
		array_ = temp;
	}
	
	array_[count_] = value;
	++count_;
}

template <typename T>
void stack<T>::pop()
{
	if (count_ == 0)
	{
		throw "Stack is empty! Try again!\n";
	}
	else
	{
		--count_;
	}
}

template <typename T>
T stack<T>::top()
{
	if (count_ == 0)
	{
		throw "Stack is empty!";
	}
	else
	{
		return array_[count_ - 1];
	}
}

template <typename T>
bool stack<T>::empty() const noexcept
{
	return (count_ == 0); 
}
