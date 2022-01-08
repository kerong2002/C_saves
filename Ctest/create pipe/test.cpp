    HANDLE hRead,hWrite;
    SECURITY_ATTRIBUTES sa;    
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);    
    sa.lpSecurityDescriptor = NULL; //使用系?默?的安全描述符    
    sa.bInheritHandle = TRUE; //?建的?程?承句柄

    if (!CreatePipe(&hRead,&hWrite,&sa,0)) //?建匿名管道
    {        
        MessageBox("CreatePipe Failed!","提示",MB_OK | MB_ICONWARNING);        
        return;
    }

    STARTUPINFO si;    
    PROCESS_INFORMATION pi;

    ZeroMemory(&si,sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);    
    GetStartupInfo(&si);    
    si.hStdError = hWrite;    
    si.hStdOutput = hWrite;    //新?建?程的?准?出?在?管道一端
    si.wShowWindow = SW_HIDE; //?藏窗口    
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;


    char cmdline[200]; 
    CString tmp,stredit2;
    GetDlgItemText(IDC_EDIT2,stredit2); //?取??框中?入的命令行
    tmp.Format("cmd /C %s",stredit2);
    sprintf(cmdline,"%s",tmp);

    if (!CreateProcess(NULL,cmdline,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi)) //?建子?程
    {
        MessageBox("CreateProcess Failed!","提示",MB_OK | MB_ICONWARNING);        
        return;
    }
    CloseHandle(hWrite); //??管道句柄

    char buffer[4096] = {0};
    CString strOutput;
    DWORD bytesRead;

    while (true) 
    {
        if (ReadFile(hRead,buffer,4095,&bytesRead,NULL) == NULL) //?取管道
            break;

        strOutput += buffer;
        SetDlgItemText(IDC_EDIT1,strOutput); //?示?出信息到??框,并刷新窗口
        UpdateWindow();
        Sleep(100);
    }
    CloseHandle(hRead);

