#include "global.h"

// ȫ�ֱ���
TCHAR szWindowClass[] = _T("win32app");
TCHAR szTitle[] = _T("��ս���");

// ����λͼ���
HBITMAP m_hBackgroundBmp;
HBITMAP m_hHeroBmp;
HBITMAP m_hGameStatusBmp;

// ����Ӣ�ۡ����������Ρ���Ϸ״̬
Hero          m_hero;
Terrian       m_terrian[MAX_TERRIAN_NUM];
GameStatus    m_gameStatus;
