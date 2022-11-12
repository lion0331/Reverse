#pragma once

#include <Windows.h>

struct T人物属性
{
	//对象+8 ID
	//[对象+C]+8 血量
	//[对象+C]+10 当前等级
	//[对象+C]+18 移动速度
	//[对象+C]+24 最大血量
	//[对象+C]+30 暴击伤害
	//[对象+C]+34 命中率
	//[对象+C]+38 治疗比例
	//[对象+C]+68 经验
	//[对象+C]+27C 剩余攻击点数
	//[对象+C]+280 剩余防御点数
	//[对象+10]+154 X
	//[对象+10]+158 Y
	//[对象+10]+15C Z
	DWORD d血量;
	DWORD d最大血量;
	FLOAT fX;
	FLOAT fY;
	FLOAT fZ;
	DWORD dID;
	DWORD d对象;
	FLOAT f距离;
	char* p名称;
	char pgbk名称[100];
	void c初始化();

};


struct T取人物对象数组
{

	T人物属性 列表[0x1000];
	DWORD d数量;
	void c初始化();

};


struct T周围遍历
{

	T人物属性 列表[0x1000];
	DWORD d数量;
	void c初始化();
	T人物属性 c返回最近怪物();

};



struct T背包物品
{
	DWORD dID;
	WORD w数量;
	WORD w最大数量;
	DWORD d对象;
	DWORD d位置;
	DWORD d所在背包;
	char* p名称;
	char pgbk名称[100];
};


struct T背包物品遍历
{
	T背包物品 列表[0x1000];
	DWORD d数量;
	void c初始化();
	void c递归遍历(DWORD);

};

struct T技能冷却
{
	DWORD dID;
	FLOAT f冷却时间;
	char* p名称;
	char pgbk名称[100];
};


struct T技能冷却遍历
{
	T技能冷却 列表[0x1000];
	DWORD d数量;
	void c初始化();
	void c递归遍历(DWORD);
};


struct T已学技能遍历
{
	T技能冷却 列表[0x1000];
	DWORD d数量;
	void c初始化();
	void c递归遍历(DWORD);
};


struct T任务
{
	WORD wID;
	WORD w完成度;
	DWORD d对象;
	char* p名称;
	char pgbk名称[100];
};


struct T任务遍历
{
	T任务 列表[0x1000];
	DWORD d数量;
	void c初始化();
	void c递归遍历(DWORD);

};

struct T任务库遍历
{
	T任务 列表[0x1000];
	DWORD d数量;
	void c初始化();
	void c递归遍历(DWORD);

};