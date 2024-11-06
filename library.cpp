#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//game struct and its members
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

//function to collect one game
void collect(ifstream &fin, Game& g)
{
  getline(fin, g.opponent, ',');
  fin >> g.our_score;
  fin.ignore();
  fin >> g.opp_score;
  fin >> g.shots;
  fin >> g.shots_on_target;
  fin >> g.possession;
  fin >> g.passes;
  fin >> g.pass_acc;
  fin >> g.fouls;
  fin >> g.yellow_cards;
  fin >> g.red_cards;
  fin >> g.offsides;
  fin >> g.corner;
  fin.ignore();

  int i;
  for(i = 0; i < 10; i++)
    {
      getline(fin, g.lineup[i], ',');
    }
  getline(fin, g.lineup[i]);

}

//displays one game
void display(Game g)
{
  const int TOTAL_PLAYERS = 11;
  const int LONG_WIDTH = 15;
  const int SHORT_WIDTH = 7;
  const int MED_WIDTH = 10;
  const int NUM_FIELDS = 11;
  const string SEP = " |" ;
  const int TOTAL_WIDTH = (LONG_WIDTH * 3) + (SHORT_WIDTH * 5) + (MED_WIDTH * 3) + SEP.size() * NUM_FIELDS;
  const string LINE = SEP + string(TOTAL_WIDTH - 1, '-' ) + '|' ;
  string posession_str = to_string(g.possession) + "%";
  string pass_acc_str = to_string(g.pass_acc) + "%";
  string score_str = to_string(g.our_score) + "-" + to_string(g.opp_score);
  cout << setw(TOTAL_WIDTH / 2) << "Liverpool VS " << g.opponent << endl;

  cout << LINE << '\n' << SEP
       << setw(SHORT_WIDTH) << "Score" << SEP << setw(SHORT_WIDTH) << "Shots" << SEP
       << setw(LONG_WIDTH) << "Shots on Target" << SEP << setw(MED_WIDTH) << "Posession" << SEP
       << setw(SHORT_WIDTH) << "Passes" << SEP << setw(LONG_WIDTH) << "Pass Accuracy" << SEP
       << setw(SHORT_WIDTH) << "fouls" << SEP << setw(LONG_WIDTH) << "Yellow Cards" << SEP
       << setw(MED_WIDTH) << "Red Cards" << SEP << setw(MED_WIDTH) << "Offsides" << SEP
       << setw(SHORT_WIDTH) << "Corner" << SEP << "\n";

  cout << SEP << setw(SHORT_WIDTH) << score_str << SEP << setw(SHORT_WIDTH) << g.shots << SEP
       << setw(LONG_WIDTH) << g.shots_on_target << SEP << setw(MED_WIDTH) << posession_str << SEP
       << setw(SHORT_WIDTH) << g.passes << SEP << setw(LONG_WIDTH) << pass_acc_str << SEP
       << setw(SHORT_WIDTH) << g.fouls << SEP << setw(LONG_WIDTH) << g.yellow_cards << SEP
       << setw(MED_WIDTH) << g.red_cards << SEP << setw(MED_WIDTH) << g.offsides << SEP
       << setw(SHORT_WIDTH) << g.corner << SEP << endl;

  cout << setw(TOTAL_WIDTH / 2) << "Players:" << endl;
  for(int i = 0; i < TOTAL_PLAYERS; i++)
    cout << setw(TOTAL_WIDTH / 2) << g.lineup[i] << endl;
}

//collects data from the input.dat file
void collect_all(Game games[], ifstream& fin, int& arr_size)
{
  string url;
  Game g;
  getline(fin, url);
  while(!fin.eof())
    {
     collect(fin, g);
     games[arr_size] = g;
     arr_size++;
    }
}

//loops through the array of Game structs in main and prints each one
void display_all(Game games[], int arr_size)
{
  for(int i = 0; i < arr_size; i++)
    {
      display(games[i]);
      cout << "\n" << endl;
    }
}

//function to keep prompting for a valid filename
void get_filename(string& filename, ifstream& fin)
{
  cout << "Enter filename:" << endl;
  getline(cin, filename);
  fin.open(filename);
  
  while(!fin.is_open())
    {
      cout << "File not found. Try Again" << endl;
      cout << "\nEnter filename:" << endl;
      getline(cin, filename);
      fin.open(filename);
    }
}

