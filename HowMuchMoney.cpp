#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>



class Person
{
	std::unordered_map<int, int> dollarBills;
	std::unordered_map<double, int> coins;
	int billsUsed;
	int coinsUsed;
public:
	Person(int amountOfBills, int amountOfCoins)
		:billsUsed(0),coinsUsed(0)
	{
		//initalize dollars
		dollarBills[20] = amountOfBills;
		dollarBills[5] = amountOfBills;
		dollarBills[10] = amountOfBills;
		dollarBills[1] = amountOfBills;

		//initialize coins
		coins[0.25] = amountOfCoins;
		coins[0.10] = amountOfCoins;
		coins[0.05] = amountOfCoins;
		coins[0.01] = amountOfCoins;
	}


	//return dollar values
	int getTwenties()
	{
		return dollarBills.find(20)->second;
	}
	int getTens()
	{
		return dollarBills.find(10)->second;
	}
	int getFives()
	{
		return dollarBills.find(5)->second;
	}
	int getOnes()
	{
		return dollarBills.find(1)->second;
	}
	int getAmountOfBillsUsed()
	{
		return billsUsed;
	}

	//return coin values
	int getQuarters()
	{
		return coins.find(.25)->second;
	}
	int getDimes()
	{
		return coins.find(.10)->second;
	}
	int getNickels()
	{
		return coins.find(.05)->second;
	}
	int getPennies()
	{
		return coins.find(.01)->second;
	}
	int getBillsUsed()
	{
		return billsUsed;
	}
	int getCoinsUsed()
	{
		return coinsUsed;
	}

	void subtractMoney(int currency)
	{
		//subtracts dollar amounts
		if (currency == 20)
		{
			--dollarBills.find(20)->second;
		}
		else if (currency == 10)
		{
			--dollarBills.find(10)->second;
		}
		else if (currency == 5)
		{
			--dollarBills.find(5)->second;
		}
		else if (currency == 1)
		{
			--dollarBills.find(1)->second;
		}
	}

	void subtractMoney(double currency) //function overloading for double parameters (coins)
	{
		//subtracts coin amounts
		if (currency == .25)
		{
			--coins.find(.25)->second;
		}
		else if (currency == .10)
		{
			--coins.find(.10)->second;
		}
		else if (currency == .05)
		{
			--coins.find(.05)->second;
		}
		else if (currency == .01)
		{
			--coins.find(.01)->second;
		}
	}

	void transactionOccured(int type) //increases
	{
		if (type == 0)
		billsUsed++;
		if (type == 1)
		{
			coinsUsed++;
		}
	}

	void DisplayMoney()
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Twenties remaining: " << dollarBills[20] << '\n';
		std::cout << "Tens remaining: " << dollarBills[10] << '\n';
		std::cout << "Fives remaining: " << dollarBills[5] << '\n';
		std::cout << "Ones remaining: " << dollarBills[1] << "\n\n";

		std::cout << "Quarters remaining: " << coins[.25f] << '\n';
		std::cout << "Dimes remaining: " << coins[.10f] << '\n';
		std::cout << "Nickels remaining: " << coins[.05f] << '\n';
		std::cout << "Pennies remaining: " << coins[.01f] << "\n\n";

		std::cout << "Total amount: " << totalAmount() << "!\n\n";
		std::cout << billsUsed << " dollar transactions!\n";
		std::cout << coinsUsed << " coin transactions!\n";
	}

	double totalAmount()
	{
		double netWorth = dollarBills[20] * 20;
		netWorth += dollarBills[10] * 10;
		netWorth += dollarBills[5] * 5;
		netWorth += dollarBills[1] * 1;

		netWorth += coins[.25] * .25;
		netWorth += coins[.10] * .10;
		netWorth += coins[.05] * .05;
		netWorth += coins[.01] * .01;
		return netWorth;
	}
};

void tradeMoney(Person& obj, float& targetVal)
{
	int pennycounter = 0;
	//traverses until dollars are exhausted
	while (targetVal >= 0.01)
	{
		//if targetVal is more than 20 and the person has twenties 
		if (targetVal >= 20 && obj.getTwenties() > 0)
		{
			obj.subtractMoney(20);
			obj.transactionOccured(0);
			targetVal -= 20;
		}
		//if targetVal is more than 10 and the person has tens 
		else if (targetVal >= 10 && obj.getTens() > 0)
		{
			obj.subtractMoney(10);
			obj.transactionOccured(0);
			targetVal -= 10;
		}
		//if targetVal is more than 5 and the person has fives 
		else if (targetVal >= 5 && obj.getFives() > 0)
		{
			obj.subtractMoney(5);
			obj.transactionOccured(0);
			targetVal -= 5;
		}
		//if targetVal is more than 1 and the person has ones 
		else if (targetVal >= 1 && obj.getOnes() > 0)
		{
			obj.subtractMoney(1);
			obj.transactionOccured(0);
			targetVal -= 1;
		}

		//traverses until coins are exhausted
		//if targetVal is more than .25 and the person has quarters 
		else if (targetVal >= .25 && obj.getQuarters() > 0)
		{
			obj.subtractMoney(.25);
			obj.transactionOccured(1);
			targetVal -= .25;
		}
		//if targetVal is more than .10 and the person has dimes 
		else if (targetVal >= .10 && obj.getDimes() > 0)
		{
			obj.subtractMoney(.10);
			obj.transactionOccured(1);
			targetVal -= .10;
		}
		//if targetVal is more than .05 and the person has nickels 
		else if (targetVal >= .05 && obj.getNickels() > 0)
		{
			obj.subtractMoney(.05);
			obj.transactionOccured(1);
			targetVal -= .05;
		}
		//if targetVal is more than .01 and the person has pennies 
		else if (targetVal >= .01 && obj.getPennies() > 0)
		{
			obj.subtractMoney(.01);
			obj.transactionOccured(1);
			targetVal -= .01;
			pennycounter++;
			if (pennycounter == 10)
			{
				break;
			}
		}
	}

}


int main()
{
	std::cout << "Bob has the current amount of money on him...\n\n";
	Person Bob(10,10);
	Bob.DisplayMoney();

	std::cout << "How much would you like to borrow? Type an amount! ";
	float target;
	std::cin >> target;
	tradeMoney(Bob, target);
	Bob.DisplayMoney();
}