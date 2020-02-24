#pragma once
#include <iostream>

char** create_squard(const int n);
void print_squard(char** m);
void print_sudoku(char** m, const int n, int point);
char** new_copy(char** m, const int n);
char** str_to_squard(char** m, const int n, char* str);
char** copy_squard(char** m, char** m1, const int n);

bool check_num(char ch);
bool check_horizont(char** ch, int i, int j, char z);
bool check_vertical(char** ch, int i, int j, char z);
bool check_squard(char** ch, int i, int j, char z);
bool check_sq(char** ch, int i, int j, char z);

char** brute_force(char** m, const int n);
int n_space(char** m, const int n);
int n_space2(char** m, const int n);

void sudoku(char* str);

void draw_item(char item, int color, int bg);
void SetColor(int text, int background);

char **scan_point(char** m, const int nn, int point);