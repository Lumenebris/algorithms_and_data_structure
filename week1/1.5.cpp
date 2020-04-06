#include <iostream>
#include <fstream>

int compare(const void * x1, const void * x2) {
    return ( *(int*)x1 - *(int*)x2 );
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int length;
    int array[5000];
    int sorted[5000];
    bool usedArray[5000];
    bool usedSorted[5000];

    fin >> length;

    for (int i = 0; i < length; i++){
        fin >> array[i];
        sorted[i] = array[i];
        usedSorted[i] = true;
        usedArray[i] = true;
    }

    for (int i = 1; i < length; i++) {
        int cell = sorted[i];
        int cellPosition = i;
        int swapIndex;
        if (sorted[cellPosition - 1] > cell){
            swapIndex = cellPosition + 1;
            while (cellPosition > 0 && sorted[cellPosition - 1] > cell){
                sorted[cellPosition] = sorted[cellPosition - 1];
                cellPosition--;
            }
        }
        sorted[cellPosition] = cell;
    }

    for (int i = 0; i < length; i++){
        if (usedArray[i]){
            int j = i;
            while (usedArray[j]){
                for (int k = 0; k < length; k++){
                    if (usedSorted[k] && array[j] == sorted[k]){
                        usedArray[j] = false;
                        usedSorted[k] = false;
                        if (i < k){
                            fout << "Swap elements at indices " << i + 1 << " and " << k + 1 << "." << std::endl;
                        } else if (i > k) {
                            fout << "Swap elements at indices " << k + 1 << " and " << i + 1 << "." << std::endl;
                        }
                        j = k;
                        break;
                    }
                }
            }
        }
    }

    fout << "No more swaps needed." << std::endl;
    for (int i = 0; i < length; i++){
        fout << sorted[i] << " ";
    }
}