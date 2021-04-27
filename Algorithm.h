// Copyright Ayrton Reulet 2021 reulayrt@bu.edu
// Copyright Megan Freeman 2021 megfree@bu.edu
// Copyright Dasha Smolina 2021 dsmolina@bu.edu
// Copyright Georgia Vachon gvachon@bu.edu
#pragma once
using std::vector;
using std::string;
using std::stoi;


// makes all the dates go back to normal
void back2Normal(vector<vector<string>> &p) {
  vector<string> month, day;
  for (auto e : p) {
    string tmonth, tday;
    for (int j = 0; j<2; j++) {            
      tmonth += e.at(0).at(j);
    }
    for (int j = 3; j<5; j++) {           
      tday += e.at(0).at(j);
    }
    month.push_back(tmonth);
    day.push_back(tday);
  }

  for (int i = 0; i < month.size(); i++) {
  if (day.at(i) == "00") {
    month.at(i) = std::to_string(stoi(month.at(i))-1);
    month.at(i).insert(month.at(i).begin(), 1, '0');
    if (month.at(i) == "01" || month.at(i) == "03" || month.at(i) == "05" || month.at(i) == "07"
     || month.at(i) == "08" || month.at(i) == "10" || month.at(i) == "12") {
      day.at(i) = "31";
    }
    else if (month.at(i) == "04" || month.at(i) == "06" || month.at(i) == "09"
             || month.at(i) == "11") {
      day.at(i) = "30";
    }
    else if (month.at(i) == "02") {
      day.at(i) = "28";
    }
  }
  }
  for (int i = 0; i < month.size(); i++) {
    p.at(i).at(0) = month.at(i) + "/" + day.at(i);
  }




}

// turn the exceptions into a new day 0
void dayZero(vector<vector<string>> &exception) {
  vector<string> month, day;

  for (int i = 0; i < exception.size(); i++) {
    string tmonth, tday;
    //month
    for (int j = 0; j < 2; j++) {
      tmonth += exception.at(i).at(0).at(j);
    }
    month.push_back(tmonth);
    //day
    for (int j = 3; j < 5; j++) {
      tday += exception.at(i).at(0).at(j);
    }
    day.push_back(tday);
  }
  for (int i = 0; i < month.size(); i++) {
    month.at(i) = std::to_string(stoi(month.at(i)) + 1);
    month.at(i).insert(month.at(i).begin(), 1, '0');
    day.at(i) = "00";
  }
  for (int i = 0; i < month.size(); i++) {
    exception.at(i).at(0) = month.at(i) + "/" + day.at(i);
  }
}


// exceptions for the 12 days of the year that don't work with the normal algorithm
vector<vector<string>> exceptions(vector<vector<string>> &p, vector<float> month,
                                  vector<float> day, vector<float> priority) {
  vector<vector<string>> exception;
  int counter = 0;

  
  for (int i = 0; i < month.size(); i++) {
  if (priority.at(i) < 6) {
    // 31 days
    if ((month.at(i) == 1 || month.at(i) == 3 || month.at(i) == 5 || month.at(i) == 7
     || month.at(i) == 8 || month.at(i) == 10 || month.at(i) == 12) && (day.at(i) == 31)) {
      exception.push_back(p.at(i-counter));
      p.erase(p.begin()+i-counter);
      counter++;
    }
    // 30 days
    else if ((month.at(i) == 4 || month.at(i) == 6 || month.at(i) == 9 || month.at(i) == 11)
             && (day.at(i) == 30)) {
      exception.push_back(p.at(i-counter));
      p.erase(p.begin()+i-counter);
      counter++;
    }
    // 28 days
    else if (month.at(i) == 2 && day.at(i) == 28) {
      exception.push_back(p.at(i-counter));
      p.erase(p.begin()+i-counter);
      counter++;
    }
  }
  }

  dayZero(exception);

  return exception;
}

// Normal ordering Algorithm
void order(vector<vector<string>> &p, vector<float> month, vector<float> day, vector<float> priority) {
  vector<vector<string>> finder;
  finder = p;
  int n = p.size();
  vector<float> mag(n), old;
  for (int i = 0; i < month.size(); i++) {
    mag.at(i) = ((13-month.at(i))*500) + ((31-day.at(i))*4.9) + (priority.at(i));
    for (int j = 0; j < i; j++) {
      if (mag.at(i) == mag.at(j)) {
        mag.at(i) = mag.at(i) + 0.01;
      }
    }
  }
  old = mag;
  sort(mag.begin(),mag.end(), std::greater<int>());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mag.at(i) == old.at(j)) {
        p.at(i) = finder.at(j);
      }
    }
  } 
}


// Function that gets used in the main program
vector<vector<string>> algorithm(vector<vector<string>> &p) {
  vector<float> Emonth, Eday, Epriority;
  vector<vector<string>> exception;

  for (int i = 0; i < p.size(); i++) {
    string tMonth, tDay, tPriority;
    // Months
    for (int j = 0; j < 2; j++) {
      tMonth += p.at(i).at(0).at(j);
    }
    Emonth.push_back(stoi(tMonth));
    // Days
    for (int j = 3; j < 5; j++) {
      tDay += p.at(i).at(0).at(j);
    }
    Eday.push_back(stoi(tDay));
    Epriority.push_back(stoi(p.at(i).at(2)));
  }

  exception = exceptions(p, Emonth, Eday, Epriority);
  vector<float> month, day, priority;
  for (auto e : exception) {
    p.push_back(e);
  }

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

  order(p, month, day, priority);
  back2Normal(p);

  return p;
}
