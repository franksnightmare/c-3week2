#ifndef TYPE_H
#define TYPE_H

#include <iostream>

using namespace std;

template <typename Needle, size_t index, typename Other, typename ...Stack>
class TypeIdx : public TypeIdx<Needle, index + 1, Stack...>
{};

template <typename Needle, size_t index, typename ...Stack>
class TypeIdx<Needle, index, Needle, Stack...>
{
	public:
		enum { located = index + 1 };
};

template <typename Needle, size_t index>
class TypeIdx<Needle, index, Needle>
{
	public:
		enum { located = index + 1};
};

template <typename Needle, size_t index, typename Other>
class TypeIdx<Needle, index, Other>
{
	public:
		enum { located = 0 };
};

template <typename Needle, typename ...Stack>
class Type : public TypeIdx<Needle, 0, Stack...>
{};

template <typename Needle>
class Type<Needle>
{
	public:
		enum { located = 0};
};

#endif
