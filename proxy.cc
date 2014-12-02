#include<iostream>
#include<string>
using namespace std;

class SchoolGirl
{
public:
        string name;
        int age;
        SchoolGirl() { };
        SchoolGirl(int a, string b) {name = b; age =a; }
};


class GiveGift
{
public:
        virtual void GiveFlower() =0;
        virtual void GiveDoll() =0;
        virtual void GiveCandy() =0;
};

class Pursuiter : public GiveGift
{
public:
        SchoolGirl girl;
        Pursuiter(){};
        Pursuiter(SchoolGirl mm) {
                (*this).girl =mm;
                }

        void GiveDoll()
         { cout<< girl.name <<", I love you, I send you a Dool !" <<endl;  }
        void GiveFlower()
         { cout<< girl.name <<", I love you, I send you a Flower !" <<endl;  }
        void GiveCandy()
         { cout<< girl.name <<", I love you, I send you a Candy !" <<endl;  }

};
class Proxyer : public GiveGift
{
        Pursuiter gg;
public:
        int age;
        string name;
        Proxyer(int a, string b, SchoolGirl mm) {
                gg.girl =mm;
                (*this).age = a;
                (*this).name = b;
                                 }
         void GiveDoll()
         {    gg.GiveDoll();   }
        void GiveFlower()
         { gg.GiveFlower();  }
        void GiveCandy()
         { gg.GiveCandy();  }

};
int main(){
        SchoolGirl Mary(26,"Mary Lee");
        cout << "The girl name is : " << Mary.name <<endl;
        Proxyer John(30,"John Huang", Mary);
        John.GiveDoll();
        John.GiveCandy();
        John.GiveFlower();
        cout << " But I am : " << John.name << ", just a proxy of my boss! " <<endl;
}
