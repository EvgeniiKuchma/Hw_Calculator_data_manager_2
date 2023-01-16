#pragma once
#include <string>
#include <iostream>
#include <map>
#include <set>

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
			_key_counter.insert({ id });
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
			_key_counter.insert({ id });
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
			_key_counter.insert({ id });
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
			_key_counter.insert({ id });
			return _data.at(id);
		}
		else
			std::cout << "Opss your elements not founded!\n";
	}
	void mostPopularKeyToFind() 
	{
		for (std::multiset<int>::iterator it = _key_counter.begin(); it != _key_counter.end(); it++)
		{
			std::cout << "\n\nElement: " << *it;
			auto a = _key_counter.count(*it);
			std::cout << "\nEgo kolichestvo: " << a;
		}
	}
private:
	std::map<int, T> _data;
	std::multiset<int> _key_counter;
};