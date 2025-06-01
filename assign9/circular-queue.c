#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int q[MAX];
int rear = -1;
int front = -1;

int enqueue(int data);
int dequeue();
void display();
int peek();


int main(void)
{
	int op, d;
	while(1)
	{
		printf("Enter an option:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			    printf("Enter the value: ");
			    scanf("%d", &d);
			    int a = enqueue(d);
			    if (d == 0)
				printf("%d enqueued.", a);
			    break;
			case 2:
			    d = dequeue();
			    printf("Dequeued element: %d\n", d);
			    break;
			case 3:
			    printf("Front element: %d\n", peek());
			    break;
			case 4:
			    display();
			    break;
			case 5:
			    exit(0);
			default:
			    printf("Invalid case, please try again.\n");
		}
	}
}


int enqueue(int data)
{
	if (rear == MAX - 1)
	{
		printf("Queue overflow.\n");
		return -1;
	}
	q[++rear] = data;
	if (front == -1)
	{
		front = 0;
	}
	return 0;
}

int dequeue()
{
	if (front == -1)
	{
		printf("Queue underflow.\n");
		return -1;
	}
	int d = q[front++];
	if (front > rear)
	{
		rear = -1;
		front = -1;
	}
	return d;
}

int peek()
{
	if (front == -1)
	{
		printf("Queue underflow.\n");
		return -1;
	}
	return q[front];
}

void display()
{
	if (rear == -1)
	{
		printf("Queue underflow.\n");
		return;
	}

	for(int i = front; i <= rear; i++)
	{
		printf("%d\n", q[i]);
	}
}


