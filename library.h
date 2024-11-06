#include <iostream>
#include <fstream>
using namespace std;

struct Game{
  string opponent = "";
  int our_score = -1;
  int opp_score = -1;
  int shots = -1;
  int shots_on_target = -1;
  int possession = -1;
  int passes = -1;
  int pass_acc = -1;
  int fouls = -1;
  int yellow_cards = -1;
  int red_cards = -1;
  int offsides = -1;
  int corner = -1;
  string lineup[11];
};

void collect(ifstream &fin, Game& g);

void display(Game g);

void collect_all(Game games[], ifstream& fin, int& arr_size);

void display_all(Game games[], int arr_size);

void get_filename(string& filename, ifstream& fin);

int search(Game games[],int arr_size);

void insertion_sort(Game games[], int arr_size);

int menu();

void to_lower(string& s);

void passes_completed(Game games[], int arr_size);

void player_games(Game games[], int arr_size);

void games_fouls(Game games[], int arr_size);

void remove_game(Game games[], int& arr_size);
