//float4 main(float4 pos : POSITION) : SV_POSITION
//{
//    return pos * float4(1.0f, 1.0f, 1, 1);
//}
#include "Basic.hlsli"

VSOutput main(float4 pos : POSITION, float2 uv : TEXCOORD)
{
    VSOutput output;//ピクセルシェーダーに渡す値
    /*output.svpos = pos;*/
    output.svpos = mul(mat, pos); // 座標に行列を乗算
    output.uv = uv;
    return output;
}