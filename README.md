# 1주차 Study [ 2024-11-07 ~ 2024-11-08 ]

**[ 목표 ]**
- 이번주 목표 : C++ MFC 개요에 대해 알기, 마우스 클릭 프로그램 제작, 이론 복습

- 2주차 목표 : 메세지 박스 프로그램 제작, 시간/날짜 프로그램 제작, [ 혼자 공부하는 C ] 복습하기

-----

**[ 진행 사항 ]**

- C++ 언어

C++ 언어는 C언어를 확장한 언어로서, 객체 지향의 대표적인 프로그래밍 언어이다.

C++ 언어는 시스템프로그램과 응용프로그램 분야에서 호환성을 가지는 C 언어의 장점과 객체지향 속성을 가지는 언어로서 다양한 분아야에서 사용 될 수 있다.

- 객체 지향 언어 특징
[ 추상화 ] : 객체(Class)가 가지는 공통적인 속성과 기능을 추출해내는 역할을 하는, **클래스를 정의**하는 과정이다.
[ 상속성 ] : 클래스가 이미 정의된 것을 **다시 정의하지 않더라도 다른 멤버 변수나 멤버 함수에서 사용할 수 있는 것을 의미**하는데, 상속받은 객체는 쉽게 유지보수가 가능하다.
[ 캡슐화 ] : **안전과 보안에 대한 것으로서 데이터를 관리하는 함수가 하나의 묶음**으로 사용해서 객체는 독립적으로 활용되는 것을 의미한다.
[ 다형성 ] : **재정의와 상속을 이용하여 다양한 객체를 처리할 수 있는 특징**을 가진다.
[ 정보은닉 ] : **캡슐화와 유사한 것으로 외부에 필요 없이 정보를 노출시키지 않는 것이다.** 정보은닉은 다른 객체에서 발생되는 **훼손을 방지**할 수 있고, **추가된 기능에 대해 유연하게 대처함**으로서 유연상과 확장성을 높일 수 있다.

- 윈도우 프로그램 특징

윈도우 기반 프로그램은 **GUI(Graphic User Interface: 그래픽 사용자 인터페이스)** 를 기반으로 시각적인 인터페이스를 제공한다. 윈도우 프로그램의 특징은 여러 가지 프로그램을 동시에 실행 시킬 수 있는 **멀티태스킹(Multitasking)** 과 하나의 프로그램을 동시에 여러가지 기능을 실행 할 수 있도록 프로세스를 여러 수행 단위(Thread)로 나누어 처리할 수 있는 **멀티스레딩(Multi-Threading) 기능**을 가진다.

윈도우 프로그램은 **API 기반 프로그래밍**과 **MFC 기반 프로그래밍**으로 크게 구분된다

[ API 기반 프로그래밍 ]
- Application Programming Interface 의 약어
- 윈도우 환경 프로그램 개발 위해 윈도우 내에 포함된 내부 코드를 가져와 프로그램 개발에 활용하는 프로그래밍 기법
- API에서는 개발자들이 버튼, 아이콘과 같이 모든 속성을 직접 설정하고 제어 가능하다.
- API에서는 필요한 부분만 만들어서 사용할 수 있기 때문에, 코딩의 양을 크게 감소시킬 수 있는 장점이 있다.

[ MFC 기반 프로그래밍 ]
- Microsoft Foundation Class의 약어
- 개발자들이 윈도우 PAI를 좀 더 쉽게 접근하기 위해서 제공되는 함수의 집합
- 클래스 라이브러리를 사용하는 MFC는 윈도우 기능이 복잡해짐에 따라서 API를 직접 이용하는 것보다, 편하게 프로그래밍을 할 수 있는 장점때문에 사실상 윈도우 프로그래밍을 위한 클래스 라이브러리의 표준이 되었다.
- 내부적으로는 윈도우 API 함수를 사용하지만, **C++ 클래스 라이브러리의 집합체**로서 최적의 인터페이스를 제공받을 수 있는 언어이다.
- 운영체제의 확장된 프로그램을 생성하는데 편리한 클래스를 제공할 뿐만 아니라, 문자열 처리, 날짜, 시간 등과 같은 다양한 클래스를 제공한다.
- 그러므로 MFC는 간편하게 응용프로그램을 생성함으로서 개발 시간을 단축시킬 수 있다.

