#ifndef CLASS_H
#define CLASS_H

class Class: public BinopsBase<Class, '*', '+'>
{
	friend BinopsBase<Class, '*', '+'>
	
	public:
	
	private:
		void mul(Class const &rhs);
		void add(Class const &rhs);
};

#endif
