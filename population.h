#ifndef POPU_H
#define POPU_H
#include "unit.h"
#include<stdlib.h>
const int SIZE = 500;
const int WMAX = 80; //背包的最大承受重量
const int VMAX = 80;  // 背包的最大承受容积
const float PC = 0.75;
const float PV = 0.15;
const int GENERATION_MAX = 100;



class population {
private:
	unit ALL[SIZE];
	unit Best;
public:
	void popu();
	int Cal_val(int i);
	int Cal_v(int i);
	int Cal_w(int i);
	void Cal_fit();
	void Cal_Best(int m);
	void select();
	bool iscross(){ return ((rand() % 1000 / 1000.0) <= PC); }
	void cross();
	bool isvariation(){ return ((rand() % 1000 / 1000.0) <= PV); }
	void Variation();
	void GO();

};


#endif