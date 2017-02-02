#ifndef ADDER_H
#define ADDER_H

#include <string>

#include "binopsbase.h"

class Adder: public BinopsBase<Adder, '+'>
{
	friend BinopsBase<Adder, '+'>;
	
	std::string d_value;
	
	public:
		Adder &operator=(std::string const &rhs);
		std::string const &value() const;
	
	private:
		void add(Adder const &rhs);
};

#endif
