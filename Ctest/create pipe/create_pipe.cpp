#include <iostream>
#include <windows.h>
#include <Shlwapi.h>

using namespace std;

#define BUFSIZE 4096

int main()
{
    BOOL bRet = FALSE;
    DWORD dwRead = 0;
    DWORD dwAvail = 0;
    char cbBuf[4096] = { 0 };
    HANDLE hReadPipe = NULL;
    HANDLE hWritePipe = NULL;
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;
    char *pCommandLine = new TCHAR[0x200];//
    char szPath[] = "C:\\Windows\\System32\\calc.exe";
    CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
    STARTUPINFO si = { 0 };
    si.cb = sizeof(STARTUPINFO);
    GetStartupInfo(&si);
    si.wShowWindow = SW_HIDE;
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    si.hStdError = hWritePipe;
    si.hStdOutput = hWritePipe;
    PROCESS_INFORMATION   pi = { 0 };

    memset(pCommandLine, 0, sizeof(szPath));
    lstrcpy(pCommandLine, szPath);

    if (!CreateProcess(NULL, pCommandLine, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))//?�ؤl?�{
    {
        if (pCommandLine)
            delete pCommandLine;

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        CloseHandle(hReadPipe);
        CloseHandle(hWritePipe);

        return 1;
    }
    std::string strResult;
    do
    {
        cout << "test.." << endl;
        if (!PeekNamedPipe(hReadPipe, NULL, NULL, &dwRead, &dwAvail, NULL) || dwAvail <= 0)//PeekNamePipe��???�@?�޹D����?�u�A��?�P?�޹D���O�_?��
        {
             break;
         }
        if (ReadFile(hReadPipe, cbBuf, BUFSIZE, &dwRead, NULL))//?���O?�޹D�A�Y�K�w??��?�u�A���M?���ݱ���?�u�A�]?�A�l?�{???��?�{����?�u�n?�e�A�u�O???�k�e�A
        {                                                        //�ҥH�A?���d���b?���C�ҥH�~�ݭnPeekNamePipe
            if (dwRead == 0)
                break;
            cout << dwRead << endl;
            cout << cbBuf << endl;
        }
    } while (TRUE);

    if (pCommandLine)
        delete pCommandLine;
    cout << "delete" << endl;
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hReadPipe);
    CloseHandle(hWritePipe);

    return 0;
}
