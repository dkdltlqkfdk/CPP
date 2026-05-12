#include "1.hpp"

int Sample::count=0;

Sample::Sample(const char* name){ //(2)
    int i=0;
    this->name= new char[size];
    while(name[i]!='\0'){
        this->name[i]=name[i];
        i++;
    }
    this->name[i]='\0';
    count++;
}
Sample::Sample(const Sample& s){ //(4)
    this->name=new char[size];
    strcpy(this->name,s.name);
}
Sample::~Sample(){  //(3)
    delete[] this->name;
}
void Sample::printCount(){  //(1)
    printf("클래스 Sample의 객체 수는 %d\n",count);
}

int main(){
    Sample a("sample");
    Sample b("a");
    a.printCount();
    return 0;
}