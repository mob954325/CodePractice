// https://github.com/nlohmann/json/releases

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

int main()
{
	std::ifstream file("Stage1.json", std::ios::in);

	if (!file.is_open())
	{
		std::cerr << "Error opening Stage1.json \n";
		return 1;
	}

	json j;
	file >> j;

	std::vector<int> stage_vector;

	// layer에서 height의 요소 출력
	for (const auto& result : j)	{

		if (result["height"].is_number_integer())
		{
			int curr = result["height"].get<int>();
			printf("%d\n", curr);
		}
		else if (result["height"].is_array())
		{
			const auto& data = result["height"];
			stage_vector.insert(stage_vector.end(), data.begin(), data.end());
		}

	}

	for (const auto& layer : j["layers"])
	{
		const auto& data = layer["data"];
		stage_vector.insert(stage_vector.end(), data.begin(), data.end());
	}

	for (const auto& value : stage_vector)
	{
		std::cout << value << " ";
	}
}