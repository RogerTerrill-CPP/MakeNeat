//Illustrates output formatting instructions.
//Reads all the numbers in the file rawdata.dat and writes the numbers
//to the screen and to the file neat.dat in a neatly formatted way.
#include <iostream> //Library for standard cin and cout
#include <fstream> //Library to stream input and output from file
#include <cstdlib> //Library for exit function
#include <iomanip> //Library to set the width of the number output
using namespace std;

//Prototype that calls by references the input and output streams
//As well as call by value for numbers after decimal and width of number
void make_neat(ifstream& messy_file, ofstream& neat_file, int number_after_decimalpoint, int field_width);


//Precondition: The streams messy_file and neat_file have been connected
//to files using the function open.
//Postcondition: The numbers in the file connected to messy_file have been
//written to the screen and to the file connected to the stream neat_file.
//The numbers are written one per line, in fixed-point notation (that is, not in
//e-notation), with number_after_decimalpoint digits after the decimal point;
//each number is preceded by a plus or minus sign and each number is in a field
//of width field_width. (This function does not close the file.)
int main()
{
	//Create variable fin of datatype ifstream (input file stream)
	ifstream fin;

	//Create a variable fout of datatype ofstream (output file stream)
	ofstream fout;

	//The object fin uses member function open with paramater of external name of file to access file
	fin.open("rawdata.dat");

	//Test if object fin opened successfully with fail() function that if true means a failed open attempt has occured
	if (fin.fail())
	{
		//Displays the failed message
		cout << "Input file opening failed.\n";

		//exit will end the program
		exit(1);
	}

	//Will open file neat.dat or create file if it doesn't exist
	fout.open("neat.dat");

	//Test if object fout opened successfully with fail() function that if true means a failed open attempt has occured
	if (fout.fail())
	{
		//Display a failed message if fail is true
		cout << "Output file opening failed.\n";

		//Exit function will end program
		exit(1);
	}

	//Function make_neat will attempt to run with objects fin and fout as parameters
	make_neat(fin, fout, 5, 12);

	//Close stream fin
	fin.close();

	//Close stream fout
	fout.close();

	//Display to screen the end of the program
	cout << "End of program.\n";


	return 0;
}


//Function with same parameters as prototype
void make_neat(ifstream& messy_file, ofstream& neat_file, int number_after_decimalpoint, int field_width)
{
	//Magic formula will be applied to both the onscreen display object of cout as well as the file output object of neat_file
	neat_file.setf(ios::fixed);
	neat_file.setf(ios::showpoint);
	neat_file.setf(ios::showpos);
	neat_file.precision(number_after_decimalpoint);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.precision(number_after_decimalpoint);

	//Create a variable that will temporarily take on the value of current number
	double next;

	//While there is a value to read
	while (messy_file >> next)
	{
		//Display to screen each number with each separate line with format as provided in function parameters
		cout << setw(field_width) << next << endl;

		//Output to file each number with each separate line with format as provided in function parameters
		neat_file << setw(field_width) << next << endl;
	}
}
