Attribute VB_Name = "MainStart"
Sub Main()
    Dim Result As Long
    m_nDevIndex = 0
    m_nCH1VoltDIV = 5
    m_nCH2VoltDIV = 5
    m_nTimeDIV = 14
    
    Result = dsoOpenDevice(m_nDevIndex)
    If Result = 1 Then
    
        Result = dsoGetCalLevel(m_nDevIndex, m_nCalData(0), 32)
        Result = dsoSetVoltDIV(m_nDevIndex, 0, m_nCH1VoltDIV)
        Result = dsoSetVoltDIV(m_nDevIndex, 1, m_nCH2VoltDIV)
        Result = dsoSetTimeDIV(m_nDevIndex, m_nTimeDIV)
    
    End If
    
    MainForm.Show
    
End Sub
