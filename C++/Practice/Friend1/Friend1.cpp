#include <iostream>

class MyClass {
private:
    int secret = 42;

    // 이 함수는 클래스 외부지만 friend로 내부 접근 허용됨
    // 클래스 내부에서 구현도 가능하지만 전역함수로 구분됨.
    friend void PrintSecret(const MyClass& obj);
};

//전역함수
void PrintSecret(const MyClass& obj) {
    std::cout << obj.secret << std::endl; // private 멤버 접근 가능!
}

int main()
{
    MyClass myClass;
    PrintSecret(myClass);
}