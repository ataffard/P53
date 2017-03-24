#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
/*
  Blackjack game.... almost
  http://en.wikipedia.org/wiki/Blackjack
  
  Use 1 deck of card
  Users play against the computer(dealer)
  
  Aim: reach 21 points or a score higher that the dealer, but <=21
  
  Ace can eb counted as 1 or 11 points.
  
  Author Anyes Taffard
*/

const int N=52;
//Blackjack card value (1-52);
int card_values[52] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
		       1,2,3,4,5,6,7,8,9,10,10,10,10,
		       1,2,3,4,5,6,7,8,9,10,10,10,10,
		       1,2,3,4,5,6,7,8,9,10,10,10,10 };

/*
  Use Marsaglia's RNG 
*/
unsigned long long int v;
//_______________________________________________
unsigned long long int64() {
  v ^= v >> 21; v ^= v << 35; v ^= v >> 4;
  return v*2685821657736338717LL;
}
//_______________________________________________
void setSeed(unsigned long long int j) {
  v = 4101842887655102017LL;
  v ^= j;
  v = int64();
}
//_______________________________________________
double myRandom() {
  return 5.42101086242752217e-20*int64();
}

//_________________________________________
// Choose a card randomly from what's left in the deck
int drawCard(int deck[])
{
  int aCard;
  do{
    aCard = (int) (myRandom()*N);
  } while (deck[aCard]);
  
  deck[aCard] = 1; //flag this card as already drawn
  return card_values[aCard];
}

//_________________________________________
// Calculate the best Blackjack score
int bestScore(int score, int nAces){
  int totScore = score;
  for(int i=0; i<nAces && totScore<=11; i++)
    totScore += 10;

  return totScore;
}
//_________________________________________
void whoWon(int pScore, int pAces,
	    int dScore, int dAces)
{
  int pBest = bestScore(pScore,pAces);
  int dBest = bestScore(dScore,dAces);

  if(pBest > dBest){
    if(pBest>21) printf("Player lost %i (dealer %i) \n",pBest,dBest);
    else         printf("Player won!!! %i (dealer %i) \n",pBest,dBest);
  }
  else{
    if(dBest>21) printf("Player won!!! %i (dealer %i) \n",pBest,dBest);
    else         printf("Player lost %i (dealer %i) \n",pBest,dBest);
  }

}

//_________________________________________
//_________________________________________
int main(){
  
  int playerScore = 0;  //player score
  int playerAces  = 0;  //player number of aces

  int dealerScoreOpen   = 0; //Dealer score for turned cards
  int dealerScoreHidden = 0; //Dealer hidden card score
  int dealerAces        = 0; //Dealer number of aces  
    

  //Set random seed
  setSeed( time(NULL) * 391740128);

  //Track the cards pull of the deck
  //1 true, 0 false;
  int deck[N]; 
  memset(deck,0,sizeof(deck[0])*N); 

  //Initialize the game - draw 2 cards for player and dealer
  //  get the value of the card drawned 
  //  & keep track of scores and # of aces
  //  for the player and dealer 
  printf("\nPlayer initial hand \n");
  for(int i=0; i<2; i++){
    int newCard = drawCard(deck); 
    playerScore += newCard;
    if(newCard==1) playerAces++;
    printf("\t Card value %i \n",newCard);
  }

  printf("\nDealer initial hand \n");
  for(int i=0; i<2; i++){
    int newCard = drawCard(deck); 
    if(newCard==1) dealerAces++;
    if(i==0){ //Open card
      dealerScoreOpen += newCard;
      printf("\t Card value %i \n",newCard);
    } 
    else{ //Hidden card
      dealerScoreHidden += newCard;
    }
  }

  
  //Let's take the hit ?
  int endGame=0;
  do{
    //Player: show his/her best score and ask if 
    //he/she wants another card 
    printf("\n\nYou best score is: %i \n",
	   bestScore(playerScore,playerAces));
    
    char choice[2];
    printf("\nHit [y/n] ?\n");
    scanf("%s",choice);
    if(choice[0] == 'y'){ //Hit !
      int newCard = drawCard(deck); 
      playerScore += newCard;
      if(newCard==1) playerAces++;
      printf("\t Player card value %i \n",newCard);

      
      // Dealer 
      // takes a hit until his card total >=17
      if(dealerScoreOpen+dealerScoreHidden<16){
	newCard = drawCard(deck); 
	if(newCard==1) dealerAces++;
	dealerScoreOpen += newCard;
	printf("\t Dealer card value %i \n",newCard);
      }
    }//Done taking a hit 
    else if(choice[0] == 'n'){
      endGame = 1;
    }
    
    //Check scores and finish game ?
    if(bestScore(playerScore,playerAces)>21 ||
       bestScore(dealerScoreOpen+dealerScoreHidden,dealerAces) >21)
      endGame = 1;

  } while(!endGame);
  
  whoWon(playerScore,playerAces,
	 dealerScoreOpen+dealerScoreHidden,dealerAces);

  
  return 0;
}
