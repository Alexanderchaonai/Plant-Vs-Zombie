#pragma once
#include<iostream>
#include<vector>
using namespace std;
//声明  植物大战僵尸的角色
class pvz_character
{
public:
    struct effect
    {
        //名称
        char name[50];

        //持续时间
        unsigned long s;

        //威力
        unsigned short power;
    };
    //判断当前角色是否存在（伤害值）
    virtual char exist(unsigned short power=0 )=0;
    //获取数据（目标数据）
    virtual unsigned short look(char goal)=0;
    //往状态列表添加效果（新增效果）；
	void using_effects(vector<effect>new_effects);
protected:
    //这里的移动速度v表示移动单位距离所需要的时间
    //声明 构造（横坐标，纵坐标，移动速度，标志，效果列表）；
    pvz_character(unsigned short x, unsigned short y,
		unsigned short r, unsigned short v, char sign,
		vector<effect>new_effects);
    //声明 析构（）；
    ~pvz_character();

	//标志
	char sign;

	//横坐标，纵坐标，半径，速度，血量
	unsigned short x, y, r, v, hp;

	//状态列表
	vector<effect>effects;
};