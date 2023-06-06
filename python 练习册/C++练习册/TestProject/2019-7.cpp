#include <iostream>

int *allocate_array( int m, int n ) {
    int len = std::abs(m-n) +1;

    int* arr = new int[len]{};

    if (m < n){

        for (int i = m; i <= n; i++){

            arr[i-m] = i;
        }

        return arr;
    }else{

        for (int i = m; i >= n; i--){

            arr[len-(i-n)-1] = i;

        }
        return arr;
    }
}


int main(){

int* ptr = allocate_array(3,-1);

for (int i = 0 ; i <5; i ++){

    std::cout<<ptr[i]<<" ";

}


}



