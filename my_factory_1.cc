#include<iostream>
using namespace std;

class Operation
{
  public:
         static Operation *make_operation(int choice);
            virtual void operation(int aa, int bb) = 0;
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

Operation* Operation::make_operation(int choice)
{
  if (choice == 1)
    return new Add;
  else
    return new Mult;
}

int main()
{
  Operation* roles;
  int choice;
  cout << "Sum(1) Multi(2): ";
    cin >> choice;
    roles=   Operation::make_operation(choice);
  roles->operation(4,2.);
}

