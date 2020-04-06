#include<iostream>
#include<fstream>
#include<string>

const std::string filein = "input.txt";
const std::string fileout = "output.txt";
std::ofstream ofstr;
std::ifstream ifstr(filein);
void merge(int* a, int low, int mid, int high);
void mergeSort(int* a, int low, int high);

int main()
{
	ofstr.open(fileout);
	int num;
	
	if (ifstr.is_open())
	{
		ifstr >> num;
		int n = num, i = 0;
		int* arr = new int[n];
		
		while (ifstr >> num)
		{
			arr[i++] = num;
		}
		std::cout << std::endl;
		mergeSort(arr, 0, n - 1);
		
		for (int j = 0; j < n; j++) {
			ofstr << arr[j] << ' ';
		}
		
		delete(arr);
		ifstr.close();
		ofstr.close();
	}

    return 0;
}

void merge(int* a, int low, int mid, int high) {

	int N = high - low + 1;
	int *b = new int[N];
	int left = low, right = mid + 1, bIdx = 0;
	while (left <= mid && right <= high) {
		if (a[left] <= a[right]) {
			b[bIdx++] = a[left];
			left++;
		}
		else {
			b[bIdx++] = a[right];
			right++;
		}
	}
	while (left <= mid) b[bIdx++] = a[left++];
	while (right <= high) b[bIdx++] = a[right++];
	for (int k = 0; k < N; k++) a[low + k] = b[k];
	delete(b);
}

void mergeSort(int* a, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
		ofstr << low+1 << ' ' << high+1 << ' ' << a[low] << ' ' << a[high] << '\n';
	}
}