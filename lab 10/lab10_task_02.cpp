//#include<iostream>
//using namespace std;
//
//bool palindrome(string &str, int start, int end) {
//
//	if (start >= end) {
//		return true;
//	}
//
//	if (str[start] == str[end]) {
//		return true;
//	}
//	else {
//		return false;
//	}
//
//	return palindrome(str, start + 1, end - 1);
//}
//int main() {
//
//	string given= "sadam";
//
//	if (palindrome(given, 0, given.length() - 1)) {
//		cout << "The string is  palindrome";
//
//	}
//	else {
//		cout << "String is not  palindrome";
//	}
//
//
//
//
//	return 0;
//}