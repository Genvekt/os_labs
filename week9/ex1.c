#include <stdio.h>
#include <stdlib.h>

int main(){

// Reading number of page frames
    printf("How many page frames you are going to use?\n");
    int pf_number = 0;
    scanf("%d",&pf_number);

// One record in page table
    typedef struct Record{
        int p_id;
        int counter;
    }Record;

//Page table
    Record buffer[pf_number];
    for(int i = 0; i<pf_number;i++){
        buffer[i].p_id = -1;
        buffer[i].counter = 0;
    }

//Open file
    FILE* input = fopen("input.txt","r");
    int page_id = 0,found = 0,low_counter = 256,low_id = -1;
    double miss = 0,hit = 0;

    fscanf(input,"%d",&page_id);
    while(!feof (input)){
        //read page id from file

        low_counter = 256; 
        low_id = -1;
        found = 0;

        //Search through page table
        for(int i = 0; i<pf_number; i++){

            //if empty place, remember it
            if(buffer[i].p_id == -1){
                if(low_counter>=0){
                    low_counter = -1;
                    low_id = i;
                }
            }

            //find page with the lowest counter
            if(buffer[i].counter<low_counter){
                low_counter = buffer[i].counter;
                low_id = i;
            }

            //shift current counter
            buffer[i].counter = buffer[i].counter/2;

            //add 1 to left most bit if this page is referenced
            if(buffer[i].p_id == page_id){
                buffer[i].counter += 128;
                found = 1;
            }

        }

        //if page not found, replace with one with the lowest counter
        if(found == 0){
            miss +=1;
            buffer[low_id].p_id = page_id;
            buffer[low_id].counter = 128;
        }
        //if page is found, it is ok
        else{
            hit += 1;
        }
         fscanf(input,"%d",&page_id);
    
    }

    fclose(input);
    printf("Hit/miss rate: %lf\nHit = %lf\nMiss = %lf\n",hit/miss, hit, miss);
}