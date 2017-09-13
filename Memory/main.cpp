#include <iostream>
using namespace std;

int sum(int * numA, int * numB)
{
	return *numA + *numB;
}

void arrPop(int * arr, int size)
{
	for (int i = 0; i < 100; ++i)
	{
		arr[i] = (i + 1) * 3;
	}
}

void arrPrint(int * arr, int size)
{
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = (i + 1);
	}
}

// WALKTHROUGH
/* int main()
{
// Working with pointers
// Working with Heap-Allocation Memory
int age = 13;               // Stack data

cout << age << endl;

int * agePtr = new int(22); // Heap data

cout << agePtr << endl;     // Won't work as intended, agePtr is the memory address
cout << *agePtr << endl;    // Will work as intended. Be sure to remember the *

int * ageAlias = &age;      // Replaces Stack variable with Heap variable (age ---> ageAlias)

*ageAlias = 48;             // What we want to replace Stack variable with

cout << age << endl;
cout << *ageAlias << endl;

// Pointers as Parameters
int result = sum(agePtr, ageAlias);
cout << result << endl;

delete agePtr;              // DEALLOCATE AGE

while (true) {} // keep open
} */

int main()
{
	// CLOSED
	// Heap allocated numbers
	int * wholeNum = new int(1);
	float * wholeFlt = new float(1.0f);
	bool * aBool = new bool(true);

	int * wholeNums = new int[5];
	float * wholeFlts = new float[5];
	bool * theBooleans = new bool[5];

	delete wholeNum;
	delete wholeFlt;
	delete aBool;

	delete[] wholeNums;
	delete[] wholeFlts;
	delete[] theBooleans;

	// Subtracting heap allocated numers
	int * a = new int(5);
	int * b = new int(1);

	int res = diff(a, b);
	cout << res << endl;

	delete a;
	delete b;

	// Heap allocated integer array
	int * numbers = new int[100];

	for (int i = 0; i < 100; ++i)
	{
		numbers[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		cout << numbers[i] << endl;
	}

	// OPEN
	// Populating an array from 1 to X (function)
	int * nummz = new int[100];

	arrPop(nummz, 100);

	for (int i = 0; i < 100; ++i)
	{
		cout << nummz[i] << endl;
	}

	int * singleNum = new int;

	arrPop(singleNum, 1);

	cout << *singleNum << endl;

	// Printing a heap-allocated integer array
	int * wholeNumbs = new int[12];

	for (int i = 0; i < 12; ++i)
	{
		wholeNumbs[i] = i + 1;
	}

	for (int i = 0; i < 12; ++i)
	{
		cout << wholeNumbs[i] << endl;
	}

	// Heap-allocated array of numbers

	cout << "Hello! How many?" << endl;
	int qty = 0;

	cin >> qty;
	int * inputs = new int[qty];

	for (int i = 0; i < qty; ++i)
	{
		cout << "What is " << i + 1 << "?" << endl;
		int input = -1;
		cin >> input;

		inputs[i] = input;
	}

	int evens = 0;

	// determine how many odds vs evens
	for (int i = 0; i < qty; ++i)
	{
		if (inputs[i] % 2 == 0) { evens++; }
	}

	int odds = qty - evens;

	if (evens > odds)
	{
		cout << "You really like even numbers" << endl;
	}
	else if (odds > evens)
	{
		cout << "You really like odd numbers" << endl;
	}
	else
	{
		cout << "You have no preference between odd and even numbers" << endl;
	}


	// Adding up to 21
	cout << "How many?" << endl;

	int count = 0;
	cin >> count;

	int * numberz = new int[count];

	for (int i = 0; i < count; ++i)
	{
		cout << "Okay, what's the number" << i + 1 << "?" << endl;

		int userInput = 0;
		cin >> userInput;

		numberz[i] = userInput;
	}

	int total = 0;
	for (int i = 0; i < count; ++i)
	{
		total += numberz[i];
	}

	if (total == 21) { cout << "Hooray! You can add correctly!" << endl; }
	else { cout << "You don't seem to be able to add correctly." << endl; }

	delete[] nummz;
	delete singleNum;
	delete[] inputs;
	delete[] numberz;
}

