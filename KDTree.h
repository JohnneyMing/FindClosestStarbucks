
//Author : Mingwei zhong

#ifndef KDTREE_H
#define KDTREE_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



class KDNode
{
public:
    double		x;
	double		y;
	string city;
	string address;
    KDNode*     left;
    KDNode*     right;

    KDNode(double x, double y, string city, string address)
    {
        this->x = x;
		this->y = y;
		this->city = city;
		this->address = address;
        left = right = NULL;
    }
};

class KDTree
{
public:
	KDTree();
	~KDTree();
	void insert(double x, double y, string city, string address);
	void getNearest(double x, double y, vector<KDNode*>& result);
private:
	KDNode* root;
	KDNode* insert(double x, double y, string city, string address, KDNode* t, int level);
	void getNearest(double x, double y, KDNode* root, vector<KDNode*>& result, int level);
	void clear(KDNode*t);
};

#endif


