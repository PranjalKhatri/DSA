#ifndef _P_ARRAY_H_
#define _P_ARRAY_H_
#include <iostream>
#include<cstddef>
namespace pop
{
	template <class Array>
	class ArrayIterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using value_type = typename Array::value_type;
		using pointer = value_type*;
		using reference = value_type&;
		using difference_type = std::ptrdiff_t;
	private:
		pointer m_ptr;
	public:
		ArrayIterator(pointer ptr)
			:m_ptr(ptr) {}

		ArrayIterator& operator++()
		{
			m_ptr++;
			return *this;
		}
		ArrayIterator& operator--()
		{
			m_ptr--;
			return *this;
		}
		reference operator*()
		{
			return *m_ptr;
		}
		pointer operator->() { return m_ptr; }
		ArrayIterator operator++(int)
		{
			ArrayIterator tmp(*this);
			operator++();
			return tmp;
		}
		ArrayIterator operator--(int)
		{
			ArrayIterator tmp(*this);
			operator--();
			return tmp;
		}
		ArrayIterator& operator+=(difference_type offset) { m_ptr += offset; return *this; }
		ArrayIterator& operator-=(difference_type offset) { m_ptr -= offset; return *this; }
		ArrayIterator operator+(difference_type offset) const { return ArrayIterator(m_ptr + offset); }
		ArrayIterator operator-(difference_type offset) const { return ArrayIterator(m_ptr - offset); }
		difference_type operator-(const ArrayIterator& other) const { return m_ptr - other.m_ptr; }
		reference operator[](difference_type index) const { return m_ptr[index]; }
		bool operator<(const ArrayIterator& other) const { return m_ptr < other.m_ptr; }
		bool operator>(const ArrayIterator& other) const { return m_ptr > other.m_ptr; }
		bool operator<=(const ArrayIterator& other) const { return m_ptr <= other.m_ptr; }
		bool operator>=(const ArrayIterator& other) const { return m_ptr >= other.m_ptr; }

		bool operator!=(const ArrayIterator& other)
		{
			return !(this->m_ptr == other.m_ptr);
		}
		bool operator==(const ArrayIterator& other) {
			return (this->m_ptr == other.m_ptr);
		}


	};


	template <class T, int _size>
	class Array
	{
	public:
		using value_type = T;
		using Iterator = ArrayIterator<Array<T, _size>>;
		using reference = T&;
		using pointer = T*;
	private:
		pointer arr = nullptr;
	public:
		int total_size;
		int used_size;

		Array() : total_size(_size), used_size(0) { create(); };

		void create()
		{
			if (arr != nullptr)
				delete[] arr;
			total_size = _size;
			arr = new T[total_size];
			memset(arr, 0, total_size * sizeof(value_type));
		}

		size_t size() const noexcept
		{
			return this->total_size;
		}

		size_t max_size()const noexcept {
			return total_size;
		}

		bool empty()const noexcept {
			return (used_size == 0);
		}

		void show() const  noexcept
		{
			for (int i = 0; i < used_size; i++)
			{
				std::cout << arr[i] << std::endl;
			}
		}

		void destroy()
		{
			delete[] arr;
			arr = nullptr;
		}

		~Array()
		{
			delete[] arr;
		}

		reference operator[](int i)
		{
			if (i >= total_size || i < 0)
				throw std::out_of_range("array subscript out of range");
			if (i > used_size) {
				used_size = i + 1;
			}
			return (arr[i]);
		}


		reference at(int index)  const
		{
			if (index < 0 || index >= total_size)
				throw std::out_of_range("Index out of range");
			else
				return arr[index];
		}

		void insert_at(T ele, int pos) {
			if (used_size >= (total_size - 1)) {
				std::cout << "Array out of bounds\n";
				return;
			}
			if (pos < 0 || pos > used_size) {
				std::cout << "Invalid position\n";
				return;
			}
			for (int i = used_size; i > pos; --i) {
				arr[i] = arr[i - 1];
			}
			arr[pos] = ele;
			++used_size;
		}

		void remove_at(int pos)
		{
			if (pos < 0 || pos > used_size)
			{
				return;
			}
			for (int i = pos; i < (used_size - 1); i++)
			{
				arr[i] = arr[i + 1];
			}
			used_size--;
		}

		int linear_search(T ele)  const
		{
			for (int i = 0; i < used_size; i++)
			{
				if (arr[i] == ele)
				{
					return i;
				}
			}
			return -1;
		}

		int binary_search(T ele, int s, int e)  const
		{
			int mid;
			while (s <= e)
			{

				mid = int((s + e) / 2);
				if (arr[mid] == ele)
				{
					// std::cout<<"duh";
					return mid;
				}
				else if (arr[mid] > ele)
				{
					e = mid - 1;
				}
				else
				{
					s = mid + 1;
				}
			}
			return -1;
		}

		Iterator begin()  noexcept
		{
			return Iterator(arr);
		}

		Iterator end() noexcept {
			return Iterator(arr + used_size);
		}

		reference front() noexcept {
			return arr[0];
		}
		reference back()  noexcept {
			return arr[used_size - 1];
		}

		pointer data()  noexcept
		{
			return arr;
		}
	};
}
#endif