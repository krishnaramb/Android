#include <iostream>
#include <memory>


class Vector{
private:
    int sz;
    int* ptr;
public:
    Vector():sz(0),ptr(nullptr){ std::cout<<"default constructor called\n";}
    Vector(int sz):sz(sz)
    {
      ptr = new int[sz];
      std::cout<<"constructor called";
    }
    ~Vector(){
      std::cout<<"Destructor called\n";
      delete[] ptr;

    }

    int get_size(){
      return sz;
    }
};


int main()
{
  std::cout<<"In main\n";
  Vector* v1 = new Vector;
  std::shared_ptr<Vector> s_ptr =(std::shared_ptr<Vector>) new Vector(2);
  std::cout<<"sz:v1 "<<(v1[2]).get_size()<<"\n";
  std::cout<<"sz:sptr: "<<(s_ptr.get())->get_size()<<"\n";
  // delete[] v1;
  std::cout<<"end of  main\n";
}
