#include"stdio.h"
#include"5a.h"
int main() {
	char parenthesis_sequence[100];
	int number_of_inputs = 0;
	printf("Number of inputs: ");
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) {
        printf("Enter string: ");
		scanf("%s", parenthesis_sequence);
		printf("%d\n", match_parenthesis(parenthesis_sequence));
	}
	return 0;
}

