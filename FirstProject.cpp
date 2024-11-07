#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS WndClass; // 윈도우 클래스 구조체
    HWND hwnd; // 윈도우 핸들
    MSG msg; // 메세지 구조체

    // 윈도우 클래스 초기화와 등록
    WndClass.style = CS_HREDRAW | CS_VREDRAW; // 클래스 스타일
    WndClass.lpfnWndProc = WinProc; // 윈도우 프로시저
    WndClass.cbClsExtra = 0; // 윈도우 클래스 데이터 영역
    WndClass.cbWndExtra = 0; // 윈도우의 데이터 영역
    WndClass.hInstance = hInstance; //  인스턴스 핸들
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = TEXT("MouseClass");

    if (!RegisterClass(&WndClass)) {
        MessageBox(NULL, TEXT("윈도우 클래스 등록 실패!"), TEXT("오류"), MB_OK | MB_ICONERROR);
        return 1;
    }

    // 윈도우 생성
    hwnd = CreateWindow( // 윈도우생성 API함수
        TEXT("MouseClass"), // 등록된 윈도우 클래스 이름
        TEXT("MouseSDK"), // 타이틀바에 출력될 문자
        WS_OVERLAPPEDWINDOW, // 윈도우 스타일
        CW_USEDEFAULT, // 윈도우 좌측 상단의 x좌표
        CW_USEDEFAULT, // 윈도우 좌측 상단의 y좌표
        CW_USEDEFAULT, // 윈도우의 너비
        CW_USEDEFAULT, // 윈도우의 높이
        NULL, // 부모 윈도우의 핸들
        NULL, // 메뉴 또는 자식 윈도우의 핸들
        hInstance, // 어플리케이션 인스턴스 핸들
        NULL // 윈도우 생성 데이터의 주소
    );

    ShowWindow(hwnd, nCmdShow);

    // 메세지 루프
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// 윈도우 프로시저
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; // 디바이스 프로시저
    PAINTSTRUCT ps; // 페인트 구조체
    TCHAR str1[200] = TEXT("마우스를 클릭하세요");
    TCHAR str2[200] = TEXT("오른쪽 마우스 / 왼쪽 마우스를 클릭하시면 메시지 상자가 나타납니다.");

    switch (message) { //커널에서 들어온 메세지를 switch 문으로 처리
    case WM_CREATE:
        return 0;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd, TEXT("왼쪽 마우스를 클릭하셨습니다."), TEXT("왼쪽 마우스 클릭!"), MB_OK);
        return 0;
    case WM_RBUTTONDOWN:
        MessageBox(hwnd, TEXT("오른쪽 마우스를 클릭하셨습니다."), TEXT("오른쪽 마우스 클릭!"), MB_OK);
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        TextOut(hdc, 100, 100, str1, lstrlen(str1));
        TextOut(hdc, 100, 200, str2, lstrlen(str2));
        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

// RESULT : https://github.com/Hancho0/1-study/blob/main/%EA%B2%B0%EA%B3%BC

-----

#include "stdafx.h": 미리 컴파일된 헤더 파일, 프로젝트 속도 최적화를 위해 사용
#include <Windows.h>: Windows API 함수들을 사용하기 위한 헤더
#include <tchar.h>: 유니코드 및 멀티바이트 문자 처리를 위한 헤더

LRESULT CALLBACK WinProc(...): 이 함수는 윈도우에서 발생하는 이벤트(클릭, 창 닫기 등)를 처리하기 위한 콜백 함수로 정의

.WinMain(...): 모든 Windows 애플리케이션의 진입점 함수, 콘솔 프로그램의 main() 함수와 비슷하다.
hInstance: 현재 애플리케이션의 인스턴스 핸들
hPrevInstance: 이전 인스턴스 핸들이며, 현재는 사용되지 않는다.
lpCmdLine: 명령줄 인수
nCmdShow: 윈도우 창이 처음 보여질 때의 상태(최소화, 최대화 등)

WNDCLASS WndClass: 윈도우 클래스를 정의하는 구조체, 창의 속성을 설정하는 데 사용
HWND hwnd: 창의 핸들(참조값)
MSG msg: 메시지 구조체, 메시지 루프에서 사용할 메시지를 저장하는 데 사용

WndClass.style = CS_HREDRAW | CS_VREDRAW: 창을 가로 또는 세로로 다시 그릴 때 윈도우를 다시 그리도록 설정
WndClass.lpfnWndProc = WinProc: 이벤트를 처리할 함수(이 경우 WinProc)를 설정
WndClass.cbClsExtra와 WndClass.cbWndExtra: 추가 메모리 공간을 설정하는 값으로 보통 0으로 설정
WndClass.hInstance = hInstance: 현재 애플리케이션 인스턴스를 설정
WndClass.hIcon: 창 아이콘을 설정
WndClass.hCursor: 커서를 설정
WndClass.hbrBackground: 창의 배경색을 흰색으로 설정
WndClass.lpszMenuName = NULL: 메뉴가 없으므로 NULL로 설정
WndClass.lpszClassName: 윈도우 클래스 이름을 "MouseClass"로 설정

RegisterClass(&WndClass): 윈도우 클래스를 등록하여 창을 만들 준비, 등록 실패 시 1을 반환

CreateWindow(...): 윈도우 창을 생성하는 함수
"MouseClass": 이전에 등록한 클래스 이름
"MouseSDK": 창의 제목
WS_OVERLAPPEDWINDOW: 기본 창 스타일
CW_USEDEFAULT: 기본 위치와 크기를 사용

ShowWindow(...): 생성된 창을 화면에 보여주는 함수

GetMessage는 메시지가 발생할 때까지 대기하고, 발생한 메시지를 처리
TranslateMessage: 키보드 메시지를 추가로 처리
DispatchMessage: WinProc 함수로 메시지를 전달하여 실제 처리

return msg.wParam: 프로그램 종료 시 반환되는 코드

WM_DESTROY: 창이 닫힐 때 발생하는 메시지, PostQuitMessage(0)을 호출하여 프로그램을 종료

return DefWindowProc(hwnd, message, wParam, lParam): 처리되지 않은 메시지는 기본 처리 함수인 DefWindowProc로 전달
