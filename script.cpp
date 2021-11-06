#include <Windows.h>
#include <ShlObj.h>


int main ()
{
	CHAR Path [256];
	CHAR Func [256];
	CHAR Title [64];

	// The following is done because the GetPrivateProfile* series of functions assumes that a filename not attached to a path is 
	// in %windir%.

	GetCurrentDirectory(sizeof(Path), Path);
	strcat(Path, "\\progscript.ini");

	int Icon;
	GetPrivateProfileStringA("MessageBox", "Message", NULL, Func, sizeof(Func), Path);
	GetPrivateProfileStringA("MessageBox", "Title", NULL, Title, sizeof(Title), Path);
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