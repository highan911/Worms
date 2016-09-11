#ifndef GLOBAL_H
#define GLOBAL_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include "resource.h"

// ����������WNDWIDTH��WNDHEIGHTΪ���ڵĿ�͸�
#define TIMER_ID             1
#define TIMER_ELAPSE         20
#define WNDWIDTH             800
#define WNDHEIGHT            600
#define TITLEBARHEIGHT       32
#define MAX_TERRIAN_NUM      1

// ������Դ�ĳߴ�
#define HERO_SIZE_X          30
#define HERO_SIZE_Y          30
#define HERO_MAX_FRAME_NUM   3
#define GAME_STATUS_SIZE_X   40
#define GAME_STATUS_SIZE_Y   43

// Ӣ�۽ṹ�壬Ӣ��λͼ��λ�á���С*/
typedef struct
{
	HBITMAP	hBmp;
	POINT	pos;
	SIZE	size;
	int     curFrameIndex;
	int     maxFrameSize;
} Hero;

/*���νṹ�壬���η���λ�á���С*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Terrian;

/*��Ϸ״̬�ṹ��*/
typedef struct
{
	HBITMAP	hBmp;
	POINT   pos;
	SIZE	size;
	BOOL	isPaused;
	int     totalDist;
} GameStatus;


// ȫ�ֱ���
extern TCHAR szWindowClass[];
extern TCHAR szTitle[];

// ����λͼ���
extern HBITMAP m_hBackgroundBmp;
extern HBITMAP m_hHeroBmp;
extern HBITMAP m_hGameStatusBmp;

// ����Ӣ�ۡ����������Ρ���Ϸ״̬
extern Hero          m_hero;
extern Terrian       m_terrian[MAX_TERRIAN_NUM];
extern GameStatus    m_gameStatus;


// ȫ�ֺ���
// ������̺���
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/*************************************************
Fucntion : ����Ӣ������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
curFrameIndex��ǰ֡
maxFrameSize���֡��
*************************************************/
Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize);

/*************************************************
Fucntion : ������Ϸ״̬
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
*************************************************/
GameStatus CreateGameStatus(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ������������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

#endif // !GLOBAL_H
