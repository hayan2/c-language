#define _CRT_SECURE_NO_WARNINGS
#define ull unsigned long long 
#define MAX_V 20005
#define MAX_E 300005
#define INF 1e9
#define ROOT 1
#define VISITED 1
#define START 1
#include <stdio.h>
#include <stdlib.h>

// failed

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
int V, E, v1, v2;

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
    scanf("%d %d", &V, &E);

    for (int i = 1; i <= E; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        edge[i].prev = pos[edge[i].u];
        pos[edge[i].u] = i;
    }

    scanf("%d %d", &v1, &v2);

    sol(START);
    int res1 = res[v1];
    int res2 = res[v2];
    sol(v1);
    res1 += res[v2];
    res2 += res[V];
    sol(v2);
    res1 += res[V];
    res2 += res[v1];

    if (res1 >= INF && res2 >= INF) {
        printf("-1");
    }
    else {
        res1 < res2 ? printf("%d", res1) : printf("%d", res2);
    }   

    return 0;
}