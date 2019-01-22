//
//	Embed resource in a Static Library
//	by Michael Haephrati https://www.codeproject.com/Members/Michael-Haephrati
//	Date :		30 March,2017
//	Updated :	22 January, 2019
//

#include "libMain.h"
#include "XMessageBox.h"
#include "iconStaticData.h"


//	GetIcon()
//	Loads the icon from the static data (s_byIconData)
//	
//	by Michael Haephrati https://www.codeproject.com/Members/Michael-Haephrati
//	Date :		30 March,2017
//	Updated :	22 January, 2019
//

HICON GetIcon()
{
	DWORD dwTmp;
	int offset;
	HANDLE hFile;
	HICON hIcon = NULL;

	offset = LookupIconIdFromDirectoryEx(s_byIconData, TRUE, 0, 0, LR_DEFAULTCOLOR);

	if (offset != 0)
	{
		hIcon = CreateIconFromResourceEx(s_byIconData + offset, 0, TRUE, 0x00030000, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE);
	}

	return hIcon;
}
//	DisplayMessageWithIcon()
//	Displays a MessageBox showing the icon encapsulated in s_byIconData
//	
//	by Michael Haephrati https://www.codeproject.com/Members/Michael-Haephrati
//	Date :		30 March,2017
//	Updated :	22 January, 2019
//	Uses:
//	XMessageBox.cpp  Version 1.10
//
//	Author: Hans Dietrich
//         hdietrich@gmail.com
//

void DisplayMessageWithIcon(LPWSTR message)
{
	XMSGBOXPARAMS xmb;
	xmb.dwOptions |= XMSGBOXPARAMS::RightJustifyButtons;
	xmb.crBackground = RGB(255, 255, 255);
	xmb.crText = RGB(10, 135, 180);
	xmb.nIdIcon = 101;
	xmb.nTimeoutSeconds = 5;
	XMessageBox(NULL,
		message,
		L"Code Project article by Michael Haephrati",
		MB_YESNO, &xmb);
}