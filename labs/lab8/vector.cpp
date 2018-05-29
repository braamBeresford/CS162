#include "./vector.hpp"
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
using std::exception;
using std::out_of_range;

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   vector<int> test;
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   v.push_back(22);
   test = v;

   try{
   	   cout << "at" << v.at(100) << endl;

   }
   catch(out_of_range e){
   	std::cout << e.what() << std::endl;
   }
   cout << v[0] << ' '<< test[0] << endl;
      cout << v.at(0) << ' '<< test.at(0) << endl;

   cout << "Our vector size: " << v.size() << endl;



   return 0;
}

