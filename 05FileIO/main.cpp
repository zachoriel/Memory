#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::fstream;

using std::string;

// WALKTHROUGH
int main()
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

}

// CLOSED
// Digital Printer
int main()
{
	cout << "Hello! What file would you like to read?" << endl;
	int(fileInput);
	cin >> fileInput;
	if (fileInput == famousLines.txt)
	{

	}

	fstream file;

	file.open("famousLines.txt");

	if (file.fail())
	{
		cout << "That file does not exist, please choose a new file path to open." << endl;
		return -1;
	}

	string buffer;
	while (getline(file, buffer)) 
	{
		cout << buffer << endl;
	}

	file.clear(); 
	file.close();

	while (true) {}


	// Load Entity Data
	
}