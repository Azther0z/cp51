// Digital Wallet
// Hard

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <string>
#include <bits/stdc++.h>

// you can include anything

using namespace std;

class Action{
public:
  size_t time;
  string id;
  bool operator<(const Action &other)const{
    return time>other.time;
  }
};

class Wallet{
public:
  queue<pair<int,int>> money;
  long long totalMoney = 0;  
};

class DigitalWallet {
  // you can declare variables or write new function
  public:
    map<string,Wallet> wallet;
    priority_queue<Action> pq;
    long long totalGive = 0;
    long long totalSpent = 0;
    long long totalExpired = 0;
    
    void update(size_t time){
      while(!pq.empty()&&pq.top().time<=time){
        Action current = pq.top();
        pq.pop();
        while(!wallet[current.id].money.empty()&&wallet[current.id].money.front().first<=current.time){
          wallet[current.id].totalMoney -= wallet[current.id].money.front().second;
          totalExpired += wallet[current.id].money.front().second;
          wallet[current.id].money.pop();
        }
      }
    }

    void add_money(size_t time, string person_id, int amount, size_t duration) {
      // your code here
      update(time);
      wallet[person_id].totalMoney += amount;
      totalGive += amount;
      wallet[person_id].money.push({time+duration+1,amount});
      pq.push({time+duration+1,person_id});
    }

    bool use_money(size_t time, string person_id, int amount) {
      // your code here
      update(time); 
      if(wallet[person_id].totalMoney>=amount){
        totalSpent += amount;
        wallet[person_id].totalMoney -= amount;
        while(amount>0){
          if(amount>=wallet[person_id].money.front().second){
            amount -= wallet[person_id].money.front().second;
            wallet[person_id].money.pop();
          }
          else{
            wallet[person_id].money.front().second -= amount;
            amount = 0;
          }
        }
        return true;
      }
      else{
        return false;
      }
    }

    int current_money(size_t time, string person_id) {
      // your code here
      update(time);
      return wallet[person_id].totalMoney;
    }

    void status(size_t time, long long &total_give, long long &total_spent, long long &total_expired) {
      // your code here
      update(time);
      total_give = totalGive;
      total_spent = totalSpent;
      total_expired = totalExpired;
    }
};

#endif