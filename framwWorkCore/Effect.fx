//--------------------------------------------------------------------------------------
// File: LabProject05.fx
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
cbuffer cbViewProjectionMatrix : register(b0)
{
	matrix		gmtxView : packoffset(c0);
	matrix		gmtxProjection : packoffset(c4);
};

cbuffer cbWorldMatrix : register(b1)
{
	matrix		gmtxWorld : packoffset(c0);
};

//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 position : SV_POSITION;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
float4 VS(float4 position : POSITION) : SV_POSITION
{
    float4 output = (float4)0;
    output = mul(position, gmtxWorld);
    output = mul(output, gmtxView);
    output = mul(output, gmtxProjection);
    return output;
}

VS_OUTPUT VS1(float4 position : POSITION)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    output.position = mul(position, gmtxWorld);
    output.position = mul(output.position, gmtxView);
    output.position = mul(output.position, gmtxProjection);
    return output;
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------

float4 PS(float4 input : SV_POSITION) : SV_Target
{
    return float4(1.0f, 1.0f, 0.0f, 1.0f);    // Yellow, with Alpha = 1
}

float4 PS1(VS_OUTPUT input) : SV_Target
{
    return float4(1.0f, 1.0f, 0.0f, 1.0f);    // Yellow, with Alpha = 1
}

