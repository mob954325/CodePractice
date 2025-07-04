#include "Datas.h"
#include "Loader.h"
#include "AnimationInstance.h"

#include "windows.h"

using namespace std;

int main()
{
	AnimatorController ac;
	AnimationControllerLoader::LoadAnimatorController("TestPlayer_AnimController.json", ac);

	AnimationInstance animInstance;
	animInstance.SetAnimationController(ac);
	animInstance.OnStart();

	float elapedTime = 0;
	float deltaTime = 0.16f; // 0.1초 단위로 업데이트
	float testTime = 60.0f;
	for (elapedTime = 0; elapedTime < testTime; elapedTime += deltaTime)
	{
		Sleep(deltaTime * 1000); // 대기 
		animInstance.Update(deltaTime); // 0.1초 단위로 업데이트

		if (GetAsyncKeyState('A') & 0x8000) {
			animInstance.SetFloat("speed", 1.0f);
		}
		else
		{
			animInstance.SetFloat("speed", 0.0f);
		}

		if (GetAsyncKeyState('B') & 0x8000)
		{
			bool flag = animInstance.GetBool("hit");
			if (flag)
			{
				animInstance.SetBool("hit", false);
			}
			else
			{
				animInstance.SetBool("hit", true);
			}
		}

		//if (GetAsyncKeyState('H') & 0x8000) {
		//	animInstance.SetTrigger("hurt"); // Trigger테스트
		//}
	}

	animInstance.OnExit();
}