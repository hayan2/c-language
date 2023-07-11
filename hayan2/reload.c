#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// functions
// initPistol, initBulletCase, initCartridgeBelt
// shoot, reload, generateBulletCase

typedef struct Pistol {
	int nowBulletsCount;
	int loadedBullet;
	struct BulletCase* loadedBulletCase;
}Pistol;

typedef struct BulletCase {
	int bullets;
	struct BulletCase* nextBulletCase;
}BulletCase;

typedef struct CartridgeBelt {
	int bulletCases;	
	BulletCase* front;
	BulletCase* rear;
}CartridgeBelt;

void initPistol(Pistol* pistol) {
	pistol->nowBulletsCount = 0;
	pistol->loadedBullet = 0;
	pistol->loadedBulletCase = NULL;
}

void generateBulletCase(CartridgeBelt* cartridgeBelt) {
	BulletCase* bulletCase = (BulletCase*)malloc(sizeof(BulletCase));
	bulletCase->bullets = 12;

	if (cartridgeBelt->bulletCases == 0) {
		bulletCase->nextBulletCase = NULL;
	}
	else {
		cartridgeBelt->rear->nextBulletCase = bulletCase;
		cartridgeBelt->rear = bulletCase;
	}
}
void initCartridgeBelt(CartridgeBelt* cartridgeBelt) {
	cartridgeBelt->bulletCases = 0;
	cartridgeBelt->front = NULL;
	cartridgeBelt->rear = NULL;
}

void shoot(Pistol* pistol) {
	pistol->loadedBullet = 1;
	pistol->nowBulletsCount = 12;
	if (!pistol->loadedBullet) {
		printf("\nIt cannot be fired because there is a no loaded bullet.\n");
		return;
	}

	pistol->loadedBullet = 0;
	
	if (!pistol->nowBulletsCount) {
		printf("There are no bullets in the bullet case.\n");
		return;
	}

	printf("FIRED\n\n");
	pistol->nowBulletsCount--;
	pistol->loadedBullet = 1;

	printf("Now bullets in bullet case : %d\n", pistol->loadedBulletCase->bullets);
}

void reload(Pistol* pistol, CartridgeBelt* cartridgeBelt) {
	
}


int main(void) {
	Pistol pistol;
	CartridgeBelt cartridgeBelt;

	initPistol(&pistol);
	initCartridgeBelt(&cartridgeBelt);
	generateBulletCase(&cartridgeBelt);

	int n;
	

	while (1) {
		scanf("%d", &n);

		if (n != 1) {
			break;
		}

		printf("Enter the 1 : fire a pistol");
		shoot(&pistol);
	}

	return 0;
}