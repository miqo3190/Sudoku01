#include "Game01.h"
#include <iostream>

Game::Game()
{
	for (int i = 0; i < m_size; i++)
	{
		m_board[i] = new int[m_size];
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			m_board[i][j] = 88;
		}
	}
}

Game::~Game()
{
	for (int i = 0; i < m_size; i++)
	{
		delete[] m_board[i];
	}
	delete[] m_board;
	m_board = nullptr;
}

void Game::bulid_board()
{
	for (int i = 0; i < m_size; i++)
	{
		if (!i)
		{
			std::cout << "N" << " |";
			for (int j = 0; j < 16; j++)
			{
				if (j < 10)
					std::cout << j << " |";
				else
					std::cout << j << "|";
			}
			std::cout << std::endl;
		}
		if (i < 10)
			std::cout << i << " |";
		else
			std::cout << i << "|";
		for (int j = 0; j < m_size; j++)
		{
			if (i == 3 && j == m_size - 1)
			{
				if (m_board[i][m_size - 1] < 17 && m_board[i][m_size - 1] > 10) { std::cout << m_board[3][m_size - 1] << "|"; }
				else if (m_board[i][j] < 10 && m_board[i][j] > -1) std::cout << m_board[i][j] << " |";
				else { std::cout << "  " << "|"; }
				std::cout << std::endl;
				std::cout << "===================================================";
				break;
			}
			if (i == 7 && j == m_size - 1)
			{
				if (m_board[i][m_size - 1] < 17 && m_board[i][m_size - 1] > 10) { std::cout << m_board[3][m_size - 1] << "|"; }
				else if (m_board[i][j] < 10 && m_board[i][j] > -1) std::cout << m_board[i][j] << " |";
				else { std::cout << "  " << "|"; }
				std::cout << std::endl;
				std::cout << "===================================================";
				break;
			}
			if (i == 11 && j == m_size - 1)
			{
				if (m_board[i][m_size - 1] < 17 && m_board[i][m_size - 1] > 10) { std::cout << m_board[3][m_size - 1] << "|"; }
				else if (m_board[i][j] < 10 && m_board[i][j] > -1) std::cout << m_board[i][j] << " |";
				else { std::cout << "  " << "|"; }
				std::cout << std::endl;
				std::cout << "===================================================";
				break;
			}
			if (m_board[i][j] < 17 && m_board[i][j] > 10) std::cout << m_board[i][j] << "|";
			else if (m_board[i][j] < 10 && m_board[i][j] > 0) std::cout << m_board[i][j] << " |";
			else std::cout << "  " << "|";
		}
		std::cout << std::endl;
	}
}

void Game::input_elem()
{
	while (true)
	{
		do
		{
			std::cout << "Please enter X coordinates : ";
			std::cin >> m_x;
			std::cout << std::endl;
			if (m_x == 77)
			{
				chek_points = chek_board();
				finish_game(chek_points);
			}
		} while (m_x > 15 || m_x < 0 || m_x == 77);
		do
		{
			std::cout << "Please enter Y coordinates : ";
			std::cin >> m_y;
			std::cout << std::endl;
		} while (m_y > 15 || m_y < 0);
		do
		{
			std::cout << "Please enter Value : ";
			std::cin >> m_value;
			std::cout << std::endl;
		} while (m_value > 17 || m_value < 1);
		m_board[m_x][m_y] = m_value;
		system("cls");
		bulid_board();
	}
}

bool Game::chek_board()
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			for (int k = 0; k < m_size; k++)
			{
				if (m_board[i][j] !=88 && m_board[i][j] < 17 && m_board[i][j] > 0 && m_board[i][j] == m_board[i][k] && k != j)
				{
					return false;
				}
			}
		}
	}
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			for (int k = 0; k < m_size; k++)
			{
				if (m_board[j][i] != 88 && m_board[j][i] < 17 && m_board[j][i] > 0 && m_board[j][i] == m_board[k][i] && k != j)
				{
					return false;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ( m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//0-4 .1
	for (int i = 0; i < 4; i++)
	{
		for (int j = 4; j < 7; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//0-4 .2
	for (int i = 0; i < 4; i++)
	{
		for (int j = 7; j < 11; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//0-4 .3
	for (int i = 0; i < 4; i++)
	{
		for (int j = 11; j < 16; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//0-4 .4
	for (int i = 4; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//4-7 .1
	for (int i = 4; i < 7; i++)
	{
		for (int j = 4; j < 7; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//4-7 .2
	for (int i = 4; i < 7; i++)
	{
		for (int j = 7; j < 11; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//4-7 .3
	for (int i = 4; i < 7; i++)
	{
		for (int j = 11; j < 16; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//4-7 .4
	for (int i = 7; i < 11; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//7-11 .1
	for (int i = 7; i < 11; i++)
	{
		for (int j = 4; j < 7; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//7-11 .2
	for (int i = 7; i < 11; i++)
	{
		for (int j = 7; j < 11; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//7-11 .3
	for (int i = 7; i < 11; i++)
	{
		for (int j = 11; j < 16; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//7-11 .4
	for (int i = 11; i < 16; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//11 - 16 .1
	for (int i = 11; i < 16; i++)
	{
		for (int j = 4; j < 7; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//11 -16 .2
	for (int i = 11; i < 16; i++)
	{
		for (int j = 7; j < 11; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//11 - 16 .3
	for (int i = 11; i < 16; i++)
	{
		for (int j = 11; j < 16; j++)
		{
			if (m_board[i][j] < 17 && m_board[i][j] > 0) m_vec.push_back(m_board[i][j]);
		}
	}
	for (int i = 0; i < m_vec.size(); i++)
	{
		for (int j = 0; j < m_vec.size(); j++)
		{
			if (m_vec.size() > 1 && m_vec[i] == m_vec[j] && i != j)
			{
				return false;
			}
		}
	}
	m_vec.clear();
	//11 - 16 .4

	return true;
}
void Game::finish_game(bool chek)
{
	if (chek == true)
	{
		if (true)
		{
			for (int i = 0; i < m_size; i++)
			{
				for (int j = 0; j < m_size; j++)
				{
					if (m_board[i][j] == 88)
					{
						std::cout << "Its OK\n " << "Continue ? y/n : ";
						std::cin >> m_survey;
						if (m_survey == 'y') input_elem();
						else std::abort();
					}
				}
			}
		}
		std::cout << "\n\n\n\n\n\n\n                                                             YOU WIN\n\n\n\n\n\n\n ";
	}
	else
	{
		std::cout << "You have an error\n" << "Continue ? y/n : ";
		std::cin >> m_survey;
		if (m_survey == 'y') input_elem();
		else std::abort();
	}
}