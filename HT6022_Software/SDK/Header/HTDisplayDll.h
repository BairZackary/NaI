#ifndef _HT_DSO_DISPLAY_H
#define _HT_DSO_DISPLAY_H

#ifndef DLL_API
#define DLL_API extern "C" __declspec(dllimport)
#endif

#define WIN_API __stdcall

DLL_API void WINAPI HTDrawWaveInYT(HDC hDC,RECT Rect,COLORREF clrRGB,
					USHORT nDisType,short* pSrcData,
					ULONG nSrcDataLen,ULONG nDisDataLen,
					ULONG nCenterData,USHORT nDisLeverPos,
					double dbHorizontal,double dbVertical,
					USHORT nYTFormat,ULONG nScanLen);

DLL_API void WINAPI HTDrawWaveInYTVB(HDC hDC,int left,int top,int right, int bottom, USHORT R, USHORT G,
									  USHORT B,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,
									  USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);


#endif