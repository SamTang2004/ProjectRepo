#include <iostream>
#include <cassert>
void func(int n){
    assert(n > 0);
    for (unsigned int k{1}; k <= n; ++k){

        for (int j = 1; j <= k; j ++){
            std::cout<<(j%10);
        }
        std::cout<<endl;
    }

    for (int i = 1; i <n; i++){

        for(int u = 0; u <i; u ++){
            std::cout<<" ";
        }
        for(int u = i+1; u <= (i +n); u++){

            std::cout<<(u%10);
        }
        std::cout<<endl;
    }

}


int main(){
func(6);
return 0;


}
