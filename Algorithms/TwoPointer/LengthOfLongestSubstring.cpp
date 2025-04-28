#include "LengthOfLongestSubstring.h"
#include <unordered_set>

// 문제
// 문자열 s에서 중복이 없는 가장 긴 부분 문자열의 길이를 구하라.
int LengthOfLongestSubstring(string s)
{
	unordered_set<char> seen;
	int left = 0, maxLength = 0; // left는 왼쪽에서 시작, right는 오른쪽으로 이동하면서 문자열 탐색

	for (int right = 0; right < s.length(); right++)
	{
		while (seen.count(s[right])) // 중복된 문자가 있으면 해당 문자를 지우고 left++;
		{
			seen.erase(s[left]);
			left++;
		}
		seen.insert(s[right]);		// 문자 추가
		maxLength = max(maxLength, right - left + 1); // 가장 긴 문자열 값 반환
	}

	return maxLength;
}