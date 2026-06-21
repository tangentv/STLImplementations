/*
Double ended queue
sequence container that allows fast insertion and deletion at both its beginning and end.
it has all the functionality as vector. Added functionality in dequeue -
- push_front()
- emplace_front()
- prepend_range()
- pop_front()

*/
#include <iostream>
#include <deque>
#include <vector>

int main(){ 

    std::deque<std::string> words;
    //push_front() - > prepend the value to the beginning of the container
    words.push_front("Hello");
    std::string s = "Words";
    words.push_front(std::move(s));

    for(auto a : words){
        std::cout << a << " ";
    }
    std::cout<<std::endl;

    //emplace_front() - > construct an element in place at the beginning

    //prepend range() -> adds a range of elements to the beginning
    // insert in non reversing order, copies of elemnt from container whose values are converted to 
    // the deque

    std::deque<int> d{1,2,3,4,5};
    std::vector<int> v {10,11,12,13};
    
    d.prepend_range(v);

    for(auto a : d){
        std::cout<<a <<" ,";
    }
    std::cout<<std::endl << std::endl;


    //pop_front() -> removes the first element
    d.pop_front();
    for(auto a : d){
        std::cout<<a <<" ,";
    }
    std::cout<<std::endl << std::endl;

    return 0;
}