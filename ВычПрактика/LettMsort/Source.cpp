#include "Funcs.h"



int main()
{
	int arr[50];
	int size;
	int board;

	EnterArr(size, arr);
	SortArr(size, arr);
	findboard(board, size);
	Transfer(size, arr, board);



	return 0;
}