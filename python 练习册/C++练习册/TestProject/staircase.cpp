#include <iostream>
int main();
int grin(double input);
double abs(double input);
int floor(double input);

int main() {
double x{};
std::cout << "Enter value of x: ";
std::cin >> x;
std::cout<<floor(x);
return 0;
}

// O(N) finding with cycles
// O(Log N) binsearch exists?
// O(1) typecasting solution exists.

int grin(double input){
    int i = 0;
    if (input == 0){
        return 0;
    }

    if (input > 0){

        while (i+1 <= input){
            ++i;
        }
        return i;
    }else{
        while (i > input){
            --i;
        }
        return i;
    }
}

double abs(double input){
    return input>0 ? input : -input;
}

int floor(double input){

    if (input > 2147483647){
        return 2147483647;
    }
    if (input < -2147483647){
        return -2147483648;
    }

    int mid = 0;
    int64_t left = -2147483650;
    int64_t right = 2147483649;
    while (abs(mid - input) >= 1){
        if (mid > input){
            right = mid;
            mid = (left + mid)/2;
        }else{
            left = mid;
            mid = (right + mid)/2;
        }
        if (left >= right){
            break;
        }
    }
    if (mid > input){
        mid--;
    }
    return mid;
}
