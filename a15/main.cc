#include "main.ih"

int main(int argc, char **argv)
{
	Arithmetic<int> jart;
	Arithmetic<double> dart;
	//Arithmetic<size_t> illegal;
	
	jart = 10;
	dart = 10;
	//illegal = 10;
	
	Arithmetic<double> dart2(dart);
	dart = 13;
	
	cout << jart.value() << '\n';
	cout << dart.value() << '\n';
	cout << dart2.value() << '\n';
}
