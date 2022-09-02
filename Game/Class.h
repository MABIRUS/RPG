class hero
{
public:
    int hp;
    int dmg;
    int exp;
    int money;
    int goddamn;
    int lvl_number;
    int dmg_item;
    int hp_item;
    int shop;
    std::string weapon_name;
    std::string armor_name;
    std::string shop_name;
};

class ENEMY
{
public:
    int hp;
    int dmg;
    int exp;
    int money;
};

class SMITH
{
public:
    int shop_money;
    int dmg;//Урон оружия 
    int money;//Стоимость оружия
    int hp;
    int shop_hp_items;
    int shop_dmg_items;
};

class GAME
{

public:
    int enemy;
    void save(int lvl_number, int& hp, int& exp, int& goddamn, int& dmg, int& money, std::string weapon_name, int weapon_dmg, std::string armor_name, int armor_hp);
    void recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& lvl_number, int& enemy);
    void info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn);
    void battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn);
    void shoop(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name);
    void fountain_(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn);
    void game_loop();
};
