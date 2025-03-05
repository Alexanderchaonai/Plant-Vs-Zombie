#include"pvz_character.h"
using namespace std;
//实现 植物大战僵尸的角色类构造（横坐标，纵坐标，攻击力，攻击半径，
// 移动速度，标志，效果列表）赋值成员属性（参数列表）：
// 横坐标（横坐标），纵坐标（纵坐标），攻击力（攻击力），
// 攻击范围（攻击范围），速度（速度），标志（标志）
// {设置状态列表（新增效果列表）；}
pvz_character::pvz_character(unsigned short x,
	unsigned short y, unsigned short r, unsigned short v,
	char sign, vector<effect>new_effects)
	:x(x), y(y), r(r), v(v), sign(sign)
{
	//导入新效果
	using_effects(new_effects);
}

//实现 植物大战僵尸的角色类析构（）{}
pvz_character::~pvz_character() {}

//实现 植物大战僵尸的角色类导入效果（新增效果列表）{}
void pvz_character::using_effects
(vector<effect>new_effects)
{
	//遍历（新增效果）{把当前效果添加到状态列表}
	for (effect& i : new_effects)
	{
		effects.push_back(i);
	}
}
