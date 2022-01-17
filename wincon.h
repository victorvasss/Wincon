#ifndef __wincon_h
#define __wincon_h

/* wincon - ���������� ��� ������ � �������� windows. ������� ������ ncurses.
   ��� ������������� ���������� ����� �������� � ������ ���� wincon.c.
   ������ ������������� �������� � ����� demo.c

   ���� � ������� �� �������������� ��������� ������� ����, �� �������
   �������� ����� �� ����� ��������� (�������� Lucida Console).
 */

/* �������������� �������: ������������� ��������� win1251. 
   �������� double_buf ��������� - ������������ �� ������� ������������ */
void con_init(short width, short height);

/* ������� ���������� ������� ������ � ������ ������� */
short con_width();
short con_height();

/* ������� ������������� ���� ������ � ����. ����������� ���� �� �������� CON_CLR_ */
void con_set_color(short font, short background);

/* ������� ������� ������� ������� ������ ����. */
void clrscr();

void con_draw_lock();
void con_draw_release();

/* ������� ���������� ������ ������� � ��������� �������. ����� � ������� printf, putchar ����� ����������� � ���� ������� */
void gotoxy(short x, short y);

/* ������� ���������� (show=1) ��� �������� (show=0) �������� ������ ����� �������. */
void show_cursor(int show);

/* ������� ������� ��������� ���������� ����������� � ��������� ���������� ����������� ����. */
void pause(int ms);

/* ������� ��������� - ����� �� ������������ ������� � �������. ���������� 1 ��� 0. */
int key_is_pressed();

/* ������� ���������� ��� ������� �������. 
  ���� ������������ ������ �� ������� - ������� �� ������ ���������� �� ��� ���, ���� ������������ �� ������ �������.
  �������� key_is_pressed() ����� ��������� - ���� �� ��� ������� ������� � ������ */
int key_pressed_code();

/* ���� ��������� ����������� ������, ������������ key_pressed_code() */
#define KEY_UP     (256 + 72)
#define KEY_DOWN   (256 + 80)
#define KEY_LEFT   (256 + 75)
#define KEY_RIGHT  (256 + 77)
#define KEY_ENTER  (13)
#define KEY_ESC	   (27)
#define KEY_BACK   (8)


/* ���� ��������� ������ ��� con_set_color */

#define BIT_BLUE	(0x01)
#define BIT_GREEN	(0x02)
#define BIT_RED		(0x04)
#define BIT_LIGHT	(0x08)

/* 16 ������, �������������� ��������. ����� ���������� � con_set_colors */
#define CON_CLR_BLACK		(0)
#define CON_CLR_RED			(BIT_RED)
#define CON_CLR_GREEN		(BIT_GREEN)
#define CON_CLR_BLUE		(BIT_BLUE)
#define CON_CLR_YELLOW		(BIT_RED | BIT_GREEN)
#define CON_CLR_MAGENTA		(BIT_RED | BIT_BLUE)
#define CON_CLR_CYAN		(BIT_GREEN | BIT_BLUE)
#define CON_CLR_WHITE		(BIT_RED | BIT_GREEN | BIT_BLUE)

#define CON_CLR_GRAY		(BIT_LIGHT)
#define CON_CLR_RED_LIGHT		(BIT_RED | BIT_LIGHT)
#define CON_CLR_GREEN_LIGHT		(BIT_GREEN | BIT_LIGHT)
#define CON_CLR_BLUE_LIGHT		(BIT_BLUE | BIT_LIGHT)
#define CON_CLR_YELLOW_LIGHT		(BIT_RED | BIT_GREEN | BIT_LIGHT)
#define CON_CLR_MAGENTA_LIGHT		(BIT_RED | BIT_BLUE | BIT_LIGHT)
#define CON_CLR_CYAN_LIGHT		(BIT_GREEN | BIT_BLUE | BIT_LIGHT)
#define CON_CLR_WHITE_LIGHT		(BIT_BLUE | BIT_RED | BIT_GREEN | BIT_LIGHT)

#endif // __wincon_h