//takes in a string and returns it with all lowercase letters
string to_lower(string s)
{
  for(int i = 0; i < s.length(); i++)
    {
      s[i] = tolower(s[i]);
    }
  return s;
}

//searches the Game array for a game with a given opponent and return the index of the struct with that opponent
int search(Game games[],int arr_size)
{
  int index = -1;
  string opponent;

  cin.ignore();
  cout << "Enter an Opponent:\t";
  getline(cin, opponent);
  string opp_lower = to_lower(opponent);

  for(int i = 0; i < arr_size; i++)
    {
      string game_opp = to_lower(games[i].opponent);
      if(game_opp == opp_lower)
      {
        index = i;
      }
    }
  return index;
}

//sorts the array of Game structs in main by posession
void insertion_sort(Game games[], int arr_size)
{
  int i, j;
  Game key;
  for(i = 1; i < arr_size; i++)
    {
      key = games[i];
      j = i - 1;
      while(j >= 0 && games[j].possession < key.possession)
      {
        games[j + 1] = games[j];
        j--;
      }
      games[j + 1] = key;
    }
}

int read_input()
{
  int choice;
  while(!(cin >> choice))
    {
      cout << "Invalid input. Try again." << endl;
      cin.clear(); //needed to clear the input error
      cin.ignore(123,'\n'); //ignores the previous input up to 123 characters
    }
  return choice;
}

//menu to display and show options that the user chooses
int menu()
{
  int answer = 0;
  do{
    cout << "\n\n1. Display all games.\n";
    cout << "2. Search for a game.\n";
    cout << "3. Sort by Possession.\n";
    cout << "4. Display passes completed in a game.\n";
    cout << "5. Display games a specific player played in.\n";
    cout << "6. Display games with less than a certain amount of fouls.\n";
    cout << "7. Remove a game.\n";
    cout << "8. Exit.\n" << endl;
    cout << "Please enter a number:" << endl;
    //makes sure the user enters a valid option
    answer = read_input();
  }while(answer < 1 || answer > 8);

  return answer;
}

//displays the amount of passes completed against a given opponent
void passes_completed(Game games[], int arr_size)
{
  int index = search(games, arr_size);
  if(index == -1)
    cout << "Opponent not found." << endl;
  else
  {
    double pass_completed = round(games[index].passes * (games[index].pass_acc / 100.0));
    cout << "\nLiverpool completed " << pass_completed << " passes against " << games[index].opponent << "."<< endl;  
  }
}

//displays all the games that one player played in
void player_games(Game games[], int arr_size)
{
  string player = "", line(20,'-');
  bool valid_player = false;
  
  cout << "Enter the name of the player:" << endl;
  cin.ignore();
  getline(cin, player);

  
  string player_lower = to_lower(player);
  cout << "\n" << setw(20) << "Games played in:" << endl;
  cout << line << endl;
  for(int i = 0; i < arr_size; i++)
    {
      for(int j = 0; j < 11; j++)
        {
          string player_in_arr_lower = to_lower(games[i].lineup[j]);
          if(player_in_arr_lower == player_lower)
          {
            cout << setw(20)<< games[i].opponent << endl;
            valid_player = true;
          }
        }
    }
  if(!valid_player)
    cout << setw(20) << "No Games found." << endl;
}

//displays all games below a certain number of fouls
void games_fouls(Game games[], int arr_size)
{
  bool valid = false;
  int user_fouls = 0;
  cout << "Enter the number of fouls:" << endl;
  user_fouls = read_input();

  cout << "\n" << setw(20) << "Games with less than " << user_fouls << " fouls:\n" << endl;
  for(int i = 0; i < arr_size; i++)
    if(games[i].fouls < user_fouls)
    {
      display(games[i]);
      valid = true;
    }
  if(!valid)
    cout << setw(20) << "No games found." << endl;
  cout << endl;
}

//removes a game permanently
void remove_game(Game games[], int& arr_size)
{
  int index = search(games, arr_size);
  if(index == -1)
    cout << "Opponent not found." << endl;
  else
  {
    games[index] = games[arr_size - 1];
    arr_size--;
    display_all(games, arr_size);
  }
}