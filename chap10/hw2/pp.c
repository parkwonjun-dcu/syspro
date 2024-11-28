   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
  
   struct Node {
       int data;
       struct Node* next;
   };
  
  struct Queue {
      struct Node* head;
      struct Node* tail;
  };
 
  struct Queue* createQueue() {
      struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
      queue->head = NULL;
      queue->tail = NULL;
      return queue;
  }
 
  void addq(struct Queue* queue, int data) {
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->next = NULL;
      if (queue->head == NULL) {
          queue->head = newNode;
          queue->tail = newNode;
      } else {
          queue->tail->next = newNode;
          queue->tail = newNode;
      }
  }
 
  int delete(struct Queue* queue) {
      if (queue->head == NULL) {
          printf("Queue is empty\n");
          return -1;
      }
      int data = queue->head->data;
      struct Node* temp = queue->head;
      queue->head = queue->head->next;
      if (queue->head == NULL) {
          queue->tail = NULL;
      }
      free(temp);
      return data;
  }

  int main() {
      struct Queue* queue = createQueue();
      int data;
 
      while (1) {
 
          scanf("%d", &data);
          if (data == 'x') {
              break;
          }
          addq(queue, data);
      }
 
      while (queue->head != NULL) {
          data = delete(queue);
          printf("%d\n", data);
      }
 
      return 0;
  }




