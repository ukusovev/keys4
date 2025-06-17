#include "MainForm.h"
#include <windowsx.h>
#include <string>
#include <sstream>

LRESULT CALLBACK MainFormWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


static MainForm* g_mainForm = nullptr;

MainForm::MainForm() : hwnd(nullptr), hwndQueue(nullptr), hwndHeap(nullptr), hwndTree(nullptr), hwndInput(nullptr), hwndOutput(nullptr) {
    g_mainForm = this;
}

MainForm::~MainForm() {}

void MainForm::Create(HINSTANCE hInstance, int nCmdShow) {

    WNDCLASSW wc = {};
    wc.lpfnWndProc = MainFormWndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"DataStructuresMainForm";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClassW(&wc);


    hwnd = CreateWindowExW(
        0,
        L"DataStructuresMainForm",
        L"Тестирование структур данных",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 400,
        nullptr, nullptr, hInstance, nullptr
    );


    hwndQueue = CreateWindowW(L"BUTTON", L"Очередь", WS_VISIBLE | WS_CHILD, 20, 20, 100, 30, hwnd, (HMENU)1, hInstance, nullptr);
    hwndHeap  = CreateWindowW(L"BUTTON", L"Куча",    WS_VISIBLE | WS_CHILD, 140, 20, 100, 30, hwnd, (HMENU)2, hInstance, nullptr);
    hwndTree  = CreateWindowW(L"BUTTON", L"Дерево",   WS_VISIBLE | WS_CHILD, 260, 20, 100, 30, hwnd, (HMENU)3, hInstance, nullptr);


    hwndInput = CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 70, 220, 25, hwnd, (HMENU)4, hInstance, nullptr);

    
    hwndOutput = CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY | WS_VSCROLL, 20, 110, 540, 220, hwnd, (HMENU)5, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
}

void MainForm::UpdateOutput() {
    std::wstringstream ss;
    ss << L"Очередь: ";
    Queue<int> tmpQ = queue;
    while (!tmpQ.empty()) {
        ss << tmpQ.pop() << L" ";
    }
    ss << L"\r\n";

    ss << L"Куча: ";
    Heap<int> tmpH = heap;
    while (!tmpH.empty()) {
        ss << tmpH.pop() << L" ";
    }
    ss << L"\r\n";

    ss << L"Дерево: ";
    ss << L"(элементов: " << tree.size() << L")";

    SetWindowTextW(hwndOutput, ss.str().c_str());
}

void MainForm::OnCommand(WPARAM wParam) {
    int value = 0;
    wchar_t buf[32] = {0};
    GetWindowTextW(hwndInput, buf, 31);
    value = _wtoi(buf);

    switch (LOWORD(wParam)) {
        case 1: 
            queue.push(value);
            break;
        case 2: 
            heap.push(value);
            break;
        case 3: 
            tree.push(value);
            break;
    }
    UpdateOutput();
}

LRESULT CALLBACK MainFormWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_COMMAND:
        if (g_mainForm) g_mainForm->OnCommand(wParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
} 