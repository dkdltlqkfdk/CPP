#include "1.hpp"
inline void MyDic::add(std::string eng,std::string kor){ //입력은 main에서 하되 배열에 저장하는
    words[nWord].eng=eng;
    words[nWord].kor=kor;
    nWord++;
}

inline void MyDic::store(std::string filename){ //단어쌍을 store함수에서 ofstream fout(filename)을 통해 파일 생성해서 그 안에 영구 저장
    std::ofstream fout("dic.txt");
    if (fout.is_open()) {
        for (int i = 0; i < nWord; i++) {
            fout << words[i].eng << " " << words[i].kor << std::endl;
        }
        fout.close();
        std::cout << "파일 저장 완료!" << std::endl;
    }
}

inline void MyDic::load(std::string filename){ //저장한 파일을 ifstream으로 열어서 다시 배열로 옮겨오는 과정, 읽기/복구
    std::ifstream fi("dic.txt");
    std::string e, k;
    if (fi.is_open()) {
        while (fi >> e >> k) { //공백을 기준으로 데이터를 뽑아서 e와 k라는 변수에 순서대로 담겠다는 뜻
            add(e, k); //과거에 저장했던 단어를 다시 배열에 복구하는 과정이
        }
        fi.close();
    }
}

inline void MyDic::print(){ //단어장 안에 모든 단어들을 print함수를 통해 다 출력
    std::cout << "\n=== 현재 단어장 목록 (" << nWord << "개) ===" << std::endl;
    for (int i = 0; i < nWord; i++) {
        std::cout << i + 1 << ". " << words[i].eng << " : " << words[i].kor << std::endl;
    }
}
inline std::string MyDic::getEng(int id){
    if (id >= 0 && id < nWord){
        return words[id].eng;
    }
    return "Error";
}
inline std::string MyDic::getKor(int id){
    if (id >= 0 && id < nWord){
        return words[id].kor;
    }
    return "Error";
}

int main(){
    MyDic mydic;
    std::string e,k;
    int max=MAXWORDS;
    mydic.load("dic.txt");
    mydic.print();
    std::cout << "총 " << MAXWORDS << "개의 단어를 입력받습니다." << std::endl;
    while (true) {
        std::cout << "영어 단어: ";
        std::cin >> e;

        if (e == "exit") {
            break; 
        }

        std::cout << "한글 설명: ";
        std::cin >> k;

        mydic.add(e, k);
    }
    mydic.store("dic.txt");
    mydic.print();
    std::cout << "프로그램을 종료합니다." << std::endl;
    return 0;
}