#include <iostream>
#include <cmath>
#include <ctime>
#include <Windows.h>

class Game
{
public:

	unsigned long long value;
	unsigned int length;
	unsigned int* number;

	Game(unsigned long long value)
	{
		this->value = value;

		unsigned int length = 1;
		while ((value / 10) != 0)
		{
			value /= 10;
			length++;
		}
		this->length = length;

		value = this->value;
		this->number = new unsigned int[length];

		for (; length > 0;)
		{
			number[--length] = value % 10;
			value /= 10;
		}
	}

	int HowMuchCows(Game& number)
	{
		if (this->length != number.length) return -1;

		unsigned int cows = 0;

		for (unsigned int i = 0; i < this->length; i++)
		{
			for (unsigned int j = 0; j < this->length; j++)
			{
				if (i == j) continue;
				if (this->number[i] == number.number[j]) cows++;
			}
		}

		return cows;
	}

	int HowMuchBulls(Game& number)
	{
		if (this->length != number.length) return -1;

		unsigned int bulls = 0;

		for (unsigned int i = 0; i < this->length; i++)
		{
			if (this->number[i] == number.number[i]) bulls++;
		}

		return bulls;
	}

	Game& operator=(Game& another_number)
	{
		this->value = another_number.value;
		this->length = another_number.length;
		for (unsigned int i = 0; i < this->length; i++)
		{
			this->number[i] = another_number.number[i];
		}

		return *this;
	}
};

unsigned int generate_num(unsigned int n)
{
	unsigned long long begin = pow(10, --n);
	unsigned long long end = begin * 10;

	return ((long long)rand() % (end - begin)) + begin;
}

bool is_repeated(unsigned int*& digits, unsigned int length)
{
	for (unsigned int i = 0; i < length; i++)
	{
		for (unsigned int j = i + 1; j < length; j++)
		{
			if (digits[i] == digits[j]) return true;
		}
	}

	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	unsigned int n;
	std::cout << "Введите длину загадаваемого числа:\n";
	std::cin >> n;
	std::cout << "Число сгенерировано, игра началась\n" ;

	Game comp_num(generate_num(n));

	while (is_repeated(comp_num.number, n))
	{
		Game loc(generate_num(n));
		comp_num = loc;
	}

	unsigned int cur_guess;
	int cows;
	int bulls;
	while (true)
	{
		std::cin >> cur_guess;

		if (cur_guess == comp_num.value)
		{
			std::cout << "Óãàäàíî " << std::endl;
			system("pause");
			break;
		}

		Game cur_game_num(cur_guess);
		cows = comp_num.HowMuchCows(cur_game_num);
		bulls = comp_num.HowMuchBulls(cur_game_num);
		if ((cows < 0) || (bulls < 0)) std::cerr << "íåâåðíîå êîëè÷åñòâî ðàçðÿäîâ, äîëæíî áûòü:" << n << std::endl;
		else
		{
			std::cout << "Óãàäàíî: " << cows << " êîðîâ, " << bulls << " áûêîâ" << std::endl;
		}
	}

	return 0;
}
