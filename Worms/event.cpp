#include "event.h"
#include "global.h"

VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// ���ر���λͼ
	m_hBackgroundBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BACKGROUND));

	// ����Heroλͼ
	m_hHeroBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_HERO));

	// ���ط��ذ�ťλͼ
	m_hGameStatusBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BACKBUTTON));

	// ����Ӣ��
	m_hero = CreateHero(150, 450 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp, 0, HERO_MAX_FRAME_NUM);

	// ��������
	m_terrian[0] = CreateTerrian(100, 450, 600, 100, NULL);

	// ������Ϸ״̬
	m_gameStatus = CreateGameStatus(20, 20, GAME_STATUS_SIZE_X, GAME_STATUS_SIZE_Y, m_hGameStatusBmp);

	// ������ʱ��
	SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
}

VOID Render(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// ��ʼ����
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, m_hBackgroundBmp);

	// ���Ʊ���������
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// ����Hero������
	SelectObject(hdcBmp, m_hero.hBmp);
	TransparentBlt(
		hdcBuffer, m_hero.pos.x, m_hero.pos.y,
		m_hero.size.cx, m_hero.size.cy,
		hdcBmp, 0, 0, 66, 62,
		RGB(255, 255, 255)
	);

	// ���Ƶ���
	SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
	HBRUSH terrianBrush = CreateSolidBrush(RGB(223, 169, 103));
	SelectObject(hdcBuffer, terrianBrush);
	int k;
	for (k = 0; k < MAX_TERRIAN_NUM; ++k)
	{
		Terrian *terrian = &m_terrian[k];
		Rectangle(hdcBuffer, terrian->pos.x, terrian->pos.y,
			terrian->pos.x + terrian->size.cx, terrian->pos.y + terrian->size.cy);
	}
	DeleteObject(terrianBrush);

	// ������Ϸ״̬
	// ��ͣ�����λͼ
	SelectObject(hdcBmp, m_gameStatus.hBmp);
	TransparentBlt(hdcBuffer, m_gameStatus.pos.x, m_gameStatus.pos.y, m_gameStatus.size.cx, m_gameStatus.size.cy,
		hdcBmp, 0, 0,
		m_gameStatus.size.cx, m_gameStatus.size.cy, RGB(255, 255, 255));

	// ���Ʒ���
	TCHAR	szDist[13];
	SetTextColor(hdcBuffer, RGB(0, 0, 0));
	SetBkMode(hdcBuffer, TRANSPARENT);
	TextOut(hdcBuffer, WNDWIDTH - 100, 15, szDist, wsprintf(szDist, _T("0 : 0"), m_gameStatus.totalDist));

	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ�
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// ��������
	EndPaint(hWnd, &ps);
}

VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	HeroUpdate();
	GameStatusUpdate();
	InvalidateRect(hWnd, NULL, FALSE);
}

VOID HeroUpdate()
{
	// TODO
	//����λ��

	//���¶���
}

VOID GameStatusUpdate()
{
	// TODO
}

BOOL Paused(POINT ptMouse)
{
	RECT rPause;

	rPause.left = m_gameStatus.pos.x;
	rPause.top = m_gameStatus.pos.y;
	rPause.right = m_gameStatus.size.cx;
	rPause.bottom = m_gameStatus.size.cy;

	return PtInRect(&rPause, ptMouse);
}

VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_UP:
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case VK_DOWN:
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	default:
		break;
	}
}

VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_UP:
		m_hero.pos.y -= 50;
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case VK_DOWN:
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	default:
		break;
	}
}

VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	POINT ptMouse; // �����������
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	//�������˼�������ͣͼ��
	if (Paused(ptMouse))
	{
		if (!m_gameStatus.isPaused)
		{
			KillTimer(hWnd, TIMER_ID);
			m_gameStatus.isPaused = TRUE;
		}
		else
		{
			SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
			m_gameStatus.isPaused = FALSE;
		}
		InvalidateRect(hWnd, NULL, FALSE);
	}
}
