#include <iostream>
#include <vector>
#include <set>

void generate_relations(std::vector<int>& elements, std::set<std::pair<int, int>>& relation, int i, std::vector<std::set<std::pair<int, int>>>& reflexive_relations) {
    if (i == elements.size()) {
        reflexive_relations.push_back(relation);
        return;
    }
    
    relation.insert({elements[i], elements[i]});
    generate_relations(elements, relation, i + 1, reflexive_relations);
    
    relation.erase({elements[i], elements[i]});
    generate_relations(elements, relation, i + 1, reflexive_relations);
}

std::vector<std::set<std::pair<int, int>>> reflexive_binary_relations(int n) {
    std::vector<int> elements;
    for (int i = 1; i <= n; i++) {
        elements.push_back(i);
    }
    
    std::vector<std::set<std::pair<int, int>>> reflexive_relations;
    std::set<std::pair<int, int>> relation;
    generate_relations(elements, relation, 0, reflexive_relations);
    
    return reflexive_relations;
}

int main() {
    int n = 3;
    std::vector<std::set<std::pair<int, int>>> reflexive_relations = reflexive_binary_relations(n);
    for (auto relation : reflexive_relations) {
        for (auto pair : relation) {
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

