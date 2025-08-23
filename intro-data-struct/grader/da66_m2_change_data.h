// Change Data

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> b;
    while(!a.empty()){
        std::vector<std::queue<int>> tmp = a.top();
        a.pop();
        std::vector<std::queue<int>> vec;
        for(auto &q:tmp){
            std::queue<int> que;
            while(!q.empty()){
                if(q.front()==from){
                    que.push(to);
                }
                else{
                    que.push(q.front());
                }
                q.pop();
            }
            vec.push_back(que);
        }
        b.push(vec);
    }
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &x:a){
        if(x.second.second==from){
            x.second.second = to;
        }
        std::vector<int> vec;
        while(!x.second.first.empty()){
            if(x.second.first.top()==from){
                vec.push_back(to);
            }
            else{
                vec.push_back(x.second.first.top());
            }
            x.second.first.pop();
        }
        for(auto v:vec){
            x.second.first.push(v);
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> b;
    for(auto &x:a){
        std::pair<std::list<int>, std::map<int, std::pair<int, string>>> p;
        for(auto &y:x.first){
            if(y==from){
                p.first.push_back(to);
            }
            else{
                p.first.push_back(y);
            }
        }
        for(auto &y:x.second){
            if(y.second.first==from&&y.first==from){
                p.second[to] = {to,y.second.second};
            }
            else if(y.first==from){
                p.second[to] = y.second;
            }
            else if(y.second.first==from){
                p.second[y.first] = {to,y.second.second};
            }
            else{
                p.second[y.first] = y.second;
            }
        }
        b.insert(p);
    }
    a = b;
}

#endif
