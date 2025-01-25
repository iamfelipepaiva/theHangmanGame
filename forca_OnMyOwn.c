//
// Created by Felipe on 24/05/2024.
//
#include "forca_OnMyOwn.h"

char carMakers[][11] = {
        "mercedes",
        "chevrolet",
        "volkswagen",
        "ferrari",
        "fiat",
        "renault",
        "jeep",
        "honda",
        "bmw",
        "citroen"
};

char countries[][11] = {
        "brazil",
        "ireland",
        "australia",
        "india",
        "italy",
        "england",
        "portugal",
        "spain",
        "argentina",
        "peru"
};

char capitals[][11] = {
        "brasilia",
        "dublin",
        "washington",
        "sidney",
        "tokyo",
        "london",
        "berlin",
        "brussels",
        "rome",
        "barcelona"
};

char devices[][11] = {
        "laptop",
        "fan",
        "microwave",
        "mouse",
        "speakers",
        "fridge",
        "earbuds",
        "television",
        "toaster",
        "mobile"
};

void hangingMan (int livesNumber) {
    if (livesNumber == 6) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n- ");
    } else if (livesNumber == 5) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|      0");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n- ");
    } else if (livesNumber == 4) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|      0");
        printf("\n|      |");
        printf("\n|");
        printf("\n|");
        printf("\n- ");
    }else if (livesNumber == 3) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|      0");
        printf("\n|     /|");
        printf("\n|");
        printf("\n|");
        printf("\n- ");
    }else if (livesNumber == 2) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|      0");
        printf("\n|     /|\\");
        printf("\n|");
        printf("\n|");
        printf("\n- ");
    }else if (livesNumber == 1) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|      0");
        printf("\n|     /|\\");
        printf("\n|     /");
        printf("\n|");
        printf("\n- ");
    }else if (livesNumber == 0) {
        printf("\n+------+");
        printf("\n|      |");
        printf("\n|      0");
        printf("\n|     /|\\");
        printf("\n|     / \\");
        printf("\n|");
        printf("\n-");
    }
}

