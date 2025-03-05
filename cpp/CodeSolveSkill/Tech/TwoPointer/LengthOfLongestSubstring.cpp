#include "LengthOfLongestSubstring.h"
#include <unordered_set>

// ����
// ���ڿ� s���� �ߺ��� ���� ���� �� �κ� ���ڿ��� ���̸� ���϶�.
int LengthOfLongestSubstring(string s)
{
	unordered_set<char> seen;
	int left = 0, maxLength = 0; // left�� ���ʿ��� ����, right�� ���������� �̵��ϸ鼭 ���ڿ� Ž��

	for (int right = 0; right < s.length(); right++)
	{
		while (seen.count(s[right])) // �ߺ��� ���ڰ� ������ �ش� ���ڸ� ����� left++;
		{
			seen.erase(s[left]);
			left++;
		}
		seen.insert(s[right]);		// ���� �߰�
		maxLength = max(maxLength, right - left + 1); // ���� �� ���ڿ� �� ��ȯ
	}

	return maxLength;
}