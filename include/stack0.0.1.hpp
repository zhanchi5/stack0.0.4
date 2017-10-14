#include <iostream>

template <typename T> class stack
{
public:
	stack();
	~stack();
	stack(const stack&);
	stack<T>& operator=(const stack<T>& other);
	void swap(T*& this_array, const T* other_array, size_t other_count, size_t other_array_size);
	size_t count() const;
	void push(T const &);
	T pop();
	void print() const;
	T printlast() const;
	
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};


template<typename T>
stack<T>::stack() 
{
	count_ = 0;
	array_size_ = 0;
	array_ = nullptr;
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
	swap(array_, other.array_, count_, array_size_);
}

template<typename T>
void stack<T>::swap(T*& this_array, const T* other_array, size_t other_count, size_t other_array_size) {
	if (other_array_size == 0 )
		this_array = nullptr;
	else 
	{
		this_array = new T[other_array_size];
		std::copy(other_array, other_array + other_count, this_array);
	}
	
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
	if (this != &other) 
	{
		if (array_size_ != 0) 
		{
			delete[] array_;
		}
		array_size_ = other.array_size_;
		count_ = other.count_;
		swap(array_, other.array_, count_, array_size_);
	}
	return *this;
}
template<typename T>
void stack<T>::print() const
{
	if (count_ == 0) std::cout << "Stack is empty" << std::endl;
	else
	for(int i=0; i < count_ ; i++)
	std::cout<< array_[i] << ' ';
	std::cout << std::endl;
}
template<typename T>
T stack<T>::printlast()const
{
	if (count_ == 0)
		throw std::logic_error("Stack is empty");
	else return array_[count_ - 1];
}

template<typename T>
size_t stack<T>::count() const
{
	return count_;
}

template<typename T>
T stack<T>::pop() {
	if (array_size_ != 0) 
	{
		T val = array_[--count_];
		if (array_size_ == count_ * 2) 
		{
			T *ptr;
			array_size_ /= 2;
			swap(ptr, array_, count_, array_size_);
			delete[] array_;
			array_ = ptr;
		}
		return val;
	}
	else 
		throw std::logic_error("Stack is empty");
}

template<typename T>
void stack<T>::push(T const & value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	else if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T *ptr;
		swap(ptr, array_, count_, array_size_);
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}
