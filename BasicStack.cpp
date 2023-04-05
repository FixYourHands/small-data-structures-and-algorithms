#include <iostream>



void voidInput()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Stack {
private:
	int arr[5];
	int arrSize;
	int top;
public:
	Stack()
	{
		top = -1;
		arrSize = sizeof(arr) / sizeof(arr[0]);
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = 0;
		}
	}
	void push(const int& x) //adds element to the top of the stack
	{
		if (isfull()) //dont add element if stack is full
		{
			std::cout << "STACK OVERFLOW\n";
		}

		else
		{
			std::cout << "Pushing value " << x << " to the top of the stack.\n";
			top++;
			arr[top] = x;
		}
	}
	int pop() //returns value at top of stack and then removes it
	{
		if (isEmpty())
		{
			std::cout << "STACK UNDERFLOW\n"; //cant remove element if stack is empty
			return 0;
		}
		const int popValue = arr[top];
		arr[top] = NULL; //set top value to NULL
		top--;
		return popValue;
	}

	bool isEmpty() //checks if stack is empty
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isfull() //checks if stack is full
	{
		if (top == arrSize - 1)
			return true;
		else
			return false;
	}

	int peek(const int& i) //access value at i position
	{
		if (isEmpty()) //stop function is stack is empty
		{
			std::cout << "STACK UNDERFLOW\n";
			return 0;
		}
		if (i > top && i < arrSize) //checks for empty index, with valid bounds
		{
			std::cout << "Index " << i << " is empty!\n";
			return 0;
		}
		if (i >= arrSize || i < 0) //checks for index thats out of bounds
		{
			std::cout << "Index " << i << " is an invalid index!\n";
			return 0;
		}
		return arr[i];
	}

	int count() //returns number of values in stack
	{
		return top + 1;
	}

	void change(int index, int newValue) //change value at selected index
	{
		if (index > arrSize - 1 || index < 0)
			std::cout << "INVALID! Index is out of bounds!\n";
		else if (index >= top + 1 || top == -1)
			std::cout << "INVALID! The stack is not that high!\n";
		else if (index >= 0 && index < arrSize)
		{
			int oldValue = arr[index];
			std::cout << "Value changed at index: " << index << ", from " << oldValue << " to " << newValue << '\n';
			arr[index] = newValue;
		}

		else
			std::cout << "Please choose a valid index!\n";
	}

	void Display() //displays everything in stack
	{
		for (int i = arrSize - 1; i >= 0; --i)
		{
			std::cout << "Element " << i << " is " << arr[i] << '\n';
		}
	}

	static void DisplayOptions()
	{
		std::cout << "What operation would you like to perform?\n";
		std::cout << "1. Push()\n";
		std::cout << "2. Pop()\n";
		std::cout << "3. isEmpty()\n";
		std::cout << "4. isFull()\n";
		std::cout << "5. Peek()\n";
		std::cout << "6. Count()\n";
		std::cout << "7. Change()\n";
		std::cout << "8. Display()\n";
		std::cout << "9. Clear Screen\n";
		std::cout << "0. Exit\n";
	}
};


int main()
{
	Stack stack1;
	int optionMenu = 1;
	int index = 0;

	do
	{
		Stack::DisplayOptions();
		std::cin >> optionMenu;
		switch (optionMenu) {
		case 1:
			std::cout << "What value would you like to push? ";
			int pushValue;
			std::cin >> pushValue;
			stack1.push(pushValue);
			break;
		case 2:
			stack1.pop();
			break;
		case 3:
			if (stack1.isEmpty())
			{
				std::cout << "The stack is empty!\n";
			}
			else
			{
				std::cout << "The stack is not empty!\n";
			}
			break;
		case 4:
			if (stack1.isfull())
			{
				std::cout << "The stack is full!\n";
			}
			else
			{
				std::cout << "The stack is not full!\n";
			}
			break;
		case 5:
			std::cout << "What index would you like to peek? ";
			std::cin >> index;
			std::cout << "The value at index " << index << " is " << stack1.peek(index);
			break;
		case 6:
			std::cout << "The stack has " << stack1.count() << " elements!\n";
			break;
		case 7:
			int value;
			std::cout << "What index do you want to change? ";
			std::cin >> index;
			voidInput();
			std::cout << "What value would you like to change it to? ";
			std::cin >> value;
			stack1.change(index, value);
			break;
		case 8:
			stack1.Display();
			break;
		case 9:
			system("cls");
			break;
		case 0:
			std::cout << "Exiting program!\n";
			break;

		}
		std::cout << '\n' << '\n';
	} while (optionMenu != 0);



}