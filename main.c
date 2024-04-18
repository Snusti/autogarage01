#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>

int savedcars = 1;
#define MAX_TEXT 52 
#define MAX_CARS 10 

struct Car {
  char brand[MAX_TEXT];
  char name[MAX_TEXT];
  char type[MAX_TEXT];
  int year;
};

void addCar(struct Car cars[]) {
  if (savedcars == MAX_CARS) {
    printf("Garage is Full!!!");
  }

  printf("--------\n");
  printf("NEW-CAR:\n");
  printf("--------\n");

  char temp = getchar();
  printf("\nCar-Brand:");
  gets_s(cars[savedcars].brand, MAX_TEXT);
  printf("\nCar-Name:");
  gets_s(cars[savedcars].name, MAX_TEXT);
  printf("\nCar-Type:");
  gets_s(cars[savedcars].type, MAX_TEXT);
  printf("\nProduction-Year:");
  scanf_s("%d", &(cars[savedcars].year));
  savedcars++;
  system("cls");
}

void removeCar(struct Car* cars) {
  if (savedcars == 0) {
    printf("Garage is empty!!!");
  }
  int carIndex;
  printf("Enter the Number of the car you want to remove (1 to %d): ", savedcars - 1);
  scanf_s("%d", &carIndex);

  for (int i = carIndex; i < savedcars - 1; i++) {
    cars[i] = cars[i + 1];
  }
  memset(&cars[savedcars - 1], 0, sizeof(struct Car));
  savedcars--;
  printf("\nYou have successfully removed Car %d from your Garage.\n", carIndex);
}

void reviewCar(struct Car car[]) {
  printf("--------------------\n");
  printf("Here is your Garage:\n");
  printf("--------------------\n\n");

  printf("---------------------------------------------------------------------\n");
  printf("|Car-Brand:      |Name:          |Model:         |Year-Of-Production|\n");
  printf("---------------------------------------------------------------------\n\n");

  for (int i = 1; i < savedcars; i++) {

    if (strcmp(car[i].name, "")) {
      printf("|%16s|%15s|%15s|%18d|\n", car[i].brand, car[i].name, car[i].type, car[i].year);
    }
  }
}


int main() {
  char i;
  do {
    struct Car  cars[MAX_CARS];
    printf("(1)AddCar\n");
    printf("(2)RemoveCar\n");
    printf("(3)ReviewCar\n");
    printf("(4)Exit\n");
    int selection = 0;
    scanf_s("%d", &selection);
    switch (selection) {
      case 1:
        addCar(cars);
        break;
      case 2:
        removeCar(cars);
        break;
      case 3:
        reviewCar(cars);
        break;
      case 4: exit(0);
    }

    printf("do you want to go back zu the menue?(j/n)\n");
    i = _getche();
    system("cls");
  } while (i == 'j');

  return 0;
}