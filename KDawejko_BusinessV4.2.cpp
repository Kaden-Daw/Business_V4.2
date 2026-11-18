// KDawejko_ProjectV1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Kaden Dawejko
// 9.27.26
// Business Project V1: This program will be used to order smoothies and smoothie bowls from the Sweetest Smoothie Stand. 
// User will be proted to choose between smoothie or smoothie bowl, and will then choose their desired flavor.
// The program will then perfom calculations to determine the price based off of their order.
// Business V2: Added the option to purchase another item or try again if they entered an incorrect value
// Business V3: Added Arrays for the order type, order flavor, and price calculations
// Business V4: Added Functions and reformated receipt
// 4.2

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Declare Constant Variables

const int SMOOTHIE_PRICE = 7;
const int SMOOTHIE_BOWL_PRICE = 10;
const double TAX_RATE = .1;
const int ORDER_SIZE = 100;

int main()
{
	// Declare Variables

	char orderType;
	int smoothieFlavor;
	int smoothieBowlFlavor;
	double subtotal = 0;
	double total = 0;
	double taxCost;
	char orderAgain;
	int i = 0;
	char orderCorrect;

	// Declare File Variables

	ofstream fout;
	char printReceipt;

	// Array Variables

	string orderTypeArray[ORDER_SIZE];
	string orderFlavorArray[ORDER_SIZE];
	double orderSubtotalArray[ORDER_SIZE];

	// Declare Function

	void foutFuntion(ofstream& fout, char printReceipt, double subtotal, double total, double taxCost,
		string orderTypeArray[], string orderFlavorArray[], double orderSubtotalArray[], int i, int k);

	char errorCheckFunction(char orderType);

	// Business Menu

	cout << left << setw(90) << "Welcome to The Sweetest Smoothie Stand!" << endl;
	cout << setw(90) << "Where every bite is Naturally Sweet and Perfectly Blended!" << endl << endl;
	cout << setw(90) << "****************************************************************************" << endl << endl;
	cout << setw(90) << " What would you like to order today? We have: " << endl << endl;
	cout << setw(80) << " Smoothie Flavors (S): " << endl;
	cout << setw(80) << " 1. Strawberry Banana ($7) 2. Mango Pineapple ($9) 3. Triple Berry ($7)" << endl << endl;
	cout << setw(90) << " Smoothie Bowl Flavors (B): " << endl;
	cout << setw(90) << " 1. Acai ($13) 2. Pink Dragon Friut ($12) 3. Triple Berry ($10)" << endl << endl;
	cout << setw(90) << "****************************************************************************" << endl << endl;

	// Customer Selection

	do {

		cout << setw(90) << "Will you be having a Smoothie or Smoothie Bowl today?" << endl;
		cout << setw(26) << "Please enter as 'S' or 'B': ";
		cin >> orderType;
		cout << endl;


		// Call Function

		orderType = errorCheckFunction(orderType);

		if (orderType == 'S' || orderType == 's')
		{
			orderTypeArray[i] = "Smoothie";
			cout << "What flavor of smoothie would you like?" << endl;
			cout << "We have Strawberry Banana, Mango Pineapple, and Triple Berry." << endl;
			cout << "Please enter as 1,2, or 3: ";
			cin.ignore();
			cin >> smoothieFlavor;

			while (!cin || smoothieFlavor < 1 || smoothieFlavor > 3)
			{
				cout << "You entered invalid data." << endl;
				cout << "Please enter as 1, 2 or 3." << endl;
				cout << "Please try again" << endl;
				cin.clear();
				cin.ignore();
				cin >> smoothieFlavor;
			}
			if (smoothieFlavor == 1)
			{
				cout << "You have ordered a Strawberry Banana smoothie!" << endl;
				orderFlavorArray[i] = "StrawBerry Banana";
				orderSubtotalArray[i] = SMOOTHIE_PRICE;
			}
			else if (smoothieFlavor == 2)
			{
				cout << "You have ordered a Mango Pineapple smoothie!" << endl;
				orderFlavorArray[i] = "Mango Pineapple";
				orderSubtotalArray[i] = SMOOTHIE_PRICE + 2;
			}
			else if (smoothieFlavor == 3)
			{
				cout << "You have ordered a Triple Berry smoothie!" << endl;
				orderFlavorArray[i] = "Triple Berry";
				orderSubtotalArray[i] = SMOOTHIE_PRICE;
			}

		}
		else if (orderType == 'B' || orderType == 'b')
		{
			orderTypeArray[i] = "Smoothie Bowl";
			cout << "What flavor of smoothie bowl would you like?" << endl;
			cout << "We have Acai, Pink Dragon Fruit, and Triple Berry" << endl;
			cout << "Please enter as 1,2, or 3: ";
			cin.ignore();
			cin >> smoothieBowlFlavor;

			while (!cin || smoothieBowlFlavor < 1 || smoothieBowlFlavor > 3)
			{
				cout << "You entered invalid data." << endl;
				cout << "Please enter as 1, 2 or 3." << endl;
				cout << "Please try again" << endl;
				cin.clear();
				cin.ignore();
				cin >> smoothieBowlFlavor;
			}
			if (smoothieBowlFlavor == 1)
			{
				cout << "You have ordered an Acai smoothie bowl!" << endl;
				orderFlavorArray[i] = "Acai";
				orderSubtotalArray[i] = SMOOTHIE_BOWL_PRICE + 3;
			}
			else if (smoothieBowlFlavor == 2)
			{
				cout << "You have ordered a Pink Dragon Fruit smoothie bowl!" << endl;
				orderFlavorArray[i] = "Pink Dragon Fruit";
				orderSubtotalArray[i] = SMOOTHIE_BOWL_PRICE + 2;
			}
			else if (smoothieBowlFlavor == 3)
			{
				cout << "You have ordered a Triple Berry smoothie bowl!" << endl;
				orderFlavorArray[i] = "Tripple Berry";
				orderSubtotalArray[i] = SMOOTHIE_BOWL_PRICE;
			}
		}

		// Ask If Order is Correct

		do
		{
			cout << endl << "Is this order correct?" << endl;
			cout << setw(20) << orderFlavorArray[i] << " " << orderTypeArray[i] << endl;
			cout << "Please enter 'Y' or 'N'" << endl;
			cin.clear();
			cin.ignore();
			cin >> orderCorrect;
		} while (orderCorrect != 'N' && orderCorrect != 'n' && orderCorrect != 'Y' && orderCorrect != 'y');

		if (orderCorrect == 'N' || orderCorrect == 'n')
		{
			//smoothieFlavor
			//smoothieBowlFlavor
			//orderType
			//orderTypeArray[i]
			//orderFlavorArray[i]

		}

		else
		{
			i++;
		}

		do
		{
			cout << "Would you like to order another item?" << endl;
			cout << "Please enter 'Y' or 'N'" << endl;
			cin.clear();
			cin.ignore();
			cin >> orderAgain;
		} while (orderAgain != 'N' && orderAgain != 'n' && orderAgain != 'Y' && orderAgain != 'y');

	} while (orderAgain != 'N' && orderAgain != 'n');

	// Ask Whether to Print Receipt to File

	cout << "Do you want to print your recipt out to a file?" << endl;
	cout << "Please enter as 'Y' or 'N'" << endl;
	cin >> printReceipt;

	// Error Check 

	while (printReceipt != 'Y' && printReceipt != 'y' && printReceipt != 'N' && printReceipt != 'n')
	{
		cout << "You entered invalid data." << endl;
		cout << "Please enter as 'Y' or 'N'." << endl;
		cout << "Please try again" << endl;
		cin.clear();
		cin.ignore();
		cin >> printReceipt;
	}

	// Price Calculations

	for (int j = 0; j < i; j++)
	{
		subtotal = subtotal + orderSubtotalArray[j];
	}

	taxCost = TAX_RATE * subtotal;
	total = subtotal + taxCost;

	// Output Receipt

	cout << showpoint << fixed << setprecision(2) << right << endl;
	cout << "*****************************************************************" << endl << endl;
	cout << "The number of items you purchased was: " << i << endl;
	cout << "You ordered:" << endl;


	for (int j = 0; j < i; j++)
	{
		cout << left << setw(10) << endl << orderFlavorArray[j] << " " << orderTypeArray[j] << "	" << " $ " << orderSubtotalArray[j];
	}

	cout << endl << endl << "Your subtotal is:" << setw(10) << "$" << subtotal << endl;
	cout << "The tax cost is:" << setw(11) << "$" << taxCost << endl;
	cout << "Your total is:" << setw(13) << "$" << total << endl << endl;
	cout << "Thank you for choosing The Sweetest Smoothie Stand, enjoy!" << endl << endl;
	cout << "*****************************************************************" << endl;

	// Farewell Message

	cout << "		 We hope to see you again soon!" << endl;
	cout << "		" << __DATE__ << "		" << __TIME__ << endl;

	return 0;

	// Call Function

	void foutFuntion();

}

