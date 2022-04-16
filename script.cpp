#include <Windows.h>
#include <ShlObj.h>


int main ()
{
	CHAR Path [256];
	CHAR Func [256];
	CHAR Title [64];

	// The following is done because the GetPrivateProfile* series of functions assumes that a filename not attached to a path is 
	// in %windir%.

	if (GetCurrentDirectory(sizeof(Path), Path) + strlen("\\progscript.ini") < 256)
	strcat(Path, "\\progscript.ini");
	else
	{
		MessageBox(NULL, "Path is too long!", "Error", MB_ICONHAND);
		return -1;
	}

	int Icon;
	GetPrivateProfileStringA("MessageBox", "Message", "Message not defined", Func, sizeof(Func), Path);
	GetPrivateProfileStringA("MessageBox", "Title", "Title not defined", Title, sizeof(Title), Path);
	Icon = GetPrivateProfileIntA("MessageBox", "Icon", 0, Path);
	
	switch (Icon)
	{
	case MB_ICONEXCLAMATION:
	MessageBox(NULL, Func, Title, MB_ICONEXCLAMATION);
	break;
	case MB_ICONQUESTION: 
	MessageBox(NULL, Func, Title, MB_ICONQUESTION);
	break;
	case MB_ICONHAND: 
	MessageBox(NULL, Func, Title, MB_ICONHAND);
	break;
	case MB_ICONASTERISK: 
	MessageBox(NULL, Func, Title, MB_ICONASTERISK);
	break;
	default:
	MessageBox(NULL, Func, Title, NULL);
	}

	return 0;
}
