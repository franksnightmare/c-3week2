#ifndef BINOPSBASE_H
#define BINOPSBASE_H

#include "operations.h"

template <typename Binops, 
    typename Derived, int ...operators>
class BinopsBase0
{};

template <typename Binops, typename Derived>
class BinopsBase0<Binops, Derived, 0>
{};

template <typename Derived, int ...operators>
class BinopsBase : public BinopsBase0<BinopsBase<
    Derived, operators...>, Derived, operators...>
{
	friend Derived &operator+(Derived &lhs, 
	    Derived const &rhs);
	friend Derived &operator*(Derived &lhs, 
	    Derived const &rhs);
	
	friend Add<BinopsBase<Derived, operators...>, 
	    Derived>;
	friend Mul<BinopsBase<Derived, operators...>, 
	    Derived>;
	
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
