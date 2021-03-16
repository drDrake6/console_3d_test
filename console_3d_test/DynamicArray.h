#pragma once
template <class T>

class Set
{
public:
	Set() = default;
	Set(const Set& orig);
	Set& operator=(const Set& orig);
	Set(Set&& orig);
	Set& operator=(Set&& orig);

	T operator[](int index) const;
	T& operator[](int index);
	int GetSize();

	void Add(T value);
	void Print();
	void Delete();
	void Clear();

	~Set();

private:
	size_t _size = 0;
	T* _pArr = nullptr;	
};

template<class T>
Set<T>::Set(const Set& orig)
{
	_size = orig._size;
	_pArr = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_pArr[i] = orig._pArr[i];
	}
}

template<class T>
Set<T>& Set<T>::operator=(const Set& orig)
{
	if (&orig == this) return *this;

	Clear();
	_size = orig._size;
	_pArr = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_pArr[i] = orig._pArr[i];
	}
	return *this;
}

template<class T>
Set<T>::Set(Set&& orig)
{
	_size = orig._size;
	_pArr = orig._pArr;
	orig._pArr = nullptr;
	orig._size = 0;
}

template<class T>
Set<T>& Set<T>::operator=(Set&& orig)
{
	if (&orig == this) return *this;

	Clear();
	_size = orig._size;
	_pArr = orig._pArr;
	orig._pArr = nullptr;
	orig._size = 0;
	return *this;
}

template <class T>
T Set<T>::operator[](int index) const
{
	return _pArr[index];
}

template <class T>
T& Set<T>::operator[](int index)
{
	return _pArr[index];
}

template<class T>
inline int Set<T>::GetSize()
{
	return _size;
}

template <class T>
void Set<T>::Add(T value)
{
	T* tmp = new T[_size + 1];

	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _pArr[i];
	}
	tmp[_size] = value;

	if (_pArr != nullptr)
	{
		delete[] _pArr;
	}
	_pArr = tmp;
	_size++;
}

template <class T>
void Set<T>::Print()
{
	for (size_t i = 0; i < _size; i++)
	{
		cout << _pArr[i] << "\t";
	}
	cout << endl;
}

template <class T>
void Set<T>::Delete()
{
	_size--;
	T* tmp = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		tmp[i] = _pArr[i];
	}
	delete[] _pArr;
	_pArr = tmp;
}

template <class T>
void Set<T>::Clear()
{
	if (_pArr != nullptr)
	{
		delete[] _pArr;
		_pArr = nullptr;
		_size = 0;
	}
}

template <class T>
Set<T>::~Set()
{
	Clear();
}


