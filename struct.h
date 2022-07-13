#pragma once
#include <d3d12.h>
using namespace DirectX;
#include <DirectXTex.h>


//�RD�I�u�W�F�N�g�^
struct  Object3d
{
	//�萔�o�b�t�@�i�s��p�j
	ID3D12Resource* constBuffTransform;

	//�萔�o�b�t�@�}�b�v�i�s��p�j
	/*ConstBufferDataTransform* constMapTransform;*/

	//�A�t�B���ϊ���@
	XMFLOAT3 scale = { 1,1,1 };

	XMFLOAT3 rotation = { 0,0,0 };

	XMFLOAT3 position = { 0,0,0 };

	//���[���h�ϊ��s��
	XMMATRIX matworld;

	//�e�I�u�W�F�N�g�ւ̃|�C���^
	Object3d* parent = nullptr;
};