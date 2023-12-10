#include "queue.h"

// ������� ��� ������������� �������
void initialize_queue(queue_t* queue) {
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
}

// ������� ��� ���������� �������� � ����� �������
int enqueue(queue_t* queue, void* data) {
    // ������� ����� ����
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) {
        return 1;
    }
    new_node->data = data;
    new_node->next = NULL;

    // ���� ������� �����, ������������� ����� ���� ��� ������ �������
    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else {
        // ����� ��������� ����� ���� � ����� ������� � ��������� ��������� tail
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->size++;

    return 0;
}

// ������� ��� �������� �������� �� ������ �������
void* dequeue(queue_t* queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    // �������� �������� �� ������ ������� � ��������� ��������� head
    void* data = queue->head->data;
    struct Node* temp = queue->head;
    queue->head = queue->head->next;

    // ���� ����� �������� ������� ����� ������, ��������� ��������� tail
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    // ����������� ������, ���������� ��� ���������� ����
    free(temp);

    queue->size--;

    return data;
}

// ������� ��� ��������, ����� �� �������
int is_empty(queue_t* queue) {
    return queue->head == NULL;
}