#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

class home_appliances{
        public:
        string name;
};

class tv:public home_appliances{
        public:
        string condition(){
            return "is playing programs.";
        }
};

class wash:public home_appliances{
        public:
        string condition(){
            return "is washing clothes.";
        }
};

class refrigerator:public home_appliances{
        public:
        string condition(){
            return "is cooling.";
        }
};

class microwave:public home_appliances{
        public:
        string condition(){
            return "is heating foods.";
        }
};

int main(){
    int type;
    string name;
    while(cin>>type>>name){
        if(type == 1){
            tv tv1;
            tv1.name = name;
            cout<<tv1.name<<" "<<tv1.condition()<<endl;
        }else if(type == 2){
            wash wash1;
            wash1.name = name;
            cout<<wash1.name<<" "<<wash1.condition()<<endl;
        }else if(type == 3){
            refrigerator refrigerator1;
            refrigerator1.name = name;
            cout<<refrigerator1.name<<" "<<refrigerator1.condition()<<endl;
        }else if(type == 4){
            microwave microwave1;
            microwave1.name = name;
            cout<<microwave1.name<<" "<<microwave1.condition()<<endl;
        }
    }
}
