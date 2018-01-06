#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void movement(char mat[50][250], Player *pl );

int main() {
	movement(mat, Player*);
	return 0;
}

void movement(char mat[50][250], Player *pl) {
	int count = 5, steps = 0, x=pl->i, y = pl->j, tempcount = 0;
	char dir;
	while (count > 0) {
		printf("Which direction would you like to move? L/R/N=don't move \n");
		scanf("%c", &dir);
		getchar();
		if ((dir >= 65) && (dir <= 90)) {
			dir = dir + 32;
		}
		if (dir == 'n') {
			break;
		}
		printf("You have %d steps left. \nHow many steps would you like to move?\n", count);
		scanf("%d", &steps);
		getchar();
		int stepflag = steps;
		tempcount = 0;
		int oldy = 0;
		int oldx = 0;
		if (dir == 'r') {
			oldy = y;
			oldx = x;
			while (steps > 0) {
				//*regular movement right*//
				if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 249)) {
					tempcount++;
					steps--;
					y++;
				}
				//*right and down*//
				else if ((mat[x][y + 1] == ' ') && (mat[x + 1][y + 1] == ' ') && ((y + 1) != 249) && (mat[x + 2][y + 1] == 'x')) {
					tempcount++;
					steps--;
					y++;
					x++;
				}
				//*right and up*//
				else if ((mat[x][y + 1] == 'x') && (mat[x + 1][y + 1] == 'x') && ((y + 1) != 249) && (mat[x - 1][y + 1] == ' ')) {
					tempcount++;
					steps--;
					y++;
					x--;
				}
			}
			if ((tempcount == stepflag) && ((count - tempcount) >= 0)) {
				mat[oldx][oldy] = ' ';
				count = count - tempcount;
				printMap(mat);
				printf("MOVED! %d steps left!\n", count);
			}
			else {
				printf("can't move, choose other direction or fewer steps \n");
				break;
			}
		}
		if (dir == 'l') {
			oldy = y;
			oldx = x;
			while (steps > 0) {
				//*regular movement left*//
				if ((mat[x][y - 1] == ' ') && (mat[x + 1][y - 1] == 'x') && ((y + 1) != 0)) {
					tempcount++;
					steps--;
					y--;
				}
				//*left and down*//
				else if ((mat[x][y - 1] == ' ') && (mat[x + 1][y - 1] == ' ') && ((y + 1) != 0) && (mat[x + 2][y - 1] == 'x')) {
					tempcount++;
					steps--;
					y--;
					x++;
				}
				//*left and up*//
				else if ((mat[x][y - 1] == 'x') && (mat[x + 1][y - 1] == 'x') && ((y + 1) != 0) && (mat[x - 1][y - 1] == ' ')) {
					tempcount++;
					steps--;
					y--;
					x--;
				}
			}
			if ((tempcount == stepflag) && ((count - tempcount) >= 0)) {
				mat[oldx][oldy] = ' ';
				count = count - tempcount;
				printMap(mat);
				printf("MOVED! %d steps left!\n", count);
			}
			else {
				printf("can't move, choose other direction or fewer steps \n");
				y = oldy;
				x = oldx;
				break;
			}
		}
	}
	pl->i = x;
	pl->j = y;
	mat[x][y] = pl->id;
	
}