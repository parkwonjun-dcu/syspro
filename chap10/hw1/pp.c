#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("stack is empty.\n");
        return -1; 
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int top(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("stack is empty.\n");
        return -1; 
    }
    return stack->top->data;
}

int main() {
	struct Stack *Top_Node = createStack();
	int data;
	while(scanf("%d", &data)==1){
		if(data < 0){ 
			break;
		}
		push(Top_Node,data);
	}
		printf("print stack.\n");
	while (Top_Node->top != NULL) {
		printf("%d\n", pop(Top_Node));	
	}	
	free(Top_Node);
	return 0;
}
