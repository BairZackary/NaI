// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 HTMARCH_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// HTMARCH_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef HTMARCH_EXPORTS
#define HTMARCH_API extern "C" __declspec(dllexport)
#else
#define HTMARCH_API extern "C"__declspec(dllimport)
#endif
#define WINAPI __stdcall

HTMARCH_API short WINAPI dsoOpenDevice(WORD DeviceIndex);
HTMARCH_API short WINAPI dsoSetVoltDIV(WORD DeviceIndex,int nCH,int nVoltDIV);
HTMARCH_API short WINAPI dsoSetTimeDIV(WORD DeviceIndex,int nTimeDIV);
HTMARCH_API short WINAPI dsoReadHardData(WORD DeviceIndex,short* pCH1Data, short* pCH2Data,ULONG nReadLen,short* pCalLevel,int nCH1VoltDIV,int nCH2VoltDIV,short nTrigSweep,short nTrigSrc,short nTrigLevel,short nSlope,int nTimeDIV,short nHTrigPos,ULONG nDisLen,ULONG* nTrigPoint,short nInsertMode);
HTMARCH_API WORD WINAPI dsoGetCalLevel(WORD DeviceIndex,short* level,short nLen);
HTMARCH_API short WINAPI dsoCalibrate(WORD nDeviceIndex,int nTimeDIV,int nCH1VoltDIV,int nCH2VoltDIV,short* pCalLevel);
HTMARCH_API WORD WINAPI dsoSetCalLevel(WORD DeviceIndex,short* level,short nLen);
