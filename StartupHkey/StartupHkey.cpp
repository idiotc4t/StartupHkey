// StartupHkey.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>


BOOL WINAPI RegCurrentUser(PCHAR lpszFileName, PCHAR lpszKeyValue) {
	HKEY hKey;
	if (ERROR_SUCCESS!=RegOpenKeyEx(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_WRITE,&hKey))
	{
		return FALSE;
	}
	if (ERROR_SUCCESS!= RegSetValueEx(hKey,lpszKeyValue,0,REG_SZ,(PBYTE)lpszFileName,1+strlen(lpszFileName)))
	{
		RegCloseKey(hKey);
		return FALSE;
	}
	RegCloseKey(hKey);
}
int  main()
{	
	if (FALSE == RegCurrentUser((PCHAR)"C:\\Windows\\System32\\cmd.exe", (PCHAR)"cmd"))
	{
		MessageBox(0, 0, 0, 0);
	}
}
