#pragma once
#include <Windows.h>
#include <CommCtrl.h>
#include <string>
#include <vector>
#include "src/queue.h"
#include "src/heap.h"
#include "src/binary_tree.h"

class MainForm {
public:
    MainForm();
    ~MainForm();

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    void Create(HINSTANCE hInstance, int nCmdShow);
    void UpdateOutput();
    void OnCommand(WPARAM wParam);

private:
    HWND hwnd;
    HWND hwndQueue;
    HWND hwndHeap;
    HWND hwndTree;
    HWND hwndInput;
    HWND hwndOutput;

    Queue<int> queue;
    Heap<int> heap;
    BinaryTree<int> tree;

    void InitializeControls();
}; 