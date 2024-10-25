#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int HAND_SIZE = 14;

class Blackjack {
private:
    int deck[13];
    int deckSize;
    int playerHand[HAND_SIZE];
    int dealerHand[HAND_SIZE];
    int playerStand;
    int dealerStand;

public:
    Blackjack() {
       
        // Initialize the deck with numbers 1 to 13
        for (int i = 0; i < 13; i++) {
            deck[i] = i + 1;
        }

        playerStand = 0;
        dealerStand = 0;
        for (int i = 0; i < HAND_SIZE; i++) {
            playerHand[i] = 0;
            dealerHand[i] = 0;
        }
    }

    int summ(int hand[]) {
        int sum = 0;
        for (int i = 0; i < HAND_SIZE; i++) {
            sum += hand[i];
        }
        return sum;
    }

    int game() {
        bool gameOver = false; 
        int turn = 0;
        while (!gameOver) {
            if (playerStand == 0) {
                cout << "Would you like to hit or stand (h/s)? ";
                char choice;
                cin >> choice;
                if (choice == 'h') {
                    //srand(time(0));
                    int chooseCard = rand() % 13;
                    playerHand[turn] = deck[chooseCard];
                    if (playerStand == 1 && dealerStand == 1) {
                        if (summ(playerHand) > summ(dealerHand)) {
                            cout << "You won:)\n";
                            return 1;
                        }
                        else if (summ(playerHand) < summ(dealerHand)) {
                            cout << "Dealer won:(\n";
                            return 0;
                        }
                        else {
                            cout << "draw:/!\n";
                            return -1;
                        }
                    }
                    turn += 1;
                }
                else if (choice == 's') {
                    playerStand = 1;
                    break;
                }
            }
            if (dealerStand == 0) {
                int chooseCard = rand() % 13;
                dealerHand[turn] = deck[chooseCard];
                for (int i = chooseCard; i < deckSize; i++) {
                    deck[i] = deck[i + 1];
                }
                deckSize -= 1;
            }
            if (playerStand == 0) {
                cout << "Your current hand is " << summ(playerHand) << endl;
            }
            
                if (summ(dealerHand) > 21) {
                    cout << "Dealer went over" << endl;
                    if (summ(playerHand) > 21) {
                        cout << "Player went over as well" << endl;
                        cout << "DRAW!" << endl;
                        return -1;
                    }
                    else {
                        cout << "Player WINS!" << endl;
                        return 0;
                    }
                }
            
        }
        return 2; 
    }
    
};


int main() {
    
    Blackjack blackjackGame;

    bool quit = 0;
    int whoWon = -1;
    int dealerScore = 0;
    int playerScore = 0;

    cout << "Welcome to BlackJack! Let's Begin\n";
    
    do {
        whoWon = blackjackGame.game();

       
        if (whoWon == 0) {
            dealerScore += 1;
        }
        else if (whoWon == 1) {
            playerScore += 1;
        }

        cout << "Your Score = ";
        cout << playerScore;
        cout << "\n";
        cout << "Dealer Score = ";
        cout << dealerScore;
        cout << "\n";

        
        cout << "Do you want to quit? 1 for exit, 0 to continue\n";
        cin >> quit;

       

    } while (quit == 0);//

}
