#include <stdio.h>
#include <pthread.h>

int available_seats = 1;

void* book_seat(void* arg) {
    if (available_seats > 0) {
        printf("Seat available, booking...\n");
        available_seats--;
        printf("Booking successful!\n");
    } else {
        printf("No seats left\n");
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, book_seat, NULL);
    pthread_create(&t2, NULL, book_seat, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Seats left: %d\n", available_seats);
    return 0;
}
