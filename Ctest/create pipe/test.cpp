    HANDLE hRead,hWrite;
    SECURITY_ATTRIBUTES sa;    
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);    
    sa.lpSecurityDescriptor = NULL; //�ϥΨt?�q?���w���y�z��    
    sa.bInheritHandle = TRUE; //?�ت�?�{?�ӥy�`

    if (!CreatePipe(&hRead,&hWrite,&sa,0)) //?�ذΦW�޹D
    {        
        MessageBox("CreatePipe Failed!","����",MB_OK | MB_ICONWARNING);        
        return;
    }

    STARTUPINFO si;    
    PROCESS_INFORMATION pi;

    ZeroMemory(&si,sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);    
    GetStartupInfo(&si);    
    si.hStdError = hWrite;    
    si.hStdOutput = hWrite;    //�s?��?�{��?��?�X?�b?�޹D�@��
    si.wShowWindow = SW_HIDE; //?�õ��f    
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;


    char cmdline[200]; 
    CString tmp,stredit2;
    GetDlgItemText(IDC_EDIT2,stredit2); //?��??�ؤ�?�J���R�O��
    tmp.Format("cmd /C %s",stredit2);
    sprintf(cmdline,"%s",tmp);

    if (!CreateProcess(NULL,cmdline,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi)) //?�ؤl?�{
    {
        MessageBox("CreateProcess Failed!","����",MB_OK | MB_ICONWARNING);        
        return;
    }
    CloseHandle(hWrite); //??�޹D�y�`

    char buffer[4096] = {0};
    CString strOutput;
    DWORD bytesRead;

    while (true) 
    {
        if (ReadFile(hRead,buffer,4095,&bytesRead,NULL) == NULL) //?���޹D
            break;

        strOutput += buffer;
        SetDlgItemText(IDC_EDIT1,strOutput); //?��?�X�H����??��,�}��s���f
        UpdateWindow();
        Sleep(100);
    }
    CloseHandle(hRead);

