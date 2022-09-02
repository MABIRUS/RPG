#include <iostream>
#include <fstream>
#include <ctime>
#include "Class.h"
#include "function.h"
#include <direct.h>


const int n = 10;
int lvl[n];//������
int lvl_hp[n];//����� ��� ��������������� ������
int lvl_exp[n];//���� ��� ��������������� ������
int lvl_dmg[n];//���� ��� ��������������� ������

//������� ��� �����
enum SMITH_COMMAN
{
    SMITH_COMMAND_IRON_CLUB = 1,
    SMITH_COMMAND_STEEL_SWORD = 2,
    SMITH_COMMAND_LEATHER_ARMOR = 3,
    SMITH_COMMAND_IRON_ARMOR = 4,
};

//�������������� �����������
enum ENEMIES
{
    ENEMIES_OGR_hp = 15,
    ENEMIES_OGR_dmg = 6,
    ENEMIES_OGR_exp = 6,
    ENEMIES_OGR_money = 14,
    ENEMIES_ELF_hp = 8,
    ENEMIES_ELF_dmg = 12,
    ENEMIES_ELF_exp = 8,
    ENEMIES_ELF_money = 17,
    ENEMIES_WOOD_GOBLIN_hp = 18,
    ENEMIES_WOOD_GOBLIN_dmg = 8,
    ENEMIES_WOOD_GOBLIN_exp = 7,
    ENEMIES_WOOD_GOBLIN_money = 20,
    ENEMIES_SLIZEN_hp = 10,
    ENEMIES_SLIZEN_dmg = 4,
    ENEMIES_SLIZEN_exp = 4,
    ENEMIES_SLIZEN_money = 10,
    ENEMIES_WILD_DOG_hp = 5,
    ENEMIES_WILD_DOG_dmg = 4,
    ENEMIES_WILD_DOG_exp = 2,
    ENEMIES_WILD_DOG_money = 5,
};

//������ � �����
enum WEAPON_AND_ARMOR
{
    WEAPON_money_IRON_CLUB = 40,
    WEAPON_dmg_IRON_CLUB = 5,
    WEAPON_money_STEEL_SWORD = 150,
    WEAPON_dmg_STEEL_SWORD = 15,
    ARMOR_money_LEATHER_ARMOR = 70,
    ARMOR_hp_LEATHER_ARMOR = 50,
    ARMOR_money_IRON_ARMOR = 300,
    ARMOR_hp_IRON_ARMOR = 250,
};

void lvl_inic(int const& n, int* lvl, int* lvl_hp, int* lvl_exp, int* lvl_dmg)
{
    for (int i = 0; i < n; i++)
        lvl[i] = i + 1;
    for (int i = 0; i < n; i++)
        lvl_hp[i] = 25 * i + 100;
    int lvl_exp1[10] = { 10,25,45,70,85,100,130,170,200,250 };//���� ��� ��������������� ������
    for (int i = 0; i < n; i++)
    {
        lvl_exp[i] = lvl_exp1[i];
    }
    int lvl_dmg1[10] = { 3,5,9,12,15,19,24,28,35,40 };//���� ��� ��������������� ������
    for (int i = 0; i < n; i++)
    {
        lvl_dmg[i] = lvl_dmg1[i];
    }
}

void GAME::info(const int n, int& lvl_number, int lvl[10], int lvl_exp[10], int& exp, int& hp, int& dmg, int& money, std::string weapon_name, std::string armor_name, int& goddamn)
{
    system("cls");
    std::cout << "��� ������� " << lvl[lvl_number] << "." << std::endl;
    if (lvl_number + 1 != n) {
        std::cout << "�� ������ ������ �������� " << lvl_exp[lvl_number] - exp << " �����." << std::endl;
    }
    else {
        std::cout << "�� ������ ������ �������� 0 �����." << std::endl;
    }
    std::cout << "���� ���������� ��������� " << goddamn / 10 << ". " << "���� �������� ����� ���������� �� " << goddamn << "." << std::endl;
    std::cout << "���� �������� " << hp << "." << std::endl;
    std::cout << "��� ���� " << dmg << "." << std::endl;
    std::cout << "���������� ����� " << money << "." << std::endl;
    std::cout << "���� ������ " << weapon_name << "." << std::endl;
    std::cout << "���� ����� " << armor_name << "." << std::endl << std::endl;
}