- MFC의 구조

[ MFC 프로그램의 구성 ]
MFC 프로그램은 크게 **단일 윈도우(SDI: Single Documnet InterFace)** 와 **다중 윈도우(MDI: Multiple Document Interface)** 로 나눌 수 있다. SDI는 단일 윈도우로 표현하는데 사용되며 CWinApp, CFrameWnd, CDocument, Cview 4개의 클래스로 구성되어 있다. 여러 개의 윈도우 창을 생성할 수 있는 MDI는 CwinApp, CMDIFrameWnd, CMDIChildWnd, CDocument, CView로 구성되어 있고, 사용자가 특별한 인터페이스 구성 요구 시 주로 많이 사용된다.

[ MFC 구성도 ]
MFC 클래스 간의 계층관계가 성립하는데, **기반 클래스(Base Class)** 와 **파생 클래스(Derived Class)** 로 구분한다.

MFC 기반 클래스는 **CObject, CCmdTarget, CWinApp, CWnd, CDocument, CDOCTemplate** 이다.

---

* CObject

MFC의 최상위 클래스로서 메모리 클래스를 설정하는 기능을 가진 기본 클래스이다. 대부분의 클래스는 이 클래스로부터 파생된다. 프로그램 실행 중 객체 정보를 알아내서, 객체 상태를 점검한다.

---

* CCmdTarget

명령 관련 클래스로서 윈도우 메시지 응답을 위한 기본 클래스이다.

---

* CWinApp

프로그램 시작/종료를 제어하고, 프로그램 전체를 대표한는 클래스로서 윈도우 application을 생성하는 기본 클래스이다.

---

* CWnd

WIndow Object를 클래스로 구현한 것으로 윈도의 크기, 위치, 모양 등의 상태를 제어하거나 윈도우 메시지를 처리하는 클래스이다.

---

* CDocument

파일로 부터 데이터를 읽고/저장하는 기능과 새로운 데이터를 생성/수정 변경 처리하는 클래스로서, 주로 데이터의 입출력에 관련된 클래스이다.

---

* CDocTemplate

Document Template에 대한 기본 클래스로서, 단일 문서에 관련된 CSingleDocTemplate와 다중 문서와 관련된 CMultiDocTemplate가 있다.

---

* CFrameWnd

윈도우 클래스로서 윈도우 괴각 경계를 정의하는 클래스이고, CWnd에서 클래스를 상속받아 윈도우 메시지를 처리한다.

---

* Cdialog

다이얼로그를 생성하거나 다이얼로그를 가진 컨트롤과 멤버 변수 사이의 데이터 교환하는 클래스이다.

---

* CView

작업영역을 나타내는 클래스로서 데이터를 화면에 보일 수 있도록 처리하는 클래스이다.

-----

**[ 진행 사항 , 진행중 문제 발생 ]**

https://github.com/Hancho0/1-study/blob/main/FirstProject.cpp

위 코드에서 생각 하는 핵심 코드는

1. 윈도우 클래스 등록과 생성

WNDCLASS WndClass;
WndClass.style = CS_HREDRAW | CS_VREDRAW;
WndClass.lpfnWndProc = WinProc;
WndClass.hInstance = hInstance;
WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
WndClass.lpszClassName = TEXT("MouseClass");

if (!RegisterClass(&WndClass))
    return 1;

hwnd = CreateWindow(
    TEXT("MouseClass"),
    TEXT("MouseSDK"),
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    NULL, NULL, hInstance, NULL
);
ShowWindow(hwnd, nCmdShow);

