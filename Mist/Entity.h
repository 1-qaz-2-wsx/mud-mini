#pragma once
#include <string> 
class Entity
{
protected:
	std::string name;  //名称
	unsigned int id_;  //唯一ID
public:
	Entity();
	Entity(const std::string& name, unsigned int id);

	const std::string& getName ()const;
	unsigned int getId() const;

	//比较函数
	std::string CompName() const; //返回小写名称

	bool FullMatch(const std::string& name) const; //完全匹配
	bool Match(const std::string& name) const; //部分匹配

	virtual ~Entity();

};

