#include "Tetris.h"

Tetris::Tetris():Figure(Point(0,0)),m_NextFigure(Point(15,1)),m_Figure(Point(5,1))
{
	m_Figure = IBlock(Point(5, 1));
	m_NextFigure = random_figure(Point(15, 1));
	track_key(VK_LEFT);
	track_key(VK_RIGHT);
	track_key(VK_DOWN);
	track_key(VK_SPACE);
	track_key(VK_UP);
	track_key(VK_ESCAPE);
	paint_device().resize(Size(m_Width + 6, m_Height));
	m_GameField.resize(m_Width, m_Height);
}

bool Tetris::end() const
{
	if (m_End)while (_getch() != 27);
	return m_End;
}

void Tetris::DrawScore(PaintDevice& paintdevice)
{
	std::string score = std::to_string(m_Score);
	Vector2 v1(14, 6);
	Vector2 v2(15, 6);
	Vector2 v3(16, 6);
	Vector2 v4(17, 6);
	Vector2 v5(18, 6);
	paintdevice.set_char(v1, 'S');
	paintdevice.set_char(v2, 'C');
	paintdevice.set_char(v3, 'O');
	paintdevice.set_char(v4, 'R');
	paintdevice.set_char(v5, 'E');
	for (size_t i = 0; i < score.size(); i++)
	{
		Vector2 v7(14+i, 7);
		paintdevice.set_char(v7, score[i]);
	}
}

void Tetris::DrawBoards(PaintDevice& paintdevice)
{
	for (int i = m_Width; i < m_Width + 5; i++)
	{
		Vector2 v1(i, m_Height - 1);
		paintdevice.set_char(v1, 0x2550);
		Vector2 v2(i, 0);
		paintdevice.set_char(v2, 0x2550);
		Vector2 v3(i, 5);
		paintdevice.set_char(v3, 0x2550);
	}

	for (int i = 1; i < m_Height - 1; i++)
	{
		Vector2 v2(m_Width +5, i);
		paintdevice.set_char(v2, 0x2551);
	}
	Vector2 v10(m_Width -1, 5);
	paintdevice.set_char(v10, 0x2560);
	Vector2 v11(m_Width +5, 5);
	paintdevice.set_char(v11, 0x2563);
	Vector2 v12(m_Width +5, 0);
	paintdevice.set_char(v12, 0x2557);
	Vector2 v14(m_Width +5, m_Height - 1);
	paintdevice.set_char(v14, 0x255D);
}

void Tetris::GameOver(PaintDevice& paintdevice)
{
	Vector2 v1(8, 11);
	Vector2 v2(9, 11);
	Vector2 v3(10, 11);
	Vector2 v4(11, 11);
	Vector2 v5(8, 12);
	Vector2 v6(9, 12);
	Vector2 v7(10, 12);
	Vector2 v8(11, 12);
	paintdevice.set_char(v1, 'G');
	paintdevice.set_char(v2, 'A');
	paintdevice.set_char(v3, 'M');
	paintdevice.set_char(v4, 'E');
	paintdevice.set_char(v5, 'O');
	paintdevice.set_char(v6, 'V');
	paintdevice.set_char(v7, 'E');
	paintdevice.set_char(v8, 'R');
}

void Tetris::on_button_press(const int button)
{
	m_Figure.backup();
	switch (button)
	{
	case VK_LEFT:m_Figure.move_left();
		break;
	case VK_RIGHT:m_Figure.move_right();
		break;
	case VK_DOWN:	m_Figure.boost();
		break;
	case VK_SPACE:m_Figure.rotate();
		break;
	case VK_UP:m_Figure.unboost();
		break;
	case VK_ESCAPE:m_End = true;
		break;
	}

	if (m_GameField.has_collision(m_Figure))
	{
		m_Figure.restore();
 	}
}

void Tetris::update(const int dt)
{
	m_Figure.backup();
	m_Figure.update(dt);
	if (m_GameField.has_collision(m_Figure))
	{
		m_Figure.restore();
		m_Score+= m_GameField.merge(m_Figure);
		if (m_Score > 999999) m_Score = 999999;
 		m_Figure =m_NextFigure;
		m_Figure.set_position(Point(5, 1));
		m_NextFigure = random_figure(Point(15,1));
		if (m_GameField.has_collision(m_Figure))
		{
			m_End = true;
		}
	}
}

void Tetris::render(PaintDevice& paintDevice)
{
	m_NextFigure.render(paintDevice);
	DrawScore(paintDevice);
	m_GameField.render(paintDevice);
	m_Figure.render(paintDevice);
	DrawBoards(paintDevice);
	if (m_End)
	{
		paintDevice.clear();
		GameOver(paintDevice);
	}
}
