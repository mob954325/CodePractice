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
//		cout << "�� ���� ���� �� �����ϴ�.\n";
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
	//cout << "�� ���� �����̽��� �����Ͽ� �Է����ּ��� > \n";
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

	cout << "< ���� �߱� >" << endl;
	while (true)
	{
		cout << "���� ������ �������ּ��� (4 - 100)" << endl;

		cin >> input;
		if (input < 4)
		{
			cout << "������ �߸� ����ϴ�" << endl;
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
		cout << "���� 3���� �����Ͽ� �Է����ּ���" << endl;
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
			cout << "�����Դϴ�." << loopCount << "�� ���� ���߼̽��ϴ�." <<endl;
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
	//// ���� ���� �� �ֱ�
	//for (int i = 0; i < 6; i++)
	//{
	//	atariNum[i] = rand() % 45;
	//}
	//
	////// �����ȣ ���
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
	//		cout << "6��" << endl;
	//		break;
	//	case 2:
	//		cout << "5��" << endl;
	//		break;
	//	case 3:
	//		cout << "4��" << endl;
	//		break;
	//	case 4:
	//		cout << "3��" << endl;
	//		break;
	//	case 5:
	//		cout << "2��" << endl;
	//		break;
	//	case 6:
	//		cout << "1��" << endl;
	//		break;
	//	default:
	//		cout << "�ƽ�" << endl;
	//		break;
	//}

#pragma endregion

int num = 3 && 2;

	cout << num;
}