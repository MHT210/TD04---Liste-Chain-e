#include "stdio.h"
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
} POINT;

typedef struct liste_points {
	POINT p;
	struct liste_points *suiv;
}LISTE_POINTS;

LISTE_POINTS * insert_first(LISTE_POINTS *list, int x, int y) {
	LISTE_POINTS * temp;
	temp = malloc(sizeof(LISTE_POINTS));
	if (!temp) {fprintf(stderr, "pb malloc\n"); exit(12);}
	(*temp).p.x = x;
	(*temp).p.y = y;
	(*temp).suiv = list;
	return temp;
}

LISTE_POINTS * insert_last(LISTE_POINTS *list, int x, int y) {
	LISTE_POINTS * temp = list;
	LISTE_POINTS * previous_temp;
	LISTE_POINTS * last;
	while (temp) {
		previous_temp = temp;
		temp = (*temp).suiv;
	}

	last = malloc(sizeof(LISTE_POINTS));
	if (!last) {fprintf(stderr, "pb malloc\n"); exit(12);}
	
	(*last).p.x = x;
	(*last).p.y = y;
	temp = (*last).suiv;
	(*temp).suiv = last;

	return last;
}

int count_values(LISTE_POINTS *list) {
	int i = 0;
	if (list->p.x) {i++;}
	if (list->p.y) {i++;}
	return i;
}

void print_list(LISTE_POINTS *list) {
	printf(" // %d element(s) ", count_values(list));
	while (list) {
		printf("[%d, %d] ", (*list).p.x, (*list).p.y);
		list = (*list).suiv;
	}
	printf(" // \n");
}

int main () {
	LISTE_POINTS *l;
	l = NULL;
	l = insert_first(l, 1, 2);
	l = insert_first(l, 3, 4);
	print_list(l);
	l = insert_last(l, 1, 1);
	print_list(l);

	return 0;
}