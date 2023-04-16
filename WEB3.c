#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    char make[20];
    char model[20];
    int year;
    int speed;
    int x;
    int y;
    int z;
} Car;

void accelerate(Car *car, int speed_increment) {
    car->speed += speed_increment;
}

void brake(Car *car, int speed_decrement) {
    car->speed -= speed_decrement;
}

void move(Car *car) {
    car->x += car->speed;
    car->y += car->speed;
    car->z += car->speed;
}

bool detect_collision(Car car1, Car car2) {
    if (car1.x == car2.x && car1.y == car2.y && car1.z == car2.z) {
        return true;
    } else {
        return false;
    }
}

double time_to_collision(Car car1, Car car2) {
    int x_diff = car2.x - car1.x;
    int y_diff = car2.y - car1.y;
    int z_diff = car2.z - car1.z;
    int distance_squared = x_diff * x_diff + y_diff * y_diff + z_diff * z_diff;
    double distance = sqrt(distance_squared);
    return distance / (double)(car1.speed - car2.speed);
}

int main() {
    Car car1 = {"Hyundai", "Alto", 2021, 60, 0, 0, 0};
    Car car2 = {"Maruti", "Creta", 2019, 50, 50, 50, 50};

    accelerate(&car1, 10);
    brake(&car2, 20);

    move(&car1);
    move(&car2);

    if (detect_collision(car1, car2)) {
        printf("Cars have collided!\n");
    } else {
        printf("Cars have not collided.\n");
    }

    double time = time_to_collision(car1, car2);
    printf("Time to collision: %lf hours\n", time);

    return 0;
}
