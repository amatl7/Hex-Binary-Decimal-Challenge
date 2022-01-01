#include <stdio.h>

//DID extra credit 100% not the extra 50%

//Replacement for math module of taking a number to a power.
int to_power(int orig_num, int power)
{
	//once power is zero, base case triggers as no more multiplication is necessary
	if (power == 0){
		return 1;
	}
	if (power > 1)
	{
		//recursively continues multiplication
		return orig_num * to_power(orig_num, power - 1);
	} else {
		return orig_num;
	}
}

//uses C-string logic in order to get the number of elements in a C-String
int arr_size(char *arr, int indx = 0){
	//if not at end of C-string
	if (arr[indx] != 0)
	{
		//continues to add one to the return value
		return 1 + arr_size(arr, indx + 1);
	} else
	{
		//base case
		return 0;
	}
}

//converts binary numbers to integers numbers
int bin_to_int(char *bin, int arr_len, int indx = 0)
{
	//before it hits the end of the array
	if (indx < arr_len) 
	{
		//formula for converting binary to integer
		//adding 2 to the power of the digit place times the binary digit
		return (((int)bin[indx] - 48) * to_power(2, arr_len - 1 - indx) + 
			bin_to_int(bin, arr_len, indx + 1));
	} else
	{
		//base case
		return 0;
	}
}

//converts hexadecimal numbers to integers numbers
int hex_to_int(char *hex, int arr_len, int indx = 0)
{
	//before it hits the end of the array
	if (indx < arr_len) 
	{
		//if statements comparing to a-f according to rules of hexadecimal conversion
		//10 times 16 to the power of the digit place then calling function at next index
		if (hex[indx] == 'A' || hex[indx] == 'a')
		{
			return (10 * to_power(16, arr_len - 1 - indx)
		 + hex_to_int(hex, arr_len, indx + 1));
		} else if (hex[indx] == 'B' || hex[indx] == 'b')
		{
			return (11 * to_power(16, arr_len - 1 - indx)
		 + hex_to_int(hex, arr_len, indx + 1));
		} else if (hex[indx] == 'C' || hex[indx] == 'c'){
			return (12 * to_power(16, arr_len - 1 - indx)
		 + hex_to_int(hex, arr_len, indx + 1));
		} else if (hex[indx] == 'D' || hex[indx] == 'd'){
			return (13 * to_power(16, arr_len - 1 - indx)
		 + hex_to_int(hex, arr_len, indx + 1));
		} else if (hex[indx] == 'E' || hex[indx] == 'e'){
			return (14 * to_power(16, arr_len - 1 - indx)
		 + hex_to_int(hex, arr_len, indx + 1));
		} else if (hex[indx] == 'F' || hex[indx] == 'f'){
			return (15 * to_power(16, arr_len - 1 - indx)
		 + hex_to_int(hex, arr_len, indx + 1));
		} else {
			return (((int)hex[indx] - 48) * to_power(16, arr_len - 1 - indx)
			 + hex_to_int(hex, arr_len, indx + 1));
		}
	} else 
	{
		//base case
		return 0;
	}
}

//converting integer to binary and printing it out
int output_bin(int num)
{
	//repeating until number decreases to zero
	if (num > 0) 
	{
		//recalling function
		output_bin(num / 2);
		//printing number based on remainder
		if (num % 2 == 0){
			putchar('0');
		} else {
			putchar('1');
		}
	} else 
	{
		//base case
		return 0;
	}
	//function error terminator
	return 0;
}

//converting integer to hexadecimal and printing it out
int output_hex(int num){
	//repeating until number decreases to zero
	if (num > 0)
	{
		output_hex(num / 16);
		if (num % 16 == 15){
			putchar('f');
		} else if (num % 16 == 14){
			putchar('e');
		} else if (num % 16 == 13){
			putchar('d');
		} else if (num % 16 == 12){
			putchar('c');
		} else if (num % 16 == 11){
			putchar('b');
		} else if (num % 16 == 10){
			putchar('a');
		} else {
			putchar((char)(48 + (num % 16)));
		}
	} else {
		//base case
		return 0;
	}
	//funciton error terminator
	return 0;
}

