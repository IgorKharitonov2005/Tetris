#pragma once
#include "Engine.h"
#include "GameField.h"
#include "Figure.h"
#include <string>
#include <conio.h>

class Tetris:public Engine,public Figure
{
private:
	bool m_End = false;
	Figure m_Figure;
	GameField m_GameField;  
	const size_t m_Width = 14;
	const size_t m_Height = 26;
	size_t m_Score = 0;
	Figure m_NextFigure;
public:
	Tetris();
	bool end() const override;
	void DrawScore(PaintDevice& paintdevice);
	void DrawBoards(PaintDevice& paintdevice);
	void GameOver(PaintDevice& paintdevice);
	void on_button_press(const int button)override;
	void update(const int dt)override;
	void render(PaintDevice& paintDevice)override;
};
