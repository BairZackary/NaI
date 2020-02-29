VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "DSO"
   ClientHeight    =   6870
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   11715
   LinkTopic       =   "Form1"
   ScaleHeight     =   6870
   ScaleWidth      =   11715
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton ReadData 
      Caption         =   "Read Data"
      Height          =   495
      Left            =   4440
      TabIndex        =   1
      Top             =   6240
      Width           =   2535
   End
   Begin VB.PictureBox DisplayPicture 
      BackColor       =   &H80000008&
      Height          =   6015
      Left            =   0
      ScaleHeight     =   397
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   781
      TabIndex        =   0
      Top             =   0
      Width           =   11775
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub ReadData_Click()
   Dim nReadLen As Long
   Dim nDrawLen As Long
   Dim nTrigLevel As Integer
   Dim nSlope As Integer
   Dim nHTrigPos As Integer
   Dim nTrigPoint(0) As Long
   Dim nRe As Integer
   
    
    nReadLen = 10240 '10K
    nDrawLen = 10000 '
    nTrigLevel = 64 '
    nSlope = 0 ' 0:Rise; 1: Fall
    nHTrigPos = 50 ' 0 ~ 100
    nTrigPoint(0) = 0 '


    nRe = dsoReadHardData(m_nDevIndex, m_nCH1Data(0), m_nCH2Data(0), nReadLen, m_nCalData(0), m_nCH1VoltDIV, m_nCH2VoltDIV, 0, 0, nTrigLevel, nSlope, m_nTimeDIV, nHTrigPos, nDrawLen, nTrigPoint(0), 0)
    If nRe > 0 Then
        MainForm.DisplayPicture.Cls
        'Draw CH1
         nRe = HTDrawWaveInYTVB(MainForm.DisplayPicture.hDC, 0, 0, MainForm.DisplayPicture.ScaleWidth, MainForm.DisplayPicture.ScaleHeight, 255, 255, 0, 0, m_nCH1Data(0), nReadLen, nDrawLen, nReadLen / 2, 64, 1#, 1#, 0, 0)

    'Draw CH2
         nRe = HTDrawWaveInYTVB(MainForm.DisplayPicture.hDC, 0, 0, MainForm.DisplayPicture.ScaleWidth, MainForm.DisplayPicture.ScaleHeight, 0, 255, 0, 0, m_nCH2Data(0), nReadLen, nDrawLen, nReadLen / 2, 192, 1#, 1#, 0, 0)
    End If
    
End Sub
