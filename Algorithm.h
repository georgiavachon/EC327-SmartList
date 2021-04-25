// Copyright Ayrton Reulet 2021 reulayrt@bu.edu
// Copyright Megan Freeman 2021 megfree@bu.edu
// Copyright Dasha Smolina 2021 dsmolina@bu.edu
// Copyright Georgia Vachon gvachon@bu.edu
#pragma once
using std::vector;
using std::string;
using std::stoi;

vector<vector<string>> exceptions(vector<vector<string>> &p, vector<float> month,
                                  vector<float> day, vector<float> priority) {
  vector<vector<string>> exception;

  for (int i = 0; i < month.size(); i++) {
    // 31 days
    if ((month.at(i) == 1 || month.at(i) == 3 || month.at(i) == 5 || month.at(i) == 7
     || month.at(i) == 8 || month.at(i) == 10 || month.at(i) == 12) && (day.at(i) == 31)) {
      exception.push_back(p.at(i));
      p.erase(p.begin()+i);
    }
    // 30 days
    else if ((month.at(i) == 4 || month.at(i) == 6 || month.at(i) == 9 || month.at(i) == 11)
             && (day.at(i) == 30)) {
      exception.push_back(p.at(i));
      p.erase(p.begin()+i);
    }
    // 28 days
    else if (month.at(i) == 2 && day.at(i) == 28) {
      exception.push_back(p.at(i));
      p.erase(p.begin()+i);
    }
  }

  return exception;
}

void order(vector<vector<string>> &p, vector<float> month, vector<float> day, vector<float> priority) {
  vector<vector<string>> finder;
  finder = p;
  int n = p.size();
  vector<int> mag(n), old;
  for (int i = 0; i < month.size(); i++) {
    mag.at(i) = ((13-month.at(i))*500) + ((31-day.at(i))*4.9) + (priority.at(i));
  }
  old = mag;
  sort(mag.begin(),mag.end(), std::greater<int>());

  for (auto e : old)

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mag.at(i) == old.at(j)) {
        p.at(i) = finder.at(j);
      }
    }
  }
}


vector<vector<string>> algorithm(vector<vector<string>> &p) {
  vector<float> month, day, priority;
  vector<vector<string>> exception;

  for (int i = 0; i < p.size(); i++) {
    string tMonth, tDay, tPriority;
    // Months
    for (int j = 0; j < 2; j++) {
      tMonth += p.at(i).at(0).at(j);
    }
    month.push_back(stoi(tMonth));
    // Days
    for (int j = 3; j < 5; j++) {
      tDay += p.at(i).at(0).at(j);
    }
    day.push_back(stoi(tDay));
    priority.push_back(stoi(p.at(i).at(2)));
  }

  //if (p.size() > 1)*************************************************maybe use for ease***********
    //exception = exceptions(p, month, day, priority);
  order(p, month, day, priority);
  
  


  return p;
}
