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
	if (!list) {
		LISTE_POINTS * last = malloc(sizeof(LISTE_POINTS));
		if (!last) {fprintf(stderr, "pb malloc\n"); exit(12);}
		(*last).p.x = x;
		(*last).p.y = y;
		(*last).suiv = NULL;
		return last;
	}
	
	list->suiv = insert_last(list->suiv, x, y);
	return list;
}

int count_values(LISTE_POINTS *list) {
	int i = 0;
	while (list) {
		i++;
		list = list->suiv;
	}
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

int research(LISTE_POINTS *list, int x, int y) {
	int i = 0;
	while (list) {
		i++;
		if (list->p.x == x && list->p.y == y) {return i;}
		list = list->suiv;
	}

	return 0;
}

void research_rec(LISTE_POINTS *list, int x, int y) {
	if (list->p.x == x && list->p.y == y) {printf("Found : [%d, %d] \n", x, y);}
	if (list->suiv) {research_rec(list->suiv, x, y);}
}

LISTE_POINTS * delete_first(LISTE_POINTS * list) {
	if (!list) {return NULL;}
	LISTE_POINTS * temp;

	temp = list;
	list = list->suiv;
	free(temp);
	return list;
}

LISTE_POINTS * delete_last(LISTE_POINTS * list) {
	LISTE_POINTS * temp;
	LISTE_POINTS * prev_temp;

	temp = list; 

	while (temp->suiv) {
		prev_temp = temp;
		temp = temp->suiv;
	}

	prev_temp->suiv = NULL;
	free(temp);
	return list;
}

int main () {
	LISTE_POINTS *l;
	l = NULL;
	l = insert_first(l, 1, 2);
	l = insert_first(l, 3, 4);
	print_list(l);
	
	l = insert_last(l, 1, 1);
	print_list(l);
	
	printf("L'element est a la pos : %d \n",research(l, 1, 2));
	research_rec(l, 1, 1);

	l = delete_first(l);
	printf("Suppression du PREMIER element : \n");
	print_list(l);

	l = delete_last(l);
	printf("Suppression du DERNIER element : \n");
	print_list(l);

	return 0;
}