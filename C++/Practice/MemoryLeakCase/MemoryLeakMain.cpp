//다양한 메모리 누수 케이스를 예시로 만들어 보세요

//1. 주소 상실
//2. 해제 없음
//3. 중복 할당
//4. 중복 해제

#include <iostream>

using namespace std;

int main()
{
	// p1, p2 생성
	int* p1 = new int;
	int* p2 = new int;

	cout << "original p1 address : " << p1 << "\n";
	cout << "original p2 address : " << p2 << "\n";
	int* legacyP1 = p1;

	p1 = new int;	// 새 주소 할당으로 인해 이전 주소 접근 불가
	cout << "\n--- p1한테 중복 할당 \n";
	cout << "legacy   p1 address : " << legacyP1 << "\n";	// 기존 original 주소에서 다른 주소로 변경됨
	cout << "new      p1 address : " << p1 << "\n";			// 기존 original 주소에서 다른 주소로 변경됨
	cout << "original p2 address : " << p2 << "\n";			// 기존 주소 유지

	int* p3 = new int;
	delete p3;
	//delete p3;		// p3 중복해제 (Undefined Behavior)

	delete legacyP1;	// legacy P1 주소 해제
	delete p2; 
} // p1 해제안함 -> 메모리 누수 발생