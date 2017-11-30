#include <iostream>
#include <queue>

using namespace std;

int INPUT_SIZE;

void InputNumber(int number[]);
void printJolly(int number[]);

void HeapSort(int number[], int size);

int main(void)
{
	char again = 'y';

	while (again == 'y')
	{
		cin >> INPUT_SIZE;
		int* number = (int*)malloc(sizeof(int)*INPUT_SIZE);

		InputNumber(number);
		HeapSort(number, INPUT_SIZE);
		printJolly(number);

		cout << "다시 하시겠습니까? y or n" << endl;
		cin >> again;
	}
	return 0;
}

void HeapSort(int number[], int size)
{
	priority_queue<int> PQ;

	for (int i = 0; i < size; i++)
	{
		PQ.push(number[i]);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		number[i] = PQ.top();
		PQ.pop();
	}
}

void InputNumber(int number[])
{
	int* input;
	input = new int[INPUT_SIZE];

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < INPUT_SIZE-1; i++)
	{
		int cha;
		cha = input[i + 1] - input[i];
		if (cha < 0)
			cha = -cha;
		number[i] = cha;
	}
}

void printJolly(int number[])
{
	int count = 0;

	for (int i = 1; i < INPUT_SIZE; i++)
	{
		if (number[i] == i)
		{
			count++;
		}
	}

	if (count == INPUT_SIZE - 1)
	{
		cout << "Jolly" << endl;
	}
	else
	{
		cout << "Not Jolly" << endl;
	}
}