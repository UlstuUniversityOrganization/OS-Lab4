#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// ��������� ��� ������������� �������� �������
typedef struct node_s {
    void* data;
    struct node_s* next;
} node_t;

// ��������� ��� ������������� �������
typedef struct {
    node_t* head; // ��������� �� ������ �������
    node_t* tail;  // ��������� �� ����� �������
    int size;
} queue_t;

// ������� ��� ������������� �������
void initialize_queue(queue_t* queue);

// ������� ��� ���������� �������� � ����� �������
int enqueue(queue_t* queue, void* data);

// ������� ��� �������� �������� �� ������ �������
void* dequeue(queue_t* queue);

// ������� ��� ��������, ����� �� �������
int is_empty(queue_t* queue);

#endif