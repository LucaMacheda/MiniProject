#include <stdio.h>
#include <stdlib.h>
#include "Queue/queue.h"
#include "Deque/deque.h"
#include "Stack/stack.h"

typedef struct Plane
{
    int id;
    int fuel; // carburant (si bas = urgence)
} Plane;

void printPlane(Plane p)
{
    printf("Plane %d (fuel=%d)", p.id, p.fuel);
}

int main()
{
    Deque landing;
    Queue takeoff;
    Stack history;

    initDeque(&landing, 3, sizeof(Plane));
    initQueue(&takeoff, 3, sizeof(Plane));
    initStack(&history, 3, sizeof(Plane));

    int plane_id = 1;

    printf("=== AIRPORT SIMULATION START ===\n\n");

    // 🔁 simulation sur 10 cycles
    for(int time = 1; time <= 20; time++)
    {
        printf("\n--- TIME %d ---\n", time);

        // 🎲 nouvel avion arrive
        if(rand() % 2)
        {
            Plane p;
            p.id = plane_id++;
            p.fuel = rand() % 10; // 0 → 9

            if(p.fuel <= 2)
            {
                printf("EMERGENCY LANDING: ");
                printPlane(p);
                printf("\n");
                insertFront(&landing, &p);
            }
            else
            {
                printf("Landing request: ");
                printPlane(p);
                printf("\n");
                insertRear(&landing, &p);
            }
        }

        // 🎯 priorité : landing d'abord
        Plane current;

        if(!isEmptyDeque(&landing))
        {
            deleteFront(&landing, &current);
            printf("Landing: ");
            printPlane(current);
            printf("\n");

            // après atterrissage → va en takeoff queue
            enqueue(&takeoff, &current);

            push(&history, &current);
        }
        else if(!isEmptyQueue(&takeoff))
        {
            dequeue(&takeoff, &current);
            printf("Takeoff: ");
            printPlane(current);
            printf("\n");

            push(&history, &current);
        }
        else
        {
            printf("No planes this cycle\n");
        }
    }

    printf("\n=== FINAL TAKEOFF PHASE ===\n");

    Plane p;
    while(!isEmptyQueue(&takeoff))
    {
        dequeue(&takeoff, &p);
        printf("Final takeoff: ");
        printPlane(p);
        printf("\n");

        push(&history, &p);
    }

    printf("\n=== HISTORY (LAST EVENTS FIRST) ===\n");

    while(!isEmptyStack(&history))
    {
        pop(&history, &p);
        printPlane(p);
        printf("\n");
    }

    destroyDeque(&landing);
    destroyQueue(&takeoff);
    destroyStack(&history);

    return 0;
}