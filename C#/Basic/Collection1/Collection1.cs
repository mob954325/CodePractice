using System;
using System.Collections;
using System.Collections.Generic;

namespace Collection1
{
    internal class Collection1
    {
        static void Main(string[] args)
        {
            // 일반 컬렉션 사용
            // boxing과 unboxing의 사용으로 메모리 낭비
            Queue q1 = new Queue();
            q1.Enqueue(1);  // object 타입 변환 : boxing
            q1.Peek();      // object -> int형 변환 : unboxing
            q1.Dequeue();

            // 제테릭(Generic) 컬렉션 사용
            // 일반과 다르게 boxing unboxing이 없음
            // 위 방식보단 제네릭 방식을 권장함
            Queue<int> q2 = new Queue<int>(); // queue의 int형이라고 선언
            q2.Enqueue(1);  // int 값 저장
            q2.Peek();      // int 값 가져오기
            q2.Dequeue();   
        }
    }
}
