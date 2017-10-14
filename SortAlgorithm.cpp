//https://magiclen.org/sorting-algorithm/
#include <iostream>

#define IS_SHOW_LOG false

/*
Function aim : export Log file
parameter->
	FuncName : What does word want to export
*/
void ShowLog(char * FuncName) {
	std::cout << FuncName << std::endl;
}
/*
Function aim : Initial location of the sort array
parameter->
	SortLocArr : Declared memory block of the sort array which has not been initialized;
	SortNum : How many sizes are in the array;
*/
void InitSortLocArr(int * SortLocArr, int SortNum) {
	if (IS_SHOW_LOG == true) {
		ShowLog("InitSortLocArr");
	}
	for (int i = 0; i < SortNum; i++) {
		SortLocArr[i] = i;
	}
}
/*
Function aim : It is to Swap the value between memory address of A and B
*/
void Swap(int *A , int *B) {
	if (IS_SHOW_LOG == true) {
		ShowLog("Swap");
	}
	int tmp = *A;
	*A = *B;
	*B = tmp;
}
/*
Function aim : Is x smaller than y if it is true then the function must return the value of x.
			   Otherwise, the function must return the value of y.
*/
int Min(int x, int y) {
	return (x < y) ? x : y;
}
/*
Function aim : It is implement the Bubble Sort Algorithm.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void BubbleSort(int * NonSortArr, int SortNum,int * SortLocArr)
{
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	for (int i = SortNum - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (tNonSortArr[j] > tNonSortArr[j + 1]) {
				Swap(&tNonSortArr[j], &tNonSortArr[j + 1]);
				Swap(&SortLocArr[j], &SortLocArr[j + 1]);
			}
		}
	}
}
/*
Function aim : It is implement the Exchange Sort Algorithm.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void ExchangeSort(int * NonSortArr, int SortNum, int * SortLocArr) {
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	for (int i = 0; i < SortNum - 1 ; i++){
		for (int j = i + 1; j < SortNum; j++) {
			if (tNonSortArr[i] > tNonSortArr[j]) {
				Swap(&tNonSortArr[i], &tNonSortArr[j]);
				Swap(&SortLocArr[i], &SortLocArr[j]);
			}
		}
	}
}
/*
Function aim : It is implement the Selection Sort Algorithm.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void SelectionSort(int * NonSortArr, int SortNum, int * SortLocArr) {
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	for (int i = 0; i < SortNum - 1; i++) {
		for (int j = i + 1; j < SortNum; j++) {
			int k = i;
			if (tNonSortArr[k] > tNonSortArr[j]) {
				k = j;
			}
			if (k != i) {
				Swap(&tNonSortArr[i], &tNonSortArr[j]);
				Swap(&SortLocArr[i], &SortLocArr[j]);
			}
		}
	}
}
/*
Function aim : It is implement the Insertion Sort Algorithm.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void InsertionSort(int * NonSortArr, int SortNum, int * SortLocArr) {
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	for (int i = 0; i < SortNum; i++) {
		int tTmp = tNonSortArr[i];
		int tLoc = SortLocArr[i];
		int j = i - 1;
		while( j >= 0 && tNonSortArr[j] > tTmp ) {
			tNonSortArr[j + 1] = tNonSortArr[j];
			SortLocArr[j + 1] = SortLocArr[j];
			j--;
		}
		tNonSortArr[j + 1] = tTmp;
		SortLocArr[j + 1] = tLoc;
	}
}

int Partition(int number[], int left, int right, int *SortLocArr) {
	int i = left - 1;
	int j;
	for (j = left; j < right; j++) {
		if (number[j] <= number[right]) {
			i++;
			Swap(&number[i], &number[j]);
			Swap(&SortLocArr[i], &SortLocArr[j]);
		}
	}

	Swap(&number[i + 1], &number[right]);
	Swap(&SortLocArr[i + 1], &SortLocArr[right]);
	return i + 1;
}

/* A[] --> Array to be sorted,
l  --> Starting index,
h  --> Ending index */
void QuickSortRecursiveFunc(int data[], int left, int right, int *SortLocArr)
{
	if (left < right) {
		int q = Partition(data, left, right, SortLocArr);
		QuickSortRecursiveFunc(data, left, q - 1, SortLocArr);
		QuickSortRecursiveFunc(data, q + 1, right, SortLocArr);
	}
}
/*
Function aim : It is implement the quick sort algorithm by recursive way.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void QuickSortRecursive(int * NonSortArr, int SortNum, int * SortLocArr) {
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	QuickSortRecursiveFunc(tNonSortArr, 0, SortNum- 1, SortLocArr);
}
/* This function is same in both iterative and recursive*/
int partition(int* A, int low, int high, int * SortLocArr)
{
	int mid = (low + high) / 2;
	int pivot = A[mid];
	while (low <= high) {
		while (low <= high && A[high] >= pivot) {
			high--;
		}
		while (low <= high && A[low] <= pivot) {
			low++;
		}
		if (low <= high) {
			Swap(&SortLocArr[low], &SortLocArr[high]);
			Swap(&A[low], &A[high]);

			high--;
			low++;
		}
	}
	return mid;
}

