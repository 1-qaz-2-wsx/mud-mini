#include "Entity.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

Entity::Entity() : name(""), id_(0) {}
Entity::Entity(const string& name, unsigned int id) : name(name), id_(id) {}

//������
const string& Entity::getName() const { return name; }

unsigned int Entity::getId() const { return id_; }

//����Сд����
string Entity::CompName() const
{
	string lower_name = name;
	transform(lower_name.begin(), lower_name.end(), lower_name.begin(),
		[](unsigned char c) { return tolower(c); });
	return lower_name;
}

//��ȫƥ��
bool Entity::FullMatch(const std::string& name) const {
	return CompName() == name;
}

//����ƥ��
bool Entity::Match(const std::string& name) const {
    std::string name = CompName();     // ��ǰ��������֣�Сд��
    std::string search = name;

    // ת��Сд�������Сд���ţ�
    std::transform(search.begin(), search.end(), search.begin(),
        [](unsigned char c) { return std::tolower(c); });

    size_t pos = name.find(search);     // �����Ӵ�
    while (pos != std::string::npos) {
        // ƥ������ڿ�ͷ������һ�����ʱ߽磨ǰһ���ַ��ǿո�
        if (pos == 0 || name[pos - 1] == ' ')
            return true;
        pos = name.find(search, pos + 1);   // ����������һ��
    }
    return false;
}

