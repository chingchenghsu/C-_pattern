#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
        Person(){};
        virtual void Legs() =0;
        virtual void Nose() =0;
        void Eyes() {cout << "I have Eyes" <<endl; };
        void Hands(){cout<< "I have Hands"<<endl; };
};
class TallPerson : public Person
{
public:
        TallPerson(){cout << "I am tall person" <<endl;};
        void Legs(){ cout <<"I have Long Legs" <<endl;}
        void Nose(){ cout <<"I have Nose " <<endl;}
};

class HighNosePerson : public Person
{
public:
        HighNosePerson(){cout << "I have high nose person"<<endl;};
        void Nose(){ cout <<" I have High Nose" <<endl;}
        void Legs(){ cout <<" I have Legs " <<endl;}
};
class PersonBuilder
{
public:
        Person * thisperson_;
        PersonBuilder(Person * thisperson) {
                thisperson_ = thisperson;
}
        void Create(){
                thisperson_->Legs();
                thisperson_->Nose();
                thisperson_->Eyes();
                thisperson_->Hands();
                        }
};
int main()
{
        TallPerson myperson;
        PersonBuilder my_personbuilder(&myperson);
        my_personbuilder.Create();
}