void GAME::game_loop()
{
    setlocale(LC_ALL, "rus");
    hero Hobbit{ 100,0,0,0,0,0,0,0,0,"������������� ��������","������ ������"," " };
    GAME my_game;
    ENEMY my_enemy;
    SMITH smith;
    int k=1;
    lvl_inic(n, lvl, lvl_hp, lvl_exp, lvl_dmg);
    _mkdir("..\\saves");
    std::ifstream file("..\\saves\\save.txt");
    if (file.is_open()) {
        while (k == 1) {
            std::cout << "1) ������ ����� ����.\n2) ����������.\n" << std::endl;
            int menu_choice;
            std::cin >> menu_choice;
            system("cls");
            if (menu_choice == 1) { k = 0; }
            else if (menu_choice == 2) {
                file >> Hobbit.lvl_number;
                file >> Hobbit.hp;
                file >> Hobbit.exp;
                file >> Hobbit.goddamn;
                file >> Hobbit.dmg;
                file >> Hobbit.money;
                std::string weapon_name1;
                file >> weapon_name1;
                std::string weapon_name2;
                file >> weapon_name2;
                std::string weapon_name0 = weapon_name1 + " " + weapon_name2;
                Hobbit.weapon_name = weapon_name0;
                file >> Hobbit.dmg_item;
                std::string armor_name1;
                file >> armor_name1;
                std::string armor_name2;
                file >> armor_name2;
                std::string armor_name0 = armor_name1 + " " + armor_name2;
                Hobbit.armor_name =armor_name0;
                file >> Hobbit.hp_item;
                k = 0;
            }
            else {
                std::cout << "�� ����� ������������ �����\n";
            }
        }
    }
    while (Hobbit.hp > 0) { //���� ����
        Hobbit.dmg = lvl_dmg[Hobbit.lvl_number] + Hobbit.dmg_item;
        std::cout << "������� ����� ��� ������ �������:\n1) ������� ���������� � �����.\n2) ����������� � ���.\n3) ����� � �������.\n4) ���� � �������.\n\n";
        int my_choice;
        std::cin >> my_choice;
        system("cls");
        switch (my_choice) {
        case 1:         //����� ������� ���������� � �����.
            my_game.info(n, Hobbit.lvl_number, lvl, lvl_exp, Hobbit.exp, Hobbit.hp, Hobbit.dmg, Hobbit.money, Hobbit.weapon_name, Hobbit.armor_name, Hobbit.goddamn);
            my_game.save(Hobbit.lvl_number, Hobbit.hp, Hobbit.exp, Hobbit.goddamn, Hobbit.dmg, Hobbit.money, Hobbit.weapon_name, Hobbit.dmg_item, Hobbit.armor_name, Hobbit.hp_item);
            break;
        case 2:         //��� � ����� ����������
            my_game.recruitment_of_the_enemy(my_enemy.hp, my_enemy.dmg, my_enemy.exp, my_enemy.money, Hobbit.lvl_number, my_game.enemy);
            //����� ������� �����
            if (my_game.enemy >= 0 && my_game.enemy <= 92) {
                my_game.battle(my_game.enemy, Hobbit.hp, my_enemy.hp, Hobbit.dmg, my_enemy.dmg, Hobbit.money, my_enemy.money, Hobbit.lvl_number, n, my_enemy.exp, Hobbit.exp, &lvl_exp[Hobbit.lvl_number], &lvl_hp[Hobbit.lvl_number], Hobbit.hp_item, Hobbit.goddamn);
            }
            if (Hobbit.hp >= 1) {
                my_game.save(Hobbit.lvl_number, Hobbit.hp, Hobbit.exp, Hobbit.goddamn, Hobbit.dmg, Hobbit.money, Hobbit.weapon_name, Hobbit.dmg_item, Hobbit.armor_name, Hobbit.hp_item);
            }
            break;
        case 3: //������
            my_game.shoop(Hobbit.money, Hobbit.shop, smith.shop_money, smith.shop_hp_items, smith.shop_dmg_items, my_choice, Hobbit.hp_item, Hobbit.dmg_item, Hobbit.weapon_name, Hobbit.armor_name, Hobbit.shop_name);
            my_game.save(Hobbit.lvl_number, Hobbit.hp, Hobbit.exp, Hobbit.goddamn, Hobbit.dmg, Hobbit.money, Hobbit.weapon_name, Hobbit.dmg_item, Hobbit.armor_name, Hobbit.hp_item);
            break;
        case 4: //����� ������� �������
            my_game.fountain_(Hobbit.money, Hobbit.hp, Hobbit.lvl_number, &lvl_hp[Hobbit.lvl_number], Hobbit.hp_item, Hobbit.goddamn);
            my_game.save(Hobbit.lvl_number, Hobbit.hp, Hobbit.exp, Hobbit.goddamn, Hobbit.dmg, Hobbit.money, Hobbit.weapon_name, Hobbit.dmg_item, Hobbit.armor_name, Hobbit.hp_item);
            break;
        }
    }

}

