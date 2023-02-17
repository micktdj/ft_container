#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace	ft
{
	template <class T, class Allocator = std::allocator<T>>
	class Vector {

	public:

		//	Default constructors/destructor
		explicit Vector(T::allocator);
		
		explicit Vector(int nb, int value, T::allocator)
			:_length(nb),
			_capacity(nb + 5),
			_arr(new int[_capacity])
		{
			for (int i = 0; i < _length, i++)
				_arr[i] = value;
		}

		explicit Vector(iterator::begin, iterator::end, T::allocator);
		
		~Vector(void)
		{
			delete[] _arr;
		}

		//	Accessors
		int	getLength(void) const
		{
			return (_length);
		}

		int	getCapacity(void) const
		{
			return (_capacity);
		}

		//	Usefull
		bool	empty() const
		{
			return (_length == 0);
		}

		void	push_back(int value)
		{
			if (_length < _capacity)
			{
				_arr[_length] = value;
				++_length;
			}
			else
			{
				_capacity *= 2;
				int *newarray = new int[capacity];
				for (int i = 0; i < _length; i++)
					newarray[i] = _arr[i];
				newarray[_length] = value;
				++_length;
				delete [] _arr;
				_arr = newarray;
			}
		}

		void	pop_back()
		{
			if (_length == 0)
				throw std::exception("Pop back an empty vector !")
			--_length;
		}

	private:

	// arr is the integer pointer which stores the address of our vector
	T*	_arr;
 
	// length is the number of elements currently present in the vector
	int	_length;
 
	// capacity is the total storage capacity of the vector
	int	_capacity;

	};

}

#endif
