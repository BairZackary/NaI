Attribute VB_Name = "DeclareFunctions"
'Draw
Public Declare Function HTDrawWaveInYTVB Lib "HTDisplayDll.dll" (ByVal hDC As Long, ByVal Left As Long, ByVal Top As Long, ByVal Right As Long, ByVal Bottom As Long, ByVal R As Integer, ByVal G As Integer, ByVal B As Integer, ByVal nDisTye As Integer, ByRef pData As Integer, ByVal nLen As Long, ByVal nDisLen As Long, ByVal CenterData As Long, ByVal nDisLeverPos As Integer, ByVal Horizontal As Double, ByVal Vertical As Double, ByVal YTFormat As Integer, ByVal AlreadLen As Long) As Long

'Hard
Public Declare Function dsoOpenDevice Lib "HTMarch.dll" (ByVal nDeviceIndex As Integer) As Integer
Public Declare Function dsoSetVoltDIV Lib "HTMarch.dll" (ByVal nDeviceIndex As Integer, ByVal nCH As Long, ByVal nVoltDIV As Long) As Integer
Public Declare Function dsoSetTimeDIV Lib "HTMarch.dll" (ByVal nDeviceIndex As Integer, ByVal nTimeDIV As Long) As Integer
Public Declare Function dsoReadHardData Lib "HTMarch.dll" (ByVal nDeviceIndex As Integer, pCH1Data As Integer, pCH2Data As Integer, ByVal nReadLen As Long, pCalLevel As Integer, ByVal nCH1VoltDIV As Long, ByVal nCH2VoltDIV As Long, ByVal nTrigSweep As Integer, ByVal nTrigSrc As Integer, ByVal nTrigLevel As Integer, ByVal nSlope As Integer, ByVal nTimeDIV As Long, ByVal nHTrigPos As Integer, ByVal nDisLen As Long, nTrigPoint As Long, ByVal nInsertMode As Integer) As Integer
Public Declare Function dsoGetCalLevel Lib "HTMarch.dll" (ByVal nDeviceIndex As Integer, level As Integer, ByVal nLen As Integer) As Integer
