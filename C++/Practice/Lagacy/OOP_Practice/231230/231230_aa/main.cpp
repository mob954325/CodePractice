#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Heart {
private:   
    float _purseRate; // �ڵ���
public:   
    Heart(float purseRate) 
        : _purseRate(purseRate) { cout << "Heart�� ������" << endl; }
      ~Heart() 
      {
          cout << "Heart�� �Ҹ���" << endl; 
      }

      void Show() 
      { 
          cout << "������ " << _purseRate << "�� �ٰ� �ֽ��ϴ�." << endl; 
      }
};
class Watch {
private:   
    string _color;
public:  
    Watch(string color)
        : _color(color)
    {
        cout << "Watch�� ������" << endl; 
    }

      ~Watch() 
      { 
          cout << "Watch�� �Ҹ���" << endl; 
      }

      string GetColor() 
      { 
          return _color; 
      }

      void DisplayCurrentTime() 
      {
          time_t timer;      
          struct tm* t;      
          timer = time(NULL);      
          t = localtime(&timer);
          cout << _color << "Watch�� ����ð��� : " << t->tm_year + 1900 << "�� " << t->tm_mon << "�� " << t->tm_mday << "�� " << t->tm_hour << "�� " << t->tm_min << "�� �Դϴ�." << endl;
      }
};

class Human {
private:   
    Heart _heart; // ���԰��� Composition (���Ѱ���) // �����Ѱ�ü�� �����ֱ⸦ ������.   Watch& _refWatch; // ���� ���� agreggation(���Ѱ���) // ������ ��ü�� �����ֱ⸦ ���� ���� ����.
    Watch* _pWatch;
public:   
    Human(float purseRate, Watch* pWatch) 
        :_heart(purseRate), _pWatch(pWatch) 
    { 
        cout << "Human ������" << endl; 
    }
      ~Human() { 
          cout << "Human �Ҹ���" << endl; 
      }
      void ShowHeartRate() 
      { 
          _heart.Show(); 
      }

      void ChangeWatch(Watch* pWatch)
      {
          cout << _pWatch->GetColor() << "�� " << pWatch->GetColor() << "�� �ٲ���" << "\n";

          _pWatch = pWatch;
      }

      void DisplayWatch() 
      { 
          _pWatch->DisplayCurrentTime(); 
      }
};

int main() {
    Watch redWatch("����");
    Watch blackWatch("����");

    cout << "-------------------------- ���α׷� ���� -------------------------------\n";
    {     
        Human human(70, &redWatch);
        human.ShowHeartRate();      
        human.DisplayWatch();   

        human.ChangeWatch(&blackWatch);
        human.DisplayWatch();   
    }
    cout << "-------------------------- ���α׷��� ���� -----------------------------\n";
}