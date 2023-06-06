#include <iostream>
using namespace std;

int* mix_array(int * array1, int* array2, std::size_t capacity){

    int* newArray =  new int[2* capacity]{};

    int pt = 0;


    while (pt < capacity*2){
        newArray[pt] = array1[pt/2];
        newArray[pt+1] = array1[pt/2+1];
        newArray[pt+2] = array2[pt/2];
        newArray[pt+3] = array2[pt/2+1];

        pt += 4;
    }

    return newArray;
}

int main(){
    int* a = new int[4]{1,2,3,4};
    int* b = new int[4]{1,2,3,4};

    int* ret = mix_array(a,b,4);

    for (int i = 0 ; i < 8; i ++){

        cout<<ret[i]<<" ";
    }


}
