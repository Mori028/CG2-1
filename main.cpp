#include <Windows.h>

//windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�R���\�[���ւ̕����o��
	OutputDebugStringA("Hellow,DirectX!!\n");

	return 0;
}
	//�E�B���h�E�v���V�[�W��
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg) {
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//os�ɑ΂��āA�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}
	//�W�����b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}
//�E�B���h�E�T�C�Y
const int window_widht = 1280;//����
const int window_height = 720;//�c��
//�E�B���h�E�N���X�̐ݒ�
WNDCLASSEX w{};
w.cbSize = sizeof(WNDCLASSEX);//�E�B���h�E�v���V�[�W����ݒ�
w.lpfnWndProc = (WNDPROC)WindowProc;//�E�B���h�E�N���X��
w.lpszClassName = L"DirectXGame";//�E�B���h�E�n���h��
w.hInstance = GetModuleHandle(nullptr);//�J�[�\���w��
w.hCursor = LoadCursor(NULL, IDC_ARROW);

//�E�B���h�E�N���X��OS�ɓo�^����
RegisterClassEx(&w);
//�E�B���h�E�T�C�Y{�@X���W�@Y���W�@�����@�c���@}
RECT wrc = { 0,0,window_width,window_height };
//�����ŃT�C�Y��␳����
AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

//�E�B���h�E�I�u�W�F�N�g�̐���
HWND hwnd = CreateWindow(w.lpszClassName,//�N���X��
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

//�E�B���h�E��\����Ԃɂ���
ShowWindow(hwnd, SW_SHOW);


