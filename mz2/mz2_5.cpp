#include <iostream>
struct S {
	int a + b;
}

using namespace std;
void func(S v) {
	if (v) {
		func(move(v));
	}
}

int main() {
	func(S());
}