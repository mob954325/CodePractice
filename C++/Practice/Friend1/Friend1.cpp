#include <iostream>

class MyClass {
private:
    int secret = 42;

    // �� �Լ��� Ŭ���� �ܺ����� friend�� ���� ���� ����
    // Ŭ���� ���ο��� ������ ���������� �����Լ��� ���е�.
    friend void PrintSecret(const MyClass& obj);
};

//�����Լ�
void PrintSecret(const MyClass& obj) {
    std::cout << obj.secret << std::endl; // private ��� ���� ����!
}

int main()
{
    MyClass myClass;
    PrintSecret(myClass);
}