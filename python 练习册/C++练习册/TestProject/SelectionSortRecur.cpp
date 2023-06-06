#include <iostream>

using namespace std;

void selectionSort(int index, int* arr, std::size_t len){
    if (index == 0){
        return;
    }

    int mxpos = index;
    for ( int i = index-1; i >= 0 ; i--){
        if (arr[i] > arr[mxpos]){
            mxpos = i;
        }
    }
    int temp = arr[index];
    arr[index] = arr[mxpos];
    arr[mxpos]=temp;
    selectionSort(index -1, arr, len);
}

int main(){
    int* arr = new int[10]{2,5,1,4,7,8,2,6,3,0};

    selectionSort(9,arr,10);

    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}
