_printf: A project by Simon Sun and Chad Calvert.

	 Usage: Prints a formatted string to the standard output in a similar manner to the printf builtin for C, using a buffer size of 1024 bytes.
	 **Be sure to compile with "gcc *.c" or similar**

	 Supported Format Specifiers:

- %c: Print a single character
- %s: Print a character string
- %d: AND %i: Print an integer
- %b: Convert and print a given decimal number to an unsigned binary
- %o: Convert and print a given decimal number to an unsigned octal
- %x: Convert and print a given decimal number to an unsigned hexadecimal
- %X: Same as "%x", but use uppercase letters for "ABCDEF" instead of "abcdef"
- %r: Takes an input string and prints it in reverse
- %R: Prints a string in "rot 13" encryption format, prints all non-letters as normal
- %%: Escapes the % character and simply prints a single "%"

      	  Example:
_printf("%s is a string.", "This");
yields
$ This is a string.
