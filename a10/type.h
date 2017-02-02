#ifndef TYPE_H
#define TYPE_H

#include <iostream>

using namespace std;

template <typename Needle, typename ...Stack>
class Type
{
	template <size_t index, typename Other, typename ...Stacker>
	struct TypeIdx
	{
		public:
			enum {located = TypeIdx<index + 1, Stacker...>::located};
	};
	
	template <size_t index, typename ...Stacker>
	struct TypeIdx<index, Needle, Stacker...>
	{
		public:
			enum { located = index + 1 };
	};
	
	template <size_t index>
	struct TypeIdx<index, Needle>
	{
		public:
			enum { located = index + 1};
	};
	
	template <size_t index, typename Other>
	struct TypeIdx<index, Other>
	{
		public:
			enum { located = 0 };
	};
	
	public:
		enum { located = TypeIdx<0, Stack...>::located};
};

template <typename Needle>
class Type<Needle>
{
	public:
		enum { located = 0};
};

#endif
