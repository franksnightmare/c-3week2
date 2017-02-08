#ifndef TYPE_H
#define TYPE_H

#include <iostream>

using namespace std;

// TYPEIDX LOOPER
// Generic case: no Needle found
template <typename Needle, size_t index, 
    typename Other, typename ...Stack>
class TypeIdx
{
	public:
		enum { result = TypeIdx<Needle, index + 1,
			Stack...>::located };
		enum { located = (result == 0 ? 0 : result)};
};

// Exit case: Needle found
template <typename Needle, size_t index, 
    typename ...Stack>
class TypeIdx<Needle, index, Needle, Stack...>
{
	public:
		enum { located = index + 1 };
};

// Exit case: No more hay
template <typename Needle, size_t index, 
    typename Other>
class TypeIdx<Needle, index, Other>
{
	public:
		enum { located = 0 };
};

// Exit case: No more hay + Needle found
// Disambiguates between "Needle found" and
//  "no more hay"
template <typename Needle, size_t index>
class TypeIdx<Needle, index, Needle>
{
	public:
		enum { located = index + 1 };
};

// TYPE STARTER
// Starter for TypeIdx and looping
template <typename Needle, typename ...Stack>
class Type
{
	public:
		enum { located =
			TypeIdx<Needle, 0, Stack...>::located };
};

// Empty stack specialization because TypeIdx
//  requires at least one item in the stack
template <typename Needle>
class Type<Needle>
{
	public:
		enum { located = 0 };
};

#endif
