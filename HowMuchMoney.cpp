#include <iostream>
#include <vector>
#include <unordered_map>



struct Person
{
	std::unordered_map<int, double> money;
	Person(int amountOfTwenties,int amountOfTens, int amountOfFives, int amountOfOnes)
	{
		money[20] = amountOfTwenties;
		money[5] = amountOfFives;
		money[10] = amountOfTens;
		money[1] = amountOfOnes;
	}

	int getTwenties()
	{
		return money.find(20)->second;
	}
	int getTens()
	{
		return money.find(10)->second;
	}
	int getFives()
	{
		return money.find(5)->second;
	}
	int getOnes()
	{
		return money.find(1)->second;
	}

	void subtractMoney(int currency)
	{
		if (currency == 20)
		{
			--money.find(20)->second;
		}
		else if (currency == 10)
		{
			--money.find(10)->second;
		}
		else if (currency == 5)
		{
			--money.find(5)->second;
		}
		else if (currency == 1)
		{
			--money.find(1)->second;
		}
	}

	void DisplayMoney()
	{
		std::cout << "Twenties remaining: " << money[20] << '\n';
		std::cout << "Tens remaining: " << money[10] << '\n';
		std::cout << "Fives remaining: " << money[5] << '\n';
		std::cout << "Ones remaining: " << money[1] << "\n\n";
		std::cout << "Total amount: " << totalAmount() << "!\n\n";
	}

	double totalAmount()
	{
		double netWorth = money[20] * 20;
		netWorth += money[10] * 10;
		netWorth += money[5] * 5;
		netWorth += money[1] * 1;
		return netWorth;
	}
};

void howMuch(Person& obj, double& targetVal)
{
	while (targetVal > 0)
	{
		//if targetVal is more than 20 and the person has twenties 
		if (targetVal >= 20 && obj.getTwenties() > 0)
		{
			obj.subtractMoney(20);
			targetVal -= 20;
		}
		//if targetVal is more than 10 and the person has tens 
		else if (targetVal >= 10 && obj.getTens() > 0)
		{
			obj.subtractMoney(10);
			targetVal -= 10;
		}
		//if targetVal is more than 5 and the person has fives 
		else if (targetVal >= 5 && obj.getFives() > 0)
		{
			obj.subtractMoney(5);
			targetVal -= 5;
		}
		else if (targetVal >= 1 && obj.getOnes() > 0)
		{
			obj.subtractMoney(1);
			targetVal -= 1;
		}
	}
}

int main()
{0
	std::cout << "Bob has the current amount of money on him...\n\n";
	Person Bob(10,10,10,10);
	Bob.DisplayMoney();

	std::cout << "How much would you like to borrow? Type an amount! ";
	double target;
	std::cin >> target;
	howMuch(Bob, target);
	Bob.DisplayMoney();
}