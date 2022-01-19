#define _CRT_SECURE_NO_WARNINGS
#include "wincon.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>


int len_ryd=5;
int ddde = 1;
char field[20][20] = {0};
int y_max = 6;
int x_max = 6;
int global_glubina = 3;
int currentx=0;
int currenty=0;
int polzovatelsym = 2;
int globalscet = 0;
int difficulty = 0;
int smechx = 33;
int smechy = 4;

int xtemp=-1;
int ytemp = -1;

struct a
{
	int len_ryd ;
	char field[20][20] ;
	int y_max;
	int x_max;
	
	
	int polzovatelsym;
	int globalscet;
	int difficulty;

};
long long int minimax(int x, int y, int depth, int maxiPlayer, int symvol,int alpha,int beta);

int anti(int a)
{
	if (a == 1) return 2;
	if (a == 2) return 1;

}
void main_menu();
int check_win(int players_sym, int x, int y);
void player(int);
void bot1(int);
void bot2(int);
void bot3(int);
void bot(int);
void play();

void about();
void otrisovka();
void dlinalinii();
void setting();
void razmerpole();
void figura();
void slognost();
int check_win(int players_sym, int x, int y)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = x + 1; i < x + len_ryd && i <= x_max - 1; i++)
	{
		if (field[y][i] == players_sym)
		{
			//sum1++;
			_asm //MZ
			{
				mov eax, sum1
				inc eax
				mov sum1, eax
			}
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
			//sum2++;
			_asm //MZ
			{
				mov eax, sum2
				inc eax
				mov sum2, eax
			}
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
		//sum3++;
		_asm //MZ
		{
			mov eax, sum3
			inc eax
			mov sum3, eax
		}
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
		//sum4++;
		_asm 
		{
			mov eax, sum4
			inc eax
			mov sum4, eax
		}
	}
	else
	{
		break;
	}

	if (i == 0) break;
}

int sum5 = 0;
int sum6 = 0;
//���������
int j = 0;
for (int i = y + 1,j = x + 1; (i < y + len_ryd)&&(j<x+len_ryd) && (i <= y_max - 1) && (j <= x_max - 1); i++,j++)
{
	if (field[i][j] == players_sym)
	{
		//sum5++;
		_asm //MZ
		{
			mov eax, sum5
			inc eax
			mov sum5, eax
		}
	}
	else
	{
		break;
	}

	if (i == y_max - 1 || j == x_max - 1) //MNZ
		break;

}

j = 0;
for (int i = y - 1, j = x - 1; (i > y - len_ryd) && (j > x - len_ryd) && (i >= 0) && (j >= 0); i--,j--)
{
	if (field[i][j] == players_sym)
	{
		//sum6++;
		_asm //MZ
		{
			mov eax, sum6
			inc eax
			mov sum6, eax
		}
	}
	else
	{
		break;
	}

	if (i == 0 || j == 0) //MNZ
		break;
}



//ddd

int sum7 = 0;
int sum8 = 0;
//���������
 j = 0;
for (int i = y - 1, j = x + 1; (i > y - len_ryd) && (j < x + len_ryd) && (i >= 0) && (j <= x_max - 1); i--, j++)
{
	if (field[i][j] == players_sym)
	{
		//sum7++;
		_asm //MZ
		{
			mov eax, sum7
			inc eax
			mov sum7, eax
		}
	}
	else
	{
		break;
	}

	if (i == 0 || j == x_max - 1) //MNZ
		break;

}

j = 0;
for (int i = y + 1, j = x - 1; (i < y + len_ryd) && (j > x - len_ryd) && (i <= y_max - 1) && (j >= 0) ; i++, j--)
{
	if (field[i][j] == players_sym)
	{
		//sum8++;
		_asm //MZ
		{
			mov eax, sum8
			inc eax
			mov sum8, eax
		}
	}
	else
	{
		break;
	}

	if (i == y_max-1 || j == 0) //MNZ
		break;

}


	/*gotoxy(13, 13);
	printf("%d", sum1+sum2+1);
	gotoxy(15, 15);
	printf("%d", sum3 + sum4 + 1);
	gotoxy(17, 17);
	printf("%d", sum5+ sum6 + 1);
	gotoxy(19, 19);
	printf("%d", sum7 + sum8 + 1);
	*/

if ((sum1 + sum2 + 1 == len_ryd) || (sum3 + sum4 + 1 == len_ryd) || (sum5 + sum6 + 1 == len_ryd) || (sum7 + sum8 + 1 == len_ryd))
{
	return 1;
} //MNZ

