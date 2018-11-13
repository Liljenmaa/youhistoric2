/* You Historic 2 */

/*
Jesse Liljenmaa 
GNU GPL v 3.0
*/

typedef struct Human
{
    struct Human *father;
    struct Human *mother;
    int id;
    size_t age;
    int gender;
    int married;
    struct Human *married_with;
} Human;

typedef struct World
{
    Human **humanlist;
    size_t humanlistsize;
    int human_id_counter;
} World;

Human ** createHumanlist(void);

void createHuman(World *world, size_t age, int gender, int married, Human *married_with);

void birthHuman(World *world, Human *father, Human *mother);

void tick(World *world);

void marry(World *world, Human *female, Human *male);
