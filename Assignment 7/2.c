#include <stdio.h>
#include <string.h>
#include <limits.h>

int minStep;

void removeGroups(char board[]) {
    int i = 0, k = 0;
    char temp[200];

    while (board[i] != '\0') {
        int j = i;

        while (board[j] == board[i]) {
            j++;
        }

        if (j - i >= 3) {
            // remove this group
            i = j;
        } else {
            for (int x = i; x < j; x++) {
                temp[k++] = board[x];
            }
            i = j;
        }
    }

    temp[k] = '\0';
    strcpy(board, temp);
}

void dfs(char board[], int hand[], int steps) {
    if (board[0] == '\0') {
        if (steps < minStep) {
            minStep = steps;
        }
        return;
    }

    if (steps >= minStep) {
        return;
    }

    int len = (int)strlen(board);

    for (int c = 0; c < 5; c++) {
        if (hand[c] == 0) {
            continue;
        }

        hand[c]--;

        for (int i = 0; i <= len; i++) {
            char temp[200];
            int p = 0;
            char ch = "RYBGW"[c];

            for (int j = 0; j < i; j++) {
                temp[p++] = board[j];
            }

            temp[p++] = ch;

            for (int j = i; j < len; j++) {
                temp[p++] = board[j];
            }

            temp[p] = '\0';

            removeGroups(temp);
            dfs(temp, hand, steps + 1);
        }

        hand[c]++;
    }
}

int findMinStep(char board[], char handStr[]) {
    int hand[5] = {0};
    minStep = INT_MAX;

    for (int i = 0; handStr[i] != '\0'; i++) {
        if (handStr[i] == 'R') hand[0]++;
        else if (handStr[i] == 'Y') hand[1]++;
        else if (handStr[i] == 'B') hand[2]++;
        else if (handStr[i] == 'G') hand[3]++;
        else if (handStr[i] == 'W') hand[4]++;
    }

    dfs(board, hand, 0);

    if (minStep == INT_MAX) {
        return -1;
    }

    return minStep;
}

int main() {
    char board[200], hand[200];

    scanf("%s %s", board, hand);

    printf("%d\n", findMinStep(board, hand));

    return 0;
}