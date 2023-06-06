#include <iostream>

int * merge_arrays (int * & data_1, std::size_t data_1_size,int * & data_2, std::size_t data_2_size){

    int new_length = data_1_size + data_2_size;

    int* newArray = new int[new_length]{};

    int m = data_1_size < data_2_size ? data_1_size : data_2_size;
    int ptr1 = 0;
    int ptr2 = 0;

    while (std::min(ptr1, ptr2) != m){
        if (data_1[ptr1] > data_2[ptr2]){
            ptr2 ++;
            newArray[ptr1+ptr2] = data_2[ptr2];
        }else{
            ptr1 ++;
            newArray[ptr1+ptr2] = data_1[ptr1];
        }
    }

    if (m == data_2_size){
        for (int i = m; i <data_1_size;i++){


        }

    }

    delete data_1;
    delete data_2;
    data_1 = nullptr;
    data_2 = nullptr;
    return newArray;
}


int main(){
int* d1 = new int[5]{1,3,3,4,5};
int* d2 = new int[5]{1,2,3,6,7};

int* newList = merge_arrays(d1, 5, d2, 5);
for (int i = 0; i <10; i ++){
    std::cout<<newList[i]<<std::endl;

}
return 0;
}
