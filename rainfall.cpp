#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#define VK_Q 0x51
using namespace std;

unsigned int counter = 0;

void set_cursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int main(void)
{
    cout << "press q to quit" << endl;
    cout << "" << endl;
    Sleep(300);
    int running = 1;
    while (running = 1)
    {
        set_cursor(false);
        DWORD mode;
        INPUT_RECORD event;
        BOOL done = FALSE;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int k = 1; k < 16; k++)
        {
            SetConsoleTextAttribute(hConsole, k);
            SetConsoleOutputCP(65001);
            HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
            GetConsoleMode(hstdin, &mode);
            SetConsoleMode(hstdin, 0);

            if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0)
            {
                DWORD count;

                ReadConsoleInput(hstdin, &event, 1, &count);

                if ((event.EventType == KEY_EVENT) && !event.Event.KeyEvent.bKeyDown)
                    switch (event.Event.KeyEvent.wVirtualKeyCode)
                    {
                    case VK_Q:
                        set_cursor(true);
                        return 0;
                    }
            }
            Sleep(150);
            printf("█       █       █       █       █       █\n");
            printf("    █       █       █       █       █       █\n");
        }
    }
}