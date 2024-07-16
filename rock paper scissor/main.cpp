#include <iostream>
#include <string>
#include <ctime>
#include <format>

using namespace std;

string user_input;
string user_play_again;
string random_array[3] = {"r","p","s"};
string random_answer;
string picks;
void rock_paper();
void play_again();

string convert(string pick){
    if (pick == "p"){
        return "paper";
    }
    if (pick == "s"){
        return "scissor";
    }
    else{
        return "rock";
    }
}

bool not_in_an_array(string word){
    for (int i = 0; i < 3; i++){
        if (random_array[i] == word){
            return false;
        }
    }
    return true;
}

void play_again(){
    cout << "wanna play again ? [y] [n] ";
    cin >> user_play_again;
    if (user_play_again == "y"){
        system("clear");
        cout << "okay lets play again \n";
        rock_paper();
    }
    else {
        return;
    }
}
void rock_paper() {
    random_answer = random_array[rand()%3];
    cout << "Choose between [r , p , s] \n";
    cin >> user_input;
    picks = format("Your pick: {} , Computer pick: {} \n",convert(user_input),convert(random_answer));
    if (user_input == "" || not_in_an_array(user_input)){
        cout << "please write a valid answer \n";
        rock_paper();
        return;
    }
    if (user_input == random_answer){
        cout << "It is a tie \n";
        cout << picks;
        play_again();
        return;
    }
    if ((random_answer == "r" && user_input == "p") || (random_answer == "p" && user_input == "s") || (random_answer == "s" && user_input == "p")) {
        cout << "You win! \n";
        cout << picks;
        play_again();
        return;
    }
    else {
        cout << "You lost! \n";
        cout << picks;
        play_again();
        return;
    }
}
int main() {
    system("clear");
    string response;
    cout << "Wanna play rock , paper , scissor [yes , no] \n";
    cin >> response ;
    if (response == "yes"){
        system("clear");
        cout << "Okay lets play \n";
        rock_paper();
        cout << "bye";
        return 0;
    }
    else {
        return 0;
    }
}
