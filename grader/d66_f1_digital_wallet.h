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
    long long money;
    string id;
    bool operator<(const Action &other)const{
      return time>other.time;
    }
};

class DigitalWallet {
  // you can declare variables or write new function
  public:
    map<string,long long> wallet;
    priority_queue<Action> pq;
    long long totalGive = 0;
    long long totalSpent = 0;
    long long totalExpired = 0;
    void update(size_t time){
      while(!pq.empty()&&pq.top().time<=time){
        Action current = pq.top();
        pq.pop();
        current.money = min(current.money,wallet[current.id]);
        totalExpired += current.money;
        wallet[current.id] -= current.money;
      }
    }
    void add_money(size_t time, string person_id, int amount, size_t duration) {
      // your code here
      update(time);
      wallet[person_id] += amount;
      totalGive += amount;
      pq.push({time+duration,amount,person_id});
    }

    bool use_money(size_t time, string person_id, int amount) {
      // your code here
      update(time); 
      if(wallet[person_id]>=amount){
        wallet[person_id] -= amount;
        totalSpent += amount;
        return true;
      }
      else{
        return false;
      }
    }

    int current_money(size_t time, string person_id) {
      // your code here
      update(time);
      return wallet[person_id];
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