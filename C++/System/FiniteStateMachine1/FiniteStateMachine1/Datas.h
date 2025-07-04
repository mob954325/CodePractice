#pragma once
#include <string>
#include <unordered_map>
#include <vector>
struct Sprite
{
	std::string name; // sprite 이름
	float x, y;				 // sprite 좌표 ( sourceRect 위치 값으로 추정 )
	float width, height;	 // sprite 너비
	float pivotX, pivotY;	 // sprite 피벗 ( 중심점 )
};

struct SpriteSheet
{
	std::string texture;			// 해당 시트 이름
	float textureWidth, textureHeight;	// 해당 시트 너비와 높이
	std::vector<Sprite> sprites;		// 시트에 있는 Sprite 목록
	std::unordered_map<std::string, int> spriteIndexMap;	// std::wstring으로 찾기 위한 인덱스 맵 <이름, 인덱스>
};

struct FrameInfo
{
	std::string sprite;
	int spriteSheetIndex;
	float duration;
};

struct AnimationClip
{
	std::string clipName;
	std::string texturePath;
	bool loop;
	float duration; // 전체 애니메이션 시간
	std::vector<FrameInfo> frames;
};

struct Parameter
{
	std::string name;			// 파라미터 이름
	std::string type;			// 파라미터 타입 (예: Float, Int, Bool)
	float defaultFloat = 0.0f;	// 기본값 (Float 타입일 때 사용)
	int defaultInt = 0;			// 기본값 (Int 타입일 때 사용)
	bool defaultBool = false;	// 기본값 (Bool 타입일 때 사용)
};

enum ParameterType
{
	Int, Float, Bool, Trigger
};

struct Condition
{
	std::string parameter;	// 조건 파라미터 이름
	std::string mode;		// 조건 모드 (예: Greater, IfNot 등)
	ParameterType type;		// 파라미터 타입 (Int, Float, Bool, Trigger)

	float threshold = 0.0f; // 조건 임계값
};

struct Transition
{
	std::string fromState;		// 전이 시작 상태 이름
	std::string toState;		// 전이 종료 상태 이름	
	bool hasExitTime = false;	// 종료 시간이 있는지 여부
	float exitTime = -1.0f;		// 1.0이면 100% 완료 후 전이 | -1.0이면 종료 시간 없음
	std::vector<Condition> conditions;
};

struct AnyStateTransition
{
	std::string toState; // 전이 종료 상태 이름
	std::vector<Condition> conditions;
};

struct State
{
	int index = -1;				// 상태 인덱스 (필요시 사용)
	std::string name;			// 상태 이름
	std::string motionName;		// 모션 이름 (애니메이션 클립 이름)
	float clipLength = 1.0f;	// 초 단위 
	bool loop = false;			// 루프 여부
	std::vector<Transition> transitions; // 전이 목록
};

struct AnimatorController
{
	std::string controllerName;			// 컨트롤러 이름
	std::vector<Parameter> parameters;	// 컨트롤러 파라미터 목록

	std::string defaultState;	// 기본 상태 이름	
	std::vector<State> states;	// 상태 목록
	std::unordered_map<std::string, int> stateNameToIndex;
	std::unordered_map<std::string, ParameterType> paramNameToType; // 파라미터 이름으로 해당 파라미터의 타입 저장
	std::vector<AnyStateTransition> anyStateTransitions;	// Any State 전이 목록

	State* GetState(const std::string& stateName)
	{
		auto it = stateNameToIndex.find(stateName);
		if (it != stateNameToIndex.end())
		{
			return &states[it->second]; // 상태가 존재하면 해당 상태 반환
		}
		return nullptr; // 상태가 존재하지 않으면 nullptr 반환
	}
};