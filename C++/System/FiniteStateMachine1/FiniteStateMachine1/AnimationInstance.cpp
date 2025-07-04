#include "AnimationInstance.h"
#include "Loader.h"

int AnimationInstance::GetInt(const std::string& paramName)
{
	auto it = intParams.find(paramName);
	if (it == intParams.end())
	{
		std::cerr << "존재하지 않는 int 파라미터" << std::endl;
	}

	return it->second;
}

void AnimationInstance::SetInt(const std::string& paramName, int value)
{
	auto it = intParams.find(paramName);
	if (it == intParams.end())
	{
		std::cerr << "존재하지 않는 int 파라미터" << std::endl;
	}

	it->second = value;
}

bool AnimationInstance::GetBool(const std::string& paramName)
{
	auto it = boolParams.find(paramName);
	if (it == boolParams.end())
	{
		std::cerr << "존재하지 않는 bool 파라미터" << std::endl;
	}

	return it->second;
}

void AnimationInstance::SetBool(const std::string& paramName, bool value)
{
	auto it = boolParams.find(paramName);
	if (it == boolParams.end())
	{
		std::cerr << "존재하지 않는 bool 파라미터" << std::endl;
	}

	it->second = value;
}

float AnimationInstance::GetFloat(const std::string& paramName)
{
	auto it = floatParams.find(paramName);
	if (it == floatParams.end())
	{
		std::cerr << "존재하지 않는 float 파라미터" << std::endl;
	}

	return it->second;
}

void AnimationInstance::SetFloat(const std::string& paramName, float value)
{
	auto it = floatParams.find(paramName);
	if (it == floatParams.end())
	{
		std::cerr << "존재하지 않는 float 파라미터" << std::endl;
	}

	it->second = value;
}

void AnimationInstance::RegisterIntParameters()
{
	if (controller == NULL) return;

	auto it = controller->parameters.begin();
	for (; it != controller->parameters.end();)
	{
		if (it->type == "Int")
		{
			intParams[it->name] = it->defaultInt;
		}

		it++;
	}	
}

void AnimationInstance::RegisterFloatParameters()
{
	if (controller == NULL) return;

	auto it = controller->parameters.begin();
	for (; it != controller->parameters.end();)
	{
		if (it->type == "Float")
		{
			floatParams[it->name] = it->defaultInt;
		}

		it++;
	}
}

void AnimationInstance::RegisterBoolParameters()
{
	if (controller == NULL) return;

	auto it = controller->parameters.begin();
	for (; it != controller->parameters.end();)
	{
		if (it->type == "Bool")
		{
			boolParams[it->name] = it->defaultInt;
		}

		it++;
	}
}

void AnimationInstance::RegisterTriggerParameters()
{
	if (controller == NULL) return;

	auto it = controller->parameters.begin();
	for (; it != controller->parameters.end();)
	{
		if (it->type == "Trigger")
		{
			triggerParams[it->name] = it->defaultInt;
		}

		it++;
	}
}

void AnimationInstance::ChangeState(const std::string& name)
{
}

void AnimationInstance::OnStart()
{
	currentStateIndex = 0;
}

void AnimationInstance::OnExit()
{
}

void AnimationInstance::Update(float deltaTime)
{
	elapsedTime += deltaTime; // 시간 누적

	if (currentStateIndex < 0) return;

	float clipLength = controller->states[currentStateIndex].clipLength;	// 해당 상태의 지속시간
	float currentClipTimeRatio = elapsedTime / clipLength;					// 현재 시간 비율 (0.0 - 1.0)

	std::cout << std::to_string(currentClipTimeRatio) << "--" << controller->states[currentStateIndex].motionName << std::endl;

	//  <-- State Upate 실행 구간

	auto currState = controller->states.at(currentStateIndex);
	// 현재 상태의 모든 transition의 condition 확인
	// for transition 
	// exit 타임 확인
	// 
	for (auto& translition : currState.transitions)
	{
		for (auto& condition : translition.conditions)
		{
			// 컨디션 확인
		}
	}
}

void AnimationInstance::SetAnimationController(AnimatorController& ac)
{
	controller = &ac;

	RegisterIntParameters();
	RegisterFloatParameters();
	RegisterBoolParameters();
	RegisterTriggerParameters();
}

/// translate 규칙
/// 1. 파라미터 변경 시 클립의 exit타임을 확인하고 exit타임보다 시간이 지나면 다음 상태로 변경
/// 2. anystate의 전이가 진행될 때 모든 state내용은 즉시 중단되고 해당 전이를 시작한다.