
#include <iostream>

using namespace std;

class Heart
{

	int bloodLiters;

public:
	Heart(int bloodLiters)
	{

		this->bloodLiters = bloodLiters;
		cout << "I am pumping " << bloodLiters << " Liters of blood\n";
	}

	~Heart()
	{
		cout << "I stopped pumping blood\n";
	}
};

class Kidney
{

public:
	Kidney()
	{
		cout << "I am a Kidney i am working\n";
	}
};

/**
 *
 * Human Body is Compsed of a Kidney and a Heart.
 * when God creates a human, he creates the heart and kidney first.
 *
 */
class Human
{

public:
	Kidney kid;

	Heart heart;

	Human() : heart(3)
	{
		cout << "I am alive\n";
	}

	~Human()
	{
		cout << "I died\n";
	}
};

int main()
{

	Human Menna;

	return 0;
}
