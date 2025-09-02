
enum Attribute {
    max_health,         // ����ֵ���� 
    max_mana,           // ����ֵ���� Mp
    attack,             // ������ ATK
    agility,            // ���� 
    accuracy,           // ׼ȷ�� 
    money,              // ��Ǯ
    experience_points,  // ����
    defence,            // ����
    NUMATTRIBUTES       // ����ֵ
};

class Stats {
private:
    int values[NUMATTRIBUTES];  // �洢��������ֵ������
public:
    Stats() {}     // ���캯������ʼ����������
    int& operator[](Attribute attr) {} // ����[]����� - �����޸�����ֵ
    const int& operator[](Attribute attr) const {}// const�汾 - ���ڶ�ȡ����ֵ
    void display() const {}; // ��ʾ��������
};

class Player {
private:
    Stats characterStats;
    int max_experience;      // �������辭��
    int level;               // �ȼ�
    int current_health;      // ��ǰ����ֵ
    int current_mana;        // ��ǰ����ֵ
public:
    Player()  {}// ���캯��
    int getLevel() const {}// ��ȡ��ǰ�ȼ�
    int getCurrentHealth() const {}// ��ȡ��ǰ����ֵ
    int getCurrentMana() const {} // ��ȡ��ǰ����ֵ
    int getMaxExperience() const {}// ��ȡ�����ֵ���������裩
    const Stats& getStats() const {}// ��ȡ��ɫ����
    void setCurrentHealth(int health) {}// ���õ�ǰ����ֵ
    void setCurrentMana(int mana) {}// ���õ�ǰ����ֵ
    void addExperience(int exp) {}// ���Ӿ���ֵ���������
    void levelUp() {}// ������ɫ
    void heal(int amount) {}// �ָ�����ֵ
    void restoreMana(int amount) {}// �ָ�����ֵ
    bool useMana(int amount) {}// ���ķ���ֵ
    void takeDamage(int damage) {} // �ܵ��˺�
    void addMoney(int amount) {}// ���ӽ�Ǯ
    bool spendMoney(int amount) {}// ���ѽ�Ǯ
    bool isAlive() const {}
    void displayStatus() const {} // ��ʾ��ɫ״̬
    void displayDetailedStats() const {}// ��ʾ��ϸ����
};


