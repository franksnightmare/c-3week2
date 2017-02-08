#include <iostream>

using namespace std;

/*template <size_t constant, size_t mask, bool flag>
struct Bin<constant, mask, flag>
{};

template <size_t constant, bool flag>
struct Bin<constant, 0, flag>
{
	enum { value = 0};
};

template <size_t constant>
struct Bin<constant, -1, false>
{
	enum { value = Bin<constant, ((0-1)>>1)+1, false>::value };	
};*/

void rec(size_t value, size_t mask, bool flag)
{
	if (mask != 0)
	{	
		
		cout << static_cast<char>('0' + ((value & mask) == mask));
		mask >>= 1;
		rec(value, mask, flag); 
	}
	
}

void rec(size_t value, size_t mask)
{
	if (mask != 0)
	{	
		
		if ((value & mask) != mask)
			rec(value, mask >> 1);
		else
			rec(value, mask, true);
	}
	
}

int main()
{
	size_t value = 27;
	size_t mask = 0;
	mask -= 1;
	mask >>= 1;
	mask += 1;
	
	rec(value, mask);
	cout << '\n';
	//bool check = false;
	
	
	
	
	
	//while(mask != 0)
		//{	
			//if ((value & mask) == mask)
				//check = true;
				
			//if (check == true)	
			//	cout << ('0' + ((value & mask) == mask));
			//mask >>= 1;			
		//}
	//cout << '\n';	
}



