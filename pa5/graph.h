#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>

using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex {
    T label; // unique int for a vertex
    vector<T> adj_list;
    int indegree; // Part 2: number of nodes pointing in
    int top_num; // Part 2: topological sorting number
    Vertex(T l) : label(l) {top_num = 0; label = l;} //Part 1
};

// optional, but probably helpful
template <class T>
ostream& operator<<(ostream &o, Vertex<T> v){
    o << v.label;
    return o;
};


// syntax for custom compare functor
template<class T>
class VertexCompare {
public:
    bool operator()(Vertex<T> v1, Vertex<T> v2){
        return (v1.top_num > v2.top_num); 
    }
};

template <class T>
class Graph {
private:
    //c++ stl hash table
    unordered_map<T, Vertex<T>> node_set;
    //Use other data fields if needed
public:
    Graph() {};  // default constructor
    ~Graph() {};
    // build a graph
    void buildGraph(istream &input) {
        T val;
        T l;
        while (input >> l) {
            Vertex<T> v(l);
            string x;
            getline(input, x);
            stringstream ss(x);
            while(ss >> val) {
                v.adj_list.push_back(val);
            }
            ss.clear();
            node_set.insert({l, v});
        }
    }

    // display the graph into o
    void displayGraph(ostream& o) {
        for (auto i = node_set.begin(); i != node_set.end(); i++) {
            T l = i->first;
            o << l << " : ";
            Vertex<T> v = i->second;
            for (int i = 0; i < v.adj_list.size(); i++) {
                o << v.adj_list.at(i) << " ";
            }
            o << endl;
        }
    }

    //return the vertex at label, else throw any exception
    Vertex<T> at(T label) {
        return node_set.at(label);
    }

    //return the graph size (number verticies)
    int size() {
        int size = 0;
        for (auto i = node_set.begin(); i != node_set.end(); i++) {
            size++;
        }
        return size;
    }

    // topological sort
    // return true if successful, false on failure (cycle)
    bool topological_sort() {
        queue<Vertex<T>> q;
        int cnt = 0;
        for (auto i = node_set.begin(); i != node_set.end(); i++) {
            Vertex<T> v = i->second;
            if (v.indegree == 0) {
                q.push(v);
            }
        }
        while (!q.empty()) {
            Vertex<T> v = q.front();
            q.pop();
            node_set.at(v.label).top_num = ++cnt;
            for (int i = 0; i < v.adj_list.size(); i++) {
                T val = v.adj_list[i];
                if (--node_set.at(val).indegree == 0) {
                    q.push(node_set.at(val));
                }
            }
        }
        return (cnt == this->size());
    }; // Part 2

  // find indegree
    void compute_indegree() {
        for (auto i = node_set.begin(); i != node_set.end(); i++) {
            i->second.indegree = 0;
        }
        for (auto i = node_set.begin(); i != node_set.end(); i++) {
            Vertex<T> v = i->second;
            for (int j = 0; j < v.adj_list.size(); j++) {
                node_set.at(v.adj_list[j]).indegree++;
            }
        }
    }; // Part 2

    // print topological sort into o
    //  if addNewline is true insert newline into stream
    void print_top_sort(ostream& o, bool addNewline=true) { 
        priority_queue<Vertex<T>, vector<Vertex<T>>, VertexCompare<T>> q;
        for (auto i = node_set.begin(); i != node_set.end(); i++) {
            q.push(i->second);
        }
        while (!q.empty()) {
            o << q.top().label << " ";
            q.pop();
        }

        if(addNewline) {o << '\n';};
    }; // Part 2
    };

#endif