// Define the Function

	// Define Function #1

char errorCheckFunction(char orderType)
{
	while (orderType != 'S' && orderType != 's' && orderType != 'B' && orderType != 'b')
	{
		cout << "You entered invalid data." << endl;
		cout << "Please enter as 'S' or 'B'." << endl;
		cout << "Please try again" << endl;
		cin.clear();
		cin.ignore();
		cin >> orderType;
	}

	return orderType;

}

	// Define Function #2

void foutFunction(ofstream& fout, char printReceipt, double subtotal, double total, double taxCost,
	string orderTypeArray[], string orderFlavorArray[], double orderSubtotalArray[], int i, int k)
{
	// Print Recipt to File

	if (printReceipt == 'Y' || printReceipt == 'y')
	{

		fout.open("SweetestSmoothieStandReceipt.txt");

		if (!fout)
		{
			cout << "File was not able to be opened." << endl;
		}
		else
		{

			fout << showpoint << fixed << setprecision(2) << right << endl;
			fout << "*****************************************************************" << endl << endl;
			fout << "You ordered:" << endl;

			for (int k = 0; k < i; k++)
			{
				fout << setw(20) << endl << orderFlavorArray[k] << " " << orderTypeArray[k] << "					" << " $ " << orderSubtotalArray[k] << endl;
			}

			fout << "Your subtotal is:" << setw(10) << "$" << subtotal << endl;
			fout << "The tax cost is:" << setw(11) << "$" << taxCost << endl;
			fout << "Your total is:" << setw(13) << "$" << total << endl << endl;
			fout << "Thank you for choosing The Sweetest Smoothie Stand, enjoy!" << endl << endl;
			fout << "*****************************************************************" << endl;
			fout << "We hope to see you again soon!" << endl;
			fout << "		" << __DATE__ << "		" << __TIME__ << endl;
			cout << "Recipt has been printed to file." << endl;
			cout << "Please check output file \"SweetestSmoothieStandReceipt.txt\" for your results." << endl;

			// Close File

			fout.close();
		}

	}
}