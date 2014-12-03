#include<iostream>
#include<string>
using namespace std;

class Resume
{
public:
        string name_, sex_, date_, company_;
        int age_;
        Resume(){};
        Resume(string mm){ name_=mm; }
        void SetPersonInfo(string sex, int age) {
                sex_ = sex;
                age_ = age;
                 } ;
        void SetWorkExperience(string date, string company) {
                date_=date;
                company_=company;  }
      void PrintOut(){
                cout << " Person: " << name_ << " " << sex_ <<" " << age_ <<endl;
                cout << " Working Experience: " << date_ << " " << company_ <<endl;

        }


        Resume Clone(){
                        return (*this);
                        }


};


int main(){

        Resume resume1("John Huang");
        Resume resume2;
        resume1.SetPersonInfo("M",30);
        resume1.SetWorkExperience("1998-2000","IBM");
        resume1.PrintOut();
        resume2=resume1.Clone();
        resume2.SetWorkExperience("2000-2005","Google");
        resume2.PrintOut();
}
