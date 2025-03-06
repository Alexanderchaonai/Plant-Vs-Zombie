#pragma once
#include"pvz_character.h"

class pvz_shell:public pvz_character
{
    //声明友元 植物大战僵尸的地图类
	friend class pvz_map;
    public:

	//声明 存在（伤害值）重写；,为什么要写存在函数，因为这个函数参数列表是对方的攻击力，，攻击也可以当成一种效果，
	//无非就是只需要写一次就可以了
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
	//	初始横纵坐标,半径，速度
	unsigned short x,y,r,v;
	//标志
	char sign;

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
	//可以攻击是指一个目标是否在你的攻击范围内，如果交给我来判断，我要获取你的攻击范围，
	//但是你的攻击范围不是三言两语能讲清的，比如胆小菇吧，僵尸离它太近它就不敢攻击了
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
	//外界大部分情况只需要读取不需要修改，那就给一个接口look函数让它们获取自己需要的属性即可
	unsigned short look(char goal)override;
    
protected://植物的自身属性都设置成保护，防止外界访问，不过本身也是抽象类，就算知道属性也无法1依次创建对象
//抽象类的使用场景
//定义接口：抽象类用于定义一组接口，派生类必须实现这些接口。

//代码复用：抽象类可以提供部分实现，派生类可以复用这些实现。

//多态：通过基类指针或引用调用派生类的实现。

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
