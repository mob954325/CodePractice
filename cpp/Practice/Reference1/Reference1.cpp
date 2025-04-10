#include <iostream>

void ChangeValueByValue(int x) {
    x = 999;  // ���� �� ���� �� ��
}

void ChangeValueByRef(int& x) {
    x = 999;  // ���� �� �����
}

int main() {
    int a = 1;

    ChangeValueByValue(a);   // ���� ����
    std::cout << a << "\n";  //  1

    ChangeValueByRef(a);     // ���� ����
    std::cout << a << "\n";  // 999
}
