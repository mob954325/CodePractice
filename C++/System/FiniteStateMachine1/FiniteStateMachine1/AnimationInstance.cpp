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

void AnimationInstance::SetTrigger(const std::string& paramName)
{
	auto it = triggerParams.find(paramName);
	if (it == triggerParams.end())
	{
		std::cerr << "Error: Parameter " << paramName << " is not registered as Trigger type." << std::endl;
		return;
	}

	it->second = true;
}

bool AnimationInstance::GetTrigger(const std::string& paramName)
{
	auto it = triggerParams.find(paramName);
	if (it == triggerParams.end())
	{
		return false;
	}

	return it->second;
}

bool AnimationInstance::IsParameterChanged(Condition& condition)
{
	std::string param = condition.parameter;
	std::string mode = condition.mode;
	float threshold = condition.threshold;

	if (mode == "Always") // 파라미터 없으면 무조건 통과
	{
		return true;
	}

	switch (condition.type)
	{
	case ParameterType::Bool:
	{
		bool val = GetBool(param);
		if (mode == "If") return val;
		if (mode == "IfNot") return !val;
		break;
	}
	case ParameterType::Int:
	{
		int val = GetInt(param);
		if (mode == "Greater") return val > threshold;
		if (mode == "Less") return val < threshold;
		if (mode == "Equals") return val == static_cast<int>(threshold);
		if (mode == "NotEqual") return val != static_cast<int>(threshold);
		break;
	}
	case ParameterType::Float:
	{
		float val = GetFloat(param);
		if (mode == "Greater") return val > threshold;
		if (mode == "Less") return val < threshold;
		if (mode == "Equals") return val == threshold;
		if (mode == "NotEqual") return val != threshold;
		break;
	}
	case ParameterType::Trigger:
	{
		bool val = GetTrigger(param);
		if (mode == "If") return val;
		if (mode == "IfNot") return !val;
		break;
	}
	default:
		return false;
	}
	return false;
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
			triggerParams[it->name] = it->defaultBool;
		}

		it++;
	}
}

void AnimationInstance::ChangeState(const std::string& name)
{
	if (name == "Exit") // AnyState의 종료 노드
	{
		int temp = currentStateIndex;

		ExitStateBehavior(currentStateIndex);

		currentStateIndex = prevStateIndex;	// 이전 상태로 되돌림
		prevStateIndex = temp;				// Anystate의 노드를 이전 상태로 저장

		StartStateBehavior(currentStateIndex);
	}
	else
	{
		State* state = controller->GetState(name);
		if (state->index != currentStateIndex) // 교체할 상태가 같은 상태가 아닐때만
		{
			ExitStateBehavior(currentStateIndex);

			prevStateIndex = currentStateIndex;
			currentStateIndex = state->index;	

			StartStateBehavior(currentStateIndex);
		}
	}

	elapsedTime = 0.0f; // 시간 초기화
}

void AnimationInstance::ResetTrigger(const std::string& name)
{
	auto it = triggerParams.find(name);
	if (it == triggerParams.end())
	{
		std::cerr << "Error: Parameter " << name << " is not registered as Trigger type." << std::endl;
		return;
	}

	it->second = false;
}

void AnimationInstance::StartStateBehavior(int index)
{
	if (stateBehavitors[index] == nullptr) return;

	stateBehavitors[index]->OnStateEnter();
}

void AnimationInstance::UpdateStateBehavior(int index)
{
	if (stateBehavitors[index] == nullptr) return;

	stateBehavitors[index]->OnStateUpdate();
}

void AnimationInstance::ExitStateBehavior(int index)
{
	if (stateBehavitors[index] == nullptr) return;

	stateBehavitors[index]->OnStateExit();
}

void AnimationInstance::OnStart()
{
	currentStateIndex = 0;
	StartStateBehavior(currentStateIndex);
}

void AnimationInstance::OnExit()
{
	stateBehavitors[currentStateIndex]->OnStateExit();
}

void AnimationInstance::Update(float deltaTime)
{
	if (currentStateIndex < 0) return;

	elapsedTime += deltaTime; // 시간 누적

	// 1. 시간 증가
	float clipLength = controller->states[currentStateIndex].clipLength;	// 해당 상태의 지속시간
	float currentClipTimeRatio = 0.0f;
	currentClipTimeRatio = elapsedTime / clipLength;					// 현재 시간 비율 (0.0 - 1.0)

	std::cout << std::to_string(currentClipTimeRatio) << "--" << controller->states[currentStateIndex].motionName << std::endl;

	// 2. AnyState 확인
	for (auto& transition : controller->anyStateTransitions)
	{
		// 컨디션 평가
		if (EvaluateConditions(transition.conditions))
		{
			// 컨디션이 확인하는 parameter값이 변경되었으면 상태 변경
			ChangeState(transition.toState);

			for (auto& condition : transition.conditions)
			{
				if (condition.type == ParameterType::Trigger)
				{
					ResetTrigger(condition.parameter);
				}
			}

			return; // 변경을 감지하면 이번 프레임 업데이트 종료
		}
	}

	//  <-- State Upate 실행 구간
	UpdateStateBehavior(currentStateIndex);

	// 3. transition 확인
	auto currState = controller->states.at(currentStateIndex);
	for (auto& transition : currState.transitions)
	{
		// exit타임이 존재할 때 현재 state 상태의 시간이 exitTime만큼 지났는지 확인
		if (transition.hasExitTime && (currentClipTimeRatio < 1.0f))
			continue;

		for (auto& condition : transition.conditions)
		{
			// 컨디션 평가
			if (EvaluateConditions(transition.conditions))
			{
				// 컨디션이 확인하는 parameter값이 변경되었으면 상태 변경
				ChangeState(transition.toState);

				for (auto& condition : transition.conditions)
				{
					if (condition.type == ParameterType::Trigger)
					{
						ResetTrigger(condition.parameter);
					}
				}

				return; // 변경을 감지하면 이번 프레임 업데이트 종료
			}			
		}
	}

	// 4. 클립 시간 확인
	if (currentClipTimeRatio >= 1.0f)
	{
		elapsedTime = 0.0f;
	}
}

bool AnimationInstance::EvaluateConditions(std::vector<Condition>& conditions)
{
	// 모든 condition에 대한 파라미터 변경 확인
	for (auto& condition : conditions)
	{
		// 하나라도 변경안되어 있으면 false
		if (!IsParameterChanged(condition)) 
		{
			return false;
		}
	}

	return true; // 모든 조건을 만족하면 true
}

void AnimationInstance::SetAnimationController(AnimatorController& ac)
{
	controller = &ac;

	RegisterIntParameters();
	RegisterFloatParameters();
	RegisterBoolParameters();
	RegisterTriggerParameters();

	stateBehavitors.reserve(ac.states.size());
	for (int i = 0; i < stateBehavitors.capacity(); i++)
	{
		stateBehavitors.push_back(nullptr);
	}
}

void AnimationInstance::SetStateBehavior(std::string stateName, IStateBehaviorBase* state)
{
	if (controller == NULL) return;

	auto it = controller->stateNameToIndex.find(stateName);
	if (it != controller->stateNameToIndex.end())
	{
		stateBehavitors[it->second] = state;
	}
}

/// translate 규칙
/// 1. 파라미터 변경 시 클립의 exit타임을 확인하고 exit타임보다 시간이 지나면 다음 상태로 변경
/// 2. anystate의 전이가 진행될 때 모든 state내용은 즉시 중단되고 해당 전이를 시작한다.