#include<iostream>
using namespace std;

class Operation
{
  public:
         Operation make_operation(int choice);
         void operation(int aa, int bb) ;
};

class Add: public Operation
{
  public:
    void operation(int aa, int bb)
    {
        cout << "The sum: " << (aa+bb)<<endl;
    }
};

class Mult: public Operation
{
  public:
    void operation(int aa, int bb)
    {
        cout << "The products: " << aa*bb<<endl;
    }
};
Operation Operation::make_operation(int choice)
{
  if (choice == 1)
    return Add;
  else
    return Mult;
}

int main()
{
  Operation roles;
  int choice;
  cout << "Sum(1), Multi(2): ";
    cin >> choice;
    roles.make_operation(choice);
    roles.operation(4,2.);
}
