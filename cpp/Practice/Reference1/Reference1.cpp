#include <iostream>

void ChangeValueByValue(int x) {
    x = 999;  // 원본 값 변경 안 됨
}

void ChangeValueByRef(int& x) {
    x = 999;  // 원본 값 변경됨
}

int main() {
    int a = 1;

    ChangeValueByValue(a);   // 값만 복사
    std::cout << a << "\n";  //  1

    ChangeValueByRef(a);     // 참조 전달
    std::cout << a << "\n";  // 999
}
