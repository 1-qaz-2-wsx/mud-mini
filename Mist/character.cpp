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
        "����ֵ����", "����ֵ����", "������", "����", "�ٶ�", "��Ǯ", "����", "����"
    };

    for (int i = 0; i < NUMATTRIBUTES; i++) {
        cout << attributeNames[i] << ": " << values[i] << endl;
    }
}

// ���캯��
Player::Player() : level(1), max_experience(100),
current_health(characterStats[max_health]),
current_mana(characterStats[max_mana]) {}

// ��ȡ��ǰ�ȼ�
int Player::getLevel() const {
    return level;
}

// ��ȡ��ǰ����ֵ
int Player::getCurrentHealth() const {
    return current_health;
}

// ��ȡ��ǰ����ֵ
int Player::getCurrentMana() const {
    return current_mana;
}

// ��ȡ�����ֵ���������裩
int Player::getMaxExperience() const {
    return max_experience;
}

// ��ȡ��ɫ����
const Stats& Player::getStats() const {
    return characterStats;
}

// ���õ�ǰ����ֵ
void Player::setCurrentHealth(int health) {
    current_health = health;
    if (current_health < 0) current_health = 0;
    if (current_health > characterStats[max_health])
        current_health = characterStats[max_health];
}

// ���õ�ǰ����ֵ
void Player::setCurrentMana(int mana) {
    current_mana = mana;
    if (current_mana < 0) current_mana = 0;
    if (current_mana > characterStats[max_mana])
        current_mana = characterStats[max_mana];
}

// ���Ӿ���ֵ���������
void Player::addExperience(int exp) {
    Player::characterStats[experience_points] += exp;

    // ����Ƿ�����
    while (characterStats[experience_points] >= max_experience) {
        levelUp();
    }
}

// ������ɫ
void Player::levelUp() {
    level++;
    characterStats[experience_points] -= max_experience;
    max_experience = static_cast<int>(max_experience * 1.5); // ÿ���������辭������50%

    // ������������
    characterStats[max_health] += 20;
    characterStats[max_mana] += 10;
    characterStats[attack] += 5;
    characterStats[agility] += 2;
    characterStats[accuracy] += 5;
    characterStats[defence] += 3;

    // �ָ�����ֵ�ͷ���ֵ
    current_health = characterStats[max_health];
    current_mana = characterStats[max_mana];

    cout << "��ϲ����ɫ������ " << level << " ����" << endl;
}

// �ָ�����ֵ
void Player::heal(int amount) {
    current_health += amount;
    if (current_health > characterStats[max_health]) {
        current_health = characterStats[max_health];
    }
}

// �ָ�����ֵ
void Player::restoreMana(int amount) {
    current_mana += amount;
    if (current_mana > characterStats[max_mana]) {
        current_mana = characterStats[max_mana];
    }
}

// ���ķ���ֵ
bool Player::useMana(int amount) {
    if (current_mana >= amount) {
        current_mana -= amount;
        return true;
    }
    return false;
}

// �ܵ��˺�
void Player::takeDamage(int damage) {
    // ����ʵ���˺������Ƿ�����
    srand(time(0));
    int a = rand() % 100 + 1;  //�������һ��1-100��������С��miss�����ܳɹ�
    int actualDamage = damage - characterStats[defence];

    if (a <= characterStats[agility]) {
        cout << "��������ι���" << endl;
        return;
    }

    if (actualDamage < 1) actualDamage = 1;    //�˺�С��1ʱ��Ϊ1

    printf("�ܵ�%d���˺�\n", actualDamage);
    current_health -= actualDamage;
    if (current_health < 0) current_health = 0;
}

// ���ӽ�Ǯ
void Player::addMoney(int amount) {
    characterStats[money] += amount;
}

// ���ѽ�Ǯ
bool Player::spendMoney(int amount) {
    if (characterStats[money] >= amount) {
        characterStats[money] -= amount;
        return true;
    }
    return false;
}

// ����Ƿ���
bool Player::isAlive() const {
    return current_health > 0;
}

// ��ʾ��ɫ״̬
void Player::displayStatus() const {
    cout << "=== ��ɫ״̬ ===" << endl;
    cout << "�ȼ�: " << level << endl;
    cout << "����ֵ: " << current_health << "/" << characterStats[max_health] << endl;
    cout << "����ֵ: " << current_mana << "/" << characterStats[max_mana] << endl;
    cout << "����ֵ: " << characterStats[experience_points] << "/" << max_experience << endl;
    cout << "��Ǯ: " << characterStats[money] << endl;
    cout << "=================" << endl << endl;
}

// ��ʾ��ϸ����
void Player::displayDetailedStats() const {
    cout << "=== ��ϸ���� ===" << endl;
    characterStats.display();
    cout << "================" << endl << endl;
}