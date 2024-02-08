# include "Array.hpp"

template<typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
	for (unsigned int i = 0; i < _size; ++i) {
		_arr[i] = T();
	}
}

template<typename T>
Array<T>::Array(const Array<T>& src) : _arr(new T[src._size]), _size(src._size) {
	for (unsigned int i = 0; i < _size; i++) {
		_arr[i] = src._arr[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
	if (this != &rhs) {
		delete[] _arr;
		_size = rhs._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_arr[i] = rhs._arr[i];
		}
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
