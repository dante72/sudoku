#pragma once
#include <iostream>

struct Sudoku
{
	char** task;
	char** result;
	int n_result;
};

char** create_squard(const int n);
void print_squard(char** m);
void print_sudoku(Sudoku item, const int n, int point);
char** new_copy(char** m, const int n);
char** str_to_squard(char** m, const int n, char* str);
char** copy_squard(char** m, char** m1, const int n);
void double_print_sudoku(Sudoku item, const int n);
bool check_num(char ch);
bool check_str(char* str, const int n);

bool check_num(char ch);
bool check_horizont(char** ch, int i, int j, char z);
bool check_vertical(char** ch, int i, int j, char z);
bool check_squard(char** ch, int i, int j, char z);
bool check_sq(char** ch, int i, int j, char z);

char** brute_force(char** m, const int n);
int n_space(char** m, const int n);
int n_space2(char** m, const int n);

char **sudoku_result(Sudoku &list);

void draw_item(char item, int color, int bg);
void SetColor(int text, int background);

char** correct_sudoku(Sudoku item, const int nn, int point, bool game);

int change_menu(Sudoku list, int index, int& point);
void print_menu(char str[][20], const int n, int i);