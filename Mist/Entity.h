#pragma once
#include <string> 
class Entity
{
protected:
	std::string name;  //����
	unsigned int id_;  //ΨһID
public:
	Entity();
	Entity(const std::string& name, unsigned int id);

	const std::string& getName ()const;
	unsigned int getId() const;

	//�ȽϺ���
	std::string CompName() const; //����Сд����

	bool FullMatch(const std::string& name) const; //��ȫƥ��
	bool Match(const std::string& name) const; //����ƥ��

	virtual ~Entity();

};

