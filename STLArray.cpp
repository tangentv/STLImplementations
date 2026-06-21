#include <iostream>
#include <array>

//it is a fixed size

int main(){

    std::array<int,10> arr{1,3,4,11,0,9,4,5,7,8}; 

    for(auto a : arr){
        std::cout<<a<<std::endl;
    }

    std::cout<<std::endl<<std::endl;
    
    //accessing the elements of an array
    //int a = arr.at(1);
    //int a = arr[1];
    //int a = arr.front();
    //int a = arr.back();
    int a = arr.back();
    std::cout<<"Accessing element using at : "<<a<<std::endl;

    return 0;
}