#include<iostream>
#include<string>
using namespace std;

class WorkPlace
{
public:
        string company_, date_;
        WorkPlace(string date, string company){
                company_= company;
                date_=date; }
        WorkPlace(){};
};
class Resume
{
public:
        string name_, sex_, date_, company_;
        int age_;
        Resume(){};
        Resume(string mm){ name_=mm; }
        WorkPlace workplace;
        void SetPersonInfo(string sex, int age) {
                sex_ = sex;
                age_ = age;
                 } ;
        void SetWorkExperience(WorkPlace myworkplace) {
                workplace = myworkplace; // be careful here !! 
                  }

        void PrintOut(){
                cout << " Person: " << name_ << " " << sex_ <<" " << age_ <<endl;
              cout << " Working Experience: " << workplace.date_ << " " << workplace.company_ <<endl;

        }


        Resume Clone(){
                        return (*this);
                        }


};
int main(){

        Resume resume1("John Huang");
        Resume resume2;
        resume1.SetPersonInfo("M",30);
//      resume1.SetWorkExperience("1998-2000","IBM");
        WorkPlace mywork("1998-2000","IBM");
        resume1.SetWorkExperience(mywork);
        resume1.PrintOut();
        resume2=resume1.Clone();
        WorkPlace mywork2("2000-2005","Google");
        resume2.SetWorkExperience(mywork2);
        resume2.PrintOut();

}
