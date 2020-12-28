#include <iostream>
#include <fstream>
#include <sstream>
#include "Jeans.h"
#include "Collection.h"

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

istream& operator>>(istream& is, CollectionJN& c) {
    string x;
    while (getline(is, x)) {
        int idx = x.find(" ");
        string colour = x.substr(0, idx);
        string size = x.substr(idx + 1);

        Jeans_colors col;
        Jeans_sizes sz;
        if (colour == "white") {col = Jeans_colors::white;}
        else if (colour == "black") {col = Jeans_colors::black;}
        else if (colour == "blue") {col = Jeans_colors::blue;}
        else {col = Jeans_colors::grey;}
        if (size == "small") {sz = Jeans_sizes::small;}
        else if (size == "medium") {sz = Jeans_sizes::medium;}
        else if (size == "large") {sz = Jeans_sizes::large;}
        else {sz = Jeans_sizes::xlarge;}

        c.insert_item(Jeans(col, sz));
    }
    return is;
}
void test_jeans(){
    Jeans jeans_1 = Jeans(Jeans_colors::grey, Jeans_sizes::small);
    Jeans jeans_2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
    Jeans jeans_3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
    Jeans jeans_4 = Jeans(Jeans_colors::black, Jeans_sizes::medium);
    CollectionJN collection_0;
    CollectionJN collection_1;
    CollectionJN collection_2(3);
    CollectionJN collection_3(5);
    CollectionJN collection_file(1);
    collection_0.insert_item(jeans_1);
    collection_0.make_empty();
    collection_1.insert_item(jeans_1);
    collection_2.insert_item(jeans_2);
    
    collection_2.print_items();
    collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
    collection_2.insert_item(jeans_3);
    collection_2.insert_item(jeans_3);
    CollectionJN collection_copy(collection_1);
    collection_1.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
    CollectionJN collection_7 = move(collection_1);
    collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
    collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
    collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
    collection_2.remove_this_item(jeans_2);
    
    collection_2.print_items();
    collection_copy.make_empty();
    if(collection_2.is_empty()){
        collection_2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
    }
    ifstream ifs("jeans1.data");
    ifs >> collection_file;
    collection_file.insert_item(jeans_3);
    collection_file.insert_item(jeans_3);
    collection_2.insert_item(jeans_3);
    collection_2.insert_item(jeans_3);
    collection_2.insert_item(jeans_2);
    collection_2.insert_item(jeans_1);
    
    collection_file.print_items();
    
    swap(collection_file,collection_2);
    collection_3 = make_union(collection_file,collection_2);                
    if((collection_3.total_items() - collection_2.total_items()) == collection_file.total_items()){
        sort_by_size(collection_2,Sort_choice::selection_sort);
        cout<<collection_3;
    }
}
