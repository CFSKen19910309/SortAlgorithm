//https://magiclen.org/sorting-algorithm/
#include <iostream>

void Swap(int &A , int &B) {
	//int tmp = A;
	//A = B;
	//B = tmp;

	A ^= B;
	B ^= A;
	A ^= B;
}

void BubbleSort(int * NonSortArray, int SortNumber,int * SortLocArray)
{
	int * tNonSortArray = new int[SortNumber];
	::memcpy_s(tNonSortArray, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	for (int i = 0; i < SortNumber; i++) {
		SortLocArray[i] = i;
	}
	for (int i = SortNumber - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (tNonSortArray[j] > tNonSortArray[j + 1]) {
				Swap(tNonSortArray[j], tNonSortArray[j + 1]);
				Swap(SortLocArray[j], SortLocArray[j + 1]);
			}
		}
	}
}

void ExchangeSort(int * NonSortArray, int SortNumber, int * SortLocArray) {
	int * tNonSortArray = new int[SortNumber];
	::memcpy_s(tNonSortArray, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	for (int i = 0; i < SortNumber; i++) {
		SortLocArray[i] = i;
	}
	for (int i = 0; i < SortNumber - 1 ; i++){
		for (int j = i + 1; j < SortNumber; j++) {
			if (tNonSortArray[i] > tNonSortArray[j]) {
				Swap(tNonSortArray[i], tNonSortArray[j]);
				Swap(SortLocArray[i], SortLocArray[j]);
			}
		}
	}
}

void SelectionSort(int * NonSortArray, int SortNumber, int * SortLocArray) {
	int * tNonSortArray = new int[SortNumber];
	::memcpy_s(tNonSortArray, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	for (int i = 0; i < SortNumber; i++) {
		SortLocArray[i] = i;
	}
	for (int i = 0; i < SortNumber - 1; i++) {
		for (int j = i + 1; j < SortNumber; j++) {
			int k = i;
			if (tNonSortArray[k] > tNonSortArray[j]) {
				k = j;
			}
			if (k != i) {
				Swap(tNonSortArray[i], tNonSortArray[j]);
				Swap(SortLocArray[i], SortLocArray[j]);
			}
		}
	}
}
	
void InsertionSort(int * NonSortArray, int SortNumber, int * SortLocArray) {
	int * tNonSortArray = new int[SortNumber];
	::memcpy_s(tNonSortArray, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	for (int i = 0; i < SortNumber; i++) {
		SortLocArray[i] = i;
	}
	for (int i = 0; i < SortNumber; i++) {
		int tTmp = tNonSortArray[i];
		int j = i - 1;
		while (j >= 0) {
			if (tNonSortArray[j] > tTmp) {
			}
		}
	}

}

void QuickSort(int * NonSortArray, int SortNumber, int * SortLocArray) {
	int * tNonSortArray = new int[SortNumber];
	::memcpy_s(tNonSortArray, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	for (int i = 0; i < SortNumber; i++) {
		SortLocArray[i] = i;
	}

}

void MergeSort(int * NonSortArray, int SortNumber, int * SortLocArray) {
	int * tNonSortArray1 = new int[SortNumber];
	int * tNonSortArray2 = new int[SortNumber];
	::memcpy_s(tNonSortArray1, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	::memcpy_s(tNonSortArray2, sizeof(int) * SortNumber, NonSortArray, sizeof(int) * SortNumber);
	for (int i = 0; i < SortNumber; i++) {
		SortLocArray[i] = i;
	}
	for (int i = 1; i < SortNumber; i *= 2) {
		for (int j = 0; j < SortNumber - 1; j += (i *= 2)) {

		}
	}

}

void main() {
	int t_TestArray[10] = { 9,8,5,7,2,6,4,3,1,0 };
	int t_TestSortArray[10];

	// 9 8 5 7 2 6 4 3 1 0
	// 0 1 2 3 4 5 6 7 8 9
	// 9 8 4 7 6 2 5 3 1 0
	int aa = 0; int bb = 2;
	Swap(aa, bb);
	std::cout << aa << " " << bb << std::endl;
	std::system("pause");

	BubbleSort(t_TestArray, 10, t_TestSortArray);
	for (int i = 0; i < 10; i++) {
		std::cout << t_TestSortArray[i] << " ";
	}
	std::system("pause");
	std:: cout << "----------" << std::endl;

	ExchangeSort(t_TestArray, 10, t_TestSortArray);
	for (int i = 0; i < 10; i++) {
		std::cout << t_TestSortArray[i] << " ";
	}
	std::system("pause");
	std::cout << "----------" << std::endl;

	SelectionSort(t_TestArray, 10, t_TestSortArray);
	for (int i = 0; i < 10; i++) {
		std::cout << t_TestSortArray[i] << " ";
	}
	std::system("pause");
	
}
