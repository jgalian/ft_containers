#ifndef STACK_HPP
# define STACK_HPP

# include <cstddef>
# include "../Vector/vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T 			value_type;
			typedef Container 	container_type;
			typedef	size_t 		size_type;

		protected:
			container_type _c;

		public:

		/////////////////////////     Constructors      /////////////////////////////////

			explicit stack(const container_type& ctnr = container_type()) :
				_c(ctnr)
			{}

			stack(const stack<T, Container>& src) :
				_c(src._c)
			{}


		/////////////////////////     Destructor      //////////////////////////////////

			~stack()
			{}


		///////////////////////     Operator= overload      ///////////////////////////

			stack<T, Container>& operator= (const stack<T, Container>& src)
			{
				this->_c = src._c;
				return (*this);
			}


		///////////////////////     Member functions      ///////////////////////////

			bool empty() const
			{
				return (this->_c.empty());
			}

			size_type size() const
			{
				return (this->_c.size());
			}

			value_type& top()
			{
				return (this->_c.back());
			}

			const value_type& top() const
			{
				return (this->_c.back());
			}

			void push(const value_type& val)
			{
				this->_c.push_back(val);
			}

			void pop()
			{
				this->_c.pop_back();
			}


		///////////   Friend declaration for nom member function overloads   ///////////

			template <class U, class Cont>
			friend bool	operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

			template <class U, class Cont>
			friend bool	operator!= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

			template <class U, class Cont>
			friend bool	operator<  (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

			template <class U, class Cont>
			friend bool	operator<= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

			template <class U, class Cont>
			friend bool	operator>  (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

			template <class U, class Cont>
			friend bool	operator>= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);

	};


	/////////////////////     Non member function overloads      /////////////////////////

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c == rhs._c);
	}

	template <class T, class Container>
	bool	operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c != rhs._c);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c < rhs._c);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c <= rhs._c);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c > rhs._c);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._c >= rhs._c);
	}

}

#endif