void GAME::fountain_(int& money, int& hp, int& lvl_number, int lvl_hp[], int hp_item, int& goddamn)
{
    int comand;
    std::cout << "�� ������� � ������.\n�� �������� ����� ���� ���� ���������: \n����� ������ ������ �� ���������� �������, ������, ������ �� ��������� 30 �����, � ���� ������ ������ ������ �������!�" << std::endl << std::endl;
    std::cout << "���� ���������� �����: " << money << std::endl << std::endl;
    std::cout << "1) ���������.\n2) �� �������.\n0) ����." << std::endl << std::endl;
    std::cin >> comand;
    std::cout << std::endl;
    system("cls");
    switch (comand) {
    case 0:break;
    case 1:
        if (money >= 30) {
            std::cout << "�� ����������." << std::endl << std::endl;
            hp = lvl_hp[lvl_number] + hp_item - goddamn;
            money -= 30;
        }
        else {
            std::cout << "� ��� ������������ �����." << std::endl << std::endl;
        }
        break;
    case 2:
        std::cout << "�� ����������.\n���� ������������ ���������� �������� ���������� �� 10 ������." << std::endl << std::endl;
        goddamn += 10;
        hp = lvl_hp[lvl_number] + hp_item - goddamn;
        if (hp < 1) {
            std::cout << "��� �������� ��������." << std::endl;
        }
        break;
    }
}

