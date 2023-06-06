#include <iostream>

using namespace std;
int main();
char *concatenate( char *s_s1, char *s_s2 ) {
    int ct = 0;
    int i = 0;
    int len1 = 0;
    int len2 = 0;
    while (s_s1[i] != '\0'){
        ct ++;
        i++;
        len1 ++;
    }
    i = 0;
    while (s_s2[i] != '\0'){
        ct ++;
        i++;
        len2++;
    }

    char *newList = new char[ct+1]{};

    for(int ind = 0; ind < len1; ind ++){
        newList[ind] = s_s1[ind];
    }
    for(int ind = len1; ind < len1+len2; ind++){
        newList[ind] = s_s2[ind-len1];
    }
    return newList;
}


int main(){

cout<<concatenate("12345","67890");

return 0;

}
