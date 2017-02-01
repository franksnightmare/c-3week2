#ifndef BINOPSBASE_H
#define BINOPSBASE_H

#include "operations.h"

template <typename Binops, typename Derived, int op, int ...operators>
class BinopsBase0;

template <typename Binops, typename Derived>
class BinopsBase0<Binops, Derived, 0, 0>{};

template <typename Binops, typename Derived, int ...operators>
class BinopsBase0<Binops, Derived, '+', operators...> : public BinopsBase0<Binops, Derived, operators...>, public Add<Binops, Derived>{};

template <typename Binops, typename Derived, int ...operators>
class BinopsBase0<Binops, Derived, '*', operators...> : public BinopsBase0<Binops, Derived, operators...>, public Mul<Binops, Derived>{};

template <typename Derived, int ...operators>
class BinopsBase : public BinopsBase0<BinopsBase<Derived, operators...>, Derived, operators...>
{
	friend Derived &operator+(Derived &lhs, Derived const &rhs);
	friend Derived &operator*(Derived &lhs, Derived const &rhs);
	
	friend Add<BinopsBase<Derived, operators...>, Derived>;
	friend Mul<BinopsBase<Derived, operators...>, Derived>;
	
	void addWrap(Derived &lhs, Derived const &rhs)
	{
		lhs.add(rhs);
	}
	
	void mulWrap(Derived &lhs, Derived const &rhs)
	{
		lhs.add(rhs);
	}
};

#endif
