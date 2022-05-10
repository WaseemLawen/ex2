#define DEFAULT_FORCE 5
#define MAX_HP 100


class Player{
    const char* name;
    int maxHP;
    int force;
    int level=1;
    int HP=MAX_HP;
    int coins=0;

    public:
    Player(const char* name,int maxHP=MAX_HP,int force=DEFAULT_FORCE);
    Player(const Player&);
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int strengthen);
    void heal(int healing);
    void damage(int damage_points);
    bool isKnockedOut();
    void addCoins(int profit);
    bool pay(int payment);
    int getAttackStrength();
    ~Player();
};

