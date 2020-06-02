#include <iostream>

class Vehicle
{
private:
    int x;
public:
  void setx(int data)
  {
    x = data;
  }
 int getx()
  {
    return x;
  }
};


class derived:public Vehicle
{
  private:
    int hehe;
  public:
  void sethehe(int data)
  {
      hehe = data;
  }

  int gethehe()
  {
    return hehe;
  }
};

int main()
{

  Vehicle* Obj = new derived;
  Obj->sethehe(10);
  std::cout<<Obj->gethehe();
  return 0;

}
