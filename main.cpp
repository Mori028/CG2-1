#include <Windows.h>

//windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//コンソールへの文字出力
	OutputDebugStringA("Hellow,DirectX!!\n");

	return 0;
}
	//ウィンドウプロシージャ
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	//メッセージに応じてゲーム固有の処理を行う
	switch (msg) {
		//ウィンドウが破棄された
	case WM_DESTROY:
		//osに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	//標準メッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}
//ウィンドウサイズ
const int window_widht = 1280;//横幅
const int window_height = 720;//縦幅
//ウィンドウクラスの設定
WNDCLASSEX w{};
w.cbSize = sizeof(WNDCLASSEX);//ウィンドウプロシージャを設定
w.lpfnWndProc = (WNDPROC)WindowProc;//ウィンドウクラス名
w.lpszClassName = L"DirectXGame";//ウィンドウハンドル
w.hInstance = GetModuleHandle(nullptr);//カーソル指定
w.hCursor = LoadCursor(NULL, IDC_ARROW);

//ウィンドウクラスをOSに登録する
RegisterClassEx(&w);
//ウィンドウサイズ{　X座標　Y座標　横幅　縦幅　}
RECT wrc = { 0,0,window_width,window_height };
//自動でサイズを補正する
AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

//ウィンドウオブジェクトの生成
HWND hwnd = CreateWindow(w.lpszClassName,//クラス名
	L"DirectXGame",
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	wrc.right - wrc.left,
	wrc.bottom - wrc.top,
	nullptr,
	nullptr,
	w.hInstance,
	nullptr);

//ウィンドウを表示状態にする
ShowWindow(hwnd, SW_SHOW);


