#include "unit.h"
#include "population.h"
int random() {
	float k;
	k = rand() % 1000 / 1000.0;
	if (k < 0.8)
		return 0;
	else
		return 1;
}

void population::popu() {
	int i,j,wsum1,vsum1;
	for (i = 0;i < SIZE;i++)
	{
		wsum1 = 0;
		vsum1 = 0;
		for (j = 0;j < NUM;j++)
		{
			ALL[i].gene[j] =random();
			wsum1 += ALL[i].gene[j] * ww[j];
			vsum1 += ALL[i].gene[j] * vv[j];
		}
		if (wsum1 > WMAX || vsum1 > VMAX)
		{
			i--;
		}
	}
}

int population::Cal_val(int i) {
	int ssum=0;
	int j;
	for (j = 0;j < NUM;j++)
	{
		ssum += ALL[i].gene[j] * value[j];

	}
	ALL[i].valsum= ssum;
	return ssum;
}

int population::Cal_v(int i) {
	int ssum = 0;
	int j;
	for (j = 0;j < NUM;j++)
	{
		ssum += ALL[i].gene[j] * vv[j];

	}
	ALL[i].vsum = ssum;
	return ssum;
}
int population::Cal_w(int i) {
	int ssum = 0;
	int j;
	for (j = 0;j < NUM;j++)
	{
		ssum += ALL[i].gene[j] * ww[j];

	}
	ALL[i].wsum = ssum;
	return ssum;
}

void population::Cal_fit() {
	int i,w1,v1,value1;
	for (i = 0;i < SIZE;i++)
	{
		w1 = Cal_w(i);
		v1 = Cal_v(i);
		value1 = Cal_val(i);
		if ((w1 > WMAX) || (v1 > VMAX))
		{
			ALL[i].fit = 0;
			continue;
		}
		ALL[i].fit = value1;
	}
}

void population::Cal_Best(int m)
{
	int maxb = ALL[0].fit;
	int i, j,temp,id;
	id = 0;

	for (i =0;i < SIZE;i++)
	{
		if (ALL[i].fit > maxb)
		{
			maxb = ALL[i].fit;
			id = i;
		}

	}
	if (maxb > Best.fit) {
		Best = ALL[id];
		Best.gen = m;
	}

}

void population::select() {
	int fit_sum = 0;
	unit Newu[SIZE];
	float srate[SIZE],rrate;
	int i, j;
	for (i = 0;i < SIZE;i++)
	{
		fit_sum += ALL[i].fit;
	}

	srate[0] = float(ALL[0].fit) / fit_sum;
	for (i = 1;i < SIZE;i++)
	{
		srate[i]=srate[i-1]+ float(ALL[i].fit) / fit_sum;

	}
	for (i = 0;i < SIZE;i++) {
		rrate = (rand() % 1000 / 1000.0);
		for (j = 0;j < SIZE;j++)
		{
			if (srate[j] >= rrate)
			{
				Newu[i] = ALL[j];
				break;
			}
		}
	}
	for (i = 0;i < SIZE;i++)
	{
		ALL[i] = Newu[i];

	}
}

void population::cross()
{
	int i,j,temp;
	int pos;
	for (i = 0;i < SIZE - 1; i=i+2)
	{
		pos = rand() % 32;
		for (j = 0;j <= pos;j++)
		{
			if (iscross())
			{
				temp = ALL[i].gene[j];
				ALL[i].gene[j] = ALL[i+1].gene[j];
				ALL[i+1].gene[j] = temp;
			}
		}
	}
}

void population::Variation()
{
	int i, j;
	for (i = 0;i < SIZE;i++)
	{
		if (isvariation())
		{
			for (j = 0;j < NUM;j++)
			{
				if (isvariation())
				{
					ALL[i].gene[j] = ALL[i].gene[j] ? 0 : 1;
				}
			}
		}
	}
}

void population::GO()
{
	int i, j;
	popu();
	
	for (i = 0;i < GENERATION_MAX;i++)
	{
		Cal_fit();
		Cal_Best(i);
		select();
		cross();
		if (i % 10 == 0 && i != 0) {
			Variation();
		}
	}
	Cal_fit();
	Cal_Best(GENERATION_MAX);
	cout << "得到的最大价值是： " << Best.fit << endl;
	cout << "此时的总体积为： " << Best.vsum << endl;
	cout << "此时的总重量为： " << Best.wsum << endl;
	cout << "其选择物品的编号为： ";
	for (i = 0;i < NUM;i++)
	{
		if (Best.gene[i] == 1)
		{
			cout << i+1 << ' ' ;
		}
	}
	cout << endl;
	cout << "最优个体的代是： " << Best.gen << endl;



}