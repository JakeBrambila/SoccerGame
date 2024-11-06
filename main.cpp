#include <iostream>
#include <iomanip>
#include <fstream>
#include "library.h"
using namespace std;

int main() 
{
  const int MAX_GAMES = 100;
  string url, filename = "";
  Game games[MAX_GAMES];
  //how many games in struct array
  int arr_size = 0;
  ifstream fin;

  //function to get the filename and test if its valid
  get_filename(filename, fin);

  collect_all(games, fin, arr_size);

  int choice;
  //loops until user quits
  do{
    //choice returns the user's choice from the menu
    choice = menu();
    switch(choice)
      {
        case 1:
          display_all(games, arr_size);
          break;
        case 2:
          {int index = search(games, arr_size);
          if(index == -1)
          {
            cout << "Game not found." << endl;
          }
          else
            display(games[index]);
          }
            break;
        case 3:
          cout << "Sorted by Possession:" << endl;
          insertion_sort(games, arr_size);
          display_all(games, arr_size);
          break;
        case 4:
          passes_completed(games, arr_size);
          break;
        case 5:
          player_games(games, arr_size);
          break;
        case 6:
          games_fouls(games, arr_size);
          break;
        case 7:
          remove_game(games, arr_size);
          break;
        case 8:
          cout << "Exiting..." << endl;
          cout << "Goodbye! Thanks for using this program!" << endl;
          break;
        default:
          cout << "Invalid choice. Please try again." << endl;
          break;
      }
  }while(choice != 8);

  fin.close();
}
