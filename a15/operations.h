#ifndef OPERATIONS_H
#define OPERATIONS_H

template <typename Base, typename Derived>
class Add
{
	public:
		/*
		Derived &operator+=(Derived &&lhs, Derived const &rhs)
		{
			Base::addWrap(lhs, rhs);
			return std::move(lhs);
		}
		Derived &operator+=(Derived &lhs, Derived const &rhs)
		{
			Base::addWrap(lhs, rhs);
			return lhs;
		}
		Derived &operator+(Derived &&lhs, Derived const &rhs)
		{
			Base::addWrap(lhs, rhs);
			return std::move(lhs);
		}
		Derived &operator+(Derived const &lhs, Derived const &rhs)
		{
			Derived temp(lhs);
			Base::addWrap(temp, rhs);
			return temp;
		}
		*/
		Derived &operator+=(Derived const &rhs)
		{
			Base::addWrap(*this, rhs);
			return *this;
		}
		Derived &operator+(Derived const &rhs)
		{
			Derived temp(*this);
			Base::addWrap(temp, rhs);
			return temp;
		}
};

template <typename Base, typename Derived>
class Mul
{
	public:
		/*
		Derived &operator*=(Derived &&lhs, Derived const &rhs)
		{
			Base::mulWrap(lhs, rhs);
			return std::move(lhs);
		}
		Derived &operator*=(Derived &lhs, Derived const &rhs)
		{
			Base::mulWrap(lhs, rhs);
			return lhs;
		}
		Derived &operator*(Derived &&lhs, Derived const &rhs)
		{
			Base::mulWrap(lhs, rhs);
			return std::move(lhs);
		}
		Derived &operator*(Derived const &lhs, Derived const &rhs)
		{
			Derived temp(lhs);
			Base::addWrap(temp, rhs);
			return temp;
		}
		*/
		Derived &operator*=(Derived const &rhs)
		{
			Base::mulWrap(*this, rhs);
			return *this;
		}
		Derived &operator*(Derived const &rhs)
		{
			Derived temp(*this);
			Base::addWrap(temp, rhs);
			return temp;
		}
};

#endif
