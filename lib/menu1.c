#include <stdio.h>
#include <string.h>
#include <time.h>
#include "data_type.h"

data_t *create_node(char buff[], int dl1, int dl2, int dl3, int priority){
    data_t *new = malloc(sizeof(data_t));
    new->next = NULL;

    strcpy(new->nama_tugas, buff);
    new->priority = priority;
    new->dl_dd = dl1;
    new->dl_mm = dl2;
    new->dl_yyyy = dl3;

    return new;
}

void input(data_t **main_node){
    char tempInput_namaTugas[255];
    int dl_dd, dl_mm, dl_yyyy, priority;

	printf("Nama Tugas : ");
    scanf("%[^\n]", tempInput_namaTugas); fflush(stdin);
    printf("Deadline : \n");
    printf("    Tanggal : "); scanf("%d", &dl_dd);
    printf("    Bulan   : "); scanf("%d", &dl_mm);
    printf("    Tahun   : "); scanf("%d", &dl_yyyy);
    printf("Level Prioritas : \n");
    printf("    1. Penting & Mendesak\n");
    printf("    2. Tidak Penting & Mendesak\n");
    printf("    3. Penting & Tidak Mendesak\n");
    printf("    4. Tidak Penting & Tidak Mendesak\n");
    printf("Pilihan : ");
    scanf("%d", &priority);

    //creating new node
    data_t *baru = create_node(tempInput_namaTugas, dl_dd, dl_mm, dl_yyyy, priority);
	
    //inserting to linkedList
    data_t *ptr = *main_node;
    if(*main_node == NULL) *main_node = baru;
    else {
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = baru;
    }

    printf("\n test print\nmain : %s\ninput : %s\n", (*main_node)->nama_tugas, baru->nama_tugas);
}
