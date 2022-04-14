#pragma once
#include <vector>
#include <iostream>

class Game
{
public:
	Game();
	~Game();
	bool chek_board();
	void bulid_board();
	void input_elem();
	void finish_game(bool);
private:
	const int m_size = 16;
	int** m_board = new int* [m_size];
	int m_x, m_y , m_value;
	std::vector<int> m_vec;
	bool chek_points;
	char m_survey;
};
