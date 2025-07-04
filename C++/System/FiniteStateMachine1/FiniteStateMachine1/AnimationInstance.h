#pragma once
#include "Datas.h"
#include "unordered_map"
#include "vector"

class AnimationInstance
{
private:
	AnimatorController* controller{};
	int currentStateIndex = -1;
	int prevStateIndex = -1;

	float elapsedTime = 0.0f; 

	// 파라미터 컨테이너
	std::unordered_map<std::string, int> intParams;
	std::unordered_map<std::string, float> floatParams;
	std::unordered_map<std::string, bool> boolParams;
	std::unordered_map<std::string, bool> triggerParams;

	void RegisterIntParameters();
	void RegisterFloatParameters();
	void RegisterBoolParameters();
	void RegisterTriggerParameters();

	void ChangeState(const std::string& name);

	// trigger
public:
	// eventCycle
	void OnStart();
	void OnExit();
	void Update(float deltaTime);
	bool EvaluateConditions(std::vector<Condition>& conditions);

	// init
	void SetAnimationController(AnimatorController& ac);

	// Param getter/setter
	int GetInt(const std::string& paramName);
	void SetInt(const std::string& paramName, int value);

	bool GetBool(const std::string& paramName);
	void SetBool(const std::string& paramName, bool value);

	float GetFloat(const std::string& paramName);
	void SetFloat(const std::string& paramName, float value);

	// flag
	bool IsParameterChanged(Condition& condition);
};

// Update 순서
// 시간 증가 -> AnyState 전이 확인 -> 현재 상태의 전이 확인 -> clipTime 확인