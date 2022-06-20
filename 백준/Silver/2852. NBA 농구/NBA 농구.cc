#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int total_seconds = 48 * 60;
int n, team_1_score, team_2_score, team_1_winning_seconds, team_2_winning_seconds, start_seconds;
string scored_team, score_time, prev_winning_team;

vector<string> split(string input, string delimiter)
{
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while ((pos = input.find(delimiter)) != string::npos)
  {
    token = input.substr(0, pos);
    ret.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  ret.push_back(input);
  return ret;
}

string time_format(int num)
{
  string ret = "";
  int minute = num / 60;
  int second = num % 60;

  if (minute < 10) ret += "0" + to_string(minute);
  else ret += to_string(minute);

  ret += ":";

  if (second < 10) ret += "0" + to_string(second);
  else ret += to_string(second);
  
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> scored_team >> score_time;

    if (scored_team == "1") team_1_score++;
    else if (scored_team == "2") team_2_score++;
    
    vector<string> splitted = split(score_time, ":");
    string minute = splitted[0];
    string second = splitted[1];

    int curr_score_seconds = stoi(minute) * 60 + stoi(second);
    string curr_winning_team = "";
    if (team_1_score > team_2_score) curr_winning_team = "1";
    else if (team_1_score < team_2_score) curr_winning_team = "2";

    if (i == 0) {
      if (n == 1) {
        // 첫 번째 득점이 마지막 득점
        if (curr_winning_team == "1") team_1_winning_seconds += total_seconds - curr_score_seconds;
        if (curr_winning_team == "2") team_2_winning_seconds += total_seconds - curr_score_seconds;
      } else {
        // 첫 번째 득점
        start_seconds = curr_score_seconds;
        prev_winning_team = curr_winning_team;
      }
    } else if (i == n-1) {
      // 마지막 득점
      // 득점 이전에 동점인 상황
      if (prev_winning_team == "") {
        if (curr_winning_team == "1") team_1_winning_seconds += total_seconds - curr_score_seconds;
        if (curr_winning_team == "2") team_2_winning_seconds += total_seconds - curr_score_seconds;
        break;
      }
      // 연속 득점 상황
      if (prev_winning_team == curr_winning_team) {
        if (curr_winning_team == "1") team_1_winning_seconds += total_seconds - start_seconds;
        if (curr_winning_team == "2") team_2_winning_seconds += total_seconds - start_seconds;
        // 동점이 된 상황
      } else {
        if (prev_winning_team == "1") team_1_winning_seconds += curr_score_seconds - start_seconds;
        if (prev_winning_team == "2") team_2_winning_seconds += curr_score_seconds - start_seconds;
      }
    } else {
      // 득점 이전에 동점인 상황
      if (prev_winning_team == "") {
        start_seconds = curr_score_seconds;
        prev_winning_team = curr_winning_team;
        continue;
      }

      // 연속 득점 상황
      if (prev_winning_team == curr_winning_team) {
        if (curr_winning_team == "1") team_1_winning_seconds += curr_score_seconds - start_seconds;
        if (curr_winning_team == "2") team_2_winning_seconds += curr_score_seconds - start_seconds;
        start_seconds = curr_score_seconds;
        // 동점이 된 상황
      } else {
        if (prev_winning_team == "1") team_1_winning_seconds += curr_score_seconds - start_seconds;
        if (prev_winning_team == "2") team_2_winning_seconds += curr_score_seconds - start_seconds;
        prev_winning_team = curr_winning_team;
        start_seconds = curr_score_seconds;
      }
    }
  }

  cout << time_format(team_1_winning_seconds) << "\n";
  cout << time_format(team_2_winning_seconds);

  return 0;
}