void singlePlayer(){
    int usersChoice;
    srand(time(NULL));

    printf("\n|\t WORDS CATEGORIES\t\t|");
    printf("\n|\t  1. Car Makers\t\t\t|");
    printf("\n|\t  2. Countries \t\t\t|");
    printf("\n|\t  3. Capitals\t\t\t|");
    printf("\n|\t  4. Devices \t\t\t|");
    printf("\n|\t  Input an option: \t\t");
    scanf("%d", &usersChoice);

    int randomPositioning = (rand () % 10);

//User's choice for category switch
    switch(usersChoice){
        case 1:
            carMakers[randomPositioning];
            int letterGuessed[10] = {0,0,0,0,0,0,0,0,0,0};
            char enteredLetter;
            char guess[10];

//Size of random word for the round
            int randomWordLength = strlen(carMakers[randomPositioning]);

//Data checking for the round. Debugging purpose only.
//Debugging purpose printf("\nRandom number: %d, selected word: %s, its length: %d\n", randomNum, guessingWords[randomNum], randomWordLength);
            int correctGuesses = 0, incorrectGuesses = 0, livesNumber = 6, incorrectLivesNumber = 0;
            int lastCorrect = 0;

//Array to store and return incorrect characters
            char putTogether[15];

//Index to change position of pointer to store next character
            int currentIndex = 0;

//Routine kick off
            while(correctGuesses<=randomWordLength || incorrectGuesses<=livesNumber){
//The hangman illustration by round
                hangingMan(livesNumber);

//Showing of incorrect guessed letters
//printf("\nWrong guessed letters letters: %c", putTogether[15]);
                printf("\n");
                printf("Incorrect guesses thus far: ");
                for(int i = 0; i < currentIndex; i++){
                    printf("%c ", putTogether[i]);
                }

//End of condition to print out incorrect letters
//Gaps to be filled with letters belonging to random word from array
                printf("\nLetters still missing:");
                for(int i = 0; i < randomWordLength; i++){
                    if(letterGuessed[i] == 1){
                        printf("%c", carMakers[randomPositioning][i]);
                    }
                    else{
                        printf("-");
                    }
                }
                printf("\n");
//Collecting letter from user
                fflush(stdin);
                printf("\nInput a guess letter: ");
                fgets(guess, sizeof(guess), stdin);

//Checking inserted info and possible bug, storing letter from user into another variable to manipulate
                enteredLetter = guess[0];

// Debugging purpose letter checking printf("Entered letter: %c", enteredLetter);
                lastCorrect = correctGuesses;

//For to run array of 0s transforming into 1s as correct letters are inserted
                for(int i = 0; i < randomWordLength; i++){
                    if (letterGuessed[i] == 1){
                        continue;
                    }
                    else if(enteredLetter == carMakers[randomPositioning][i]){
                        letterGuessed[i] = 1;
                        correctGuesses++;
                    }
                }
//End of incorrect guess looping - just changed
                if(lastCorrect == correctGuesses){
                    incorrectGuesses++;
                    livesNumber--;
                    putTogether[currentIndex] = enteredLetter;
                    printf("\nIncorrect guess!");
                    currentIndex++;
                }
                else if(lastCorrect != correctGuesses && correctGuesses != randomWordLength){
                    printf("\nCorrect guess!");
                }
                if(livesNumber == 0){
                    hangingMan(livesNumber);
                    printf("\nYou lose! The word was [%s]! Try again!\n\n", carMakers[randomPositioning]);
                    break;
                }
                else if (correctGuesses == randomWordLength){
                    hangingMan(livesNumber);
                    printf("\nPerfect final guess!");
                    printf("\nYOU WIN!!! The word is [%s]!\n\n", carMakers[randomPositioning]);
                    break;
                }
// Debugging purpose printf("\nAssertive guesses: %d\n", correctGuesses);
            }
            //while
        break;

        case 2:
            countries[randomPositioning];
            int letterGuessed2[10] = {0,0,0,0,0,0,0,0,0,0};
            char enteredLetter2;
            char guess2[10];
            int randomWordLength2 = strlen(countries[randomPositioning]);
            int correctGuesses2 = 0, incorrectGuesses2 = 0, livesNumber2 = 6, incorrectLivesNumber2 = 0;
            int lastCorrect2 = 0;
            char putTogether2[15];
            int currentIndex2 = 0;

            while(correctGuesses2<randomWordLength2 || incorrectGuesses2<=livesNumber2){
                hangingMan(livesNumber2);

                printf("\n");
                printf("Incorrect guesses thus far: ");
                for(int i = 0; i < currentIndex2; i++){
                    printf("%c ", putTogether2[i]);
                }

                printf("\nLetters still missing:");
                for(int i = 0; i < randomWordLength2; i++){
                    if(letterGuessed2[i] == 1){
                        printf("%c", countries[randomPositioning][i]);
                    }
                    else{
                        printf("-");
                    }
                }
                printf("\n");

                fflush(stdin);
                printf("\nInput a guess letter: ");
                fgets(guess2, sizeof(guess2), stdin);

                enteredLetter2=guess2[0];

                lastCorrect2=correctGuesses2;

                for(int i = 0; i < randomWordLength2; i++){
                    if(letterGuessed2[i] == 1){
                        continue;
                    }
                    else if(enteredLetter2 == countries[randomPositioning][i]){
                        letterGuessed2[i]=1;
                        correctGuesses2++;
                    }
                }

                if(lastCorrect2 == correctGuesses2){
                    incorrectGuesses2++;
                    livesNumber2--;
                    putTogether2[currentIndex2]=enteredLetter2;
                    printf("\nIncorrect guess! Sorry!");
                    currentIndex2++;
                }
                else if(lastCorrect2 != correctGuesses2 && correctGuesses2 != randomWordLength2){
                    printf("\nCorrect guess!");
                }
                if(livesNumber2==0){
                    hangingMan(livesNumber2);
                    printf("\nYou lose! The word was [%s]! Try again!\n\n", countries[randomPositioning]);
                    break;
                }
                else if(correctGuesses2 == randomWordLength2){
                    hangingMan(livesNumber2);
                    printf("\nPerfect final guess!");
                    printf("\nYOU WIN!!! The word is [%s]!\n\n", countries[randomPositioning]);
                    break;
                }
            }
            //while
            break;

        case 3:
           capitals[randomPositioning];
            int letterGuessed3[10] = {0,0,0,0,0,0,0,0,0,0};
            char enteredLetter3;
            char guess3[10];
            int randomWordLength3 = strlen(capitals[randomPositioning]);
            int correctGuesses3 = 0, incorrectGuesses3 = 0, livesNumber3 = 6, incorrectLivesNumber3 = 0;
            int lastCorrect3 = 0;
            char putTogether3[15];
            int currentIndex3 = 0;

            while(correctGuesses3<randomWordLength3 || incorrectGuesses3<=livesNumber3){
                hangingMan(livesNumber3);

                printf("\n");
                printf("Incorrect guesses thus far: ");
                for(int i = 0; i < currentIndex3; i++) {
                    printf("%c ", putTogether3[i]);
                }

                printf("\nLetters still missing: ");
                for(int i = 0; i < randomWordLength3; i++){
                    if(letterGuessed3[i] == 1){
                        printf("%c", capitals[randomPositioning][i]);
                    }
                    else{
                        printf("-");
                    }
                }
                printf("\n");

                fflush(stdin);
                printf("\nInput a guess letter: ");
                fgets(guess3, sizeof(guess3), stdin);

                enteredLetter3=guess3[0];

                lastCorrect3=correctGuesses3;

                for(int i = 0; i < randomWordLength3; i++){
                    if(letterGuessed3[i] == 1){
                        continue;
                    }
                    if(enteredLetter3 == capitals[randomPositioning][i]){
                        letterGuessed3[i]=1;
                        correctGuesses3++;
                    }
                }

                if(lastCorrect3 == correctGuesses3){
                    incorrectGuesses3++;
                    livesNumber3--;
                    putTogether3[currentIndex3] = enteredLetter3;
                    printf("\nIncorrect guess! Sorry!");
                    currentIndex3++;
                }
                else if (lastCorrect3 != correctGuesses3 && correctGuesses3 != randomWordLength3 ){
                    printf("\nCorrect guess!");
                }
                if(livesNumber3==0){
                    hangingMan(livesNumber3);
                    printf("\nYou lose! The word was [%s]! Try again!\n\n", capitals[randomPositioning]);
                    break;
                }
                else if(correctGuesses3 == randomWordLength3){
                    hangingMan(livesNumber3);
                    printf("\nPerfect final guess!");
                    printf("\nYOU WIN!!! The word is [%s!]\n\n", capitals[randomPositioning]);
                    break;
                }
            }
            //while
            break;

        case 4:
            devices[randomPositioning];
            int letterGuessed4[10] = {0,0,0,0,0,0,0,0,0,0};
            char enteredLetter4;
            char guess4[10];
            int randomWordLength4 = strlen(devices[randomPositioning]);
            int correctGuesses4 = 0, incorrectGuesses4 = 0, livesNumber4 = 6, incorrectLivesNumber4 = 0;
            int lastCorrect4 = 0;
            char putTogether4[15];
            int currentIndex4 = 0;
            while(correctGuesses4<randomWordLength4 || incorrectGuesses4<=livesNumber4){
                hangingMan(livesNumber4);

                printf("\n");
                printf("Incorrect guesses thus far: ");
                for(int i = 0; i < currentIndex4; i++){
                    printf("%c ", putTogether4[i]);
                }

                printf("\nLetters still missing:");
                for(int i = 0; i < randomWordLength4; i++){
                    if(letterGuessed4[i] == 1){
                        printf("%c", devices[randomPositioning][i]);
                    }
                    else{
                        printf("-");
                    }
                }
                printf("\n");

                fflush(stdin);
                printf("\nInput a guess letter: ");
                fgets(guess4, sizeof(guess4), stdin);

                enteredLetter4=guess4[0];

                lastCorrect4=correctGuesses4;

                for(int i = 0; i < randomWordLength4; i++){
                    if(letterGuessed4[i] == 1){
                        continue;
                    }
                    if(enteredLetter4 == devices[randomPositioning][i]){
                        letterGuessed4[i]=1;
                        correctGuesses4++;
                    }
                }

                if(lastCorrect4 == correctGuesses4){
                    incorrectGuesses4++;
                    livesNumber4--;
                    putTogether4[currentIndex4] = enteredLetter4;
                    printf("\nIncorrect guess! Sorry!");
                    currentIndex4++;
                }
                else if(lastCorrect4 != correctGuesses4 && correctGuesses4 != randomWordLength4){
                    printf("\nCorrect guess!");
                }
                if(livesNumber4==0){
                    hangingMan(livesNumber4);
                    printf("\nYou lose! The word was [%s]. Try again!\n\n", devices[randomPositioning]);
                    break;
                }
                else if(correctGuesses4 == randomWordLength4){
                    hangingMan(livesNumber4);
                    printf("\nPerfect final guess!");
                    printf("\nYOU WIN!!! The word is [%s]!\n\n", devices[randomPositioning]);
                    break;
                }
            }
            //while
        break;
        default:
            printf("Invalid value. Try again.");
            break;
    }
}

