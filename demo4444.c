#define _CRT_SECURE_NO_WARNINGS
#include "wincon.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
int len_ryd=5;
int ddde = 1;
char field[10][10] = {0};
int y_max = 10;
int x_max = 10;
int global_glubina = 3;
int currentx=0;
int currenty=0;
//как идея возвразать код как обозначение победы функции


	int xtemp=-1;
	int ytemp = -1;
struct a
{
	int x;
	int y;
	int res;

};

int anti(int a)
{
	if (a == 1) return 2;
	if (a == 2) return 1;

}
void main_menu();
int check_win(int players_sym, int x, int y);
void player();
void bot();
void play();
void demo_animation();
void demo_colors();
void demo_input();
void about();
void otrisovka();
int func(int symbol, int glubina, int x, int y, int con_sym);
int check_win(int players_sym, int x, int y)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = x + 1; i < x + len_ryd && i <= x_max - 1; i++)
	{
		if (field[y][i] == players_sym)
		{
			sum1++;
		}
		else
		{
			break;
		}

		if (i == x_max - 1) break;
	} 

	for (int i = x -1; i > x- len_ryd && i >= 0; i--)
	{
		if (field[y][i] == players_sym)
		{
			sum2++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}





int sum3 = 0;
int sum4 = 0;
for (int i = y + 1; i < y + len_ryd && i <= y_max - 1; i++)
{
	if (field[i][x] == players_sym)
	{
		sum3++;
	}
	else
	{
		break;
	}

	if (i == y_max - 1) break;
}

for (int i = y - 1; i > y - len_ryd && i >= 0; i--)
{
	if (field[i][x] == players_sym)
	{
		sum4++;
	}
	else
	{
		break;
	}

	if (i == 0) break;
}

int sum5 = 0;
int sum6 = 0;
//диагораль
int j = 0;
for (int i = y + 1,j = x + 1; (i < y + len_ryd)&&(j<x+len_ryd) && (i <= y_max - 1) && (j <= x_max - 1); i++,j++)
{
	if (field[i][j] == players_sym)
	{
		sum5++;
	}
	else
	{
		break;
	}

	if (i == y_max - 1) break;
	if (j == x_max - 1) break;

}

j = 0;
for (int i = y - 1, j = x - 1; (i > y - len_ryd) && (j > x - len_ryd) && (i >= 0) && (j >= 0); i--,j--)
{
	if (field[i][j] == players_sym)
	{
		sum6++;
	}
	else
	{
		break;
	}

	if (i ==0) break;
	if (j == 0) break;

}



//ddd

int sum7 = 0;
int sum8 = 0;
//диагораль
 j = 0;
for (int i = y - 1, j = x + 1; (i > y - len_ryd) && (j < x + len_ryd) && (i >= 0) && (j <= x_max - 1); i--, j++)
{
	if (field[i][j] == players_sym)
	{
		sum7++;
	}
	else
	{
		break;
	}

	if (i == 0) break;
	if (j == x_max - 1) break;

}

j = 0;
for (int i = y + 1, j = x - 1; (i < y + len_ryd) && (j > x - len_ryd) && (i <= y_max - 1) && (j >= 0) ; i++, j--)
{
	if (field[i][j] == players_sym)
	{
		sum8++;
	}
	else
	{
		break;
	}

	if (i == y_max-1) break;
	if (j == 0) break;

}










	gotoxy(13, 13);
	printf("%d", sum1+sum2+1);
	gotoxy(15, 15);
	printf("%d", sum3 + sum4 + 1);
	gotoxy(17, 17);
	printf("%d", sum5+ sum6 + 1);
	gotoxy(19, 19);
	printf("%d", sum7 + sum8 + 1);

}


