#include"character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

Stats::Stats() {
    values[0] = 100;
    values[1] = 10;
    values[2] = 50;
    values[3] = 5;
    values[4] = 80;
    values[5] = 50;
    values[6] = 0;
    values[7] = 20;
}

int& Stats::operator[](Attribute attr) {
    return values[attr];
}

const int& Stats::operator[](Attribute attr) const {   
    return values[attr];
}

void Stats::display() const {
    const char* attributeNames[] = {
        "生命值上限", "法力值上限", "攻击力", "敏捷", "速度", "金钱", "经验", "防御"
    };

    for (int i = 0; i < NUMATTRIBUTES; i++) {
        cout << attributeNames[i] << ": " << values[i] << endl;
    }
}

// 构造函数
Player::Player() : level(1), max_experience(100),
current_health(characterStats[max_health]),
current_mana(characterStats[max_mana]) {}

// 获取当前等级
int Player::getLevel() const {
    return level;
}

// 获取当前生命值
int Player::getCurrentHealth() const {
    return current_health;
}

// 获取当前法力值
int Player::getCurrentMana() const {
    return current_mana;
}

// 获取最大经验值（升级所需）
int Player::getMaxExperience() const {
    return max_experience;
}

// 获取角色属性
const Stats& Player::getStats() const {
    return characterStats;
}

// 设置当前生命值
void Player::setCurrentHealth(int health) {
    current_health = health;
    if (current_health < 0) current_health = 0;
    if (current_health > characterStats[max_health])
        current_health = characterStats[max_health];
}

// 设置当前法力值
void Player::setCurrentMana(int mana) {
    current_mana = mana;
    if (current_mana < 0) current_mana = 0;
    if (current_mana > characterStats[max_mana])
        current_mana = characterStats[max_mana];
}

// 增加经验值并检查升级
void Player::addExperience(int exp) {
    Player::characterStats[experience_points] += exp;

    // 检查是否升级
    while (characterStats[experience_points] >= max_experience) {
        levelUp();
    }
}

// 升级角色
void Player::levelUp() {
    level++;
    characterStats[experience_points] -= max_experience;
    max_experience = static_cast<int>(max_experience * 1.5); // 每次升级所需经验增加50%

    // 提升各项属性
    characterStats[max_health] += 20;
    characterStats[max_mana] += 10;
    characterStats[attack] += 5;
    characterStats[agility] += 2;
    characterStats[accuracy] += 5;
    characterStats[defence] += 3;

    // 恢复生命值和法力值
    current_health = characterStats[max_health];
    current_mana = characterStats[max_mana];

    cout << "恭喜！角色升级到 " << level << " 级！" << endl;
}

// 恢复生命值
void Player::heal(int amount) {
    current_health += amount;
    if (current_health > characterStats[max_health]) {
        current_health = characterStats[max_health];
    }
}

// 恢复法力值
void Player::restoreMana(int amount) {
    current_mana += amount;
    if (current_mana > characterStats[max_mana]) {
        current_mana = characterStats[max_mana];
    }
}

// 消耗法力值
bool Player::useMana(int amount) {
    if (current_mana >= amount) {
        current_mana -= amount;
        return true;
    }
    return false;
}

// 受到伤害
void Player::takeDamage(int damage) {
    // 计算实际伤害（考虑防御）
    srand(time(0));
    int a = rand() % 100 + 1;  //随机生成一个1-100的正数，小于miss代表躲避成功
    int actualDamage = damage - characterStats[defence];

    if (a <= characterStats[agility]) {
        cout << "你躲避了这次攻击" << endl;
        return;
    }

    if (actualDamage < 1) actualDamage = 1;    //伤害小于1时设为1

    printf("受到%d的伤害\n", actualDamage);
    current_health -= actualDamage;
    if (current_health < 0) current_health = 0;
}

// 增加金钱
void Player::addMoney(int amount) {
    characterStats[money] += amount;
}

// 消费金钱
bool Player::spendMoney(int amount) {
    if (characterStats[money] >= amount) {
        characterStats[money] -= amount;
        return true;
    }
    return false;
}

// 检查是否存活
bool Player::isAlive() const {
    return current_health > 0;
}

// 显示角色状态
void Player::displayStatus() const {
    cout << "=== 角色状态 ===" << endl;
    cout << "等级: " << level << endl;
    cout << "生命值: " << current_health << "/" << characterStats[max_health] << endl;
    cout << "法力值: " << current_mana << "/" << characterStats[max_mana] << endl;
    cout << "经验值: " << characterStats[experience_points] << "/" << max_experience << endl;
    cout << "金钱: " << characterStats[money] << endl;
    cout << "=================" << endl << endl;
}

// 显示详细属性
void Player::displayDetailedStats() const {
    cout << "=== 详细属性 ===" << endl;
    characterStats.display();
    cout << "================" << endl << endl;
}