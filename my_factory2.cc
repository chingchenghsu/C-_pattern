#include<iostream>
#include<string>
#include <sstream>
using namespace std;

class Operation
{
private:
        double a,b;
        int number;
        string operand;

public:
        double get_operated();
        Operation(double aa, double bb, int num){a=aa;
        b =bb;
        number =num;
//      operand =operatnd100;   
  }
//      static enum StringValue {"+","-","*","/"};
        ~Operation(){};
};
//static enum StringValue {"+","-","*","/"};

double Operation::get_operated()
{
        double c;
switch((*this).number)
        {
        case 1:
                c = (*this).a+(*this).b;
                break;
        case 2:
                c = (*this).a-(*this).b;
                break;
        case 3:
                c = (*this).a*(*this).b;
                break;
        case 4:
                c= (*this).a/(*this).b;
                break;
        }
        return c;
}
int main(){
        double x,y;
        int num;
        string mystring;
        cout << " input an double: " <<endl;
        cin >> x;
        cout << " input an double: " <<endl;
        cin >> y;
        cout << " input oepration string: " <<endl;
        cin >> num ;
        Operation myoperation(x,y,num);
        cout << myoperation.get_operated() <<endl;

}