return 0;



}
void play_load();
void helper();
int cennost(int players_sym,int x, int y)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = x + 1; i < x + len_ryd&&i<=x_max-1; i++)
	{
		if (field[y][i] == players_sym)
		{
			//sum1++;
			_asm //MZ
			{
				mov eax, sum1
				inc eax
				mov sum1, eax
			}
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
			//sum2++;
			_asm //MZ
			{
				mov eax, sum2
				inc eax
				mov sum2, eax
			}
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
			//psum1++;
			_asm //MZ
			{
				mov eax, psum1
				inc eax
				mov psum1, eax
			}
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
			//psum2++;
			_asm //MZ
			{
				mov eax, psum1
				inc eax
				mov psum1, eax
			}
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}

	//������

	int sum3 = 0;
	int sum4 = 0;
	for (int i = y + 1; i < y + len_ryd && i<=y_max-1; i++)
	{
		if (field[i][x] == players_sym)
		{
			//sum3++;
			_asm //MZ
			{
				mov eax, sum3
				inc eax
				mov sum3, eax
			}
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
			//sum4++;
			_asm //MZ
			{
				mov eax, sum4
				inc eax
				mov sum4, eax
			}
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
		if ((field[i][x] == players_sym) || (field[i][x] == 0))
		{
			//psum3++;
			_asm //MZ
			{
				mov eax, psum3
				inc eax
				mov psum3, eax
			}
		}
		else
		{
			break;
		}

		if (i == y_max - 1) break;
	}

	for (int i = y - 1; i > y - len_ryd && i>=0; i--)
	{
		if ((field[i][x] == players_sym) || (field[i][x] == 0))
		{
			//psum4++;
			_asm //MZ
			{
				mov eax, psum4
				inc eax
				mov psum4, eax
			}
		}
		else
		{
			break;
		}

		if (i == 0) break;
	}

	//������

	int sum5 = 0;
	int sum6 = 0;
	//���������
	int j = 0;
	for (int i = y + 1, j = x + 1; (i < y + len_ryd) && (j < x + len_ryd)&&(i<=y_max-1)&&(j<=x_max-1); i++, j++)
	{
		if (field[i][j] == players_sym)
		{
			//sum5++;
			_asm //MZ
			{
				mov eax, sum5
				inc eax
				mov sum5, eax
			}
		}
		else
		{
			break;
		}

		if ((i == y_max - 1) || (j == x_max - 1)) 
			break;

	}

	j = 0;
	for (int i = y - 1, j = x - 1; (i > y - len_ryd) && (j > x - len_ryd) && (i >=0) && (j >=0); i--, j--)
	{
		if (field[i][j] == players_sym)
		{
			//sum6++;
			_asm //MZ
			{
				mov eax, sum6
				inc eax
				mov sum6, eax
			}
		}
		else
		{
			break;
		}

		if (i == 0 || j == 0) 
			break;

	}




	int psum5 = 0;
	int psum6 = 0;
	//���������
	 j = 0;
	for (int i = y + 1, j = x + 1; (i < y + len_ryd) && (j < x + len_ryd) && (i <= y_max - 1) && (j <= x_max-1); i++, j++)
	{
		if ((field[i][j] == players_sym) || (field[i][j] == 0))
		{
			//psum5++;
			_asm //MZ
			{
				mov eax, psum5
				inc eax
				mov psum5, eax
			}
		}
		else
		{
			break;
		}

		if ((i == y_max - 1) || (j == x_max - 1)) 
			break;

	}

	j = 0;
	for (int i = y - 1, j = x - 1; (i > y - len_ryd) && (j > x - len_ryd) && (i >= 0) && (j >= 0); i--, j--)
	{
		if ((field[i][j] == players_sym) || (field[i][j] == 0))
		{
			//psum6++;
			_asm //MZ
			{
				mov eax, psum6
				inc eax
				mov psum6, eax
			}
		}
		else
		{
			break;
		}

		if (i == 0 || j == 0) 
			break;

	}


	//��������� 1










	//ddd

	int sum7 = 0;
	int sum8 = 0;
	//���������
	j = 0;
	for (int i = y - 1, j = x + 1; (i > y - len_ryd) && (j < x + len_ryd) && (i >= 0) && (j <=x_max-1); i--, j++)
	{
		if (field[i][j] == players_sym)
		{
			//sum7++;
			_asm //MZ
			{
				mov eax, sum7
				inc eax
				mov sum7, eax
			}
		}
		else
		{
			break;
		}

		if (i == 0 || (j == x_max - 1)) 
			break;

	}

	j = 0;
	for (int i = y + 1, j = x - 1; (i < y + len_ryd) && (j > x - len_ryd)&&(i<=y_max-1)&&(j>=0); i++, j--)
	{
		if (field[i][j] == players_sym)
		{
			//sum8++;
			_asm //MZ
			{
				mov eax, sum8
				inc eax
				mov sum8, eax
			}
		}
		else
		{
			break;
		}

		if (i == y_max - 1 || j == 0) 
			break;

	}


	int psum7 = 0;
	int psum8 = 0;
	//���������
	j = 0;
	for (int i = y - 1, j = x + 1; (i > y - len_ryd) && (j < x + len_ryd) && (i >= 0) && (j <= x_max - 1); i--, j++)
	{
		if ((field[i][j] == players_sym)|| (field[i][j] == 0))
		{
			//psum7++;
			_asm //MZ
			{
				mov eax, psum7
				inc eax
				mov psum7, eax
			}
		}
		else
		{
			break;
		}

		if (i == 0 || (j == x_max - 1)) 
			break;

	}

	j = 0;
	for (int i = y + 1, j = x - 1; (i < y + len_ryd) && (j > x - len_ryd) && (i <= y_max - 1) && (j >= 0); i++, j--)
	{
		if ((field[i][j] == players_sym)|| (field[i][j] == 0))
		{
			//psum8++;
			_asm //MZ
			{
				mov eax, psum8
				inc eax
				mov psum8, eax
			}
		}
		else
		{
			break;
		}

		if ((i == y_max - 1) || j == 0) //MNZ
			break;

	}

	//��������� 2

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;

	 
	if ((psum1 + psum2+1) >= len_ryd)
	{
		p1 = sum1 + sum2 + 1; 
		p1 = (int)pow(len_ryd, p1);

	}
	if ((psum3 + psum4+1) >= len_ryd)
	{

		p2 = sum3 + sum4+1;
		p2 = (int)pow(len_ryd, p2);

	}
	if ((psum5 + psum6+1) >= len_ryd)
	{

		p3 = sum5 + sum6+1;
		p3 = (int)pow(len_ryd, p3);
	}
	if ((psum7 + psum8+1) >= len_ryd)
	{

		p4 = sum7+sum8+1;
		p4 = (int)pow(len_ryd, p4);
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


int save(char* filename, struct a* p);
int load(char* filename);


int vygoda(int players_sym, int x, int y)
{
	return cennost(players_sym, x, y) + cennost(anti(players_sym), x, y);
}
int main()
{
	//field[1][0] = 1;

	/*for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			field[i][j] = 0;
		}
	}*/

	memset(field, 0, y_max * x_max); //MNZ


	con_init(80, 25);
	show_cursor(0);

	main_menu();

	return 0;
}



  



void onesimvol (char d,int x,int y)
{
	switch (d) //MNZ
	{
		case 0:
			con_set_color(CON_CLR_BLACK, CON_CLR_GRAY);
			gotoxy(x + smechx, y + smechy);
			printf(" ");
			break;

		case 1:
			con_set_color(CON_CLR_BLACK, CON_CLR_GRAY);
			gotoxy(x + smechx, y + smechy);
			printf("o");
			break;
	
		case 2:
			con_set_color(CON_CLR_BLACK, CON_CLR_GRAY);
			gotoxy(x + smechx, y + smechy);
			printf("x");
			break;
	
		case 3:
			con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
			gotoxy(x + smechx, y + smechy);
			printf(" ");
			break;

		case 4:
			con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
			gotoxy(x + smechx, y + smechy);
			printf("o");
			break;

		case 5:
			con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
			gotoxy(x + smechx, y + smechy);
			printf("x");
			break;
	}

}
void otrisovka()
{
	
	clrscr();
	
	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			onesimvol(field[i][j], j, i);
		}
	}
	

}
void player(int playerr)
{
	

	if (globalscet == x_max * y_max) printf("�����");

	int players_sym = 2;
	players_sym = playerr;
	

	int x = currentx;// ��� ��������� �������
	int y = currenty;
	int oldx = 0;
	int oldy = 0;
	struct a tosave;
	
	while (1)
	{

		gotoxy(x,y);

		onesimvol(field[y][x]+3, x, y);
		if (key_is_pressed())
		{
			int c = key_pressed_code();
			if (c == 'q' || c == 'Q' || c == KEY_ESC)
				main_menu();
			if (c == KEY_UP && (y>0))
			{
				//y--; //asm dec MZ
				_asm //MZ
				{
					mov eax, y
					dec eax
					mov y, eax
				}
				
			}
			if (c == 's' || c == 'S' || c == (unsigned char)'�' || c == (unsigned char)'�')
			{

				/*for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						tosave.field[i][j] = field[i][j];

					}

				}*/

				memcpy(tosave.field, field, 400); //MNZ

				tosave.difficulty = difficulty;

				tosave.globalscet = globalscet;
				tosave.len_ryd = len_ryd;
				tosave.polzovatelsym = polzovatelsym;
				tosave.x_max = x_max;
				tosave.y_max = y_max;
				char* filename = "data.dat";
				save(filename, &tosave);

				main_menu();
			}
			if (c == KEY_DOWN && (y<y_max-1) )
			{
				//y++; //MZ inc/dec
				_asm //MZ
				{
					mov eax, y
					inc eax
					mov y, eax
				}
				
			}
			if (c == KEY_RIGHT && (x < x_max - 1) )
			{
				//x++;
				_asm //MZ
				{
					mov eax, x
					inc eax
					mov x, eax
				}

			}
			if (c == KEY_LEFT && (x > 0))
			{
				//x--;
				_asm //MZ
				{
					mov eax, x
					dec eax
					mov x, eax
				}
			}

			if (c == KEY_ENTER)
			{
				//vygoda(players_sym, x, y);
				xtemp = 1;
				ytemp = 1;

				gotoxy(13, 13);
				printf("________________                      ");
				gotoxy(13, 13);
				printf("%d",minimax(x,y,4,1,2,-1000000,1000000) );
				//gotoxy(15, 15);
				//printf("%d", xtemp);
				//gotoxy(17, 17);
				//printf("%d", ytemp);
			}
			if (c==32)
			{
				if (field[y][x] == 0)
				{
					field[y][x] = players_sym;
					onesimvol(field[y][x] + 3, x, y);
					currentx = x;
					currenty = y;
					globalscet++;
					if (check_win(players_sym, x, y))
					{
						gotoxy(15, 15);
						printf("������");
						pause(2000);

						main_menu();

					}
					
				
						onesimvol(field[y][x], x, y);

					
					
					


					return;

				}
				//check_win(players_sym, x, y);
				// cennost(players_sym, x, y);

			}


			

		}
		
		if ((x != oldx) || (y != oldy))
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
//c ��������� ����
void bot1(int bott)
{

	if (globalscet == x_max * y_max) return;

	//�������  � ����� �������
	//con_set_color(CON_CLR_BLACK, CON_CLR_BLACK);!
	//clrscr();!
	int players_sym = 1;
	players_sym = bott;
	//if (ddde) otrisovka();!
	//ddde = 0; !
	//������������ ������ �������
	int oldx = 0;
	int oldy = 0;
	int x = 0; // ��� ��������� �������
	int y = 0;
	int max = -100000000;
	long long int temp = -1;
	
	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			
			
			if (field[i][j] == 0)
			{

				//temp = minimax(j, i, 2, 1, players_sym);
				temp = vygoda(players_sym, j, i);
				if (temp > max)
				{
					max = temp;
					y = i;
					x = j;

				}

			}
		}
	}
	
	globalscet++;


	/*   

	temp = func(players_sym, 0, 0, 0, players_sym);
	y = ytemp;
	x = xtemp;
	*/




	//�������� -1 � ��� ��� �� ������ ������


	
//	int oldx = 0;
	//int oldy = 0;
	//��������� ����� ���� ������ ��� ��������

	gotoxy(15, 15);
	//printf("%d", minimax(x, y, 4, 1, players_sym));


		gotoxy(x, y);
		
		onesimvol(field[y][x] + 3, x, y);
		
				if (field[y][x] == 0)
				{
					field[y][x] = players_sym;
					onesimvol(field[y][x] + 3, x, y);
					//�������� ������ �����

				}

				onesimvol(field[y][x], x, y);
				
				if (check_win(players_sym, x, y))
				{
					gotoxy(21, 21);
					printf("������� ���");
					pause(2000);

					main_menu();
				}
				gotoxy(currentx, currenty);

			}
//������� 2 ����
void bot(int bott)
{
	///clock_t start, end;
	if (globalscet == x_max * y_max) return;

	//�������  � ����� �������
	//con_set_color(CON_CLR_BLACK, CON_CLR_BLACK);!
	//clrscr();!
	int players_sym = 1;
	players_sym = bott;
	//if (ddde) otrisovka();!
	//ddde = 0; !
	//������������ ������ �������
	int oldx = 0;
	int oldy = 0;
	int x = 0; // ��� ��������� �������
	int y = 0;
	int max = -100000000;
	long long int temp = -1;

	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{


			if (field[i][j] == 0)
			{

				temp = minimax(j, i, 2, 1, players_sym,-100000000,100000000);
				//temp = vygoda(players_sym, j, i);
				if (temp > max)
				{
					max = temp;
					y = i;
					x = j;

				}

			}
		}
	}
	///end time
	gotoxy(20, 20);
	//fprintf();
	globalscet++;


	/*

	temp = func(players_sym, 0, 0, 0, players_sym);
	y = ytemp;
	x = xtemp;
	*/




	//�������� -1 � ��� ��� �� ������ ������



//	int oldx = 0;
	//int oldy = 0;
	//��������� ����� ���� ������ ��� ��������

	//gotoxy(15, 15);
	//printf("%d", minimax(x, y, 4, 1, players_sym));


	gotoxy(x, y);

	onesimvol(field[y][x] + 3, x, y);

	if (field[y][x] == 0)
	{
		field[y][x] = players_sym;
		onesimvol(field[y][x] + 3, x, y);
		//�������� ������ �����

	}

	onesimvol(field[y][x], x, y);

	if (check_win(players_sym, x, y))
	{
		gotoxy(21, 21);
		printf("������� ���");
		pause(2000);

		main_menu();
	}
	gotoxy(currentx, currenty);

}
//�����
void bot2(int bott)
{

	if (globalscet == x_max * y_max) return;

	//�������  � ����� �������
	//con_set_color(CON_CLR_BLACK, CON_CLR_BLACK);!
	//clrscr();!
	int players_sym = 1;
	players_sym = bott;
	//if (ddde) otrisovka();!
	//ddde = 0; !
	//������������ ������ �������
	int oldx = 0;
	int oldy = 0;
	int x = 0; // ��� ��������� �������
	int y = 0;
	int max = -100000000;
	long long int temp = -1;

	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{


			if (field[i][j] == 0)
			{

				//temp = minimax(j, i, 2, 1, players_sym);
				temp = vygoda(players_sym, j, i);
				
				if (temp == max)
				{
					if (minimax(j, i, 4, 1, players_sym,-100000000,100000000) > minimax(x, y, 4, 1, players_sym,-100000000,100000000))
					{
						max = temp;
						y = i;
						x = j;

					}
				}
				
				if (temp > max)
				{
					max = temp;
					y = i;
					x = j;

				}

			}
		}
	}

	globalscet++;


	/*

	temp = func(players_sym, 0, 0, 0, players_sym);
	y = ytemp;
	x = xtemp;
	*/




	//�������� -1 � ��� ��� �� ������ ������



