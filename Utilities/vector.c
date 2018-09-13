#ifndef VECTOR_C
#define VECTOR_C

typedef struct {
	int x, y;
} Vector2;

static Vector2 add(Vector2 a, Vector2 b){
	Vector2 output = {a.x + b.x, a.y + b.y};
	return output;
}


typedef struct {
	Vector2 (*add)(Vector2, Vector2);
} functionList;

functionList VECTOR = { &add };

#endif