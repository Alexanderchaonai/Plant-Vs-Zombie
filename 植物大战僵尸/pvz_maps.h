//包含 植物大战僵尸的地图
#include "pvz_map.h"

//声明 植物大战僵尸的关卡1类
class pvz_map_1 :public Map
{
	//声明 生成僵尸（）重写；
	void new_zombie()override;	

public:

	//声明 构造（宽，高）；
	pvz_map_1(unsigned short w = 120,
		unsigned short h = 30);

	//声明 析构（）重写；
	~pvz_map_1()override;

	//声明 主循环（阳光）重写；
	void main_cycle(unsigned short& sun)override;
};