//	int oldx = 0;
	//int oldy = 0;
	//��������� ����� ���� ������ ��� ��������

	gotoxy(15, 15);
	//printf("%d", minimax(x, y, 4, 1, players_sym));


	gotoxy(x, y);

	onesimvol(field[y][x] + 3, x, y);

	if (field[y][x] == 0)
	{
		field[y][x] = players_sym;
		onesimvol(field[y][x] + 3, x, y);
		//�������� ������ �����

	}

	onesimvol(field[y][x], x, y);

	if (check_win(players_sym, x, y))
	{
		gotoxy(21, 21);
		printf("������� ���");
		pause(2000);

		main_menu();
	}
	gotoxy(currentx, currenty);

}


void bot3(int bott)
{

	if (globalscet == x_max * y_max) return;

	//�������  � ����� �������
	//con_set_color(CON_CLR_BLACK, CON_CLR_BLACK);!
	//clrscr();!
	int players_sym = 1;
	players_sym = bott;
	//if (ddde) otrisovka();!
	//ddde = 0; !
	//������������ ������ �������
	int oldx = 0;
	int oldy = 0;
	int x = 0; // ��� ��������� �������
	int y = 0;
	int max = -100000000;
	long long int temp = -1;

	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{


			if (field[i][j] == 0)
			{

				temp = minimax(j, i, 6, 1, players_sym, -100000000, 100000000) + vygoda(players_sym, j, i);
				//temp = vygoda(players_sym, j, i);
				if (temp >= max)
				{
					max = temp;
					y = i;
					x = j;

				}

			}
		}
	}

	globalscet++;


	/*

	temp = func(players_sym, 0, 0, 0, players_sym);
	y = ytemp;
	x = xtemp;
	*/




	//�������� -1 � ��� ��� �� ������ ������



