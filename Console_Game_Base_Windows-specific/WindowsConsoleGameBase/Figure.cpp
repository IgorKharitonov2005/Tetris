#include "Figure.h"

void Figure::update(double dt)
{
	m_TimeFromLastUpdatec += dt;
	if (m_TimeFromLastUpdatec > m_TimeForUpdate) 
	{
		m_TimeFromLastUpdatec = 0;
		++m_Position.y;
	}
}

void Figure::render(PaintDevice& paintDevice)
{
	for (const Point& point : m_Body[m_CurrentRotate])
	{
		Vector2 v(point.x + m_Position.x,point.y + m_Position.y);
		paintDevice.set_char(v, 0x25D8);
	}
}

Figure Figure::random_figure(Point f)
{
	srand(time(0));
	switch (rand() % 7)
	{
	case 0:
	{
		return IBlock(f);
	}
	case 1:
	{
		return JBlock(f);
	}
	case 2:
	{
		return LBlock(f);
	}
	case 3:
	{
		return OBlock(f);
	}
	case 4:
	{
		return ZBlock(f);
	}
	case 5:
	{
		return  TBlock(f);
	}
	case 6:
	{
		return  SBlock(f);
	}
	}
}

void Figure::rotate()
{
	m_CurrentRotate++;
	if (m_CurrentRotate==4)m_CurrentRotate = 0;
}



IBlock::IBlock(Point position) :Figure(position)
{
	m_Body = { { Point(1,0), Point(1,1), Point(1,2), Point(1,3) },
		{ Point(0,2), Point(1,2), Point(2,2), Point(3,2) },
		{ Point(2,0), Point(2,1), Point(2,2), Point(2,3) },
		{ Point(0,1), Point(1,1), Point(2,1), Point(3,1) } };
}

JBlock::JBlock(Point position) :Figure(position)
{
	m_Body = { {Point(1,0),Point(1,1),Point(1,2),Point(0,2)},
		{Point(0,0),Point(0,1),Point(1,1),Point(2,1)},
		{Point(1,0),Point(2,0),Point(1,1),Point(1,2)},
		{Point(0,1),Point(1,1),Point(2,1),Point(2,2)} };
}

OBlock::OBlock(Point position) :Figure(position)
{
	m_Body = { {Point(0,0),Point(1,0),Point(0,1),Point(1,1)},
		{Point(0,0),Point(1,0),Point(0,1),Point(1,1)},
		{Point(0,0),Point(1,0),Point(0,1),Point(1,1)},
		{Point(0,0),Point(1,0),Point(0,1),Point(1,1)} };
}

ZBlock::ZBlock(Point position) :Figure(position)
{
	m_Body = { {Point(0,0),Point(1,0),Point(1,1),Point(2,1)},
		{Point(1,0),Point(1,1),Point(0,1),Point(0,2)},
		{Point(0,0),Point(1,0),Point(1,1),Point(2,1)},
		{Point(1,0),Point(1,1),Point(0,1),Point(0,2)} };
}

TBlock::TBlock(Point position) :Figure(position)
{
	m_Body = { {Point(1,0),Point(1,1),Point(2,1),Point(0,1)},
		{Point(1,0),Point(1,1),Point(2,1),Point(1,2)},
		{Point(1,2),Point(1,1),Point(2,1),Point(0,1)},
		{Point(1,0),Point(1,1),Point(0,1),Point(1,2)}};
}

SBlock::SBlock(Point position) :Figure(position)
{
	m_Body = { {Point(0,1),Point(1,1),Point(1,0),Point(2,0)},
		{Point(1,0),Point(1,1),Point(2,1),Point(2,2)},
		{Point(0,1),Point(1,1),Point(1,0),Point(2,0)},
		{Point(1,0),Point(1,1),Point(2,1),Point(2,2)}};
}

LBlock::LBlock(Point position) :Figure(position)
{
	m_Body = { {Point(1,0),Point(1,1),Point(1,2),Point(2,2)},
		{Point(0,2),Point(0,1),Point(1,1),Point(2,1)},
		{Point(0,0),Point(1,0),Point(1,1),Point(1,2)},
		{Point(0,1),Point(1,1),Point(2,1),Point(2,0)} };
}
