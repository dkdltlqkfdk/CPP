#include<iostream>
#include<string>
#include<fstream> //open() 함수를 통해 파일을 열거나 파일 존재 안하면 자동 생성. 스트림 클래스
#define MAXWORDS 40
struct WordPair{
    std::string eng;
    std::string kor;
};
class MyDic{
    private:
        WordPair words[MAXWORDS];
        int nWord=0;
    public:
        void add(std::string eng,std::string kor);
        void load(std::string filename);
        void store(std::string filename);
        void print();
        std::string getEng(int id);
        std::string getKor(int id);
};
