#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <windowsx.h>
#include <gl/GL.h>
#include <gl/GLU.h>
// #include <gl/glaux.h>

float angle = 0.0f;
HDC  g_HDC;

void SetupPixelFormat(HDC hDC)
{
    int  nPixelFormat;

    static PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,
        0,
        0,
        0,0,0,0,
        16,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0 };

    nPixelFormat = ChoosePixelFormat(hDC, &pfd);

    SetPixelFormat(hDC, nPixelFormat, &pfd);    
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    static HGLRC hRC;
    static HDC hDC;
    char string[] = "hello world!";
    int width, height;

    switch (message)
    {
        case WM_CREATE:
            hDC = GetDC(hwnd);
            g_HDC = hDC;
            SetupPixelFormat(hDC);

            hRC = wglCreateContext(hDC);
            wglMakeCurrent(hDC, hRC);

            return 0;
            break;
        case WM_CLOSE:
            wglMakeCurrent(hDC, NULL);
            wglDeleteContext(hRC);

            PostQuitMessage(0);

            return 0;
            break;
        case WM_SIZE:
            height = HIWORD(lParam);
            width = LOWORD(lParam);

            if (height == 0)
            {
                height = 1;
            }
            
            glViewport(0, 0, width, height);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            return 0;
            break;
            /*
        case WM_PAINT:
            hDC = BeginPaint(hwnd, &ps);

            SetTextColor(hDC, COLORREF(0x00FF0000));

            TextOut(hDC, 150, 150, string, sizeof(string) - 1);

            EndPaint(hwnd, &ps);

            return 0;
            break;
        case WM_DESTROY:
            wglMakeCurrent(hDC, NULL);
            wglDeleteContext(hRC);
            PostQuitMessage(0);
            break;
            */
        default:
            break;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASSEX windowClass;
    HWND hwnd;
    MSG msg;
    bool done;

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.hInstance = hInstance;
    windowClass.lpfnWndProc = WndProc;
    windowClass.style = CS_VREDRAW | CS_HREDRAW; 
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = NULL;
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = "MyClass";

    if(!RegisterClassEx(&windowClass))
        return 0;

    hwnd = CreateWindowEx(NULL,
        "MyClass",
        "The OpenGL Window Application",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
        100, 100,
        400, 400,
        NULL,
        NULL,
        hInstance,
        NULL);
    
    if (!hwnd)
        return 0;
    
    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    done = false;

    //MessageBox(NULL, "\tHello, World!!!", "My first Windows Application GameDev.net", NULL);
    while (!done)
    {
        PeekMessage(&msg, hwnd, NULL, NULL, PM_REMOVE);
        //GetMessage(&msg, hwnd, NULL, NULL);
        
        if (msg.message == WM_QUIT)
        {
            done = true;
        }
        else
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            angle += 0.9f;
            if (angle >= 360.0f)
                angle = 0.0f;
            glTranslatef(0.0f, 0.0f, -5.0f);
            glRotated(angle, 0.0f, 0.0f, 1.0f);

            glColor3f(1.0f, 0.0f, 0.0f);
            glBegin(GL_TRIANGLES);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(1.0f, 0.0f, 0.0f);
                glVertex3f(1.0f, 1.0f, 0.0f);
            glEnd();

            SwapBuffers(g_HDC);

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return msg.wParam;
}