//prints an array of characters
void print_arr(char *ans, int arr_size, int indx = 0){
	//before indx hits end of array
	if (indx < arr_size){
		//outputs character then reruns
		putchar(ans[indx]);
		print_arr(ans, arr_size, indx + 1);
	}
}

//prints variables of type integer
void print_int(int integer){
	//repeating until number decreses to zero
	if (integer > 0){
		//re runs and then outputs character
		print_int(integer / 10);
		putchar((char)(integer % 10 + 48));
	
	}
}

//converts an array of characters into an integer number
int to_int(char *arr, int arr_len, int indx = 0){
	//before indx hits the end of array
	if (indx < arr_len){
		//number time 10 to the power of the units place plus the function run
		//at the next index
		return (((int)arr[indx] - 48) * to_power(10, arr_len - 1 - indx)) 
		+ to_int(arr, arr_len, indx + 1);
	} else {
		//base case
		return 0;
	}
}

//prints string by processing it as an array of characters
void print_string(char arr[]){
	if (*arr == 0){
		return;
	}
	putchar(*arr);
	arr++;
	print_string(arr);
}

//simply prints desired message character by character
void print_message(char *arr)
{
	print_string("Usage: ");
	//prints specific case
	print_arr(arr, arr_size(arr));
	print_string(" [ h | d | b ] [ h | d | b ]");
}

//main function that dealas predominatly with user i/o
//NOTE: I assumed that all input values will be 1 or larger as 0 is 0
// so adding that as a conversion is redundant
int main(int num, char **inf)
{
	//if there is no conversion desired
	if (*inf[1] == *inf[2]){
		print_arr(inf[3], arr_size(inf[3]));
	//hexadecimal to binary
	} else if (*inf[1] == 'h' && *inf[2] == 'b'){
		print_string("Hexadecimal ");
		print_arr(inf[3], arr_size(inf[3]));
		print_string(" is binary ");
		output_bin(hex_to_int(inf[3], arr_size(inf[3])));
	//binary to hexadecimal
	} else if (*inf[1] == 'b' && *inf[2] == 'h'){
		print_string("binary ");
		print_arr(inf[3], arr_size(inf[3]));
		print_string(" is hexadecimal ");
		output_hex(bin_to_int(inf[3], arr_size(inf[3])));
	//decimal to binary
	} else if (*inf[1] == 'd' && *inf[2] == 'b'){
		print_string("Decimal ");
		print_arr(inf[3], arr_size(inf[3]));
		print_string(" is binary ");
		output_bin(to_int(inf[3], arr_size(inf[3])));
	//decimal to hexadecimal
	} else if (*inf[1] == 'd' && *inf[2] == 'h'){
		print_string("Decimal ");
		print_arr(inf[3], arr_size(inf[3]));
		print_string(" is hexadecimal ");
		output_hex(to_int(inf[3], arr_size(inf[3])));
	//binary to decimal
	} else if (*inf[1] == 'b' && *inf[2] == 'd'){
		print_string("Binary ");
		print_arr(inf[3], arr_size(inf[3]));
		print_string(" is decimal ");
		print_int(bin_to_int(inf[3], arr_size(inf[3])));
	//hexadecimal to decimal
	} else if (*inf[1] == 'h' && *inf[2] == 'd'){
		print_string("Hexadecimal ");
		print_arr(inf[3], arr_size(inf[3]));
		print_string(" is decimal ");
		print_int(hex_to_int(inf[3], arr_size(inf[3])));
	} else {
	//in the event user input is invalid
		print_message(inf[0]);
	}
	putchar('\n');
	return 0;
}



