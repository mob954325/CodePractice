#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
//char* solution(const char* bin1, const char* bin2) {
//    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
//    char* answer;
//    char* temp = (char*)malloc(12 * sizeof(char));
//    int tempIndex = 0;
//
//    int bin1len = strlen(bin1);
//    int bin2len = strlen(bin2);
//
//    int index1 = 0, index2 = 0, roundUp = 0;
//    tempIndex = bin1len > bin2len ? bin1len - 1 : bin2len - 1;
//
//    if (bin1[index1] == '1' && bin2[index2] == '1')
//    {
//        temp[0] = '1';
//        temp[1] = '0';
//        tempIndex++;
//        temp[tempIndex + 1] = '\0';
//        answer = (char*)malloc((tempIndex + 2)* sizeof(char));
//    }
//    else
//    {
//        temp[tempIndex] = '\0';
//        answer = (char*)malloc((tempIndex + 1)* sizeof(char));
//    }
//
//    index1 = bin1len - 1;
//    index2 = bin2len - 1;
//
//    while (index1 >= 0 && index2 >= 0)
//    {
//        if (bin1[index1] == '0' && bin2[index2] == '0')
//        {
//            if (roundUp == 1)
//            {
//                temp[tempIndex] = '1';
//                roundUp = 0;
//            }
//            else
//            {
//                temp[tempIndex] = '0';
//            }
//        }
//        else if ((bin1[index1] == '1' && bin2[index2] == '0') || (bin2[index2] == '1' && bin1[index1] == '0'))
//        {
//            if (roundUp == 1)
//            {
//                temp[tempIndex] = '0';
//                roundUp = 1;
//            }
//            else
//            {
//                temp[tempIndex] = '1';
//            }
//        }
//        else if (bin1[index1] == '1' && bin2[index2] == '1')
//        {
//            if (roundUp == 1)
//            {
//                temp[tempIndex] = '1';
//            }
//            else
//            {
//                roundUp = 1;
//                temp[tempIndex] = '0';
//            }
//        }
//
//        tempIndex--;
//        index1--;
//        index2--;
//    }
//
//    while (index1 >= 0)
//    {
//        if (roundUp == 1)
//        {
//            if (bin1[index1] == 1)
//            {
//                temp[tempIndex] = '0';
//            }
//            else
//            {
//                temp[tempIndex] = '1';
//                roundUp = 0;
//            }
//        }
//
//        tempIndex--;
//        index1--;
//    }
//
//    while (index2 >= 0)
//    {
//        if (roundUp == 1)
//        {
//            if (bin2[index2] == 1)
//            {
//                temp[tempIndex] = '0';
//            }
//            else
//            {
//                temp[tempIndex] = '1';
//                roundUp = 0;
//            }
//        }
//
//        tempIndex--;
//        index2--;
//    }
//
//    memcpy(answer, temp, (strlen(temp) + 1) * sizeof(char));
//
//    free(temp);
//    return answer;
//}

// 1. 2������ 10������ ��ȯ�Ѵ�.
// 2. �ش� ���� ����Ѵ�
// 3. ������� �ٽ� 2������ ��ȯ�Ѵ�.

char* intToBinary(int num)
{
    char* bin = (char*)malloc(50);
    int index = 49;
    bin[index--] = '\0';

    if (num == 0)
    {
        bin[index] = '0';
        return &bin[index];
    }

    while (num > 0)
    {
        bin[index--] = (num % 2) + '0';
        num /= 2;
    }

    return &bin[index + 1];
}

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* bin1, const char* bin2) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int num1 = strtol(bin1, NULL, 2);
    int num2 = strtol(bin2, NULL, 2);

    int sum = num1 + num2;

    char* answer = (char*)calloc(16, sizeof(char));
    answer = intToBinary(sum);
    return answer;
}

int main()
{
    const char* b1 = "1001";
    const char* b2 = "1111";
    solution(b1, b2);
}