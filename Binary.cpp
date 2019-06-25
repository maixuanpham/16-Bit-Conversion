#include <iostream>
#include <string>
using namespace std;

string decToBinary (int dec);
int binary2Decimal(string b);
void addOne(string &b);
void flipBinary(string &b);

int main()
{
	/*	TESTING
	string a = "0";
	a[0]++;
	cout << a << endl;			// output: 1
	string b = "1";
	b[0]++;
	cout << b << endl;			// output: 2
	int dec = -45;
	cout << dec*-1 << endl;		// output: 45
	*/

	int option;
	string binary;
	int decimal;

	cout << "Binary Conversion Program by Mai Pham\n\n";
	cout << "This program can handle 16-bit signed &  unsigned values.\n";
	cout << "Select an option below to perform conversion.\n";
	cout << "1 - Unsigned decimal to binary\n";
	cout << "2 - Binary to unsigned decimal\n";
	cout << "3 - Signed decimal to binary\n";
	cout << "4 - Binary to Signed decimal\n";
	cout << "5 - Quit\n\n";

	cout << "Enter an option --> ";
	cin >> option;
	while (option > 0 && option < 5)
	{
		if (option == 1)	{
			cout << "Please enter a decimal value --> ";
			cin >> decimal;
			cout << "Decimal " << decimal << " is converted to binary " << decToBinary (decimal) << endl;
		}
		if (option == 2)	{
			cout << "Please enter a binary value --> ";
			cin >> binary;
			cout << "Binary " << binary << " is " << " converted to decimal " <<binary2Decimal(binary) << endl;
		}
		if (option == 3)	{
			cout << "Please enter a decimal value --> ";
			cin >> decimal;
			if (decimal >= 0)
				binary = decToBinary (decimal);
			if (decimal < 0)	{
				binary = decToBinary ((decimal*-1));
				flipBinary(binary);
				addOne(binary);
			}
			cout << "Decimal " << decimal << " is converted to binary " << binary << endl;
		}
		if (option == 4)	{
			cout << "Please enter a binary value --> ";
			cin >> binary;
			if (binary[0] == '0')
				cout << "Binary " << binary << " is " << " converted to decimal " <<binary2Decimal(binary) << endl;
			else if (binary[0] == '1')	{
				string tempBinary;
				tempBinary = binary;
				flipBinary(tempBinary);
				addOne(tempBinary);
				cout << "Binary " << binary << " is " << " converted to decimal " << (0-binary2Decimal(tempBinary)) << endl;
			}
		}

		cout << "\nEnter an option --> ";
		cin >> option;
	}

	cout << "Thanks for using my program.\n";
	return 0;
}

string decToBinary (int dec)    {
    string binary = " ";
    char c;
    while (dec != 0)    {
        c = '0' + dec % 2;
        binary = c + binary;
        dec/=2;
    }
    while (binary.length() <= 16)    {
        binary = "0" + binary;
    }
    
    return binary;
}

void flipBinary(string &b)	{
	for (int i = 0; i < 16; i++)
		if (b[i] == '0')
			b[i] = '1';
		else
			b[i] = '0';
}

void addOne(string &b)	{
	int remainder = 0;
	int i = 15;

	b[i]++;
	while (b[i] == '2')	{
		remainder = 1;
		b[i] = 0;
		i--;
		b[i] += remainder;
	}
}

int binary2Decimal(string b)	{
	int decimal = 0;
	int j = 0;
	for (int i = 15; i >= 0; i--)	{
		if (b[i] == '1')
			decimal += pow(2,j);
		j++;
	}
	return decimal;
}