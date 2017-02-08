#ifndef MAIN_H
#define MAIN_H

template <size_t constant, size_t mask, size_t power>
struct PrintBin
{
	enum { value = power * ((constant & mask) == mask) +
		PrintBin<constant, mask << 1,
			power * 10>::value };
};

template <size_t constant, size_t power>
struct PrintBin<constant, 0, power>
{
	enum { value = 0 };
};

template <size_t constant>
struct Bin
{
	enum { value = PrintBin<constant, 1, 1>::value };
};

#endif
