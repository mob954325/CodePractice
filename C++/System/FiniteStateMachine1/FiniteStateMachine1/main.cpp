#include "Datas.h"
#include "Loader.h"
#include "AnimationInstance.h"

#include "windows.h"

using namespace std;

class PlayerMoveState : public IStateBehaviorBase
{
public:
	PlayerMoveState();
	~PlayerMoveState();

	void OnStateEnter() override;
	void OnStateUpdate() override;
	void OnStateExit() override;
private:

};

PlayerMoveState::PlayerMoveState()
{
}

PlayerMoveState::~PlayerMoveState()
{
}

void PlayerMoveState::OnStateEnter()
{
	std::cout << "-- player move behavior Enter --\n";
}

void PlayerMoveState::OnStateUpdate()
{
	std::cout << "-- player move behavior update --\n";
}

void PlayerMoveState::OnStateExit()
{
	std::cout << "-- player move behavior exit --\n";
}

int main()
{
	AnimatorController ac;
	AnimationControllerLoader::LoadAnimatorController("TestPlayer_AnimController.json", ac);

	AnimationInstance animInstance;
	animInstance.SetAnimationController(ac);
	animInstance.OnStart();

	PlayerMoveState* moveBehavior = new PlayerMoveState();
	animInstance.SetStateBehavior("Move", moveBehavior);

	float elapedTime = 0;
	float deltaTime = 0.16f; // 0.1초 단위로 업데이트
	float testTime = 60.0f;
	for (elapedTime = 0; elapedTime < testTime; elapedTime += deltaTime)
	{
		Sleep(deltaTime * 1000); // 대기 
		animInstance.Update(deltaTime); // 0.1초 단위로 업데이트

		if (GetAsyncKeyState('A')) {
			animInstance.SetFloat("Speed", 1.0f);
		}
		else
		{
			animInstance.SetFloat("Speed", 0.0f);
		}

		if (GetAsyncKeyState('B') & 0x8000)
		{
			animInstance.SetTrigger("hit");
		}
	}

	animInstance.OnExit();
	delete moveBehavior;
}