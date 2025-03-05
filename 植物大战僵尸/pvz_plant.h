#pragma once
#include"pvz_character.h"

class pvz_shell:public pvz_character
{
    //声明友元 植物大战僵尸的地图类
	friend class pvz_map;
    public:

	//声明 存在（伤害值）重写；
	char exist(unsigned short power = 0)override;

	//声明 观察（目标）重写；
	unsigned short look(char goal)override;

	//声明 纯虚 攻击（）=空；
	virtual vector<effect>attack() = 0;
    protected:

	//x方向，y方向
	char x_direction, y_direction;

	//攻击力
	unsigned short power;

	//声明 构造（x方向，y方向，初始横坐标，初始纵坐标，攻击力，
	// 杀伤半径，移动速度，标志，初始状态列表）；
	pvz_shell(char x_direction, char y_direction,
		unsigned short x, unsigned short y,
		unsigned short power, unsigned short r,
		unsigned short v, char sign,
		vector<effect>new_effects);

	//声明 虚 析构（）=默认；
	virtual ~pvz_shell() = default;

	//声明 纯虚 拷贝（）=空；
	virtual shared_ptr<pvz_shell>clone() = 0;

	//声明 纯虚 可以攻击（时间，目标，横坐标，纵坐标）=空；
	virtual char can_attack(unsigned long s, char goal,unsigned short x, unsigned short y) = 0;
};
//声明 植物大战僵尸的植物
class pvz_plant :public pvz_character
{
	//声明友元 植物大战僵尸的地图类
	friend class pvz_map;

public:

	//声明 存在（伤害值）重写；
	char exist(unsigned short power = 0)override;

	//声明 纯虚 过滤效果（）=空；//给植物传递效果，比如传递减速，植物可以选择拒绝接受这个效果
	virtual void filter_effects() = 0;

	//声明 执行效果（）；//过滤效果完了，植物自己再执行剩余的效果
	void perform_effects();

	//声明 纯虚 攻击（）=空；
	virtual shared_ptr<pvz_shell>attack() = 0;

	//声明 纯虚 克隆（）=空；
	virtual shared_ptr<pvz_plant>clone() = 0;

	//声明 观察（目标）重写；
	unsigned short look(char goal)override;
    
protected:

//血量
unsigned short hp;

//声明 构造（血量，横坐标，纵坐标，射程，射速，标志，新效果）；
pvz_plant(unsigned short hp, unsigned short x,
    unsigned short y, unsigned short r,
    unsigned short v, char sign,
    vector<effect>new_effects);

//声明 虚 析构（）=默认；
virtual ~pvz_plant() = default;

//声明 纯虚 可以攻击（时间，目标，横坐标，纵坐标）=空；
virtual char can_attack(unsigned long s, char goal,
    unsigned short x, unsigned short y) = 0;
};
