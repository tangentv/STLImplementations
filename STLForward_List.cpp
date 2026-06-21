/*
Single list list
- it supports fast insertion and deletion from anywhere in the container.
- provide more space effecient approach as only single pointer is needed for traversal
*/

#include <iostream>
#include <forward_list>
#include <string>
#include <vector>

void printForwardList(std::forward_list<int> flist){
    std::for_each(flist.begin(), flist.end(), [](const int i){
        std::cout<< i <<" ,";
    });

    std::cout<<std::endl<<std::endl;
}

struct Sum{
    std::string str;
    int value;

    Sum(std::string s, int n):str(s), value(n){

    }

    void printSumList(){
        std::cout<< str << " "<< value << std::endl;
    }

};

int main(){

    std::forward_list<std::string> myList;
    //push_front() -> prepend an element to the beginning of the list
    myList.push_front("hello");
    myList.push_front("my");
    myList.push_front("name");
    myList.push_front("Tanvi");
    std::string s = "word";
    myList.push_front(std::move(s));

    for(auto a : myList){
        std::cout<< a << " ";
    }
    std::cout<<std::endl;

    //front()

    std::string frontValue = myList.front();
    std::cout<<"Front Value of the forward list is : "<<frontValue <<std::endl;

    //before_begin()
    //cbefore_begin() - >


    

    //emplace_front()
    //TODO

    
;

    
    //begin() / cbegin() -> returns the iterator to yhe first element of the forward_list
    //end() / cend() -> returns an iterator to the last element of the forward_list
    std::forward_list<std::string> fruits{"orange", "apple", "mango", "banana", "cheeku", "pineapple"};
    std::cout<<std::endl<<std::endl<<"Fruits are :"<<std::endl;
    std::for_each(fruits.begin(), fruits.end(),[](const std::string s){
        std::cout<<s << ", ";
    });
    std::cout<<std::endl<<std::endl;

    //empty() and clear()
    std::cout<<"Is myList empty             : "<<myList.empty() <<std::endl;
    myList.clear();
    std::cout<<"Is myList empty after clear : "<<myList.empty() <<std::endl;

    // max_size() ->returns the max size of the forward_list
    std::cout<<"Max size of fruit list is   :"<<fruits.max_size()<<std::endl;

    /*insert_after() ->insert element after specidic location in the container
    3 ways -
    1. insert value at a position.
    2. insert count copies of the value after the element pointed to by position
    3. insert ehe elements from another container after the element pointed by position
    4. insert elements from the initializer list 
    */
    std::forward_list<int> ints{1,2,3,4,5,6};
    printForwardList(ints);

    ints.insert_after(ints.begin(), -6);
    printForwardList(ints);

    ints.insert_after(ints.before_begin(), -6);
    printForwardList(ints);

    ints.insert_after(ints.begin()++ , 2, -7);
    printForwardList(ints);

    ints.insert_after(ints.before_begin()++ , 2, -8);
    printForwardList(ints);

    const std::vector<int> v{11,12,13,14};
    ints.insert_after(ints.before_begin(), v.begin(), v.end());
    printForwardList(ints);

    //ints.insert_after(ints.begin(), {"99,98,97,96,95"});
    //printForwardList(ints);
 //////////////////////////////////////////////////////////////////////

    //emplace_after() -> inserts a new element into a position after the specified position in the container. 
    //no copy or move operations are performed. 
    //the constructor of theelement is called with exactly the same argument as supplied to the function
    //return - iterator to the new value.

    std::forward_list<Sum> sumList;

    for(int i = 0; i<10; i++){
        sumList.emplace_after(sumList.before_begin(), "no. - ", i);
    } 

    std::cout<<"Printint list from Sum List - "<<std::endl;
    for(Sum& a : sumList){
        a.printSumList();
    }

    //insert_range_after()
    //TODO


    //erase_after() - Removes specisic elements from the container
    /*
    1. Remove the element following position
    2. Removes the elements following first until last
    - returns - iterator to the following the erased one or end() if no such elenment 
    */

    std::forward_list<int> l {1,2,3,4,5,6,7,8};

    std::cout<<"Testing erase_after function : "<<std::endl;
    printForwardList(l);

    //l.erase_after(l.before_begin());
    auto fi = std::next(l.begin());
    auto la = std::next(fi,3);
    std::cout<<"fi value is :"<<*fi << std::endl;
    std::cout<<"la value is :"<<*la << std::endl;
    l.erase_after(std::next(l.begin()), la); // erase the values between fi and la, keeping both fi and la intact.
    printForwardList(l);    
    
    //prepend_range
    //TODO


    //pop_front() - removes the first element

    std::cout<<"List after pop_front() functionality : "<<std::endl;
    l.pop_front();
    printForwardList(l);

    //resize() -> changes the number of elements stored
    std::cout<<"Resized forward list :"<<std::endl;
    l.resize(15);
    printForwardList(l);

    l.resize(20,-1);
    printForwardList(l);
    

    //swap() -> exchange the content of one container to another
    //does not invoke, move, copy or swap operations on individual.
    std::cout<<"Swap functionality : "<<std::endl;
    std::forward_list<int> a1{1,2,3,4,5,6,7,8,9};
    std::forward_list<int> a2{11,12,13,14,15,16};
    std::cout<<"element initial a1  : "<<std::endl;
    printForwardList(a1);
    std::cout<<"element initial a2  : "<<std::endl;
    printForwardList(a2);

    // auto itr1 = a1.begin();
    // auto itr2 = a2.begin();
    a1.swap(a2);

    std::cout<<"after swap a1       : "<<std::endl;
    printForwardList(a1);
    std::cout<<"after swap a2       : "<<std::endl;
    printForwardList(a2);

    //merge - merge other container to this forward list
    std::forward_list<int> a3{5, 9, 1, 3, 3};
    std::forward_list<int> a4{8, 7, 2, 3, 4, 4};

    a3.sort();
    a4.sort();
    a3.merge(a4);//if either the list is unsorted then the result in undefined. Hence'we need to sort the list before merging
    std::cout<<"Merged list : "<<std::endl;
    printForwardList(a3);


    //splice_after ->
    /*
    Moves elements from another forward list to *this list
    after the element pointer by position
    - elements are not copied, they are moved.
    - Moves all elements from 'other' list into *this. The container 'other' becomes empty after the operation.
    - Moves the element pointed to by the iterator following it from 'other' into *this
    - Moves the elements in the range (first, last) from other into *this. The element pointed-to by first is not moved.
    */

    std::forward_list<int> list1 {1,2,3,4,5,6,7};
    std::forward_list<int> list2 {11,12,13,14,15,16,17,18};

    std::cout<<"List1 container initial data    "<<std::endl;
    printForwardList(list1);
    std::cout<<"List2 container initial data    "<<std::endl;
    printForwardList(list2);
    
    //list1.splice_after(list1.before_begin(), list2); ////Moves all elements from list2 into list1
    list1.splice_after(list1.before_begin(), list2, list2.before_begin(), list2.end()); //Moves all elements from list2 into list1

    std::cout<<"List1 container after splice    "<<std::endl;
    printForwardList(list1);
    std::cout<<"List2 container after splice    "<<std::endl;
    printForwardList(list2);


    //remove / remove_if - remove elemetn satisfying particular criteria
    std::forward_list<int> list3 = {1, 100, 8,9,2,4,5,7,1, 3, 10, 1, 11, -1, 12,11,12,13};
    printForwardList(list3);
    auto count1 = list3.remove(1); //remove duplicates as well
    std::cout<<"Remove elements which is equal to 1 "<<std::endl;
    printForwardList(list3);

    auto count2 = list3.remove_if([](int n){
        return n > 10;
    });
    std::cout<<"Eleemnts greater than 10 are removed"<<std::endl;
    printForwardList(list3);

    //reverse - reverse the order of the elements
    list3.reverse();
    printForwardList(list3);

    //unique - removes consecutive duplicate elements , only deleted consecutive duplicate elememnt, 
    std::forward_list<int> list4 = {1, 100, 100,2, 8,9,2,4,5,7,1, 3,3, 10, 1,100 ,11, 10, -1, 12,11,12,13};
    std::cout<<"with duplicates " <<std::endl;
    printForwardList(list4);
    list4.unique();
    std::cout<<"without duplicates" <<std::endl;
    printForwardList(list4);


    //sort - sort the forward list in ascending order.
    std::forward_list<int> list5 = {1, 100, 100,2, 8,9,2,4,5,7,1, 3,3, 10, 1,100 ,11, 10, -1, 12,11,12,13};
    list5.sort();
    std::cout<<"Sorted list is :";
    printForwardList(list5);

    list5.unique();
    std::cout<<"without duplicates after sort " <<std::endl;
    printForwardList(list5);


    return 0;
}