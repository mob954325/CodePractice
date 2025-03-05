#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int sub(int a, int b)
//{
//	return a - b;
//}
//
//int mul(int a, int b)
//{
//	return a * b;
//}
//
//int division(int a, int b)
//{
//	if (!b)
//	{
//		cout << "두 수를 나눌 수 없습니다.\n";
//		return 0;
//	}
//
//	return a / b;
//}

//void GenerateNum(int *arr, int range)
//{
//	int check[3];
//
//	int loopNum = 0;
//
//	while (loopNum < 3)
//	{
//		int randNum = rand() % range + 1;
//
//		if (check[randNum] != 1)
//		{
//			*(arr + loopNum) = randNum;
//			check[randNum] = 1;
//
//			loopNum++;
//		}
//	}
//}


int main()
{
#pragma region asmd
	//int a, b, total;
	//
	//cout << "두 수를 스페이스로 구분하여 입력해주세요 > \n";
	//cin >> a >> b;
	//total = Add(a, b);
	//cout << total << "\n";
	//total = sub(a, b);
	//cout << total << "\n";
	//total = mul(a, b);
	//cout << total << "\n";
	//total = division(a, b);
	//cout << total << "\n";
#pragma endregion

#pragma region Pointer
	//int a = 3;
	//int* p = &a;

	//cout << p << " " << a;
#pragma endregion

#pragma region numBaseBall

	/*srand(time(NULL));

	int arr[3];
	int input, loopCount = 0, count = 0;

	cout << "< 숫자 야구 >" << endl;
	while (true)
	{
		cout << "숫자 범위를 지정해주세요 (4 - 100)" << endl;

		cin >> input;
		if (input < 4)
		{
			cout << "범위가 잘못 됬습니다" << endl;
		}
		else
		{
			break;
		}
	}
		
	GenerateNum(arr, input);

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl; 
	}
	cout << endl;


	while(true)
	{
		count = 0;
		int a, b, c;
		cout << "숫자 3개를 구분하여 입력해주세요" << endl;
		cin >> a >> b >> c;

		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == a
				|| arr[i] == b
				|| arr[i] == c)
			{
				count++;
			}
		}

		if (count == 3)
		{
			cout << "정답입니다." << loopCount << "번 만에 맞추셨습니다." <<endl;
			break;
		}
		else
		{
			cout << "S" << count << " " << "B" << 3 - count << endl;
		}
		loopCount++;
	}*/


#pragma endregion

#pragma region rotto
	//srand(time(NULL));
	//int atariNum[6];
	//
	//// 랜덤 정답 수 넣기
	//for (int i = 0; i < 6; i++)
	//{
	//	atariNum[i] = rand() % 45;
	//}
	//
	////// 정답번호 출력
	////for (int i = 0; i < 6; i++)
	////{
	////	cout << atariNum[i] << " " << endl;
	////}
	//
	//int inputArr[6];
	//int input, count = 0;
	//for (int i = 0; i < 6; i++)
	//{
	//	cin >> input;
	//	inputArr[i] = input;
	//}
	//
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 6; j++)
	//	{
	//		if (atariNum[i] == inputArr[j])
	//		{
	//			count++;
	//		}
	//	}
	//}
	//
	//
	//switch (count)
	//{
	//	case 1:
	//		cout << "6등" << endl;
	//		break;
	//	case 2:
	//		cout << "5등" << endl;
	//		break;
	//	case 3:
	//		cout << "4등" << endl;
	//		break;
	//	case 4:
	//		cout << "3등" << endl;
	//		break;
	//	case 5:
	//		cout << "2등" << endl;
	//		break;
	//	case 6:
	//		cout << "1등" << endl;
	//		break;
	//	default:
	//		cout << "아쉽" << endl;
	//		break;
	//}

#pragma endregion

int num = 3 && 2;

	cout << num;
}