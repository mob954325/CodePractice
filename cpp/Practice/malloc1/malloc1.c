#include <stdio.h>
#include <stdlib.h>

// 테스트
// C에서는 왜 할당하지 않은 메모리에도 접근이 가능한가?

int main() {
    char* str = (char*)malloc(3); // 3바이트 할당
    str[0] = 'A';
    str[1] = 'B';
    str[2] = 'C';
    str[3] = 'D';  // 버퍼 오버런 발생 (4번째 바이트에 접근)
    str[20] = 'E';  // 또 다른 범위 초과 접근

    printf("%c %c %c %c %c\n", str[0], str[1], str[2], str[3], str[20]); // 예상치 못한 값 출력 가능
    printf("%c\n", str[20]);

    printf("Address of str[0]: %p\n", (void*)&str[0]);
    printf("Address of str[1]: %p\n", (void*)&str[1]);
    printf("Address of str[2]: %p\n", (void*)&str[2]);
    // 범위 초과 접근 -> 접근은 가능하나 메모리를 계속 사용할 때 해당 위치에서 오류가 날 수 있음
    printf("Address of str[3]: %p\n", (void*)&str[3]); // str + 3 인 것을 알 수 있어서 주소 값이 안 변함 (연속적인 위치기 때문에 알 수 있음)
    
    // 결론 
    // C는 치명적인 상황이 발생하지 않는 이상 메모리에 대한 접근을 허용함( 치명적인 상황 -> 보호된 메모리 접근, OS관리 영역 접근 )
    // -> Python, Java, C#은 런타임 오류 발생(IndexOutOfBoundsException)
    // 그래서 범위에 벗어난 행동을 하면 "버퍼 오버런" 오류를 띄워서 경고를 함 ( 아니면 overflow )

    free(str);
    return 0;
}
