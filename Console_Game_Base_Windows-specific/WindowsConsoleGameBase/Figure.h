#pragma once
#include <vector>
#include "PaintDevice.h"

using namespace std;

struct Point
{
	int x;
	int y;
	Point(const int x = 0, const int y = 0) :x(x), y(y) {};
};

class Figure
{
protected:
	vector<vector<Point>> m_Body;
	size_t m_CurrentRotate = 0;
	size_t m_CurrentRotateBackup = 0;
	Point m_Position;
	Point m_PositionBackup;
	double m_TimeFromLastUpdatec = 0;
	double m_TimeForUpdate = 500; //полсекунды
public:
	Figure(Point position): m_Position(position) {};
	void update(double dt);
	void render(PaintDevice& paintDevice);
	void move_right() { m_Position.x++; };
	void move_left() { m_Position.x--; };
	void boost() { m_TimeForUpdate = 50; };
	void unboost() { m_TimeForUpdate = 500; };
	Figure random_figure(Point);
	const vector<Point>& get_body() const { return m_Body[m_CurrentRotate]; };
	Point get_position() const { return m_Position; };
	void set_position(Point position) { m_Position = position; };
	void backup() { m_PositionBackup = m_Position; m_CurrentRotateBackup = m_CurrentRotate; };
	void restore() {m_Position = m_PositionBackup; m_CurrentRotate = m_CurrentRotateBackup;};
	void rotate();
};

class IBlock :public Figure
{
public:
	IBlock(Point position);
};

class JBlock :public Figure
{
public:
	JBlock(Point position);
};

class OBlock :public Figure
{
public:
	OBlock(Point position);
};

class ZBlock :public Figure
{
public:
	ZBlock(Point position);
};

class TBlock :public Figure
{
public:
	TBlock(Point position);
};

class SBlock :public Figure
{
public:
	SBlock(Point position);
};

class LBlock :public Figure
{
public:
	LBlock(Point position);
};

