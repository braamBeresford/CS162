#include <stdlib.h>
#include <exception>
#include <stdexcept>
#include <iostream>
using std::exception;
using std::out_of_range;
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }

      vector(vector<T> &other){
      	this->s = other.s;
      	if(this->v!=NULL&& this->s > 0)
      		for(int i =0; i <other.s; i++)
      			this->v[i] = other.v[i];
      	else
      		this->v=NULL;
      }

  		void operator=(vector<T> &other){
  			if(this->v != NULL)
  				delete this->v;

  			this->s = other.s;
  			v = new int[s];
  			if(this->v!=NULL && this->s>0)
      			for(int i =0; i < other.s; i++)
      				this->v[i] = other.v[i];
      		else
      			this->v = NULL;

      		// return *this;
  		}

  		T operator[](int i){
  			return this->v[i];
  		}

  		T at(int i){
	  			if(i <= this->s)
	  				return this->v[i];
	  			else
	  				throw std::out_of_range("out of my vector bounds");
 			// return NULL;
  		}

	  
      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }
};