윈도우 클래스 등록 하고
CreateWindow 함수로 윈도우를 생성하고 ShowWindow로 화면에 표시하기에 핵심코드라고 생각합니다.

2. 메세지 루프

while (GetMessage(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}

윈도우가 생성된 후, 프로그램은 메세지 루프를 통해 윈도우가 종료 될때 까지 사용지 입력 이벤트를 처리함으로써 핵심코드라고 생각합니다.

3. 윈도우 프로시저(핸들링 함수) - WinProc

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_LBUTTONDOWN:
            MessageBox(hwnd, TEXT("왼쪽 마우스를 클릭하셨습니다."), TEXT("왼쪽 마우스 클릭!"), MB_OK);
            return 0;
        case WM_RBUTTONDOWN:
            MessageBox(hwnd, TEXT("오른쪽 마우스를 클릭하셨습니다."), TEXT("오른쪽 마우스 클릭!"), MB_OK);
            return 0;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            TextOut(hdc, 100, 100, str1, lstrlen(str1));
            TextOut(hdc, 100, 130, str2, lstrlen(str2));
            EndPaint(hwnd, &ps);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}

마우스 왼쪽 / 오른쪽 클릭 이벤트 처리하며 MessageBox를 통해서 출력되는 코드로써
WM_PAINT를 활용하여 왼도우를 그릴 때 호출되는 TextOut을 이용해 텍스트를 화면에 출력하고
WM_DESTORY 를 이용해 윈도우 종료 시 호출하며, PostQuitMessage로 프로그램을 종료함으로써
핵심 코드 라고 생각합니다.

[ 오류 발생 ]
https://github.com/Hancho0/1-study/blob/main/오류.png

WndProc가 선언되지 않는 식별자라는 오류가 발생하여 코드를 확인해보니

TextOut(hdc, 100, 100, str1, lstrlen(str1));
TextOut(hdc, 100, 130, str1, lstrlen(str2));
실수로 붙여넣기 한 후 수정을 제대로 하지 못해 WndProc가 올바르게 작동하지 못하여 선언되지 못하였다고 떴습니다.

그래서 
TextOut(hdc, 100, 100, str1, lstrlen(str1));
TextOut(hdc, 100, 130, str2, lstrlen(str2));
코드를 올바르게 수정해서 정상적으로 작동 되었습니다.

그리고 #include "stdafx.h"가 정상적으로 헤더파일 인식이 안되어
Visual Studio 에서 "미리 컴파일된 헤더" 를 사용으로 변경해줬으며
추가로 stdafx.cpp 파일에서 #include "stdafx.h"를 넣어주고 "미리 컴파일된 헤더"를 만들기로 설정해준후 헤더 파일에 stdafx.h를 추가해줬으며 내부에는
#pragma once

#include <Windows.h>
#include <tchar.h>
코드를 넣어줬더니 #include "stdafx.h" 이 정상적으로 헤더파일로 인식되었습니다.

-----

**[ 이번 Study를 통해 느낀점 ]**

조금 복잡하다고 생각한 코드를 직접 다뤄보면서 C++에 대한 이론에 대해 공부를 해보니, 어려웠지만 흥미롭게 받아들였습니다. 1주차 개발공부이지만 부족한 모습이 보여서 추가적인 개인적인 독학 공부가 더 필요하다고 느꼈으며, 반복적인 복습 및 모르는 코드에 대해 좀더 딥하게 공부하고 싶다는 생각이 들었습니다. C++은 이번에 처음 다뤄보지만 재밌게 배워보는 시간이었습니다. 주말에 남는 시간에 여기저기 블로그를 참고하면서 좀더 즐거운 공부하는 시간을 가지고 싶다는 생각이 들었습니다. 저에대해 좀더 알아가보는 시간이었으며 개인적인 개발역량을 늘릴려면 좀더 반복적인 복습이 필요하다는 생각이 들었습니다.
