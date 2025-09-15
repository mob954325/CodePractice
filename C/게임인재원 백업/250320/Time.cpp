#include "Time.h"

LARGE_INTEGER freq, curr, prev, start, end;
float deltaTime;
float timeElapsed;

void Time::InitTime()
{
    QueryPerformanceFrequency(&freq); // QPC ���ļ�(�ʴ� Tick ��) ��������
    QueryPerformanceCounter(&start);

    deltaTime = 0;
    timeElapsed = 0;
}

void Time::UpdateTime()
{
    QueryPerformanceCounter(&curr);
    deltaTime = static_cast<float>(curr.QuadPart - prev.QuadPart) / freq.QuadPart;
    prev = curr;
}

float Time::GetDeltaTime()
{
    return deltaTime;
}

float Time::GetElapsedTime()
{
    QueryPerformanceCounter(&end);
    return static_cast<float>(end.QuadPart - start.QuadPart) / freq.QuadPart;
}