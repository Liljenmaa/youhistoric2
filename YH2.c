/* You Historic 2 */

/*
Jesse Liljenmaa 
GNU GPL v 3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "YH2.h"

Human ** createHumanlist(void)
{
    Human **humanlist = NULL;
    return humanlist;
}

void generateHuman(World *world, Human *father, Human *mother, size_t age, int gender, int married, Human *married_with)
{
    Human *newhuman;
    newhuman->father = father;
    newhuman->mother = mother;
    newhuman->id = world->human_id_counter++;
    newhuman->age = age;
    newhuman->gender = gender;
    newhuman->married = married;
    newhuman->married_with = married_with;
    world->humanlist = realloc(world->humanlist, (((world->humanlistsize)+1)*sizeof(Human *)));
    world->humanlist[world->humanlistsize++] = newhuman;
}

void createHuman(World *world, size_t age, int gender, int married, Human *married_with)
{
    generateHuman(world, NULL, NULL, age, gender, married, married_with);
}

void birthHuman(World *world, Human *father, Human *mother)
{
    generateHuman(world, father, mother, 0, rand()%2, 0, NULL);
}

void tick(World *world)
{
    int i = 0;
    
    for (; i < world->humanlistsize; ++i)
    {
        ++world->humanlist[i]->age;
    }
}

void marry(World *world, Human *female, Human *male)
{
    female->married_with = male;
    female->married = 1;
    male->married_with = female;
    male->married = 1;
}

int main(void)
{
    srand(time(NULL));
    
    World *world = malloc(sizeof(World));
    
    world->humanlist = createHumanlist();
    world->humanlistsize = 0;
    world->human_id_counter = 0;
    
    int i = 0;
    
    createHuman(world, 1000, 0, 0, NULL);
    createHuman(world, 1000, 1, 0, NULL);
    birthHuman(world, world->humanlist[0], world->humanlist[1]);
    
    for (i = 0; i < world->humanlistsize; ++i)
    {
        printf("%ld\n", world->humanlist[i]->age);
    }
    
    tick(world);
    
    for (i = 0; i < world->humanlistsize; ++i)
    {
        printf("%ld\n", world->humanlist[i]->age);
    }
    
    for (i = 0; i < world->humanlistsize; ++i)
    {
        printf("%d\n", world->humanlist[i]->married);
        printf("%p\n", (void *) world->humanlist[i]->married_with);
    }
    
    marry(world, world->humanlist[0], world->humanlist[1]);
    
    for (i = 0; i < world->humanlistsize; ++i)
    {
        printf("%d\n", world->humanlist[i]->married);
        printf("%p\n", (void *) world->humanlist[i]->married_with);
    }
    
    free(world->humanlist);
    free(world);
    
    return 0;
}
