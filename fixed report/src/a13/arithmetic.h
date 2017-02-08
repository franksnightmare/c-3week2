#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <cstring>
#include <string>

#include "binopsbase.h"

template <typename T>
class Arithmetic: public BinopsBase<Arithmetic<T>>
{};

template <>
class Arithmetic<int>: 
    public BinopsBase<Arithmetic<int>>
{
	friend BinopsBase<Arithmetic<int>>;
	
	int d_value = 0;
	
	public:
		Arithmetic<int>() = default;
		Arithmetic<int>(Arithmetic<int> const &rhs)
		:
			d_value(rhs.d_value)
		{}
		Arithmetic<int>(Arithmetic<int> &&rhs)
		{
			swap(rhs);
		}
		
		Arithmetic<int> &operator=(int const &rhs)
		{
			d_value = rhs;
			return *this;
		}
		
		int const &value() const
		{
			return d_value;
		}
		
		void swap(Arithmetic<int> &other)
		{
			char step[sizeof(Arithmetic<int>)];
			std::memcpy(step, this, 
			    sizeof(Arithmetic<int>));
			std::memcpy(&other, step, 
			    sizeof(Arithmetic<int>));
			std::memcpy(this, &other, 
			    sizeof(Arithmetic<int>));
		}
	
	private:
		void add(Arithmetic<int> const &rhs)
		{
			d_value += rhs.value();
		}
};

template <>
class Arithmetic<double>: 
    public BinopsBase<Arithmetic<double>>
{
	friend BinopsBase<Arithmetic<double>>;
	
	double d_value = 0;
	
	public:
		Arithmetic<double>() = default;
		Arithmetic<double>(Arithmetic<double> const &rhs)
		:
			d_value(rhs.d_value)
		{}
		Arithmetic<double>(Arithmetic<double> &&rhs)
		{
			swap(rhs);
		}
		
		Arithmetic<double> &operator=(double const &rhs)
		{
			d_value = rhs;
			return *this;
		}
		
		double const &value() const
		{
			return d_value;
		}
		
		void swap(Arithmetic<double> &other)
		{
			char step[sizeof(Arithmetic<double>)];
			std::memcpy(step, this, 
			    sizeof(Arithmetic<double>));
			std::memcpy(&other, step, 
			    sizeof(Arithmetic<double>));
			std::memcpy(this, &other, 
			    sizeof(Arithmetic<double>));
		}
	
	private:
		void add(Arithmetic<double> const &rhs)
		{
			d_value += rhs.value();
		}
};

#endif
