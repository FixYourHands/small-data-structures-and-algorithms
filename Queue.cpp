#include <iostream>
#include <string>
#include <vector>


void ignoreInput()
{
	std::cout << "Bad input!\n";
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
class Queue
{
	size_t arraySize;
	int array[5];
	int rear;
	int front;
	int menuSelector;
	
public:
	Queue()
	{
		rear = -1;
		front = -1;
		menuSelector = 0;
		arraySize = 5;
		for (size_t i = 0; i < arraySize; i++)
		{
			array[i] = 0;
		}
	}
	Queue(int x)
	{
		rear = -1;
		front = -1;
		menuSelector = 0;
		arraySize = 5;
		for (size_t i = 0; i < arraySize; i++)
		{
			array[i] = x;
		}
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		return false;
	}
	bool isFull()
	{
		if (rear == arraySize-1)
		{
			return true;
		}
		return false;
	}
	void enqueue(int input)
	{
		if (isFull())
		{
			std::cout << "Queue is full!\n";
			return;
		}
		else if (isEmpty())
		{
			rear = 0;
			front = 0;
		}
		else
		{
			rear++;
		}
		array[rear] = input;
	}
	int getValue(int index)
	{
		if (index > arraySize - 1)
		{
			std::cout << "Queue does not have that many elements!\n";
			return 0;
		}
		else if (index > rear)
		{
			std::cout << "Index " << index << " is empty! \n";
			return 0;
		}
		return array[index];
	}
	int getFront()
	{
		if (isEmpty())
		{
			std::cout << "Queue is empty!\n";
			return 0;
		}
		return array[front];
	}

	int dequeue() //removes one from queue
	{
		if (isEmpty())
		{
			return 0;
		}
		else if (rear == front) //if there is only one number in queue
		{
			int temp = array[rear];
			array[rear] = 0;
			rear--;
			front--;
			return temp;
		}
		else 
		{
			int temp = array[front];
			for (size_t i = 0; i < rear+1; i++)
			{
				
				if (i == 0)
				{
					array[i] = array[i + 1];
					continue;
				}
				else
				{
					array[i - 1] = array[i];
				}
				
			}
			array[rear] = 0;
			rear--;
			return temp;
		}
	}
	void DisplayAll()
	{
		for (size_t i = 0; i < arraySize; i++)
		{
			std::cout << array[i] << ' ';
		}
		std::cout << '\n';
	}
	int getCount() const //return number of items in queue
	{
		return rear + 1;
	}

	static void DisplayOptions() 
	{
		std::cout << "\n\n What operation do you want to perform? Select Option number. Press 0 to exit\n";
		std::cout << "1. Enqueue()\n";
		std::cout << "2. Dequeue()\n";
		std::cout << "3. isEmpty()\n";
		std::cout << "4. isFull()\n";
		std::cout << "5. Count()\n";
		std::cout << "6. getFront()\n";
		std::cout << "7. Display Queue\n";
		std::cout << "8. Clear Screen\n";
		std::cout << "9. Display Options\n";
		std::cout << "0. Exit\n";
	}

	void Controller()
	{
		int inputValue = 0;
		do
		{
			std::cout << "What operation would you like to perform? ";
			
			if (std::cin >> menuSelector)
			{

			}
			else
			{
				ignoreInput();
			}
			switch (menuSelector)
			{
			case 1:
				std::cout << "What value would you like to enqueue? ";
				if (std::cin >> inputValue)
				{
					enqueue(inputValue);
					break;
				}
				else
					ignoreInput();
				break;
			case 2:
				std::cout << "Dequeuing!\n";
				dequeue();
				break;
			case 3:
				if (isEmpty())
					std::cout << "Queue is empty!\n";
				else
					std::cout << "Queue is not empty!\n";
				break;
			case 4:
				if (isFull())
					std::cout << "Queue is full!\n";
				else
					std::cout << "Queue is not full!\n";
				break;
			case 5:
				std::cout << "The total number of items is: " << getCount() << "!\n";
				break;
			case 6:
				std::cout << "The next value to be queued is: " << getFront() << "!\n";
				break;
			case 7:
				DisplayAll();
				break;
			case 8:
				system("cls");
				break;
			case 9:
				DisplayOptions();
				break;
			case 0:
				std::cout << "Exiting program!\n";
				break;
			default:
				std::cout << "Please enter a valid option!\n";
				break;
			}
			
		} while (menuSelector != 0);
	}
};


int main()
{
	Queue q1;
	std::cout << q1.getCount() << '\n';
	Queue::DisplayOptions();
	q1.Controller();
	system("PAUSE");
	
	return 0;
}