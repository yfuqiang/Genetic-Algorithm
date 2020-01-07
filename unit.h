#ifndef UNIT_H
#define UNIT_H
#include<iostream>
using namespace std;
const int NUM = 32;

const int value[NUM] = { 8,9,15,6,16,9,1,4,14,9,3,7,12,4,15,5,18,5,15,4,6,2,12,14,11,9,13,13,14,13,19,4 };//各物品价值
const int vv[NUM] = { 11,22,12,21,21,13,1,10,13,8,6,25,13,27,12,23,12,24,23,11,6,24,28,10,20,13,25,23,5,26,30,15 };//各物品体积
const int ww[NUM] = { 22,15,4,5,10,19,21,20,8,13,2,3,6,17,12,5,12,4,12,21,14,23,17,15,20,22,25,0,22,15,25,13 };//各物品重量

class unit {
public:
	int valsum;
	int vsum;
	int wsum;
	int gene[NUM];
	int fit;
	
	int gen;
	unit();

};






#endif