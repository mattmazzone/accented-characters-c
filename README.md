# Manipulating Accented Characters
Outputting accented characters to the console is something that should be avoided. However, if you absolutely need to, this is how.

On a Windows machine, manipulating accented characters is pretty tricky because Windows doesn't natively support them in the console (Supported on UNIX systems).
To be able to view accented characters, you need to set your debug console font to Lucida or similar a similar font with support for accents.

## Using Wide Characters 
In C++ a string is an array of char. This means that an array of wide char (wchar_t) is a wide string (wstring). Wide characters inherit functions from their base class. However, when performing certain operations, we need to specify that we are using wide characters. For example, reading and writing to files keywords (ifstream & ofstream) have a wide character specific implementation (wifstream & wofstream). Also, input and output to console keywords (cin & cout) will change (wcin & wcout).

To learn more about wide characters see this link: https://stackoverflow.com/a/402918

