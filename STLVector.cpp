#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

std::ostream& operator<<(std::ostream& s , const std::vector<int> v){
    for(auto e : v ){
        std::cout<< e << ", ";
    }
    //std::cout<<std::endl << std::endl;
    return s;
}

void println(std::vector<int> v){
    for(const auto a : v){
        std::cout<<a<<" , ";
    }
    std::cout<<std::endl<<std::endl;
}

//Rule of 5
struct  A{
    std::string s;

    A(std::string str): s(std::move(str)){
        std::cout<<"Constructor called"<<std::endl;
    }

    A(const A& obj):s(obj.s){
        std::cout<<"Copy Constructer called"<<std::endl;
    }
    A& operator=(const A& obj){
        s = obj.s;
        std::cout<<"copy assignment "<<std::endl;
        return *this;
    }

    A(A&& obj):s(std::move(obj.s)){
        std::cout<<"Move copy"<<std::endl;
    }

    A& operator=(A&& obj){
        s = std::move(obj.s);
        std::cout<<"Move assigned"<<std::endl;
        return *this;
    }
};

int main(){

    //Constructing a vector
    std::vector<int> arr1{1,3,4,6,7};
    std::cout << "1: "<<arr1;
    std::cout<<std::endl<<std::endl;

    std::vector<int> arr2(arr1.begin(), arr1.end());
    std::cout << "2: "<< arr2;
    std::cout<<std::endl<<std::endl;

    std::vector<int> arr3(arr2);
    std::cout << "3: "<< arr3;
    std::cout<<std::endl<<std::endl;

    std::vector<int> arr4(10, -1);
    std::cout << "4: "<< arr4;
    std::cout<<std::endl<<std::endl;



    //access the element with bound checking
    std::cout<<"access the element of vector : " << std::endl;
    std::cout<< "1. " << arr1.at(2) <<std::endl;
    //std::cout<< "1. " << arr1.at(7) <<std::endl; // gives an array, does bound checking

    //access specified element without bound checking
    std::cout<< "2. " << arr1[1] <<std::endl;
    std::cout<< "3. " << arr1[7] <<std::endl; //gives zero value if we check value out of the array

    //access the first element of an array
    std::cout<< "4. front : " << arr1.front() <<std::endl;

    //access the last element of an array
    std::cout<<"5. back : " << arr1.back() <<std::endl;


    //iterators

    // return and iterator to the beginning  - begin() and cbegin()
    // begin() -------> returns a mutable iterator of the vector
    // cbegin() ------> returns a constant iterator ( we can't modify the vector values)
    std::vector<int> nums{1,2,3,4,5,6};

    std::vector<std::string> names{"Tanvi", "Rashmi", "Anamika", "Juili", "Ranjana"};

    std::cout<<std::endl<<std::endl;
    std::for_each(nums.begin(), nums.end(),[](const int n){
        std::cout<< n << ", ";
    });
    std::cout<<std::endl<<std::endl;

    // returns an iterator to the element following the last element of the vector
    // element acts as a placeholder, attemting to access it results in undefined behavior.
    // end() ------>
    // cend() ----->

    //--TODO
    // std::string str = *names.end();
    // std::cout<<"names last element : "<< str << std::endl;

    /*
    TODO -
    rbegin(), crbegin() -> returns a reverese iterator to the beginning
    rend() , crend() -> returns a reverse iterator to the end
    */



    // Capacity

    //empty
    std::vector<int> numbers;
    std::cout<<"Is number empty: "<< numbers.empty() <<std::endl;
    numbers.push_back(44);
    std::cout<<"Checking if the number is empty: "<< numbers.empty() <<std::endl;

    for(int i = 0;i<9;i++){
        numbers.push_back(numbers[i]+3);
    }

    std::cout<<"Size of mnumbers vector : "<<numbers.size() <<std::endl;

    //maximum number of elements the container is able to hold due to system or library imlementation limitations
    std::cout<<"Maximum size of numbers vector: " << numbers.max_size() << std::endl;
    std::cout<<"Capacity of numbers vector: "<<numbers.capacity() << std::endl;
    
    //reserve - increase the capacity of vector to a value which is greater than or equal to new capacity of vector.

    constexpr int  max_element = 64;

    std::cout<<std::endl << "Using reserve: "<<std::endl;
    {
        std::vector<int> v1;
        v1.reserve(max_element);

        for(int i = 0; i < max_element;i++){
            v1.push_back(i);
        }
    }

    //shrint_to_fit ---> reduces memory usage by freeing unused memory
    // it reduces the capacity to size of vector

    std::vector<int> shrinkableVector;
    for(int i = 0; i<200 ; i++){
        shrinkableVector.push_back(i);
    }
    std::cout<<"Capacity of an shrinakable vector                           : "<<shrinkableVector.capacity()<<std::endl;
    shrinkableVector.shrink_to_fit();
    std::cout<<"Capacity of shrinkable vector after shrin_to_fit operation  : " << shrinkableVector.capacity()<< std::endl;
    


    //Modifiers

    //clear -> clears the cintent of vector
    shrinkableVector.clear();
    std::cout<<"Capacity of an shrinakable vector after clear operation     : "<<shrinkableVector.capacity()<<std::endl;
    
    //insert -> inserts an element
    std::vector<int> c1(3,100);
    println(c1);
    c1.insert(c1.begin(), 200);
    println(c1);
    c1.insert(c1.begin(), 2, 300);
    println(c1);

    std::vector<int> c2(3,400);
    c1.insert(std::next(c1.begin(),2),c2.begin(), c2.end());
    println(c1);

    int arr[] = {501,502,503};
    c1.insert(c1.begin(), arr, arr + std::size(arr));
    println(c1);

    c1.insert(c1.end(), {601, 602, 603});
    println(c1);


    //insert_range -> inserts a range of elements



    //emplace -> construct an element in place
    std::vector<A> container;
    container.reserve(10);
    A two{"two"};
    A three{"three"};

    container.emplace(container.end(), "one"); // constructor called

    container.emplace(container.end(), two);// copy constructor called

    container.emplace(container.end(), std::move(three));// Move copy

    std::cout<<std::endl<<std::endl;
    for(const auto& a : container){
        std::cout << a.s << "  ";
    }
    std::cout<<std::endl;


    //erase -> erases a specified element from the vector
    std::vector<int> c{0,1,2,3,4,5,6,7,8,9};
    println(c);
    c.erase(c.begin());
    println(c);

    c.erase(c.begin()+2, c.begin()+5);
    println(c);

    //push_back -> adds an element to the end
    



    //emplace_back -> construct an element in-place at the end
    //append_range -> adds a range of elements to the end
    //pop_back -> removes the last element
    //resize -> changes the number of elements stored
    //swap -> swaps the content


    return 0;
}