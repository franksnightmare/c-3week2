#ifndef BINOPSBASE_H
#define BINOPSBASE_H

template <typename Derived, int ...operators>
class BinopsBase
{
	friend Derived &operator+(Derived &lhs, Derived const &rhs);
	friend Derived &operator*(Derived &lhs, Derived const &rhs);
	
	void addWrap(Derived const &rhs)
	{
		Derived::add(rhs);
	}
	
	void mulWrap(Derived const &rhs)
	{
		Derived::mul(rhs);
	}
};

#endif
