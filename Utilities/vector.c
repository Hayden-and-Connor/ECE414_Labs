#ifndef VECTOR_C
#define VECTOR_C

typedef struct {
	int x, y;
} Vector2;

static Vector2 add(Vector2 a, Vector2 b){
	Vector2 output = {a.x + b.x, a.y + b.y};
	return output;
}

static Vector2 new_vector(int x, int y) {
	Vector2 output = {x, y};
	return output;
}

typedef struct {
	Vector2 (*new)(int, int);
	Vector2 (*add)(Vector2, Vector2);
} vector_interface;

vector_interface VECTOR = {
	&new_vector, 
	&add 
};

#endif