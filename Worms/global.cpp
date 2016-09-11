#include "global.h"

// 全局变量
TCHAR szWindowClass[] = _T("win32app");
TCHAR szTitle[] = _T("百战天虫");

// 声明位图句柄
HBITMAP m_hBackgroundBmp;
HBITMAP m_hHeroBmp;
HBITMAP m_hGameStatusBmp;

// 声明英雄、建筑、地形、游戏状态
Hero          m_hero;
Terrian       m_terrian[MAX_TERRIAN_NUM];
GameStatus    m_gameStatus;
