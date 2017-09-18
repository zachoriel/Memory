#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::fstream;

using std::string;

// My Information
void main2()
{
	string inputBuffer;

	cout << "Where would you like to save this?" << endl;
	cin >> inputBuffer;

	fstream profileData;
	profileData.open(inputBuffer.c_str(), ios_base::out);

	if (profileData.fail())
	{
		cout << "Sorry, it can't be saved there." << endl;
		return;
	}

	cin.ignore(1000, '\n');
	cout << "Who are you?" << endl;
	getline(cin, inputBuffer);
	profileData << inputBuffer << endl;

	cin.ignore(1000, '\n');
	cout << "How old are you?" << endl;
	getline(cin, inputBuffer);
	profileData << inputBuffer << endl;

	cin.ignore(1000, '\n');
	cout << "What's your favorite color?" << endl;
	getline(cin, inputBuffer);
	profileData << inputBuffer << endl;

	profileData.flush();
	profileData.close();

	cout << "Thanks!" << endl;
}

// WALKTHROUGH
/*int main()
{
	fstream file;

	file.open("text.txt");

	if (file.fail())
	{
		cout << "File not found." << endl;
		return -1;
	}

	// Reading from a File
	string buffer;
	while (getline(file, buffer))  // While used for unknown #s of iterations
	{
		// print the line!
		cout << buffer << endl;
	}

	file.clear();  // Reset the error flags, including EOF (end of file)

	file.seekp(0, ios_base::end);  // Move my cursor to the end

	// Writing to a File
	// Write a message!
	file << endl << "Today is always the present! :)";

	file.flush();  // Dump everything, comes before close
	file.close();

	// Let's make another thing!

	fstream autoCreate;

	autoCreate.open("createme.txt", ios::out | ios::in);

	if (autoCreate.fail())
	{
		cout << "Something went wrong." << endl;
		return -1;
	}

	autoCreate.close();

	while (true) {}

}*/

// CLOSED
// Digital Printer
int main()
{
	cout << "DIGITAL PRINTER" << endl;
	while (true)
	{
		cout << "What file would you like to open?" << endl;
		string inputBuffer;

		cin >> inputBuffer;
		fstream printer;

		printer.open(inputBuffer);
		if (printer.fail())
		{
			cout << "The file you have requested cannot be found." << endl;
			continue;
		}

		string fileContents;
		while (getline(printer, fileContents))
		{
			cout << fileContents;
		}

		file.close;
	}

	while (true) {}

	//2
	main2();

	fstream entityStream;
	entityStream.open("monsters.txt");

	if (entityStream.fail())
	{
		cout << "Can't open file" << endl;
	}

	int entityCount = 0;
	Entity entities[100];

	while (true)
	{
		string buf;
		bool entityFound = false;

		// seek to the next entity
		while (getline(entityStream, buf))
		{
			if (buf[0] == '@')
			{
				entityFound = true;
				break;
			}
		}

		// exit if no entity found
		if (!entityFound) { break; }
		

		// Load data into the array of entities
		Entity& curEntity = entities[entityCount];

		getline(entityStream, buf);
		curEntity.hitpoints = stof(buf);
		getline(entityStream, buf);
		curEntity.armor = stof(buf);
		getline(entityStream, buf);
		curEntity.strength = stof(buf);
		getline(entityStream, buf);
		curEntity.defense = stof(buf);
		getline(entityStream, buf);
		curEntity.agility = stof(buf);
		getline(entityStream, buf);
		curEntity.luck = stof(buf);
	}

	while (true) {}
}