#include <iostream>
#pragma once

struct Sudoku
{
	char** task;
	char** result;
	int n_result;
	int index;
};

enum Buttons {
	Button0 = 48,
	Button1,
	Button2,
	Button3,
	Button4,
	Button5,
	Button6,
	Button7,
	Button8,
	Button9,
	ESC = 27,
	Enter = 13,
	Down = 80,
	Up = 72,
	Right = 77,
	Left = 75,
	Space = 32,
};

char** create_squard(const int n);
void ft_free(char** m);
char** empty_squard(char** m, const int n);
char** new_copy(char** m, const int n);
char** copy_squard(char** m, char** m1, const int n);

bool check_num(char ch);
bool check_str(char* str, const int n);
bool check_num(char ch);
bool check_horizont(char** ch, int i, int j, char z);
bool check_vertical(char** ch, int i, int j, char z);
bool check_squard(char** ch, int i, int j, char z);
bool check_sq(char** ch, int i, int j, char z);

char** str_to_squard(char** m, const int n, char* str);
int n_space(char** m, const int n);
int n_space2(char** m, const int n);
char** brute_force(char** m, const int n);
char **sudoku_result(Sudoku &list);

void draw_item(char item, int color, int bg);
void SetColor(int text, int background);
void print_squard(char** m);
void print_sudoku(Sudoku item, const int n, int point);
void double_print_sudoku(Sudoku item, const int n);

int change_menu(Sudoku list, int index, int& point);
void print_menu(char str[][20], const int n, int i);
Sudoku* menu(Sudoku* list, int& index);

Sudoku* load(Sudoku* list, int& index);
void free_list(Sudoku* list, int index);
char** correct_sudoku(Sudoku item, const int nn, int point, bool game);
Sudoku* new_item(Sudoku* list, int& index);
Sudoku* del_item(Sudoku* list, int& index, int k);
void save(Sudoku* list, int index);