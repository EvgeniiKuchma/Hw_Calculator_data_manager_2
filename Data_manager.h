#pragma once
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T>
class Data_manager
{
public:
	Data_manager() {}
	void setShowData()
	{
		for (const auto& [key, value] : _data)
			std::cout << key << " " << value << '\n';
	}
	void setInsert(int id, const T& data)
	{
		if (_data.contains(id))
		{
			std::cout << "false\n";
			 std::cout << "==========\n";
		}
		else
			_data.insert({ id, data });
	}
	void setModif(int id, const T& data)
	{
		auto it = _data.find(id);
		if (it != _data.end())
		{
			_key_counter.push_back({ id });
			_data.at(id) = data;
		}
		else
			std::cout << "Opss your elements not founded!\n";
	}
	void setDelete(int id)
	{
		auto it = _data.find(id);
		if (it != _data.end())
		{
			_key_counter.push_back({ id });
			_data.erase(id);
		}
		else
			std::cout << "Opss your elements not founded!\n";
	}
	void setFind(int id)
	{
		auto it = _data.find(id);
		if (it != _data.end())
		{
			_key_counter.push_back({ id });
			std::cout << "Element ¹ " << id << " = " << it->second << '\n';
		}
		else
			std::cout << "Opss your elements not founded!\n";
	}
	T getDataOutput(int id)  
	{
		auto it = _data.find(id);
		if (it != _data.end())
		{
			_key_counter.push_back({ id });
			return _data.at(id);
		}
		else
			return " your elements wrong!\n";
	}
	int mostPopularKeyToFind() 
	{
		std::unordered_map<int, int> keyPop;
		for (size_t i = 0; i < _key_counter.size(); i++)
		{
			const auto& [it, isInserted] = keyPop.insert({ _key_counter[i], 1 });
			if (!isInserted)
			{
				auto value = it->second;
				value++;
				keyPop[_key_counter[i]] = value;
			}
		}
		std::pair<int, int> key_biggestValue = { 0,0 };
		for (std::unordered_map<int,int>::const_iterator it = keyPop.begin(); it != keyPop.end(); it++)
		{
			if (key_biggestValue.second < it->second)
				key_biggestValue = std::make_pair(it->first, it->second);
		}
		return key_biggestValue.first; 
	}
private:
	std::map<int, T> _data;
	std::vector<int> _key_counter;
};