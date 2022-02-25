#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Start \
"\nWelcome to Proto Snake !\n"\
"Use the w,a,s,d keys to navigate !\n"

int score = 0;
int turns = 0;

void display(char arr[12][12])
{
	for(int i=0; i<12; i++) {
      	 for(int j=0;j<12;j++) {
         	printf("%c", arr[i][j]);
    	 }
 	}

 	printf("\nTurn %i\n", turns);
 	printf("Your Score is: %i\n", score);
}

int main()
{
	int x = 5;
	int y = 5;
	char arr[12][12] = 
	{
		{'a','a','a','a','a','a','a','a','a','a','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ','s',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','\n'},
		{'a','a','a','a','a','a','a','a','a','a','a','\n'}
	};
	printf("%s\n", Start);
	display(arr);
	char input;
	int started = 0;
	int ax = 0;
	int ay = 0;

	while(score <= 20) {
		if(started == 0) {
			ax = (rand() %9)+1;
			ay = (rand() %10)+1;
			started = 2;
		}

		if((x != ax || y != ay) && (started == 2)) {
			arr[ay][ax] = 'o';
			started = 1;
		} else if((x == ax &&  y == ay) && (started == 2)) {
			if(ay < 10 || ax < 9) {
				arr[ay+1][ax+1] = 'o';
				started = 3;
			} else if(ay == 9 || ax > 9) {
				arr[ay-1][ax-1] = 'o';
				started = 4;
			}
		}
		scanf("%c", &input);
		if(input == 'w' || input == 'W') {
			turns+=1;
			y=y-1;
			arr[y][x] = 's';
			arr[y+1][x] = ' ';
			display(arr);
		} else if(input == 's' || input == 'S') {
			turns+=1;
			y=y+1;
			arr[y][x] = 's';
			arr[y-1][x] = ' ';
			display(arr);		
		} else if(input == 'd' || input == 'D') {
			turns+=1;
			x=x+1;
			arr[y][x] = 's';
			arr[y][x-1] = ' ';
			display(arr);
		} else if(input == 'a' || input == 'A') {
			turns+=1;
			x=x-1;
			arr[y][x] = 's';
			arr[y][x+1] = ' ';
			display(arr);
		}

		if(started == 1 && (x == ax && y == ay)) {
			turns+=1;
			score = score+1;
			started = 0;
			continue;
		} else if(started == 3 && (x == ax+1 && y == ay+1)) {
			score = score+1;
			started = 0;
			continue;
		} else if(started == 4 && (x == ax-1 && y == ay-1)) {
			score = score+1;
			started = 0;
			continue;
		} else if((y > 10 || y < 1) || (x > 9 || x < 1)) {
			printf("Game Over ! You hit the wall !\n");
			return 1;
		} else if(score == 20) {
			printf("CONGRATS YOU WON !\n");
			return 1;
		}
	}
}