//	int oldx = 0;
	//int oldy = 0;
	//��������� ����� ���� ������ ��� ��������

	gotoxy(15, 15);
	//printf("%d", minimax(x, y, 4, 1, players_sym));


	gotoxy(x, y);

	onesimvol(field[y][x] + 3, x, y);

	if (field[y][x] == 0)
	{
		field[y][x] = players_sym;
		onesimvol(field[y][x] + 3, x, y);
		//�������� ������ �����

	}

	onesimvol(field[y][x], x, y);

	if (check_win(players_sym, x, y))
	{
		gotoxy(21, 21);
		printf("������� ���");
		pause(2000);

		main_menu();
	}
	gotoxy(currentx, currenty);

}





		
		//while (!key_is_pressed)
		//{

		//}
	

long long int minimax(int x,int y,int depth,int maxiPlayer,int symvol,int alpha, int beta)
{
	int score;
	int val;
	int s=0;
	if (depth == 0) return vygoda(symvol, x, y);
	if (check_win(symvol, x, y) || check_win(anti(symvol), x, y))
	{
		if ((check_win(symvol, x, y)) && maxiPlayer)
		{
			return 10000000;
		}
		if ((check_win(anti(symvol), x, y))&& maxiPlayer)
		{
			return 10000000;
		}


		if ((check_win(symvol, x, y)) && !maxiPlayer)
		{
			return -10000000;
		}
		if ((check_win(anti(symvol), x, y)) && !maxiPlayer)
		{
			return -10000000;
		}


	}


	if (maxiPlayer)
	{
		field[y][x] = (symvol);
		val = -10000000;
		score = alpha;

		for (int i = 0; i < y_max; i++)
		{
			for (int j = 0; j < x_max; j++)
			{
				if (field[i][j] == 0)
				{
					

					s = minimax(j, i, depth - 1, 0, symvol, score, beta);
					if (s > score) score = s;
					if (score >= beta)
					{
						field[y][x] = 0;
						return score;
						
					}
				}
			}
		}
		field[y][x] = 0;
		return score;
	}

	if (!maxiPlayer)
	{
		field[y][x] = anti(symvol);

		val = 10000000;
		score = beta;

		for (int i = 0; i < y_max; i++)
		{
			for (int j = 0; j < x_max; j++)
			{
				if (field[i][j] == 0)
				{
					s = minimax(j, i, depth - 1, 1, symvol, alpha, score);
					if (s < score) score = s;
					if (score <= alpha)
					{
						field[y][x] = 0;

						return score;
					}
				}
			}
		}
		field[y][x] = 0;

		return score;
	}



	return 0;
}

