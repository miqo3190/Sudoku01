#include "Game01.h"

int main()
{
	Game sudoku;
	sudoku.bulid_board();
	sudoku.input_elem();
	sudoku.finish_game(1);
}