//변환 함수의 모호함
//  객체에서 변환 함수가 여러 개가 정의되어 있고 
//  그것을 cout 같은 여러 가지 자료형을 지원하는 것에서 변환 함수의 모호함이 발생합니다.

#include <iostream>
class Person {
private:
    int age;
public:
    Person(int p_age) {
        age = p_age;
    }
    explicit operator int() { return age; }              //변환 함수가 여러 개
    explicit operator double() { return double(age); }   //변환 함수가 여러 개
    explicit operator long() { return long(age); }       //변환 함수가 여러 개
};
int main(void) {
    Person per1 = 11;
    std::cout << (int)per1;                          //컴파일 에러
    return 0;
}