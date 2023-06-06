#include <iostream>
#include <cmath>
using namespace std;
int* m(int* matrix1, int* matrix2, int size){
    int len = (int)(sqrt(size));
    int mat1[len][len];
    int mat2[len][len];
    int f[len][len];
    for (int i = 0; i < size; i++){
        mat1[i/len][i%len] = matrix1[i];
        mat2[i%len][i/len] = matrix2[i];

    }
    for (int i = 0; i < len; i++){
        for (int j = 0; j <len; j ++){
            f[i][j] = 0;


        }
    }

    for (int i =0; i < len; i++){
        for (int j = 0; j < len; j ++){


            for (int k = 0; k < len; k++){
                f[i][j] += mat1[i][k]*mat2[j][k];
            }

        }
    }

    int* j = new int[size]{};

    for (int i = 0; i < size; i++){
        j[i] = f[i/len][i%len];

    }

    return j;
}



int main(){
int* ptr = new int[4]{1,2,3,4};
int* ptr2 = new int[4]{5,6,7,8};
int* ret = m(ptr, ptr2, 4);
for (int i = 0; i <4; i ++){
    std::cout<<ret[i]<<" ";
}



return 0;
}

