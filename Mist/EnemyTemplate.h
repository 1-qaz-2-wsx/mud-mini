#pragma once

struct  DropItem {
	int money;
	//掉落金币数
};

struct EnemyTemplate {
	const char* template_id;
	//所属模块标识
	const char* name;
	int base_hp;
	//初始生命值
	int base_atk;
	//初始攻击力
	int type; //0=小怪，1=大怪
	DropItem drop; //默认掉落

	//构造
	EnemyTemplate(const char* id; const char* nm, int hp, int atk, int t)
		: template_id(id), name(nm), base_hp(hp), base_atk(atk), type(t);

	//克隆默认属性
	void cloneInto(int& out_hp, int& out_atk) const {
		out_hp = base_hp;
		out_atk = base_atk;
	}
};
