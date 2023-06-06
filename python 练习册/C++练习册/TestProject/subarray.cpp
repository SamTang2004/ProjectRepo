#include <iostream>
using namespace std;


std::size_t find_sequence( int const data[], std::size_t const d_cap,int const find[], std::size_t const f_cap ) {
    size_t ret = d_cap;
    for ( std::size_t k{0}; k < d_cap - f_cap; ++k ) {
        if (data[k] == find[0]){

            size_t check = f_cap;
            for (size_t i = k; i < k + f_cap; i++){
                if (data[i] == find[i-k]){
                    check -= 1;
                }

            }

            if (check == 0){
                return k;
            }
        }


    }
    return ret;
}


int main(){
    int* a = new int[20]{1,3,5,2,3,4,5,1,3,2,4,5,1,3,3,5,4,2,3,5};
    int* b = new int[3]{5,1,3};
    cout<<find_sequence(a,20,b,3);

}
