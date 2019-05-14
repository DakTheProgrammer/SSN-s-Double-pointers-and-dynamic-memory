//***************************************************************************
//						Assignment #5
//					Name: Dakota Wilson
//				Data Structures Date: 3/27/19
//***************************************************************************
//		This program uses dynamicly alocated memory from the heap to make a
//	Matrix that holds SSN of a group of people on a village with there SSNs
//	the program shows how many people have a SSN with leading values and also
//  displays using there SSN what gender they are. At the end of the program
//	the dynamicly alocated memory is deleted to free space.
//***************************************************************************

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//***************************************************************************
//		void SSNVal(int Rows, int Col, int **SSN, int Total);
//		Parameters: This function is used to take in the dynamicly alocated
//	Matrix and show how many of the SSNs have similar leading didgets. This
//	function takes in the size of the columns and rows of the matrix to use
//	while looping. It also takes in the Dynamicly alocated matrix so that 
//	the values inside can be used to sort. Then it also uses the total 
//	number of people so that it can be output with the function.
//***************************************************************************
void SSNVal(int Rows, int Col, int **SSN, int Total);

//***************************************************************************
//		void MenOrWom(int Rows, int Col, int **SSN, int Total);
//		Parameters: This function is used to take in the dynamicly alocated
//	Matrix and show how many of the SSNs end in even numbers or odd number.
//	When the numbers end in even the person is a woman while if its odd they
//	are male. This function takes in the size of the columns and rows of the 
//	matrix to use while looping. It also takes in the Dynamicly alocated 
//	matrix so that the values inside can be used to sort. Then it also uses 
//	the total number of people so that it can be output with the function.
//***************************************************************************
void MenOrWom(int Rows, int Col, int **SSN, int Total);

int main() {
	int  Rows, Col, i, j, Total;

	cout << "Enter the number of rows for SSN's \n";
	cin >> Rows;
	cout << "Enter the number of columns for SSN's \n";
	cin >> Col;

	Total = Rows * Col;// sets total number of people

	
	int **SSN = new int*[Rows];// Allocate space for the matrix
	for (i = 0; i < Rows; i++)
	{
		SSN[i] = new int[Col];
	}

	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Col; j++)
		{
			SSN[i][j] = rand() % 4999 + 1000;//randomly loads num 1000-5999
		}
	}

	cout << "------------------------------------------------------------\n";
	cout << "The Matrix:\n";
		
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Col; j++)
		{
			cout << SSN[i][j] << '\t';//outputs the matrix
		}
		cout << '\n';
	}
	cout << "------------------------------------------------------------\n";

	SSNVal(Rows, Col, SSN, Total);//calls first didget sorter

	MenOrWom(Rows, Col, SSN, Total);//calls gender function

	delete[] SSN; //deletes alocated memory

	system("Pause");
	return 0;
}

void SSNVal(int Rows, int Col, int **SSN, int Total)
{
	int i, j, SS1 = 0, SS2 = 0, SS3 = 0, SS4 = 0, SS5 = 0;

	for (i = 0; i < Rows; i++)//loops through matrix
	{
		for (j = 0; j < Col; j++)
		{
			if (SSN[i][j] < 2000)
			{
				SS1 += 1;//increments if number starts with 1
			}
			else if (SSN[i][j] < 3000)
			{
				SS2 += 1;//increments if number starts with 2
			}
			else if (SSN[i][j] < 4000)
			{
				SS3 += 1;//increments if number starts with 3
			}
			else if (SSN[i][j] < 5000)
			{
				SS4 += 1;//increments if number starts with 4
			}
			else
			{
				SS5 += 1;//increments if number starts with 5
			}
		}
	}

	cout << "------------------------------------------------------------\n";
	cout << "The fallowing summarizes the SSN's in Tiny Ville\n";
	cout << "SSN: 1000s = " << SS1 << '\n';
	cout << "SSN: 2000s = " << SS2 << '\n';
	cout << "SSN: 3000s = " << SS3 << '\n';
	cout << "SSN: 4000s = " << SS4 << '\n';
	cout << "SSN: 5000s = " << SS5 << '\n';
	cout << "The total # of habitants in Tiny Ville is = " << Total << '\n';
	cout << "------------------------------------------------------------\n";
}

void MenOrWom(int Rows, int Col, int **SSN, int Total)
{
	int i, j, Man = 0, Wom = 0;

	for (i = 0; i < Rows; i++)//loops through matrix
	{
		for (j = 0; j < Col; j++)
		{
			if (SSN[i][j] % 2 == 0)
			{
				Wom += 1;//increments if number is even
			}
			else
			{
				Man += 1;//increments if number is odd
			}
		}
	}

	cout << "------------------------------------------------------------\n";
	cout << "The fallowing summarizes the Genders in Tiny Ville\n";
	cout << "The total # of habitants in Tiny Ville is = " << Total << '\n';
	cout << "Tiny Ville has = " << Wom << " women\n";
	cout << "Tiny Ville has = " << Man << " men\n";
	cout << "------------------------------------------------------------\n";
}