#pragma once
#include <d3d12.h>


//３Dオブジェクト型
struct  Object3d
{
	//定数バッファ（行列用）
	ID3D12Resource* constBuffTransform;

	//定数バッファマップ（行列用）
	/*ConstBufferDataTransform* constMapTransform;*/

	//アフィン変換情法
	XMFLOAT3 scale = { 1,1,1 };

	XMFLOAT3 rotation =
};