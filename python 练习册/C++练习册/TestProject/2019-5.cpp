#include <iostream>


void sort( int array[], std::size_t capacity ) {

    // index is the number.
    // i.e. count of 0 is tracked by numct[0]
    // count of 1 is tracked by numct[1]
    // etc.
    int numct[10]{};

    for (int i = 0; i <capacity; i++){
        numct[array[i]] ++;
    }

    int t = 0;
    for(int i = 0; i < 10; i++){

        for (int j = t; j < t + numct[i]; j++){
            array[j] = i;
        }
        t += numct[i];
    }

}


int main(){

int arr[10]{2,5,3,1,1,9,0,4,7,8};

sort(arr,10);

for( int i = 0; i < 10 ; i ++){
    std::cout<<arr[i];
}


return 0;
}

