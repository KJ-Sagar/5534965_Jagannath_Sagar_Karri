#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

// A simple structure to hold coordinates and moves
typedef struct {
    int x, y, moves;
} State;

// A simple queue implementation for BFS
typedef struct {
    State* data;
    int front, rear, size;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        return NULL;
    }
    q->data = (State*)malloc(capacity * sizeof(State));
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = capacity;
    return q;
}

int is_empty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, State s) {
    if ((q->rear + 1) % q->size == q->front) {
        return; // Queue is full
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = s;
}

State dequeue(Queue* q) {
    State s = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return s;
}

void freeQueue(Queue* q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 * 1. STRING_ARRAY grid
 * 2. INTEGER startX
 * 3. INTEGER startY
 * 4. INTEGER goalX
 * 5. INTEGER goalY
 */
int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    int n = grid_count;
    int** visited = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        visited[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            visited[i][j] = -1;
        }
    }

    Queue* q = createQueue(n * n);
    if (!q) {
        // Handle memory allocation failure
        for(int i = 0; i < n; i++) free(visited[i]);
        free(visited);
        return -1;
    }

    State start_state = {startX, startY, 0};
    enqueue(q, start_state);
    visited[startX][startY] = 0;

    int dx[] = {-1, 1, 0, 0}; // Up, Down
    int dy[] = {0, 0, -1, 1}; // Left, Right

    while (!is_empty(q)) {
        State current = dequeue(q);

        int x = current.x;
        int y = current.y;
        int moves = current.moves;

        if (x == goalX && y == goalY) {
            // Free allocated memory before returning
            for (int i = 0; i < n; i++) {
                free(visited[i]);
            }
            free(visited);
            freeQueue(q);
            return moves;
        }

        // Explore all 4 directions
        for (int i = 0; i < 4; ++i) {
            int new_x = x;
            int new_y = y;

            while (true) {
                new_x += dx[i];
                new_y += dy[i];

                if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n || grid[new_x][new_y] == 'X') {
                    break;
                }

                if (visited[new_x][new_y] == -1) {
                    visited[new_x][new_y] = moves + 1;
                    enqueue(q, (State){new_x, new_y, moves + 1});
                }
            }
        }
    }

    // Free allocated memory if no path is found
    for (int i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);
    freeQueue(q);

    return -1; // Path not found
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    if (fptr == NULL) {
        // Handle file open error
        return 1;
    }

    int n = parse_int(ltrim(rtrim(readline())));

    char** grid = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* grid_item = readline();
        *(grid + i) = grid_item;
    }

    char** first_multiple_input = split_string(rtrim(readline()));
    if (!first_multiple_input) {
        // Handle split string error
        return 1;
    }

    int startX = parse_int(*(first_multiple_input + 0));
    int startY = parse_int(*(first_multiple_input + 1));
    int goalX = parse_int(*(first_multiple_input + 2));
    int goalY = parse_int(*(first_multiple_input + 3));

    int result = minimumMoves(n, grid, startX, startY, goalX, goalY);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    // Freeing memory from the main function
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
    free(first_multiple_input);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);
    if (!data) return NULL;

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            return NULL;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);
        if (data) {
            data[data_length] = '\0';
        }
    }
    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return NULL;
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return NULL;
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return NULL;
        }
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}