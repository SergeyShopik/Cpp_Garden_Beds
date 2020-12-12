#include<iostream>
#include<ctime>

void initArray(int **& arr, size_t rows, size_t cols)
{
	arr = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 2;
		}
	}
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			if (arr[i - 1][j - 1] != 1)
			{
				if (arr[i][j - 1] == 1 && arr[i - 1][j] == 1)
					arr[i][j] = 0;
				else
				{
					arr[i][j] = rand() % 2;
				}
			}
			else
			{
				if (arr[i][j - 1] == 0 && arr[i - 1][j] == 0)
					arr[i][j] = rand() % 2;
				else if (arr[i][j - 1] == 1 && arr[i - 1][j] == 1)
					arr[i][j] = 1;
				else
					arr[i][j] = 0;

			}
		}
	}
}
void printArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void countBed(int** arr, size_t rows, size_t cols)
{
	int bed = 0, squareBed = 0;
	for (size_t i = 1; i < rows; i++)
	{
		for (size_t j = 1; j < cols; j++)
		{
			if (arr[i][j] == 1)
			{
				//check if bed is square
				if (arr[i - 1][j] == 1 && arr[i][j - 1] == 1)//up and left respectfuly
				{
					int tempi = --i;
					int tempj = --j;
					int up = 1, left = 1;
					while (up == 1 && left == 1)
					{
						up = arr[i--][tempj];
						left = arr[tempi][j--];
					}
					if (up == left) squareBed++;
					else bed++;
				}
				else if (arr[i - 1][j] == 1)
				{
					if (arr[i + 1][j] == 0) bed++;
					else break;
				}
				else if (arr[i][j - 1] == 1)
				{
					if (arr[i][j + 1] == 0) bed++;
					else break;
				}
			}
		}
	}
	std::cout << "Beds: " << bed << "\nSquare beds: " << squareBed << std::endl;
}
//void deleteArray()

int main()
{	
	srand(time(0));
	/*const size_t size = 20;
	int arr[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	quickSort(arr, size - 1);
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;*/

	// 4. Garden split in square cells with side 1 meter, garden's size (M * N)m2. Beds are rectangular and don't touch at any side.
	// Determine number of all beds and square beds. Represent garden as a dynamic matrix. Beds as ones '1' and empty areas as zeros '0'.

	int** arr = nullptr;
	initArray(arr, 6, 6);
	printArray(arr, 6, 6);
	countBed(arr, 6, 6);


	return 0;
}