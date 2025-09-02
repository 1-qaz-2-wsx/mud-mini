#pragma once

struct  DropItem {
	int money;
	//��������
};

struct EnemyTemplate {
	const char* template_id;
	//����ģ���ʶ
	const char* name;
	int base_hp;
	//��ʼ����ֵ
	int base_atk;
	//��ʼ������
	int type; //0=С�֣�1=���
	DropItem drop; //Ĭ�ϵ���

	//����
	EnemyTemplate(const char* id; const char* nm, int hp, int atk, int t)
		: template_id(id), name(nm), base_hp(hp), base_atk(atk), type(t);

	//��¡Ĭ������
	void cloneInto(int& out_hp, int& out_atk) const {
		out_hp = base_hp;
		out_atk = base_atk;
	}
};
