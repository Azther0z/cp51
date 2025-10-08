// Ordered Set

#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> st;
    for (auto a : A) {
        st.insert(a);
        v.push_back(a);
    }
    for (auto b : B) {
        if (st.find(b) == st.end()) {
            v.push_back(b);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> st;
    for (auto b : B) {
        st.insert(b);
    }
    for (auto a : A) {
        if (st.find(a) != st.end()) {
            v.push_back(a);
        }
    }
    return v;
}
