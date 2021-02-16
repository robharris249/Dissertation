#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Node2D {

	public:
	float x;
	float y;
	float z;


	Node2D(float x, float y, float value);
	void ToString();
	friend ostream& operator<<(ostream& os, const Node2D& n2d);
};

