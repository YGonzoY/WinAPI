// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject1.h"
#include"func.h"

#include<string>
typedef wchar_t TCHAR;

LPCWSTR convertCharArrayToLPCWSTR(char* charArray)
{
    const char* cs = charArray;
    wchar_t filename[4096] = { 0 };
    MultiByteToWideChar(CP_ACP, 0, cs, -1, filename, strlen(charArray));
    return filename;
}

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));


    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//

HWND hwndTextBox2;
HWND hwndTextBox1;
HWND hwndTextBox3;
HWND whndTextBox4;
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   HWND hwndButton = CreateWindowW(
       L"BUTTON",  // Predefined class; Unicode assumed 
       L"OK",      // Button text 
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       150,         // x position 
       150,         // y position 
       75,        // Button width
       25,        // Button height
       hWnd,     // Parent window
       NULL,     // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);      // Pointer not needed

    hwndTextBox1 = CreateWindowW(
       L"EDIT",  // Predefined class; Unicode assumed 
       L"0",      // Button text 
       WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_BORDER,  // Styles 
       250,         // x position 
       250,         // y position 
       50,        // Button width
       25,        // Button height
       hWnd,     // Parent window
       NULL,     // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);
   hwndTextBox2 = CreateWindowW(
       L"EDIT",  // Predefined class; Unicode assumed 
       L"0",      // Button text 
       WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_BORDER,  // Styles 
       250,         // x position 
       200,         // y position 
       50,        // Button width
       25,        // Button height
       hWnd,     // Parent window
       NULL,     // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);

   hwndTextBox3 = CreateWindowW(
       L"EDIT",  // Predefined class; Unicode assumed 
       L"0",      // Button text 
       WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_BORDER,  // Styles 
       250,         // x position 
       300,         // y position 
       50,        // Button width
       25,        // Button height
       hWnd,     // Parent window
       NULL,     // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);
    whndTextBox4 = CreateWindowW(
       L"EDIT",  // Predefined class; Unicode assumed 
       L"0",      // Button text 
       WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_BORDER,  // Styles 
       250,         // x position 
       350,         // y position 
       50,        // Button width
       25,        // Button height
       hWnd,     // Parent window
       NULL,     // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    const size_t size = 20;
    TCHAR StrA[size];
    int a, b, sum, dis, Len;

        switch (message)

        {
        case WM_COMMAND:
        {
            if (HIWORD(wParam) == 0)
            {

            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:

                switch (wmId)
                {
                case BN_CLICKED:
                    Len = GetWindowText(hwndTextBox2, StrA, 20);
                    char str[20];
                    for (int i = 0; i < 20; i++)
                    {
                        str[i] = static_cast<char>(StrA[i]);
                    }
                    a = StrToInt(str); // считываем число из первого поля
                    Len = GetWindowText(hwndTextBox1, StrA, 20);
                    for (int i = 0; i < 20; i++)
                    {
                        str[i] = static_cast<char>(StrA[i]);
                    }
                    b = StrToInt(str); // считываем число из второго поля
      
                    sum = a + b;  // находим сумму двух чисел
                    dis = a - b;
                    SetWindowText(hwndTextBox3, convertCharArrayToLPCWSTR(IntToStr(sum)));
                    SetWindowText(whndTextBox4, convertCharArrayToLPCWSTR(IntToStr(dis)));
                    break;
                case IDM_ABOUT:
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
                case IDM_EXIT:
                    DestroyWindow(hWnd);
                    break;

                }
        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