void multiPlayer(){
    char userWord[15], userTip[30];

    fflush(stdin);
    printf("\nType a word for your partner to guess: ");
    fgets(userWord, sizeof(userWord), stdin);

// scanf("%[^\n]", userWord);
    fflush(stdin);
    printf("Insert a tip: ");
    fgets(userTip, sizeof(userTip), stdin);

    int letterInput[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char userGuess[10];
    char letterGuessed;
    int currentWordLength = strlen(userWord);
    int wordMinusOne=currentWordLength-1;
    char finalMessageWord[16] = "";

//Debuggingpurpose printf("Word: %s Tip: %s", userWord, userTip);

    int correctGuesses = 0, incorrectGuesses = 0, livesNumber = 6, lastCorrect = 0;
    char putTogetherMulti[16];
    int currentIndexMulti = 0;

    while(correctGuesses < currentWordLength || incorrectGuesses <= 6){
        hangingMan(livesNumber);

//Showing of incorrect guessed letters
        printf("\n");
        printf("Incorrect guesses thus far: ");
        for(int i = 0; i < currentIndexMulti; i++){
            printf("%c ", putTogetherMulti[i]);
        }

        printf("\nLetters still missing: ");
        for (int i = 0; i < wordMinusOne; ++i){
            if(letterInput[i]==1){
                printf("%c", userWord[i]);
            }
            else{
                printf("-");
            }
        }
        printf("\nThe tip is: %s", userTip);
        fflush(stdin);
        printf("\nInput a letter: ");
        fgets(userGuess, sizeof(userGuess), stdin);
        userGuess[strlen(userGuess)-1]='\0';

        letterGuessed = userGuess[0];

        int lastCorrectGuess = correctGuesses;

        for(int i = 0; i < currentWordLength; i++){
            if(letterInput[i]==1){
           continue;
            }
            if(letterGuessed==userWord[i]){
                letterInput[i]=1;
                correctGuesses++;
            }
        }

        // printf("%c", userWord[i]);
        if(lastCorrectGuess==correctGuesses){
            livesNumber--;
            incorrectGuesses++;
            putTogetherMulti[currentIndexMulti] = letterGuessed;
            printf("\nIncorrect guess! Sorry!");
            currentIndexMulti++;
        }
        else if(lastCorrectGuess != correctGuesses && correctGuesses != currentWordLength ){
            printf("\nCorrect guess!");
        }
        if(correctGuesses==wordMinusOne){
            hangingMan(livesNumber);
            strcpy(finalMessageWord, userWord);
            finalMessageWord[currentWordLength-1]='\0';
            printf("\nYOU WIN! The word is [%s]!\n\n", finalMessageWord);
            break;
        }
        else if(livesNumber==0){
            hangingMan(livesNumber);
            strcpy(finalMessageWord, userWord);
            finalMessageWord[currentWordLength-1]='\0';
            printf("\nYou lose! Try again! The word was [%s]!\n\n", finalMessageWord);
            break;
        }
    }
}