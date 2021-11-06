# messagebox_ini_scripter
Basic INI-based scripter that produces MessageBox-es.

This is a very lightweight win32 application that uses the following syntax to produce a MessageBox:

<pre><code>
[MessageBox]
Title=Title goes here
Message=Message goes here
Icon=integer goes here (as expressed in the MSDN documentation, 16 for critical error, 32 for question mark, 48 for caution and 64 for "information"/asterisk)
</code></pre>


Four ANSI functions are called, and the binary is compiled using VC++ 2010 using a modified linker that outputs a SubsystemVersion of 3.10. It should work on all
Windows NT and Windows 9x, and possibly Win32s. At present it has only been tested on Windows Vista.
