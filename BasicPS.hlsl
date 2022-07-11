//float4 main() : SV_TARGET
//{
//	return float4(0.5f, 0.55f, 0.5f, 1.0f);
//}
//cbuffer ConstBufferDataMaterial : register(b0)
//{
//    float4 color; // 色(RGBA)
//};
//float4 main() : SV_TARGET
//{
//    return color;
//}
//#include "Basic.hlsli"
//
//float4 main(VSOutput input) : SV_TARGET
//{
//    return float4(input.uv, 0, 1);
//}
#include "Basic.hlsli"

Texture2D<float4> tex : register(t0);  	// 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0);      	// 0番スロットに設定されたサンプラー

float4 main(VSOutput input) : SV_TARGET{
    /*return float4(tex.Sample(smp, input.uv)) * color;*/
    float4 texcolor = float4(tex.Sample(smp, input.uv));
    //return float4(input.normal, 1);//RGBをそれぞれ法線のXYZ,Aを1で出力
    /*return float4(1,1,1,1);*/
    float3 light = normalize(float3(1,-1,1));//右下奥　向きのライト
    float diffuse = saturate(dot(-light, input.normal));
    float brightness = diffuse + 0.3f;//光源へのベクトルと法線ベクトルの内積
    return float4(texcolor.rgb * brightness, texcolor.a) * color;//輝度をRGBに代入して出力
}
