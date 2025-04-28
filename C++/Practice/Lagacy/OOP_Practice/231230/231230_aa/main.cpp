#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Heart {
private:   
    float _purseRate; // 박동수
public:   
    Heart(float purseRate) 
        : _purseRate(purseRate) { cout << "Heart의 생성자" << endl; }
      ~Heart() 
      {
          cout << "Heart의 소멸자" << endl; 
      }

      void Show() 
      { 
          cout << "심장이 " << _purseRate << "로 뛰고 있습니다." << endl; 
      }
};
class Watch {
private:   
    string _color;
public:  
    Watch(string color)
        : _color(color)
    {
        cout << "Watch의 생성자" << endl; 
    }

      ~Watch() 
      { 
          cout << "Watch의 소멸자" << endl; 
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
          cout << _color << "Watch의 현재시각은 : " << t->tm_year + 1900 << "년 " << t->tm_mon << "월 " << t->tm_mday << "일 " << t->tm_hour << "시 " << t->tm_min << "분 입니다." << endl;
      }
};

class Human {
private:   
    Heart _heart; // 포함관계 Composition (강한결합) // 포함한객체와 생명주기를 같이함.   Watch& _refWatch; // 참조 관계 agreggation(약한결합) // 포함한 객체와 생명주기를 같이 하지 않음.
    Watch* _pWatch;
public:   
    Human(float purseRate, Watch* pWatch) 
        :_heart(purseRate), _pWatch(pWatch) 
    { 
        cout << "Human 생성자" << endl; 
    }
      ~Human() { 
          cout << "Human 소멸자" << endl; 
      }
      void ShowHeartRate() 
      { 
          _heart.Show(); 
      }

      void ChangeWatch(Watch* pWatch)
      {
          cout << _pWatch->GetColor() << "를 " << pWatch->GetColor() << "로 바꿔참" << "\n";

          _pWatch = pWatch;
      }

      void DisplayWatch() 
      { 
          _pWatch->DisplayCurrentTime(); 
      }
};

int main() {
    Watch redWatch("빨간");
    Watch blackWatch("검정");

    cout << "-------------------------- 프로그램 시작 -------------------------------\n";
    {     
        Human human(70, &redWatch);
        human.ShowHeartRate();      
        human.DisplayWatch();   

        human.ChangeWatch(&blackWatch);
        human.DisplayWatch();   
    }
    cout << "-------------------------- 프로그래밍 종료 -----------------------------\n";
}