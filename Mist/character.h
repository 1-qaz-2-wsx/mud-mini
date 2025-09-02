
enum Attribute {
    max_health,         // 生命值上限 
    max_mana,           // 法力值上限 Mp
    attack,             // 攻击力 ATK
    agility,            // 敏捷 
    accuracy,           // 准确度 
    money,              // 金钱
    experience_points,  // 经验
    defence,            // 防御
    NUMATTRIBUTES       // 属性值
};

class Stats {
private:
    int values[NUMATTRIBUTES];  // 存储所有属性值的数组
public:
    Stats() {}     // 构造函数，初始化所有属性
    int& operator[](Attribute attr) {} // 重载[]运算符 - 用于修改属性值
    const int& operator[](Attribute attr) const {}// const版本 - 用于读取属性值
    void display() const {}; // 显示所有属性
};

class Player {
private:
    Stats characterStats;
    int max_experience;      // 升级所需经验
    int level;               // 等级
    int current_health;      // 当前生命值
    int current_mana;        // 当前法力值
public:
    Player()  {}// 构造函数
    int getLevel() const {}// 获取当前等级
    int getCurrentHealth() const {}// 获取当前生命值
    int getCurrentMana() const {} // 获取当前法力值
    int getMaxExperience() const {}// 获取最大经验值（升级所需）
    const Stats& getStats() const {}// 获取角色属性
    void setCurrentHealth(int health) {}// 设置当前生命值
    void setCurrentMana(int mana) {}// 设置当前法力值
    void addExperience(int exp) {}// 增加经验值并检查升级
    void levelUp() {}// 升级角色
    void heal(int amount) {}// 恢复生命值
    void restoreMana(int amount) {}// 恢复法力值
    bool useMana(int amount) {}// 消耗法力值
    void takeDamage(int damage) {} // 受到伤害
    void addMoney(int amount) {}// 增加金钱
    bool spendMoney(int amount) {}// 消费金钱
    bool isAlive() const {}
    void displayStatus() const {} // 显示角色状态
    void displayDetailedStats() const {}// 显示详细属性
};