/* A[] --> Array to be sorted,
l  --> Starting index,
h  --> Ending index */
void QuickSortIterativeFunc(int arr[], int l, int h, int * SortLocArr)
{
	// Create an auxiliary stack
	int * stack = new int[h - l + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (top >= 0)
	{
		// Pop h and l
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int p = partition(arr, l, h, SortLocArr);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
	delete[] stack;
}
/*
Function aim : It is implement the quick sort algorithm by Itertive way.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void QuickSortIterative(int * NonSortArr, int SortNum, int * SortLocArr) {
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	//QuickSortIterativeFunc(tNonSortArray, 0, SortNumber - 1, SortLocArray);
	int startIndex = 0;
	int endIndex = SortNum - 1;
	int top = -1;
	int* stack = (int*)malloc(sizeof(int) * SortNum);

	stack[++top] = startIndex;
	stack[++top] = endIndex;

	while (top >= 0)
	{
		endIndex = stack[top--];
		startIndex = stack[top--];

		int p = Partition(tNonSortArr, startIndex, endIndex, SortLocArr);

		if (p - 1 > startIndex)
		{
			stack[++top] = startIndex;
			stack[++top] = p - 1;
		}

		if (p + 1 < endIndex)
		{
			stack[++top] = p + 1;
			stack[++top] = endIndex;
		}
	}

	delete [] stack;
}

void MergingSortR(int arr[], int l, int m, int r, int * SortLocArr)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int * L = new int[n1];
	int * R = new int[n2];

	int * LocL = new int[n1];
	int * LocR = new int[n2];


	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		LocL[i] = SortLocArr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		LocR[j] = SortLocArr[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			SortLocArr[k] = LocL[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			SortLocArr[k] = LocR[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		SortLocArr[k] = LocL[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		SortLocArr[k] = LocR[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;

	delete[] LocL;
	delete[] LocR;
}

void MergeSortRecursiveFunc(int * arr,int l , int r, int * SortLocArr) {
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2 but avoids overflow for large l & h
		MergeSortRecursiveFunc(arr, l, m, SortLocArr);
		MergeSortRecursiveFunc(arr, m + 1, r, SortLocArr);
		MergingSortR(arr, l, m, r, SortLocArr);
	}
}
/*
Function aim : It is implement the merge sort algorithm by recursive way.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void MergeSortRecursive(int * NonSortArr, int SortNum, int * SortLocArr) {
	int * tNonSortArr = new int[SortNum];
	::memcpy_s(tNonSortArr, sizeof(int) * SortNum, NonSortArr, sizeof(int) * SortNum);
	InitSortLocArr(SortLocArr, SortNum);
	MergeSortRecursiveFunc(tNonSortArr, 0, SortNum - 1, SortLocArr);
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void MergeSortIterativeFunc(int *NonSortArr, int left_start, int mid, int right_end, int * SortLocArr)
{
	int i, j, k;
	int n1 = mid - left_start + 1;
	int n2 = right_end - mid;

	/* create temp arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	int *LocL = new int[n1];
	int *LocR = new int[n2];
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) {
		L[i] = NonSortArr[left_start + i];
		LocL[i] = SortLocArr[left_start + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = NonSortArr[mid + 1 + j];
		LocR[j] = SortLocArr[mid + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = left_start;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			NonSortArr[k] = L[i];
			SortLocArr[k] = LocL[i];
			i++;
		}
		else
		{
			NonSortArr[k] = R[j];
			SortLocArr[k] = LocR[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		NonSortArr[k] = L[i];
		SortLocArr[k] = LocL[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		NonSortArr[k] = R[j];
		SortLocArr[k] = LocR[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;

	delete[] LocL;
	delete[] LocR;
}
/*
Function aim : It is implement the merge sort algorithm by iterative way.
Parameter->
	NonSortArr(Input) : It is the original array that isn't sorted;
	SortNum(Input) :  How many sizes are in the array
	SortLocArr(Output) : It will be the sort result after this algorithm finish
*/
void MergeSortIterative(int* NonSortArr, int SortNum, int * SortLocArr)
{
	//Copy Non-Sort Array to temporay memory
	int * tNonSortArr = new int[SortNum];// = new int[SortNumber];
	::memcpy_s(tNonSortArr, sizeof(int)*SortNum, NonSortArr, sizeof(int)*SortNum);
	//Initial Sort Location array
	InitSortLocArr(SortLocArr, SortNum);

	int curr_size;  // For current size of subarrays to be merged
					// curr_size varies from 1 to n/2
	int left_start; // For picking starting index of left subarray to be merged

	// Merge subarrays in bottom up manner.  First merge subarrays of
	// size 1 to create sorted subarrays of size 2, then merge subarrays
	// of size 2 to create sorted subarrays of size 4, and so on.
	for (curr_size = 1; curr_size <= SortNum - 1; curr_size = 2 * curr_size)
	{
		// Pick starting point of different subarrays of current size
		for (left_start = 0; left_start < SortNum - 1; left_start += 2 * curr_size)
		{
			// Find ending point of left subarray. mid+1 is starting point of right
			int mid = left_start + curr_size - 1;

			int right_end = Min(left_start + 2 * curr_size - 1, SortNum - 1);
			if (mid > right_end) {
				mid = right_end;
			}
			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			MergeSortIterativeFunc(tNonSortArr, left_start, mid, right_end, SortLocArr);
		}
	}
}


#include <random>
#include <time.h>
#define TESTRUN 1000000

/* Generate random numbers in the half-closed interval
[range_min, range_max). In other words,
range_min <= random number < range_max*/
double RandGen(int MaxValue, int MinValue) {
	return (double)rand() / (RAND_MAX + 1) * (MaxValue - MinValue) + MinValue;
}
void ShowSortedArr(int * nonSortArr, int SortNum, int * SortLocArr) {
	for (int i = 0; i < SortNum; i++) {
		std::cout << SortLocArr[i] << " ";
	}
	std::cout << std::endl;
}

void main() {
	int tTestRun = 0;
	
	srand(time(NULL));	//Initialize the start value of the random tool

	while (tTestRun < TESTRUN) {
		tTestRun++;
		const int tRandNum = RandGen(100, 2); //How many size in the non sort array

		int * t_TestArray = new int[tRandNum] ;
		int * t_TestSortArray = new int[tRandNum];
		
		std::cout << "..........Problem Run " << tTestRun << ".........." << std::endl;
		/*
		Generate random value to set the array which you want to be sorted
		*/
		for (int i = 0; i < tRandNum; i++) {
			t_TestArray[i] = RandGen(10000, -50000);
			std::cout << t_TestArray[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "----------" << std::endl;
		//std::system("pause");
		
		std::cout << "Bublle Sort Algorithm" << std::endl;
		BubbleSort(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");

		std::cout << "Exchange Sort Algorithm" << std::endl;
		ExchangeSort(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");

		std::cout << "Selection Sort Algorithm" << std::endl;
		SelectionSort(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");

		std::cout << "Insertion Sort Algorithm" << std::endl;
		InsertionSort(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");
		
		std::cout << "Quick Sort Algorithm by Recursive way" << std::endl;
		QuickSortRecursive(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");
		
		std::cout << "Quick Sort Algorithm by Iterative way" << std::endl;
		QuickSortIterative(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");

		std::cout << "Merge Sort Algorithm by Recursive way" << std::endl;
		MergeSortRecursive(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");

		std::cout << "Merge Sort Algorithm by Iterative way" << std::endl;
		MergeSortIterative(t_TestArray, tRandNum, t_TestSortArray);
		ShowSortedArr(t_TestArray, tRandNum, t_TestSortArray);
		std::cout << "----------" << std::endl;
		//std::system("pause");
		
	}
}
