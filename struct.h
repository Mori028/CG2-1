#pragma once
#include <d3d12.h>


//�RD�I�u�W�F�N�g�^
struct  Object3d
{
	//�萔�o�b�t�@�i�s��p�j
	ID3D12Resource* constBuffTransform;

	//�萔�o�b�t�@�}�b�v�i�s��p�j
	/*ConstBufferDataTransform* constMapTransform;*/

	//�A�t�B���ϊ���@
	XMFLOAT3 scale = { 1,1,1 };

	XMFLOAT3 rotation =
};