void GAME::recruitment_of_the_enemy(int& enemy_hp, int& enemy_dmg, int& enemy_exp, int& enemy_money, int& lvl_number, int& enemy)
{
    srand(time(0));
    enemy = rand() % 100;
    if (enemy >= 0 && enemy <= 6)
    {
        std::cout << "�� ���������� �� ������." << std::endl;
        enemy_hp = ENEMIES_WOOD_GOBLIN_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_WOOD_GOBLIN_dmg;
        enemy_exp = ENEMIES_WOOD_GOBLIN_exp;
        enemy_money = ENEMIES_WOOD_GOBLIN_money;
    }
    else if (enemy >= 7 && enemy <= 20)
    {
        std::cout << "� ������ �������� ����." << std::endl;
        enemy_hp = ENEMIES_ELF_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_ELF_dmg;
        enemy_exp = ENEMIES_ELF_exp;
        enemy_money = ENEMIES_ELF_money;
    }
    else if (enemy >= 21 && enemy <= 41)
    {
        std::cout << "��� ����� ������� �� ��� ���." << std::endl;
        enemy_hp = ENEMIES_OGR_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_OGR_dmg;
        enemy_exp = ENEMIES_OGR_exp;
        enemy_money = ENEMIES_OGR_money;
    }
    else if (enemy >= 42 && enemy <= 68)
    {
        std::cout << "�� ��� ����� ����� ��� ." << std::endl;
        enemy_hp = ENEMIES_WILD_DOG_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_WILD_DOG_dmg;
        enemy_exp = ENEMIES_WILD_DOG_exp;
        enemy_money = ENEMIES_WILD_DOG_money;
    }
    else if (enemy >= 69 && enemy <= 92)
    {
        std::cout << "�� ����� ��������� �������." << std::endl;
        enemy_hp = ENEMIES_SLIZEN_hp * (lvl_number + 1);
        enemy_dmg = ENEMIES_SLIZEN_dmg;
        enemy_exp = ENEMIES_SLIZEN_exp;
        enemy_money = ENEMIES_SLIZEN_money;
    }
    else if (enemy >= 93 && enemy <= 99)
        std::cout << "��������� �� ������.\n\n";

}
void GAME::battle(int& enemy, int& hp, int& enemy_hp, int& dmg, int& enemy_dmg, int& money, int& enemy_money, int& lvl_number, const int n, int& enemy_exp, int& exp, int lvl_exp[], int lvl_hp[], int& hp_item, int& goddamn)
{
    int hit;
    int lvlexp = lvl_exp[lvl_number];
    int lvlhp = lvl_hp[lvl_number];
    int chance, head_chance = 35, body_chance = 80, arm_chance = 42;
    if (enemy != 0) {
        while (hp > 0) {
            std::cout << std::endl << "���� ���������� ����� " << hp << "." << std::endl;
            std::cout << "���������� ������ ���������� " << enemy_hp << "." << std::endl;
            std::cout << "�������� ���� ������� ����\n1) ������\n2) ����\n3) ����" << std::endl << std::endl;
            std::cin >> hit;
            system("cls");
            switch (hit)
            {
            case 1:
                chance = rand() % 100;
                if (chance < head_chance) {
                    
                    std::cout << "�� ������� ���� � ������" << std::endl;
                    std::cout << "����� ������� ���� �� " << dmg << " �����." << std::endl;
                    enemy_hp -= dmg;
                    break;
                }
                else {
                    std::cout << "�� ������������." << std::endl;
                    break;
                }
            case 2:
                chance = rand() % 100;
                if (chance < body_chance) {
                    std::cout << "�� ������� ���� � ����" << std::endl;
                    std::cout << "����� ������� ���� �� " << int(dmg * 0.7) << " �����." << std::endl;
                    enemy_hp -= int(dmg * 0.7);
                    break;
                }
                else {
                    std::cout << "�� ������������." << std::endl;
                    break;
                }
            case 3:
                chance = rand() % 100;
                if (chance < arm_chance) {
                    std::cout << "�� ������� ���� � ����" << std::endl;
                    std::cout << "����� ������� ���� �� " << int(dmg * 0.7) << " �����." << std::endl;
                    std::cout << "��������� ������ ������� �� 30% ������ �����" << std::endl;
                    enemy_hp -= int(dmg * 0.4);
                    enemy_dmg *= 0.7;
                    break;
                }
                else {
                    std::cout << "�� ������������." << std::endl;
                    break;
                }
            }
            std::cout << "��������� ����� ��� " << enemy_dmg << " �����." << std::endl;
            hp -= enemy_dmg;
            if (hp < 1) {
                std::cout << "��� �����." << std::endl;
            }
            if (enemy_hp < 1) {
                std::cout << "�� �������� ����������!" << std::endl;
                std::cout << "�������� " << enemy_money << " �����." << std::endl;
                money += enemy_money;
                if ((lvl_number + 1) == n) {
                    std::cout << "�� �������� ������������� ������!\n������ �� �� ��������� �����. " << std::endl;
                }
                else {
                    std::cout << "��������� " << enemy_exp << " �����." << std::endl << std::endl;
                    exp += enemy_exp;
                    if (exp >= lvlexp) {
                        exp = exp - lvlexp;
                        lvl_number = lvl_number + 1;
                        std::cout << "����������! �� �������� " << lvl_number + 1 << " ������." << std::endl << std::endl;
                        hp = lvlhp + hp_item - goddamn;
                    }
                }
                break;
            }
        }
    }
}
void GAME::shoop(int& money, int& shop, int& shop_money, int& shop_hp_item, int& shop_dmg_item, int& comand, int& hp_item, int& dmg_item, std::string weapon_name, std::string armor_name, std::string shop_name)
{
    std::cout << "����������� ������! ���-�� ������ ���������?\n";
    while (comand != 0)
    {
        int comand;
        std::cout << "� ��� " << money << " �����.\n\n";
        std::cout << "1) ������ �������� �������         +5  � �����              40 �����.\n2) ������ �������� ���             +15 � �����             150 �����.\n";
        std::cout << "3) ������ ������� �����            +50 � �����              70 �����.\n4) ������ �������� �����          +250 � �����             300 �����.\n";
        std::cout << "0) ����� �� �������.\n\n";
        std::cin >> comand;
        system("cls");
        switch (comand) {
        case 0:
            shop = 0;
            break;
        case SMITH_COMMAND_IRON_CLUB:
            shop_money = WEAPON_money_IRON_CLUB;
            shop_name = "�������� �������";
            shop_dmg_item = WEAPON_dmg_IRON_CLUB;
            shop = 1; break;
        case SMITH_COMMAND_STEEL_SWORD:
            shop_money = WEAPON_money_STEEL_SWORD;
            shop_name = "�������� ���";
            shop_dmg_item = WEAPON_dmg_STEEL_SWORD;
            shop = 1; break;
        case SMITH_COMMAND_LEATHER_ARMOR:
            shop_money = ARMOR_money_LEATHER_ARMOR;
            shop_name = "������� �����";
            shop_hp_item = ARMOR_hp_LEATHER_ARMOR;
            shop = 2; break;
        case SMITH_COMMAND_IRON_ARMOR:
            shop_money = ARMOR_money_IRON_ARMOR;
            shop_name = "�������� �����./n";
            shop_hp_item = ARMOR_hp_IRON_ARMOR;
            shop = 2; break;
        }
        if (shop == 0) {
            break;
        }
        else if (money < shop_money) {
            std::cout << "�� ������� �����." << std::endl;
        }
        else {
            if (shop == 1) {
                if (weapon_name == shop_name) {
                    std::cout << "� ��� ���� ��� ������." << std::endl;
                }
                else {
                    weapon_name = shop_name;
                    dmg_item = shop_dmg_item;
                    money -= shop_money;
                }
            }
            else if (shop == 2) {
                if (armor_name == shop_name) {
                    std::cout << "� ��� ���� ��� �����." << std::endl;
                }
                else {
                    armor_name = shop_name;
                    hp_item = shop_hp_item;
                    money -= shop_money;
                }
            }
        }
    }


}
void GAME::save(int lvl_number, int& hp, int& exp, int& goddamn, int& dmg, int& money, std::string weapon_name, int weapon_dmg, std::string armor_name, int armor_hp){
    std::ofstream file1("..\\saves\\save.txt");
    file1 << lvl_number << " " << hp << " " << exp << " " << goddamn << " " << dmg << " " << money << " " << weapon_name << " " << weapon_dmg << " " << armor_name << " " << armor_hp << " ";
    file1.close(); 
}