int cennost(int players_sym,int x, int y)
{


	int sum1 = 0;
	int sum2 = 0;
	for (int i = x + 1; i < x + len_ryd&&i<=x_max-1; i++)
	{
		if (field[y][i] == players_sym)
		{
			sum1++;
		}
		else
		{
			break;
		}

		if (i == x_max - 1) break;
	}

	for (int i = x - 1; i > x - len_ryd && i>=0; i--)
	{
		if (field[y][i] == players_sym)
		{
			sum2++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}




	int psum1 = 0;
	int psum2 = 0;
	for (int i = x + 1; (i < x + len_ryd)&&(i <= x_max - 1); i++)
	{
		if ((field[y][i] == players_sym)|| (field[y][i] == 0))
		{
			psum1++;
		}
		else
		{
			break;
		}

		if (i == x_max - 1) break;
	}

	for (int i = x - 1; (i > x - len_ryd)&&(i>=0); i--)
	{
		if ((field[y][i] == players_sym)|| (field[y][i] == 0))
		{
			psum2++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}



	//ширина













	int sum3 = 0;
	int sum4 = 0;
	for (int i = y + 1; i < y + len_ryd && i<=y_max-1; i++)
	{
		if (field[i][x] == players_sym)
		{
			sum3++;
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
	}

	for (int i = y - 1; i > y - len_ryd && i>=0; i--)
	{
		if (field[i][x] == players_sym)
		{
			sum4++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}


	int psum3 = 0;
	int psum4 = 0;
	for (int i = y + 1; (i < y + len_ryd)&&(i<= y_max - 1); i++)
	{
		if ((field[i][x] == players_sym)|| (field[i][x] == 0))
		{
			psum3++;
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
	}

	for (int i = y - 1; i > y - len_ryd && i>=0; i--)
	{
		if ((field[i][x] == players_sym)|| (field[i][x] == 0))
		{
			psum4++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}

	//высота







	int sum5 = 0;
	int sum6 = 0;
	//диагораль
	int j = 0;
	for (int i = y + 1, j = x + 1; (i < y + len_ryd) && (j < x + len_ryd)&&(i<=y_max-1)&&(j<=x_max-1); i++, j++)
	{
		if (field[i][j] == players_sym)
		{
			sum5++;
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
		if (j == x_max - 1) break;

	}

	j = 0;
	for (int i = y - 1, j = x - 1; (i > y - len_ryd) && (j > x - len_ryd) && (i >=0) && (j >=0); i--, j--)
	{
		if (field[i][j] == players_sym)
		{
			sum6++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
		if (j == 0) break;

	}




	int psum5 = 0;
	int psum6 = 0;
	//диагораль
	 j = 0;
	for (int i = y + 1, j = x + 1; (i < y + len_ryd) && (j < x + len_ryd) && (i <= y_max - 1) && (j <= x_max-1); i++, j++)
	{
		if ((field[i][j] == players_sym)|| (field[i][j] == 0))
		{
			psum5++;
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
		if (j == x_max - 1) break;

	}

	j = 0;
	for (int i = y - 1, j = x - 1; (i > y - len_ryd) && (j > x - len_ryd) && (i >= 0) && (j >= 0); i--, j--)
	{
		if ((field[i][j] == players_sym)|| (field[i][j] == 0))
		{
			psum6++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
		if (j == 0) break;

	}


	//диагональ 1










	//ddd

	int sum7 = 0;
	int sum8 = 0;
	//диагораль
	j = 0;
	for (int i = y - 1, j = x + 1; (i > y - len_ryd) && (j < x + len_ryd) && (i >= 0) && (j <=x_max-1); i--, j++)
	{
		if (field[i][j] == players_sym)
		{
			sum7++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
		if (j == x_max - 1) break;

	}

	j = 0;
	for (int i = y + 1, j = x - 1; (i < y + len_ryd) && (j > x - len_ryd)&&(i<=y_max-1)&&(j>=0); i++, j--)
	{
		if (field[i][j] == players_sym)
		{
			sum8++;
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
		if (j == 0) break;

	}


	int psum7 = 0;
	int psum8 = 0;
	//диагораль
	j = 0;
	for (int i = y - 1, j = x + 1; (i > y - len_ryd) && (j < x + len_ryd) && (i >= 0) && (j <= x_max - 1); i--, j++)
	{
		if ((field[i][j] == players_sym)|| (field[i][j] == 0))
		{
			psum7++;
		}
		else
		{
			break;
		}

		if (i == 0) break;
		if (j == x_max - 1) break;

	}

	j = 0;
	for (int i = y + 1, j = x - 1; (i < y + len_ryd) && (j > x - len_ryd) && (i <= y_max - 1) && (j >= 0); i++, j--)
	{
		if ((field[i][j] == players_sym)|| (field[i][j] == 0))
		{
			psum8++;
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
		if (j == 0) break;

	}

	//диагональ 2

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;

	 
	if ((psum1 + psum2+1) >= len_ryd)
	{
		p1 = sum1 + sum2+1;
		p1 = (int)pow(5, p1);

	}
	if ((psum3 + psum4+1) >= len_ryd)
	{

		p2 = sum3 + sum4+1;
		p2 = (int)pow(5, p2);

	}
	if ((psum5 + psum6+1) >= len_ryd)
	{

		p3 = sum5 + sum6+1;
		p3 = (int)pow(5, p3);
	}
	if ((psum7 + psum8+1) >= len_ryd)
	{

		p4 = sum7+sum8+1;
		p4 = (int)pow(5, p4);
	}
	/*gotoxy(13, 13);
	printf("%d.", p1);
	gotoxy(15, 15);
	printf("%d.", p2);
	gotoxy(17, 17);
	printf("%d.", p3);
	gotoxy(19, 19);
	printf("%d.", p4);
	*/
	//gotoxy(13, 13);
	//printf("+ %d_ ", p1 + p2 + p3 + p4);
	return p1 + p2 + p3 + p4;
}



int vygoda(int players_sym, int x, int y)
{



//	gotoxy(13, 13);
    return cennost(players_sym,x,y)+cennost(anti(players_sym),x,y);
}
int main()
{
	field[1][0] =1;

	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			field[i][j] = 0;
		}
	}

	/*field[2][1] = 2;
	field[2][2] = 2;


	field[2][5] = 2;
	field[2][6] = 2;
	field[3][7] = 2;
	*/

	// Инициализируется консоль, скрывается курсор
	con_init(80, 25);
	show_cursor(0);

	// Запуск главного меню
	main_menu();

	return 0;
}



  



void onesimvol (char d,int x,int y)
{
	if (d == 0)
	{
		con_set_color(CON_CLR_BLACK, CON_CLR_GREEN);
		gotoxy(x, y);
		printf(" ");

	}
	if (d == 1)
	{
		con_set_color(CON_CLR_BLACK, CON_CLR_GREEN);
		gotoxy(x, y);
		printf("o");
	}
	if (d == 2)
	{
		con_set_color(CON_CLR_BLACK, CON_CLR_GREEN);
		gotoxy(x, y);
		printf("x");
	}
	if (d == 3)
	{
		
		con_set_color(CON_CLR_BLACK, CON_CLR_YELLOW);
		gotoxy(x, y);
		printf(" ");
	}
	if (d == 4)
	{
		con_set_color(CON_CLR_BLACK, CON_CLR_YELLOW);
		gotoxy(x, y);
		printf("o");

	}
	if (d == 5)
	{
		con_set_color(CON_CLR_BLACK, CON_CLR_YELLOW);
		gotoxy(x, y);
		printf("x");

	}
	if (d == 6)
	{


	}

}
void otrisovka()
{
	
	clrscr();
	
	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			onesimvol(field[i][j],j ,i );
		}
	}
	

}
void player()
{
	
	int players_sym = 2;

	
	//отрисовывать только вначале

	int x = currentx;// для установки курсора
	int y = currenty;
	int oldx = 0;
	int oldy = 0;
	//получение извне кода нолика или крестика

	while (1)
	{

		
		gotoxy(x,y);

		onesimvol(field[y][x]+3, x, y);
		if (key_is_pressed())
		{
			int c = key_pressed_code();
			if (c == 'q' || c == 'Q' || c == KEY_ESC)
				return;
			if (c == KEY_UP && (y>0))
			{
				y--;
				
			}

			if (c == KEY_DOWN && (y<y_max-1) )
			{
				y++;
				
			}
			if (c == KEY_RIGHT && (x < x_max - 1) )
			{
				x++;

			}
			if (c == KEY_LEFT && (x > 0))
			{
				x--;

			}

			if (c == KEY_ENTER)
			{
				//vygoda(players_sym, x, y);
				xtemp = 1;
				ytemp = 1;

				gotoxy(13, 13);
				printf("________________");
				printf("%d",func((players_sym), 0, 0, 0, players_sym));
				gotoxy(15, 15);
				printf("%d", xtemp);
				gotoxy(17, 17);
				printf("%d", ytemp);
			}
			if (c==32)
			{
				if (field[y][x]==0)
				{
					field[y][x] = players_sym;
					//переместить чеквин сюды
					onesimvol(field[y][x] + 3, x, y);
					currentx = x;
					currenty = y;


					
				
						onesimvol(field[y][x], x, y);

					
					
					


					return;
					//перелача власти компу

				}
				//check_win(players_sym, x, y);
				// cennost(players_sym, x, y);

			}


			
			//условие выхода пробел

		}
		
		if ((x!=oldx) || (y!=oldy))
		{


			gotoxy(oldx, oldy);
			onesimvol(field[oldy][oldx], oldx, oldy);
			
		}
		oldx = x;
		oldy = y;
		//while (!key_is_pressed)
		//{

		//}
	}


}

void bot()
{



	//перенос  в общую функцию
	//con_set_color(CON_CLR_BLACK, CON_CLR_BLUE);!
	//clrscr();!
	int players_sym = 1;

	//if (ddde) otrisovka();!
	//ddde = 0; !
	//отрисовывать только вначале
	int oldx = 0;
	int oldy = 0;
	int x = -1; // для установки курсора
	int y = -1;
	int max = -1;
	int temp = 0;
	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			
			
			if (field[i][j] == 0 )
			{
				temp = vygoda(players_sym, j, i);
				if (temp > max)
				{
					max = temp;
					y = i;
					x = j;

				}
				temp = 0;

			}
		}
	}


	//првоерка -1 о том что не найден символ


	
//	int oldx = 0;
	//int oldy = 0;
	//получение извне кода нолика или крестика

	


		gotoxy(x, y);
		onesimvol(field[y][x] + 3, x, y);
		
				if (field[y][x] == 0)
				{
					field[y][x] = players_sym;
					onesimvol(field[y][x] + 3, x, y);
					//перелача власти компу

				}

				onesimvol(field[y][x], x, y);
				
				gotoxy(currentx, currenty);

			}

		
		//while (!key_is_pressed)
		//{

		//}
	
//вызвать с анти символом 0 глубина и коорды
int func(int symbol, int glubina,int x,int y,int con_sym)
{
	if ((glubina == global_glubina)||(1))
	{
		return vygoda(symbol, x, y);
		

	}
	int temp = 0;

	//int xtemp=-1;
	//int ytemp = -1;
	int max = -1;
	int min = 2147483647;


	if (glubina == 0)
	{
		for (int i = 0; i < y_max; i++)
		{
			for (int j = 0; j < x_max; j++)
			{
				if (field[i][j] == 0)
				{
					field[i][j] = symbol;
					temp = func(anti(symbol), glubina + 1, i, j, con_sym);
					if (temp > max)
					{
						max = temp;
						

					}
					field[i][j] = 0;
				}

			}
		}

		return;
	}
	else

	if (symbol==con_sym)
	{
		for (int i = 0; i < y_max; i++)
		{
			for (int j = 0; j < x_max; j++)
			{
				if (field[i][j] == 0)
				{
					field[i][j] = symbol;
					temp = func(anti(symbol), glubina + 1, i, j,con_sym);
					if (temp > max)
					{
						max = temp;
					
						
					}
					field[i][j] = 0;
				}

			}
		}

		return max;

	}
	else


	if (symbol!=con_sym)
	{
		for (int i = 0; i < y_max; i++)
		{
			for (int j = 0; j < x_max; j++)
			{
				if (field[i][j] == 0)
				{
					field[i][j] = symbol;
					temp = func(anti(symbol), glubina + 1, i, j, con_sym);

					if (temp < min)
					{
						min = temp;
					}
					field[i][j] = 0;
				}

			}
		}

		return min;

	}
	


}


// Поддержка главного меню
void main_menu()
{
	const char* menu_items[] = { "Демо: анимация", "Демо: ввод", "Демо: бот","Тест отрисовка", "О программе", "Выход" };
	int menu_active_idx = 0;
	int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

	short clr_bg = CON_CLR_BLUE;
	short clr_bg_active = CON_CLR_GRAY;
	short clr_font = CON_CLR_WHITE_LIGHT;

	while (1)
	{
		int left = 30;
		int top = 2;
		int b;

		// Заблокировать отрисовку
		con_draw_lock();

		// Очистка экрана
		con_set_color(clr_font, clr_bg);
		clrscr();

		// Цикл отрисовывает кнопки
		for (b = 0; b < menu_items_count; b++)
		{
			short btn_bg = clr_bg; // По умолчанию фон кнопки - как фон экрана
			if (b == menu_active_idx)
				btn_bg = clr_bg_active; // Если кнопка активна - то рисуется другим цветом

			gotoxy(left, top);
			con_set_color(clr_font, btn_bg);

			printf("********************");
			top++;
			gotoxy(left, top);
			printf("*                   ");
			
			gotoxy(left + 10 - strlen(menu_items[b]) / 2, top);
			printf("%s", menu_items[b]);

			con_set_color(clr_font, btn_bg);
			gotoxy(left + 19, top);
			printf("*");
			top++;
			gotoxy(left, top);
			printf("********************");
			top += 2;
		}
		
		// Данные подготовлены, вывести на экран
		con_draw_release();
		

		while (!key_is_pressed()) // Если пользователь нажимает кнопку
		{
			int code = key_pressed_code();
			if (code == KEY_UP) // Если это стрелка вверх
			{
				// То переход к верхнему пункту (если это возможно)
				if (menu_active_idx > 0) 
				{
					menu_active_idx--;
					break;
				}
			}
			else if (code == KEY_DOWN) // Если стрелка вниз
			{
				// То переход к нижнему пункту (если это возможно)
				if (menu_active_idx + 1 < menu_items_count)
				{
					menu_active_idx++;
					break;
				}
			}
			else if (code == KEY_ESC || code == 'q' || code == 'Q' || 
				     code == (unsigned char)'й' || code == (unsigned char)'Й') // ESC или 'q' - выход
			{
				return;
			}
			else if (code == KEY_ENTER) // Нажата кнопка Enter
			{
				if (menu_active_idx == menu_items_count - 1) // Выбран последний пункт - это выход
					return;

				if (menu_active_idx == 0)
					demo_animation();

				if (menu_active_idx == 1)
					demo_input();

				if (menu_active_idx == 2)
					bot();
				if (menu_active_idx == 3)
				{
					ddde = 1;
					play();

				}
					//otrisovka();


				if (menu_active_idx == menu_items_count - 2)
					about();

				break;
			}
		
		
			pause(40); // Небольная пауза (чтобы не загружать процессор)
		} // while (!key_is_pressed())


		// "Съедается" оставшийся ввод
		while (key_is_pressed())
			key_pressed_code();

	} // while(1)

}



void play()
{
	
	con_set_color(CON_CLR_BLACK, CON_CLR_BLUE);
	clrscr();
	if (ddde) otrisovka();
	ddde = 0;
	
	while (1)
	{
		player();

		bot();
	}




}















void about()
{
	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_BLACK);
	clrscr();

	gotoxy(8, 2);
	printf("О программе:");

	con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
	gotoxy(8, 3);
	printf("Данная программа является примером использования библиотеки wincon.\n\n");

	gotoxy(8, 4);
	printf("Для продолжения нажмите любую клавишу.");
	
	key_pressed_code();
	return;
}

void demo_colors()
{
	int x = 0, y = 0;
	gotoxy(0, 0);
	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_BLACK);
	clrscr();

	gotoxy(x, y++);
	con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
	printf("Черный / серый");

	gotoxy(x, y++);
	con_set_color(CON_CLR_BLUE_LIGHT, CON_CLR_BLUE);
	printf("Синий");

	gotoxy(x, y++);
	con_set_color(CON_CLR_RED_LIGHT, CON_CLR_RED);
	printf("Красный");

	gotoxy(x, y++);
	con_set_color(CON_CLR_GREEN_LIGHT, CON_CLR_GREEN);
	printf("Зеленый");

	gotoxy(x, y++);
	con_set_color(CON_CLR_YELLOW_LIGHT, CON_CLR_YELLOW);
	printf("Желтый");

	gotoxy(x, y++);
	con_set_color(CON_CLR_MAGENTA_LIGHT, CON_CLR_MAGENTA);
	printf("Пурпурный");

	gotoxy(x, y++);
	con_set_color(CON_CLR_CYAN_LIGHT, CON_CLR_CYAN);
	printf("Голубой");

	gotoxy(x, y++);
	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_WHITE);
	printf("Белый");


	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_BLACK);
	gotoxy(30, 20);
	printf("Пример демонстрирует все поддерживаемые цвета.");

	gotoxy(30, 21);
	printf("Для продолжения нажмите любую клавишу.");

	key_pressed_code();
	return;
}




void demo_animation()
{
	int x = 0, y = 1;
	int m = 1;
	int speed = 40;

	con_set_color(CON_CLR_BLACK, CON_CLR_GREEN);
	clrscr();

	gotoxy(40, 20);
	printf("Нажмите q для выхода.");
	gotoxy(40, 21);
	printf("Перемещение: стрелки вверх/вниз.");
	gotoxy(40, 22);
	printf("Скорость: кнопки +/-");

	while (1)
	{
		int i = 0;
		int new_y = y;

		gotoxy(x, y);
		printf("*");

		// Звездочка перемещается раз в 200 мс, но кнопку могут нажать в это время. 
		// Поэтому каждые 40 мс проверяется нажатие 
		for (i = 0; i < 5; i ++)
		{
			if (key_is_pressed())
			{
				int c = key_pressed_code();
				if (c == 'q' || c == 'Q' || c == KEY_ESC)
					return;
				if (c == KEY_UP && new_y > 1)
				{
					new_y--;
					break;
				}

				if (c == KEY_DOWN && new_y < 19)
				{
					new_y++;
					break;
				}

				if (c == '+' && speed > 0)
					speed--;
				if (c == '-')
					speed++;
			}

			pause(speed);
		}

		
		// Распечатывается пробел на старой позиции (чтобы не перерисовывать весь экран)
		gotoxy(x, y);
		printf(" "); 

		x += m;
		if (x >= 80 || x < 0)
		{
			m *= -1;
			x += m;
		}

		y = new_y;
	}
}

void demo_input()
{
	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_GRAY);
	clrscr();

	while (1)
	{
		char buf[1024] = { 0 };
		int digit = -1;

		gotoxy(0, 1);
		printf("Введите число ('q' - выход):");
		
		gotoxy(0, 2);
		show_cursor(1);
		scanf_s("%s", buf, _countof(buf));
		show_cursor(0);

		// Весь остальной пользовательский ввод съедается
		while (key_is_pressed())
			key_pressed_code();

		if (!strcmp(buf, "q"))
			return;

		digit = atoi(buf);

		clrscr();
		gotoxy(0, 0);
		printf("Вы ввели: как число: %d (0x%x), как строка: '%s'\n", digit, digit, buf);
	}
}


