/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 12 April 2019, 5:41 PM
 * Purpose:  Vectors
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <vector> 

using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Vectors ex 1
    vector<int> g1; 
    cout<<"Vector ex 1"<<endl;
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Output of begin and end: "; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of cbegin and cend: "; 
    for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of rbegin and rend: "; 
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
        cout << *ir << " "; 
  
    cout << "\nOutput of crbegin and crend : "; 
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
        cout << *ir << " "; 
    
    //Vector ex 2
    vector<int> g2; 
    cout<<endl<<endl<<"Vector ex 2"<<endl;
    for (int i = 1; i <= 5; i++) 
        g2.push_back(i); 
  
    cout << "Size : " << g2.size(); 
    cout << "\nCapacity : " << g2.capacity(); 
    cout << "\nMax_Size : " << g2.max_size(); 
  
    // resizes the vector size to 4 
    g2.resize(4); 
  
    // prints the vector size after resize() 
    cout << "\nSize : " << g2.size(); 
  
    // checks if the vector is empty or not 
    if (g2.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
  
    // Shrinks the vector 
    g2.shrink_to_fit(); 
    cout << "\nVector elements are: "; 
    for (auto it = g2.begin(); it != g2.end(); it++) 
        cout << *it << " "; 
  
    cout<<endl<<endl<<"Vector ex 3"<<endl;
    vector<int> g3; 
  
    for (int i = 1; i <= 10; i++) 
        g3.push_back(i * 10); 
  
    cout << "\nReference operator [g] : g3[2] = " << g3[2]; 
  
    cout << "\nat : g3.at(4) = " << g3.at(4); 
  
    cout << "\nfront() : g3.front() = " << g3.front(); 
  
    cout << "\nback() : g3.back() = " << g3.back(); 
  
    // pointer to the first element 
    int* pos = g3.data(); 
  
    cout << "\nThe first element is " << *pos; 
    
    cout<<endl<<endl<<"Vector ex 4"<<endl;
    // Assign vector 
    vector<int> v; 
  
    // fill the array with 10 five times 
    v.assign(5, 10); 
  
    cout << "The vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
  
    // inserts 15 to the last position 
    v.push_back(15); 
    int n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
  
    // removes last element 
    v.pop_back(); 
  
    // prints the vector 
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
  
    // inserts 5 at the beginning 
    v.insert(v.begin(), 5); 
  
    cout << "\nThe first element is: " << v[0]; 
  
    // removes the first element 
    v.erase(v.begin()); 
  
    cout << "\nThe first element is: " << v[0]; 
  
    // inserts at the beginning 
    v.emplace(v.begin(), 5); 
    cout << "\nThe first element is: " << v[0]; 
  
    // Inserts 20 at the end 
    v.emplace_back(20); 
    n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
  
    // erases the vector 
    v.clear(); 
    cout << "\nVector size after erase(): " << v.size(); 
  
    // two vector to perform swap 
    vector<int> v1, v2; 
    v1.push_back(1); 
    v1.push_back(2); 
    v2.push_back(3); 
    v2.push_back(4); 
  
    cout << "\n\nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 
  
    // Swaps v1 and v2 
    v1.swap(v2); 
  
    cout << "\nAfter Swap \nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 
    //Exit the program
    return 0;
}