void main_menu()
{
	const char* menu_items[] = { "�������", "��������� ����", "���������","����� ����", "� ���������", "�����" };
	int menu_active_idx = 0;
	int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

	short clr_bg = CON_CLR_BLACK;
	short clr_bg_active = CON_CLR_GRAY;
	short clr_font = CON_CLR_WHITE_LIGHT;

	while (1)
	{
		int left = 30;
		int top = 2;
		int b;

		// ������������� ���������
		con_draw_lock();

		// ������� ������
		con_set_color(clr_font, clr_bg);
		clrscr();

		// ���� ������������ ������
		for (b = 0; b < menu_items_count; b++)
		{
			short btn_bg = clr_bg; // �� ��������� ��� ������ - ��� ��� ������
			if (b == menu_active_idx)
				btn_bg = clr_bg_active; // ���� ������ ������� - �� �������� ������ ������

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
		
		// ������ ������������, ������� �� �����
		con_draw_release();
		

		while (!key_is_pressed()) // ���� ������������ �������� ������
		{
			int code = key_pressed_code();
			if (code == KEY_UP) // ���� ��� ������� �����
			{
				// �� ������� � �������� ������ (���� ��� ��������)
				if (menu_active_idx > 0) 
				{
					menu_active_idx--;
					break;
				}
			}
			else if (code == KEY_DOWN) // ���� ������� ����
			{
				// �� ������� � ������� ������ (���� ��� ��������)
				if (menu_active_idx + 1 < menu_items_count)
				{
					menu_active_idx++;
					break;
				}
			}
			else if (code == KEY_ESC || code == 'q' || code == 'Q' || 
				     code == (unsigned char)'�' || code == (unsigned char)'�') // ESC ��� 'q' - �����
			{
				return;
			}
			else if (code == KEY_ENTER) // ������ ������ Enter
			{
				if (menu_active_idx == menu_items_count - 1) // ������ ��������� ����� - ��� �����
					//return;
					exit(0);

				if (menu_active_idx == 0)
					helper();

				if (menu_active_idx == 1)
				{   
					ddde = 1;
					play_load();
				}
				if (menu_active_idx == 2)
					setting();
				if (menu_active_idx == 3)
				{
					globalscet = 0;
					ddde = 1;
					play();

				}
					//otrisovka();


				if (menu_active_idx == menu_items_count - 2)
					about();

				break;
			}
		
		
			pause(40); // ��������� ����� (����� �� ��������� ���������)
		} // while (!key_is_pressed())


		// "���������" ���������� ����
		while (key_is_pressed())
			key_pressed_code();

	} // while(1)

}

void setting()
{
        const char* menu_items[] = { "����� �����", "������� ����", "����� ������","����� ���������", "�����" };
		int menu_active_idx = 0;
		int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

		short clr_bg = CON_CLR_BLACK;
		short clr_bg_active = CON_CLR_GRAY;
		short clr_font = CON_CLR_WHITE_LIGHT;

		while (1)
		{
			int left = 30;
			int top = 2;
			int b;

			// ������������� ���������
			con_draw_lock();

			// ������� ������
			con_set_color(clr_font, clr_bg);
			clrscr();

			// ���� ������������ ������
			for (b = 0; b < menu_items_count; b++)
			{
				short btn_bg = clr_bg; // �� ��������� ��� ������ - ��� ��� ������
				if (b == menu_active_idx)
					btn_bg = clr_bg_active; // ���� ������ ������� - �� �������� ������ ������

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

			// ������ ������������, ������� �� �����
			con_draw_release();


			while (!key_is_pressed()) // ���� ������������ �������� ������
			{
				int code = key_pressed_code();
				if (code == KEY_UP) // ���� ��� ������� �����
				{
					// �� ������� � �������� ������ (���� ��� ��������)
					if (menu_active_idx > 0)
					{
						menu_active_idx--;
						break;
					}
				}
				else if (code == KEY_DOWN) // ���� ������� ����
				{
					// �� ������� � ������� ������ (���� ��� ��������)
					if (menu_active_idx + 1 < menu_items_count)
					{
						menu_active_idx++;
						break;
					}
				}
				else if (code == KEY_ESC || code == 'q' || code == 'Q' ||
					code == (unsigned char)'�' || code == (unsigned char)'�') // ESC ��� 'q' - �����
				{
					return;
				}
				else if (code == KEY_ENTER) // ������ ������ Enter
				{
					if (menu_active_idx == menu_items_count - 1) // ������ ��������� ����� - ��� �����
						return;

					if (menu_active_idx == 0)
						dlinalinii();

					if (menu_active_idx == 1)
						razmerpole();

					if (menu_active_idx == 2)
						figura();
					if (menu_active_idx == 3)
					{
						slognost();

					}
					//otrisovka();


					//if (menu_active_idx == menu_items_count - 2)
					//	about();

					break;
				}


				pause(40); // ��������� ����� (����� �� ��������� ���������)
			} // while (!key_is_pressed())


			// "���������" ���������� ����
			while (key_is_pressed())
				key_pressed_code();

		} // while(1)

	}


void dlinalinii()
	{
		const char* menu_items[] = { "3", "4", "5","6","7" ,"�����" };
		int menu_active_idx = 0;
		int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

		short clr_bg = CON_CLR_BLACK;
		short clr_bg_active = CON_CLR_GRAY;
		short clr_font = CON_CLR_WHITE_LIGHT;

		while (1)
		{
			int left = 30;
			int top = 2;
			int b;

			// ������������� ���������
			con_draw_lock();

			// ������� ������
			con_set_color(clr_font, clr_bg);
			clrscr();

			// ���� ������������ ������
			for (b = 0; b < menu_items_count; b++)
			{
				short btn_bg = clr_bg; // �� ��������� ��� ������ - ��� ��� ������
				if (b == menu_active_idx)
					btn_bg = clr_bg_active; // ���� ������ ������� - �� �������� ������ ������

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

			// ������ ������������, ������� �� �����
			con_draw_release();


			while (!key_is_pressed()) // ���� ������������ �������� ������
			{
				int code = key_pressed_code();
				if (code == KEY_UP) // ���� ��� ������� �����
				{
					// �� ������� � �������� ������ (���� ��� ��������)
					if (menu_active_idx > 0)
					{
						menu_active_idx--;
						break;
					}
				}
				else if (code == KEY_DOWN) // ���� ������� ����
				{
					// �� ������� � ������� ������ (���� ��� ��������)
					if (menu_active_idx + 1 < menu_items_count)
					{
						menu_active_idx++;
						break;
					}
				}
				else if (code == KEY_ESC || code == 'q' || code == 'Q' ||
					code == (unsigned char)'�' || code == (unsigned char)'�') // ESC ��� 'q' - �����
				{
					return;
				}
				else if (code == KEY_ENTER) // ������ ������ Enter
				{
					if (menu_active_idx == menu_items_count - 1) // ������ ��������� ����� - ��� �����
						return;

					if (menu_active_idx == 0)
					{
						len_ryd = 3;

						return;

					}
					if (menu_active_idx == 1)
					{
						len_ryd = 4;
						return;


					}
					if (menu_active_idx == 2)
					{  
							len_ryd = 5;
							return;

					}

					if (menu_active_idx == 3)
					{
						len_ryd = 6;
						return;


					}
					//otrisovka();


					if (menu_active_idx == menu_items_count - 2)
					{ 
						len_ryd = 7;
						return;

					}
					break;
				}


				pause(40); // ��������� ����� (����� �� ��������� ���������)
			} // while (!key_is_pressed())


			// "���������" ���������� ����
			while (key_is_pressed())
				key_pressed_code();

		} // while(1)

	}

	void razmerpole()
	{
		const char* menu_items[] = { "6*6", "11*11", "13*13","15*15","20*20" ,"�����" };
		int menu_active_idx = 0;
		int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

		short clr_bg = CON_CLR_BLACK;
		short clr_bg_active = CON_CLR_GRAY;
		short clr_font = CON_CLR_WHITE_LIGHT;

		while (1)
		{
			int left = 30;
			int top = 2;
			int b;

			// ������������� ���������
			con_draw_lock();

			// ������� ������
			con_set_color(clr_font, clr_bg);
			clrscr();

			// ���� ������������ ������
			for (b = 0; b < menu_items_count; b++)
			{
				short btn_bg = clr_bg; // �� ��������� ��� ������ - ��� ��� ������
				if (b == menu_active_idx)
					btn_bg = clr_bg_active; // ���� ������ ������� - �� �������� ������ ������

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

			// ������ ������������, ������� �� �����
			con_draw_release();


			while (!key_is_pressed()) // ���� ������������ �������� ������
			{
				int code = key_pressed_code();
				if (code == KEY_UP) // ���� ��� ������� �����
				{
					// �� ������� � �������� ������ (���� ��� ��������)
					if (menu_active_idx > 0)
					{
						menu_active_idx--;
						break;
					}
				}
				else if (code == KEY_DOWN) // ���� ������� ����
				{
					// �� ������� � ������� ������ (���� ��� ��������)
					if (menu_active_idx + 1 < menu_items_count)
					{
						menu_active_idx++;
						break;
					}
				}
				else if (code == KEY_ESC || code == 'q' || code == 'Q' ||
					code == (unsigned char)'�' || code == (unsigned char)'�') // ESC ��� 'q' - �����
				{
					return;
				}
				else if (code == KEY_ENTER) // ������ ������ Enter
				{
					if (menu_active_idx == menu_items_count - 1) // ������ ��������� ����� - ��� �����
						return;

					if (menu_active_idx == 0)
					{
						y_max = 6;
						x_max = 6;
						return;

					}
					if (menu_active_idx == 1)
					{
						y_max = 11;
						x_max = 11;
						return;


					}
					if (menu_active_idx == 2)
					{
						y_max = 13;
						x_max = 13;
						return;

					}

					if (menu_active_idx == 3)
					{
						y_max = 15;
						x_max = 15;
						return;


					}
					//otrisovka();


					if (menu_active_idx == menu_items_count - 2)
					{
						y_max = 20;
						x_max = 20;
						return;

					}
					break;
				}


				pause(40); // ��������� ����� (����� �� ��������� ���������)
			} // while (!key_is_pressed())


			// "���������" ���������� ����
			while (key_is_pressed())
				key_pressed_code();

		} // while(1)

	}

	void figura()
	{
		const char* menu_items[] = { "X", "O", "�����" };
		int menu_active_idx = 0;
		int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

		short clr_bg = CON_CLR_BLACK;
		short clr_bg_active = CON_CLR_GRAY;
		short clr_font = CON_CLR_WHITE_LIGHT;

		while (1)
		{
			int left = 30;
			int top = 2;
			int b;

			// ������������� ���������
			con_draw_lock();

			// ������� ������
			con_set_color(clr_font, clr_bg);
			clrscr();

			// ���� ������������ ������
			for (b = 0; b < menu_items_count; b++)
			{
				short btn_bg = clr_bg; // �� ��������� ��� ������ - ��� ��� ������
				if (b == menu_active_idx)
					btn_bg = clr_bg_active; // ���� ������ ������� - �� �������� ������ ������

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

			// ������ ������������, ������� �� �����
			con_draw_release();


			while (!key_is_pressed()) // ���� ������������ �������� ������
			{
				int code = key_pressed_code();
				if (code == KEY_UP) // ���� ��� ������� �����
				{
					// �� ������� � �������� ������ (���� ��� ��������)
					if (menu_active_idx > 0)
					{
						menu_active_idx--;
						break;
					}
				}
				else if (code == KEY_DOWN) // ���� ������� ����
				{
					// �� ������� � ������� ������ (���� ��� ��������)
					if (menu_active_idx + 1 < menu_items_count)
					{
						menu_active_idx++;
						break;
					}
				}
				else if (code == KEY_ESC || code == 'q' || code == 'Q' ||
					code == (unsigned char)'�' || code == (unsigned char)'�') // ESC ��� 'q' - �����
				{
					return;
				}
				else if (code == KEY_ENTER) // ������ ������ Enter
				{
					if (menu_active_idx == menu_items_count - 1) // ������ ��������� ����� - ��� �����
						return;

					if (menu_active_idx == 0)
					{
						polzovatelsym = 2;
						return;
					}
						

					if (menu_active_idx == 1)
					{
						polzovatelsym = 1;
						return;
					}
					
					//otrisovka();


					
					break;
				}


				pause(40); // ��������� ����� (����� �� ��������� ���������)
			} // while (!key_is_pressed())


			// "���������" ���������� ����
			while (key_is_pressed())
				key_pressed_code();

		} // while(1)

	}
	void slognost()
	{
		const char* menu_items[] = { "�����", "���������", "������","����� ������", "�����" };
		int menu_active_idx = 0;
		int menu_items_count = sizeof(menu_items) / sizeof(menu_items[0]);

		short clr_bg = CON_CLR_BLACK;
		short clr_bg_active = CON_CLR_GRAY;
		short clr_font = CON_CLR_WHITE_LIGHT;

		while (1)
		{
			int left = 30;
			int top = 2;
			int b;

			// ������������� ���������
			con_draw_lock();

			// ������� ������
			con_set_color(clr_font, clr_bg);
			clrscr();

			// ���� ������������ ������
			for (b = 0; b < menu_items_count; b++)
			{
				short btn_bg = clr_bg; // �� ��������� ��� ������ - ��� ��� ������
				if (b == menu_active_idx)
					btn_bg = clr_bg_active; // ���� ������ ������� - �� �������� ������ ������

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

			// ������ ������������, ������� �� �����
			con_draw_release();


			while (!key_is_pressed()) // ���� ������������ �������� ������
			{
				int code = key_pressed_code();
				if (code == KEY_UP) // ���� ��� ������� �����
				{
					// �� ������� � �������� ������ (���� ��� ��������)
					if (menu_active_idx > 0)
					{
						menu_active_idx--;
						break;
					}
				}
				else if (code == KEY_DOWN) // ���� ������� ����
				{
					// �� ������� � ������� ������ (���� ��� ��������)
					if (menu_active_idx + 1 < menu_items_count)
					{
						menu_active_idx++;
						break;
					}
				}
				else if (code == KEY_ESC || code == 'q' || code == 'Q' ||
					code == (unsigned char)'�' || code == (unsigned char)'�') // ESC ��� 'q' - �����
				{
					return;
				}
				else if (code == KEY_ENTER) // ������ ������ Enter
				{
					if (menu_active_idx == menu_items_count - 1) // ������ ��������� ����� - ��� �����
						return;

					if (menu_active_idx == 0)
					{
						difficulty = 0;
						return;
					}

					if (menu_active_idx == 1)
					{
						difficulty = 1;
						return;

					}

					if (menu_active_idx == 2)
					{
						difficulty = 2;
						return;

					}
					if (menu_active_idx == 3)
					{
						difficulty = 3;
						return;


					}
					//otrisovka();



					break;
				}


				pause(40); // ��������� ����� (����� �� ��������� ���������)
			} // while (!key_is_pressed())


			// "���������" ���������� ����
			while (key_is_pressed())
				key_pressed_code();

		} // while(1)

	}



void play()
{
	/*for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			field[i][j] = 0;
		}
	}*/

	memset(field, 0, 400);

	//��� ��������
	con_set_color(CON_CLR_BLACK, CON_CLR_BLACK);
	clrscr();
	if (ddde) otrisovka();
	ddde = 0;


	if (difficulty == 0)
	{
		if (polzovatelsym == 2)
		{
			while (1)
			{
				player(polzovatelsym);

				bot1(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		}
		//if (polzovatelsym == 1)
		else 
		{


			while (1)
			{

				bot1(anti(polzovatelsym));
				player(polzovatelsym);
				if (globalscet == x_max * y_max)
				{

					pause(2000);

					return;


				}
			}
		}

	}
	if (difficulty == 1)
	{
		if (polzovatelsym == 2)
		{
			while (1)
			{
				player(polzovatelsym);

				bot(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		}
		//if (polzovatelsym == 1)
		else
		{


			while (1)
			{

				bot(anti(polzovatelsym));
				player(polzovatelsym);
				if (globalscet == x_max * y_max)
				{

					pause(2000);

					return;


				}
			}
		}

	}
	if (difficulty == 2)
	{
		if (polzovatelsym == 2)
		{
			while (1)
			{
				player(polzovatelsym);

				bot2(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		}
		//if (polzovatelsym == 1)
		else
		{


			while (1)
			{

				bot2(anti(polzovatelsym));
				player(polzovatelsym);
				if (globalscet == x_max * y_max)
				{

					pause(2000);

					return;


				}
			}
		}

	}
	if (difficulty == 3)
	{
		if (polzovatelsym == 2)
		{
			while (1)
			{
				player(polzovatelsym);

				bot3(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		}
		//if (polzovatelsym == 1)
		else
		{


			while (1)
			{

				bot3(anti(polzovatelsym));
				player(polzovatelsym);
				if (globalscet == x_max * y_max)
				{

					pause(2000);

					return;


				}
			}
		}

	}

	




}




void play_load()
{
	char* filename = "data.dat";

	load(filename);
	con_set_color(CON_CLR_BLACK, CON_CLR_BLACK);
	clrscr();
	if (ddde) otrisovka();
	ddde = 0;


	if (difficulty == 0)
	{
		
			while (1)
			{
				player(polzovatelsym);

				bot1(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		

	}
	if (difficulty == 1)
	{
		
			while (1)
			{
				player(polzovatelsym);

				bot(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		

	}
	if (difficulty == 2)
	{
		
			while (1)
			{
				player(polzovatelsym);

				bot2(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		

	}
	if (difficulty == 3)
	{
		
			while (1)
			{
				player(polzovatelsym);

				bot3(anti(polzovatelsym));
				if (globalscet == x_max * y_max)
				{
					pause(2000);
					return;
				}

			}
		

	}






}




int save(char* filename, struct a* p)
{
	FILE* fp;
	char* c;
	int size = sizeof(struct a); // ���������� ������������ ������

	if ((fp = fopen(filename, "wb")) == NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	// ������������� ��������� �� ������ ���������
	c = (char*)p;
	// ����������� ���������� � ���� ���������
	for (int i = 0; i < size; i++)
	{
		putc(*c++, fp);
	}
	fclose(fp);
	return 0;
}

// �������� �� ����� ���������
int load(char* filename)
{
	FILE* fp;

	char* c;
	int i; // ��� ���������� ������ �������
	// ���������� ����������� ������
	int size = sizeof(struct a);
	// �������� ������ ��� ����������� ���������
	struct a* ptr = (struct a*)malloc(size);

	if ((fp = fopen(filename, "rb")) == NULL)
	{
		main_menu();
	}

	// ������������� ��������� �� ������ ����� ���������� ������
	c = (char*)ptr;
	// ��������� ����������� �� �����
	while ((i = getc(fp)) != EOF)
	{
		*c = i;
		c++;
	}




	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			field[i][j] = ptr->field[i][j];

		}
	}

	//����� �� ��������? ����� �������� ����������?
	//memcpy(field, ptr->field, 400);

	difficulty = ptr->difficulty;

	globalscet= ptr->globalscet;
	len_ryd =ptr->len_ryd;
	polzovatelsym =  ptr->polzovatelsym;
	x_max =ptr->x_max;
	y_max =ptr->y_max;




	fclose(fp);
	// ����� �� ������� ����������� ���������
	
	free(ptr);
	return 0;
}


void helper()
{
	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_BLACK);
	clrscr();

	gotoxy(0, 2);
	printf("�������:");

	con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
	gotoxy(0, 3);
	printf("��� ���������� �������� ����������� �������\n����� ��������� ���� ����������� ������\n����� ��������� ���� ������� Q\n��� ������ �� ���� � ����������� ���������� ������� S\n��� ������ ������ ���� ����������� Enter\n");

	gotoxy(8, 9);
	printf("��� ����������� ������� ����� �������.");

	key_pressed_code();
	return;
}



void about()
{
	con_set_color(CON_CLR_WHITE_LIGHT, CON_CLR_BLACK);
	clrscr();

	gotoxy(0, 2);
	printf("� ���������:");

	con_set_color(CON_CLR_GRAY, CON_CLR_BLACK);
	gotoxy(0, 3);
	printf("���������:������ �.�.,�������� �.�.\n�����-������������� ��������������� ����������� ����� ��������\n�������� ����������������� � ������ ����������\n������:4851003/00002\n2021 ���\n");

	gotoxy(8, 9);
	printf("��� ����������� ������� ����� �������.");
	key_pressed_code();
	return;
}