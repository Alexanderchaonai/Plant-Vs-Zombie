#include"pvz_plant.h"
#include"pvz_character.h"

pvz_shell::pvz_shell(char x_direction, char y_direction,
    unsigned short x, unsigned short y,
    unsigned short power, unsigned short r,
    unsigned short v, char sign,
    vector<effect>new_effects)
    :pvz_character(x, y, r, v, sign, new_effects), x_direction(x_direction), y_direction(y_direction), x(x), y(y), power(power), r(r), v(v), sign(sign) {}

    //实现： 植物大战僵尸的炮弹类存在
char pvz_shell::exist(unsigned short power)
{
    return sign;
}
//根据所观察到的目标返回属性
unsigned short pvz_shell::look(char goal)
{
    if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	if (goal == 'p')return power;
	return 0;
}

pvz_plant::pvz_plant(unsigned short hp, unsigned short x,
    unsigned short y, unsigned short r,
    unsigned short v, char sign,
    vector<effect>new_effects):pvz_character(x, y, r, v, sign, new_effects),hp(hp){}

//执行函数，这也是把血量控制的权限交给自己的原因，要让我控制你的血量，
//我的攻击力一千我就扣你一千滴血，交给你控制你想锁个几百点我管不着反正，后面可以加免伤性质
char pvz_plant::exist(unsigned short power)
{
    if(power>hp)    
        return 0;
    return hp-=power;
}
//要点：纯虚函数设置为0就是空实现，所以filter_effects---
void pvz_plant::perform_effects()
{
    //过滤可以免疫的效果
    filter_effects();
    //执行剩余效果
}
//实现 植物大战僵尸的植物类观察（目标）{根据目标返回属性}
unsigned short pvz_plant::look(char goal)
{
    if (goal == 's')return sign;
	if (goal == 'x')return x;
	if (goal == 'y')return y;
	if (goal == 'r')return r;
	if (goal == 'v')return v;
	return 0;
}
