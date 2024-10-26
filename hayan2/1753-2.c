#define _CRT_SECURE_NO_WARNINGS
#define MAX_V 20005
#define MAX_E 300005
#define INF 1e9
#define ROOT 1
#define VISITED 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    // origin destination weight
    int u, v, w;
    // link
    int prev;
}Edge;

typedef struct Heap {
    // destination weight
    int w, v;
}Heap;

Edge edge[MAX_E];
Heap heap[MAX_E];
int res[MAX_V];
int pos[MAX_V] = { 0, };
int idx = 0;
int V, E;

void swap(Heap* a, Heap* b) {
    Heap tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(Heap x) {
    heap[++idx] = x;

    for (int i = idx; i / 2 >= 1; i /= 2) {
        if (heap[i].w < heap[i / 2].w) {
            swap(&heap[i], &heap[i / 2]);
        }
        else {
            break;
        }
    }
}

Heap pop() {
    Heap ret = heap[ROOT];
    heap[ROOT] = heap[idx--];

    for (int i = 1; i <= idx;) {
        int l = i * 2, r = i * 2 + 1;
        int nxt = 0;
        if (l <= idx) {
            nxt = l;
        }
        if (r <= idx && heap[r].w < heap[nxt].w) {
            nxt = r;
        }
        if (nxt == 0 || heap[i].w <= heap[nxt].w) {
            break;
        }
        swap(&heap[i], &heap[nxt]);
        i = nxt;
    }

    return ret;
}

void sol(int K) {
    for (int i = 1; i <= V; i++) {
        res[i] = INF;
    }

    res[K] = 0;
    push((Heap) { 0, K });

    while (idx > 0) {
        Heap ret = pop();
        if (ret.w > res[ret.v]) {
            continue;
        }

        for (int i = pos[ret.v]; i; i = edge[i].prev) {
            if (res[edge[i].v] > res[ret.v] + edge[i].w) {
                res[edge[i].v] = res[ret.v] + edge[i].w;
                push((Heap) { res[edge[i].v], edge[i].v });
            }
        }
    }
}

int main(void) {
    int K;

    scanf("%d %d %d", &V, &E, &K);

    for (int i = 1; i <= E; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        edge[i].prev = pos[edge[i].u];
        pos[edge[i].u] = i;
    }

    sol(K);

    for (int i = 1; i <= V; i++) {
        res[i] == INF ? puts("INF") : printf("%d\n", res[i]);
    }

    return 0;
}